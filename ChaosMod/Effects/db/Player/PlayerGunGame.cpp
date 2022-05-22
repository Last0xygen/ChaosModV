/*
	//Effect by ProfessorBiddle, modified by Last0xygen
*/

#include <stdafx.h>
#include <Memory/WeaponPool.h>


static int playerKillsLast;

static void OnStart()
{
	playerKillsLast = -1;
	Ped playerPed = PLAYER_PED_ID();
	REMOVE_ALL_PED_WEAPONS(playerPed, 0);
	GIVE_WEAPON_TO_PED(playerPed, GET_HASH_KEY("WEAPON_PISTOL"), 9999, false, true);
}

static void OnTick()
{
	Weapon wepGive;
	Ped playerPed = PLAYER_PED_ID();

	Hash hitHash;
	int allPlayerKills = 0;
	int curKills = 0;
	for (Hash hash : { GET_HASH_KEY("SP0_KILLS"), GET_HASH_KEY("SP1_KILLS"), GET_HASH_KEY("SP2_KILLS")})
	{
		STAT_GET_INT(hash, &curKills, -1);
		allPlayerKills += curKills;
	}

	//check if stat this tick is larger than stat last tick
	if (playerKillsLast >= 0 && allPlayerKills > playerKillsLast)
	{
		REMOVE_ALL_PED_WEAPONS(playerPed, 0);
		static const std::vector<Hash>& weps = Memory::GetAllWeapons();
		wepGive = weps[g_Random.GetRandomInt(0, weps.size() - 1)];
		//make sure it's actually a gun, not a broken bottle etc.
		while (GET_WEAPON_CLIP_SIZE(wepGive) < 2)
		{
			wepGive = weps[g_Random.GetRandomInt(0, weps.size() - 1)];
		}
		//player always has pistol because sometimes the other weapon doesn't work
		GIVE_WEAPON_TO_PED(playerPed, GET_HASH_KEY("WEAPON_PISTOL"), 9999, false, true);
		GIVE_WEAPON_TO_PED(playerPed, wepGive, 9999, false, true);
	}
	playerKillsLast = allPlayerKills;
}

REGISTER_EFFECT(OnStart, nullptr, OnTick, EffectInfo
    {
        .Name = "Gun Game",
        .Id = "player_gun_game",
		.IsTimed = true
    }
);
