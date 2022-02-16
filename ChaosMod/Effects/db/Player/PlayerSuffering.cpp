#include <stdafx.h>

static void OnStart()
{
	currentHealth = -1;
}

static void OnTick()
{
	DRAW_RECT(.5f, .5f, 1.f, 1.f, 150, 0, 0, 100, false);
	Ped player = PLAYER_PED_ID();
	SET_PLAYER_INVINCIBLE(PLAYER_ID(), true);

	if (IS_PED_IN_ANY_VEHICLE(player, false))
	{
		Vehicle playerVeh = GET_VEHICLE_PED_IS_IN(player, false);
		TASK_LEAVE_VEHICLE(player, playerVeh, 4160);
	}

	if (!IS_ENTITY_ON_FIRE(player) && !IS_PED_IN_ANY_VEHICLE(player, true))
	{
		START_ENTITY_FIRE(player);
	}
}

static void OnStop()
{
	Ped player = PLAYER_PED_ID();
	if (IS_ENTITY_ON_FIRE(player))
	{
		STOP_ENTITY_FIRE(player);
	}
	SET_PLAYER_INVINCIBLE(PLAYER_ID(), false);
}

static RegisterEffect registerEffect(EFFECT_PLAYER_SUFFER, OnStart, OnStop, OnTick, EffectInfo
	{
		.Name = "Suffering",
		.Id = "player_suffer",
		.IsTimed = true,
		.IsShortDuration = true
	}
);