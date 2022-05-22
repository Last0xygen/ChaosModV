#include <stdafx.h>

static void OnStop()
{
	for (auto veh : GetAllVehs())
	{
		SET_VEHICLE_GRAVITY(veh, true);
		SPECIAL_ABILITY_FILL_METER(PLAYER_ID(), true, true);
	}
}

static void OnTick()
{
	SPECIAL_ABILITY_DEPLETE_METER(PLAYER_ID(), true, true);
	for (auto veh : GetAllVehs())
	{
		SET_VEHICLE_GRAVITY(veh, false);
	}
}

// clang-format off
REGISTER_EFFECT(nullptr, OnStop, OnTick, EffectInfo
	{
		.Name = "Vehicles Have No Gravity",
		.Id = "vehs_nogravity",
		.IsTimed = true,
		.IsShortDuration = true
	}
);