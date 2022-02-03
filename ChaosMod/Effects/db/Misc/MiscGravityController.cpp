#include <stdafx.h>

static void OnStop()
{
	SET_GRAVITY_LEVEL(0);
	SPECIAL_ABILITY_FILL_METER(PLAYER_ID(), true);
}

static void OnTickLow()
{
	SPECIAL_ABILITY_DEPLETE_METER(PLAYER_ID(), true);
	SET_GRAVITY_LEVEL(1);
}

static RegisterEffect registerEffect1(EFFECT_LOW_GRAV, nullptr, OnStop, OnTickLow, EffectInfo
	{
		.Name = "Low Gravity",
		.Id = "lowgravity",
		.IsTimed = true,
		.IsShortDuration = true,
		.IncompatibleWith = { EFFECT_VERY_LOW_GRAV, EFFECT_INSANE_GRAV, EFFECT_INVERT_GRAV, EFFECT_CHANGING_GRAVITY, EFFECT_SIDEWAYS_GRAVITY }
	}
);
static void OnTickVeryLow()
{
	SPECIAL_ABILITY_DEPLETE_METER(PLAYER_ID(), true);
	SET_GRAVITY_LEVEL(2);
}

static RegisterEffect registerEffect2(EFFECT_VERY_LOW_GRAV, nullptr, OnStop, OnTickVeryLow, EffectInfo
	{
		.Name = "Very Low Gravity",
		.Id = "verylowgravity",
		.IsTimed = true,
		.IsShortDuration = true,
		.IncompatibleWith = { EFFECT_LOW_GRAV, EFFECT_INSANE_GRAV, EFFECT_INVERT_GRAV, EFFECT_CHANGING_GRAVITY, EFFECT_SIDEWAYS_GRAVITY }
	}
);
static void OnTickInsane()
{
	Memory::SetGravityLevel(200.f);
	SPECIAL_ABILITY_DEPLETE_METER(PLAYER_ID(), true);

	for (auto ped : GetAllPeds())
	{
		if (!IS_PED_IN_ANY_VEHICLE(ped, false))
		{
			SET_PED_TO_RAGDOLL(ped, 1000, 1000, 0, true, true, false);

			Memory::ApplyForceToEntityCenterOfMass(ped, 0, 0, 0, -75.f, false, false, true, false);
		}
	}

	for (auto object : GetAllProps())
	{
		Memory::ApplyForceToEntityCenterOfMass(object, 0, 0, 0, -200.f, false, false, true, false);
	}
}

static RegisterEffect registerEffect3(EFFECT_INSANE_GRAV, nullptr, OnStop, OnTickInsane, EffectInfo
	{
		.Name = "Insane Gravity",
		.Id = "insanegravity",
		.IsTimed = true,
		.IsShortDuration = true,
		.IncompatibleWith = { EFFECT_LOW_GRAV, EFFECT_VERY_LOW_GRAV, EFFECT_INVERT_GRAV, EFFECT_CHANGING_GRAVITY, EFFECT_SIDEWAYS_GRAVITY }
	}
);
static void OnStartInvert()
{
	GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), GET_HASH_KEY("WEAPON_PARACHUTE"), 9999, true, true);
}

static void OnTickInvert()
{
	Memory::SetGravityLevel(-1.f);
	SPECIAL_ABILITY_DEPLETE_METER(PLAYER_ID(), true);

	for (auto ped : GetAllPeds())
	{
		if (!IS_PED_IN_ANY_VEHICLE(ped, false))
		{
			SET_PED_TO_RAGDOLL(ped, 1000, 1000, 0, true, true, false);

			Memory::ApplyForceToEntityCenterOfMass(ped, 0, 0, 0, 25.f, false, false, true, false);
		}
	}

	for (auto object : GetAllProps())
	{
		Memory::ApplyForceToEntityCenterOfMass(object, 0, 0, 0, 100.f, false, false, true, false);
	}
}

static RegisterEffect registerEffect4(EFFECT_INVERT_GRAV, OnStartInvert, OnStop, OnTickInvert, EffectInfo
	{
		.Name = "Invert Gravity",
		.Id = "invertgravity",
		.IsTimed = true,
		.IsShortDuration = true,
		.IncompatibleWith = { EFFECT_LOW_GRAV, EFFECT_VERY_LOW_GRAV, EFFECT_INSANE_GRAV, EFFECT_SIDEWAYS_GRAVITY, EFFECT_CHANGING_GRAVITY }
	}
);

