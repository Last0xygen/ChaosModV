#include <stdafx.h>


//static std::ofstream debugLog("ChaosLog.txt");
static std::map<Hash, CHandlingData*> processedHandling;

static std::ofstream debugLog("ChaosLog.txt");

static void OnStart()
{
	//REMOVE_ANIM_DICT("missfbi3_sniping");
	debugLog << "Size: " << processedHandling.size() << std::endl;

}


static void OnStop()
{
	for (std::pair<Vehicle, CHandlingData*> value : processedHandling)
	{
		value.second->fSuspensionRaise_ -= 0.25;
	}
	processedHandling.clear();
}


static void OnTick()
{
	int count = 20;
	for (Vehicle veh : GetAllVehs())
	{
		Hash model = GET_ENTITY_MODEL(veh);
		if (IS_THIS_MODEL_A_CAR(model) || IS_THIS_MODEL_A_QUADBIKE(model))
		{
			if (processedHandling.find(model) == processedHandling.end())
			{
				debugLog << "New Car" << std::endl;
				uint64_t pntr = Memory::GetHandlingPtr(veh);
				if (pntr == 0)
					continue;
				debugLog << "Pointer: " << pntr << std::endl;

				CHandlingData* handlingData = reinterpret_cast<CHandlingData*>(pntr);
				if (handlingData == nullptr)
				{
					debugLog << "Invalid handling" << std::endl;
					continue;
				}
				processedHandling[model] = handlingData;
				handlingData->fSuspensionRaise_ += 0.25;
			}
		}
		if (--count <= 0)
		{
			WAIT(0);
			count = 50;
		}
	}

}

static RegisterEffect registerEffect(EFFECT_IN_THE_HOOD, OnStart, OnStop, OnTick);