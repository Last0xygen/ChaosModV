#include <stdafx.h>

/*
    Effect by Last0xygen
*/

static void OnTick()
{
	REQUEST_ANIM_SET("move_ped_crouched");
	REQUEST_ANIM_SET("move_ped_crouched_strafing");
	while (!HAS_ANIM_SET_LOADED("move_ped_crouched") || !HAS_ANIM_SET_LOADED("move_ped_crouched_strafing"))
	{
		WAIT(0);
	}
	for (auto ped : GetAllPeds())
	{
		SET_PED_MOVEMENT_CLIPSET(ped, "move_ped_crouched", 1);
		SET_PED_STRAFE_CLIPSET(ped, "move_ped_crouched_strafing");
	}
}
static void OnStop()
{
	for (auto ped : GetAllPeds())
	{
		RESET_PED_MOVEMENT_CLIPSET(ped, 0);
		RESET_PED_STRAFE_CLIPSET(ped);
	}
}

// clang-format off
REGISTER_EFFECT(nullptr, OnStop, OnTick, EffectInfo
	{
		.Name = "Squatting",
		.Id = "peds_squatting",
		.IsTimed = true,
		.IsShortDuration = true
	}
);