Vector3 sidewaysGravityForce;
static void OnStartSideways()
{
	// Z is 0 since we don't want any upwards or downwards gravity
	sidewaysGravityForce = Vector3(g_Random.GetRandomFloat(-1, 1), g_Random.GetRandomFloat(-1, 1), 0.f);
	sidewaysGravityForce = sidewaysGravityForce / sidewaysGravityForce.Length(); // Normalize the direction
	sidewaysGravityForce = sidewaysGravityForce * 0.5f;
}

static void OnTickSideways()
{
	Memory::SetGravityLevel(0.f);

	for (auto ped : GetAllPeds())
	{
		if (!IS_PED_IN_ANY_VEHICLE(ped, false))
		{
			SET_PED_TO_RAGDOLL(ped, 1000, 1000, 0, true, true, false);

			Memory::ApplyForceToEntityCenterOfMass(ped, 1, sidewaysGravityForce.x, sidewaysGravityForce.y, sidewaysGravityForce.z, false, false, true, false);
		}
	}

	for (auto object : GetAllProps())
	{
		Memory::ApplyForceToEntityCenterOfMass(object, 1, sidewaysGravityForce.x, sidewaysGravityForce.y, sidewaysGravityForce.z, false, false, true, false);
	}

	for (auto veh : GetAllVehs())
	{
		Memory::ApplyForceToEntityCenterOfMass(veh, 1, sidewaysGravityForce.x, sidewaysGravityForce.y, sidewaysGravityForce.z, false, false, true, false);
	}
}

static RegisterEffect registerEffect5(EFFECT_SIDEWAYS_GRAVITY, OnStartSideways, OnStop, OnTickSideways, EffectInfo
	{
		.Name = "Sideways Gravity",
		.Id = "misc_sideways_gravity",
		.IsTimed = true,
		.IsShortDuration = true,
		.IncompatibleWith = { EFFECT_LOW_GRAV, EFFECT_VERY_LOW_GRAV, EFFECT_INVERT_GRAV, EFFECT_INSANE_GRAV, EFFECT_CHANGING_GRAVITY }
	}
);

static void OnTickChanging()
{
	static DWORD64 lastTick = 0;
	DWORD64 curTick = GET_GAME_TIMER();
	static float ChangingGravityLevel = GET_RANDOM_FLOAT_IN_RANGE(-30.f, 30.f);
	static int gravityTime = GET_RANDOM_INT_IN_RANGE(2, 6);

	if (curTick > lastTick + gravityTime)
	{
		lastTick = curTick;
		ChangingGravityLevel = GET_RANDOM_FLOAT_IN_RANGE(-30.f, 30.f);
		gravityTime = GET_RANDOM_INT_IN_RANGE(2, 6);
		gravityTime *= 1000;
	}

	Memory::SetGravityLevel(ChangingGravityLevel);
	SPECIAL_ABILITY_DEPLETE_METER(PLAYER_ID(), true);

	for (auto ped : GetAllPeds())
	{
		if (!IS_PED_IN_ANY_VEHICLE(ped, false))
		{
			SET_PED_TO_RAGDOLL(ped, 1000, 1000, 0, true, true, false);

			APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(ped, 0, 0, 0, ChangingGravityLevel * 25, false, false, true, false);
		}
	}

	for (auto object : GetAllProps())
	{
		APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(object, 0, 0, 0, ChangingGravityLevel * 100, false, false, true, false);
	}
}

static RegisterEffect registerEffectChanging(EFFECT_CHANGING_GRAVITY, nullptr, OnStop, OnTickChanging, EffectInfo
	{
		.Name = "Changing Gravity",
		.Id = "changinggravity",
		.IsTimed = true,
		.IsShortDuration = true,
		.IncompatibleWith = { EFFECT_LOW_GRAV, EFFECT_VERY_LOW_GRAV, EFFECT_INSANE_GRAV, EFFECT_INVERT_GRAV, EFFECT_SIDEWAYS_GRAVITY }
	}
);
