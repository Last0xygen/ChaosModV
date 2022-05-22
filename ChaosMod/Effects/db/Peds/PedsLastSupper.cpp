/*
    Effect by Last0xygen
*/

#include <stdafx.h>

static Vector3 getRandomOffsetCoord(Vector3 startCoord, float maxOffset)
{
	return Vector3::Init(
		startCoord.x + g_Random.GetRandomInt(-maxOffset, maxOffset),
		startCoord.y + g_Random.GetRandomInt(-maxOffset, maxOffset),
		startCoord.z
	);
}

static void OnStart()
{
	static constexpr Hash modelHash = -835930287;

	Ped playerPed = PLAYER_PED_ID();
	Vector3 playerPos = GET_ENTITY_COORDS(playerPed, false);

	static const Hash playerGroup = GET_HASH_KEY("PLAYER");
	static const Hash civGroup = GET_HASH_KEY("CIVMALE");
	static const Hash femCivGroup = GET_HASH_KEY("CIVFEMALE");

	Hash relationshipGroup;
	ADD_RELATIONSHIP_GROUP("_FRIENDLY_JESUS", &relationshipGroup);
	SET_RELATIONSHIP_BETWEEN_GROUPS(0, relationshipGroup, playerGroup);
	SET_RELATIONSHIP_BETWEEN_GROUPS(0, playerGroup, relationshipGroup);
	int playerGroupId = GET_PLAYER_GROUP(PLAYER_ID());
	float maxOffset = 3;
	for (int i = 0; i < 12; i++)
	{
		Vector3 spawnCoord = getRandomOffsetCoord(playerPos, 3);
		Ped ped = CreatePoolPed(4, modelHash, spawnCoord.x, spawnCoord.y, spawnCoord.z, 0.f);
		if (IS_PED_IN_ANY_VEHICLE(playerPed, false))
		{
			SET_PED_INTO_VEHICLE(ped, GET_VEHICLE_PED_IS_IN(playerPed, false), -2);
		}
		SET_PED_SUFFERS_CRITICAL_HITS(ped, false);

		SET_PED_RELATIONSHIP_GROUP_HASH(ped, relationshipGroup);
		SET_PED_HEARING_RANGE(ped, 9999.f);

		SET_PED_AS_GROUP_MEMBER(ped, playerGroupId);

		SET_ENTITY_PROOFS(ped, false, true, true, false, false, false, false, false);

		SET_PED_COMBAT_ATTRIBUTES(ped, 5, true);
		SET_PED_COMBAT_ATTRIBUTES(ped, 46, true);

		SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(ped, false);
		SET_RAGDOLL_BLOCKING_FLAGS(ped, 5);
		SET_PED_SUFFERS_CRITICAL_HITS(ped, false);


		SET_PED_ACCURACY(ped, 100);
		SET_PED_FIRING_PATTERN(ped, 0xC6EE6B4C);
	}
}

REGISTER_EFFECT(OnStart, nullptr, nullptr, EffectInfo
    {
        .Name = "Last Supper",
        .Id = "peds_last_supper"
    }
);
