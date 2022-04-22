#include <stdafx.h>

static void OnTick()
{
	DRAW_RECT(.5f, .5f, 1.f, 1.f, 150, 0, 0, 100, false);
	Ped player = PLAYER_PED_ID();

	if (IS_PED_IN_ANY_VEHICLE(player, false))
	{
		Vehicle playerVeh = GET_VEHICLE_PED_IS_IN(player, false);
		TASK_LEAVE_VEHICLE(player, playerVeh, 4160);
	}

	if (!IS_ENTITY_ON_FIRE(player) && !IS_PED_IN_ANY_VEHICLE(player, true))
	{
		START_ENTITY_FIRE(player);
	}
	SET_ENTITY_HEALTH(player, GET_ENTITY_MAX_HEALTH(player), 0);
}

static void OnStop()
{
	Ped player = PLAYER_PED_ID();
	if (IS_ENTITY_ON_FIRE(player))
	{
		STOP_ENTITY_FIRE(player);
	}
}

static RegisterEffect registerEffect(EFFECT_PLAYER_SUFFER, nullptr, OnStop, OnTick, EffectInfo
	{
		.Name = "Suffering",
		.Id = "player_suffer",
		.IsTimed = true,
		.IsShortDuration = true
	}
);