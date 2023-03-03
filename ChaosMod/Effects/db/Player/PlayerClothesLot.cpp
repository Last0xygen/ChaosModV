#include <stdafx.h>

static void OnTick()
{
	Ped playerPed = PLAYER_PED_ID();

	static DWORD64 lastTick = 0;
	DWORD64 curTick = GET_GAME_TIMER();

	if (curTick > lastTick + 100)
	{
		lastTick = curTick;
		for (int i = 0; i < 12; i++)
		{
			int drawableAmount = GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, i);
			int drawable = drawableAmount == 0 ? 0 : g_Random.GetRandomInt(0, drawableAmount - 1);

			int textureAmount = GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, i, drawable);
			int texture = textureAmount == 0 ? 0 : g_Random.GetRandomInt(0, textureAmount - 1);

			SET_PED_COMPONENT_VARIATION(playerPed, i, drawable, texture, g_Random.GetRandomInt(0, 3));

			if (i < 4)
			{
				int propDrawableAmount = GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(playerPed, i);
				int propDrawable = propDrawableAmount == 0 ? 0 : g_Random.GetRandomInt(0, propDrawableAmount - 1);

				int propTextureAmount = GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(playerPed, i, drawable);
				int propTexture = propTextureAmount == 0 ? 0 : g_Random.GetRandomInt(0, propTextureAmount - 1);

				SET_PED_PROP_INDEX(playerPed, i, propDrawable, propTexture, true);
			}
		}
	}
}

REGISTER_EFFECT(nullptr, nullptr, OnTick, EffectInfo
	{
		.Name = "What Clothes Do I Wear",
		.Id = "player_spamclothes",
		.IsTimed = true,
		.IsShortDuration = false
	}
);