/*
Effect by Last0xygen
*/

#include <stdafx.h>

static Camera orbitCamera = 0;
static float orbitAngle = 270;

static Vector3 RotateAround(Vector3 entityPosition, float radius)
{
    Vector3 destVector;
    destVector.x = entityPosition.x - radius * SIN(orbitAngle + 90);
    destVector.y = entityPosition.y + radius * SIN(orbitAngle);
    destVector.z = CAM::GET_GAMEPLAY_CAM_COORD().z;
    return destVector;
}


static void UpdateCamera()
{
    Ped player = PLAYER_PED_ID();
    Vector3 pos = GET_ENTITY_COORDS(player, false);
    auto coord = RotateAround(pos, 3.5);
    auto rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
    auto fov = CAM::GET_GAMEPLAY_CAM_FOV();
    CAM::SET_CAM_PARAMS(orbitCamera, coord.x, coord.y, coord.z, rot.x, rot.y, 270 - orbitAngle, fov, 0, 1, 1, 2);
}

static void OnStart()
{
    orbitAngle = 270;
    orbitCamera = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
    CAM::RENDER_SCRIPT_CAMS(true, true, 300, 1, 1, 1);
}

static void OnTick()
{
    CAM::SET_CAM_ACTIVE(orbitCamera, true);
    UpdateCamera();

    orbitAngle += 2;
    if (orbitAngle >= 360)
    {
        orbitAngle = 0;
    }
}

static void OnStop()
{
    CAM::SET_CAM_ACTIVE(orbitCamera, false);
    CAM::RENDER_SCRIPT_CAMS(false, true, 300, 1, 1, 1);
    CAM::DESTROY_CAM(orbitCamera, true);
    orbitCamera = 0;
}

REGISTER_EFFECT(OnStart, OnStop, OnTick, EffectInfo
    {
        .Name = "Orbit Camera",
        .Id = "misc_orbit_camera",
		.IsTimed = true,
		.IsShortDuration = true
    }
);
