#include <stdafx.h>


static void OnTick()
{
	static DWORD64 lastTick = 0;
	DWORD64 curTick = GET_GAME_TIMER();
	if (curTick < lastTick + 50)
	{
		return;
	}
	lastTick = curTick;


	for (Vehicle veh : GetAllVehs())
	{
		Vector3 entityVel = GET_ENTITY_VELOCITY(veh);
		if (!IS_VEHICLE_SEAT_FREE(veh, -1, false))
		{
			float multiplier = 40;
			SET_ENTITY_VELOCITY(veh, entityVel.x + entityVel.x / multiplier, entityVel.y + entityVel.y / multiplier, entityVel.z + entityVel.z / multiplier);
		}
	}


	for (Ped ped : GetAllPeds())
	{
		Vector3 entityVel = GET_ENTITY_VELOCITY(ped);
		if (!IS_PED_IN_ANY_VEHICLE(ped, false))
		{
			float multiplier = 20;
			SET_ENTITY_VELOCITY(ped, entityVel.x + entityVel.x / multiplier, entityVel.y + entityVel.y / multiplier, entityVel.z + entityVel.z / multiplier);
		}
	}
}

static RegisterEffect registerEffect(EFFECT_MISC_HYPERACCEL, nullptr, nullptr, OnTick, EffectInfo
	{
		.Name = "Hyper Acceleration",
		.Id = "misc_hyperaccel",
		.IsTimed = true
	}
);