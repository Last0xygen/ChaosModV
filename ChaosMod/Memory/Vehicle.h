#pragma once

#include "Memory.h"
#include "Handle.h"
#include "nativesNoNamespaces.h"

#include <vector>

typedef unsigned short WORD;
typedef unsigned long long DWORD64;
typedef unsigned long Hash;
typedef int Vehicle;

namespace Memory
{

	inline uintptr_t(*GetAddressOfEntity)(int handle);
	inline int handlingOffset = 0;

	inline void InitVehicles()
	{
		// Init Vehicle Handling Methods
		Handle vehicleAddr = FindPattern("83 F9 FF 74 31 4C 8B 0D ? ? ? ? 44 8B C1 49 8B 41 08");
		if (vehicleAddr.IsValid())
		{
			Handle handlingAddr = FindPattern("3C 03 0F 85 ? ? ? ? 48 8B 41 20 48 8B 88");
			if (handlingAddr.IsValid())
			{
				GetAddressOfEntity = reinterpret_cast<uintptr_t(*)(int)>(vehicleAddr.Addr());
				handlingOffset = handlingAddr.Addr() == 0 ? 0 : *(int*)(handlingAddr.Addr() + 0x16);
			}
		}
	}

	inline uint8_t* GetAddress(int handle) {
		return reinterpret_cast<uint8_t*>(GetAddressOfEntity(handle));
	}

	inline uint64_t GetHandlingPtr(int handle) {
		if (handlingOffset != 0)
		{
			uint8_t* address = GetAddress(handle);
			if (address)
			{
				return *reinterpret_cast<uint64_t*>(address + handlingOffset);
			}
		}
		return 0;
	}




	inline std::vector<Hash> GetAllVehModels()
	{
		static std::vector<Hash> vehModels;

		if (vehModels.empty())
		{
			Handle handle;

			handle = FindPattern("48 8B 05 ?? ?? ?? ?? 48 8B 14 D0 EB 0D 44 3B 12");
			if (!handle.IsValid())
			{
				return vehModels;
			}

			handle = handle.At(2).Into();
			DWORD64 modelList = handle.Value<DWORD64>();

			handle = FindPattern("0F B7 05 ?? ?? ?? ?? 44 8B 49 18 45 33 D2 48 8B F1");
			if (!handle.IsValid())
			{
				return vehModels;
			}

			handle = handle.At(2).Into();
			WORD maxModels = handle.Value<WORD>();

			for (WORD i = 0; i < maxModels; i++)
			{
				DWORD64 entry = *reinterpret_cast<DWORD64*>(modelList + 8 * i);
				if (!entry)
				{
					continue;
				}

				Hash model = *reinterpret_cast<Hash*>(entry);

				if (IS_MODEL_VALID(model) && IS_MODEL_A_VEHICLE(model))
				{
					vehModels.push_back(model);
				}
			}
		}

		return vehModels;
	}

	inline void SetVehicleOutOfControl(Vehicle vehicle, bool state)
	{
		static __int64(*sub_7FF69C749B98)(int a1);

		static bool isSetup = false;
		if (!isSetup)
		{
			Handle handle;

			handle = FindPattern("E8 ? ? ? ? 8D 53 01 33 DB");
			if (!handle.IsValid())
			{
				return;
			}

			sub_7FF69C749B98 = handle.Into().Get<__int64(int)>();

			isSetup = true;
		}

		int vehClass = GET_VEHICLE_CLASS(vehicle);
		
		static const Hash blimpHash = GET_HASH_KEY("BLIMP");
		Hash vehModel = GET_ENTITY_MODEL(vehicle);
		if (vehClass == 15 || vehClass == 16 || vehModel == blimpHash) // No helis or planes, also make sure to explicitely exclude blimps at all costs as they cause a crash
		{
			return;
		}

		__int64 v6 = sub_7FF69C749B98(vehicle);
		if (v6)
		{
			v6 = (*reinterpret_cast<__int64(**)(__int64)>(*reinterpret_cast<__int64*>(v6) + 1528))(v6);

			if (v6)
			{
				*reinterpret_cast<BYTE*>(v6 + 2373) &= 0xFEu;
				*reinterpret_cast<BYTE*>(v6 + 2373) |= state;
			}
		}
	}

	inline void OverrideVehicleHeadlightColor(int index, bool overrideColor, int r, int g, int b)
	{
		static DWORD64* qword_7FF69E1E8E88 = nullptr;

		static const int maxColors = 13;
		static DWORD origColors[maxColors] = { };

		if (index >= maxColors)
		{
			return;
		}

		if (!qword_7FF69E1E8E88)
		{
			Handle handle;

			handle = FindPattern("48 89 0D ? ? ? ? E8 ? ? ? ? 48 8D 4D C8 E8 ? ? ? ? 48 8D 15 ? ? ? ? 48 8D 4D C8 45 33 C0 E8 ? ? ? ? 4C 8D 0D");
			if (!handle.IsValid())
			{
				return;
			}

			qword_7FF69E1E8E88 = handle.At(2).Into().Get<DWORD64>();
		}

		DWORD* colors = *reinterpret_cast<DWORD**>(*qword_7FF69E1E8E88 + 328);

		if (!origColors[0])
		{
			// Orig colors not backed up yet, do it now

			for (int i = 0; i < maxColors; i++)
			{
				origColors[i] = colors[i * 4];
			}
		}

		DWORD newColor = ((((r << 24) | (g << 16)) | b << 8) | 0xFF);

		colors[index * 4] = overrideColor ? newColor : origColors[index];
		colors[index * 4 + 1] = overrideColor ? newColor : origColors[index];
	}

	inline bool IsVehicleBraking(Vehicle vehicle)
	{
		static __int64(*sub_7FF788D32A60)(Vehicle vehicle) = nullptr;

		if (!sub_7FF788D32A60)
		{
			Handle handle = FindPattern("E8 ? ? ? ? 48 85 FF 74 47");
			if (!handle.IsValid())
			{
				return false;
			}

			sub_7FF788D32A60 = handle.Into().Get<__int64(Vehicle)>();
		}

		__int64 result = sub_7FF788D32A60(vehicle);

		return result ? *reinterpret_cast<float*>(result + 2496) : false;
	}
}