#include <stdafx.h>


//static std::ofstream debugLog("ChaosLog.txt");
static std::map<Hash, CHandlingData*> processedHandling;


static void OnStart()
{
	//REMOVE_ANIM_DICT("missfbi3_sniping");
	LOG("Size: " << processedHandling.size());

}


static void OnStop()
{
	for (std::pair<Vehicle, CHandlingData*> value : processedHandling)
	{
		//value.second->fSuspensionRaise_ -= 0.65;
	}
	processedHandling.clear();
}


static void OnTick()
{
	Ped player = PLAYER_PED_ID();
	if (IS_PED_IN_ANY_VEHICLE(player, false))
	{
		Vehicle veh = GET_VEHICLE_PED_IS_IN(player, false);
		Hash model = GET_ENTITY_MODEL(veh);
		if (IS_THIS_MODEL_A_CAR(model) || IS_THIS_MODEL_A_QUADBIKE(model))
		{
			if (processedHandling.find(model) == processedHandling.end())
			{
				LOG("New Car");
				uint64_t pntr = Memory::GetHandlingPtr(veh);
				if (pntr == 0)
				{
					return;
				}
				LOG("Pointer " << pntr);

				CHandlingData* handlingData = reinterpret_cast<CHandlingData*>(pntr);
				if (handlingData == nullptr)
				{
					LOG("Invalid handling ");
					return;
				}
				processedHandling[model] = handlingData;


				LOG("fMass: " << handlingData->fMass);
				LOG("fInitialDragCoeff: " << handlingData->fInitialDragCoeff);
				LOG("fDownforceModifier: " << handlingData->fDownforceModifier);
				LOG("N000019C0: " << handlingData->N000019C0);
				LOG("N000019E5: " << handlingData->N000019E5);
				LOG("vecCentreOfMassOffset: " << handlingData->vecCentreOfMassOffset.x << " " << handlingData->vecCentreOfMassOffset.y << " " << handlingData->vecCentreOfMassOffset.z);
				LOG("N000019E9: " << handlingData->N000019E9);
				LOG("vecInertiaMultiplier: " << handlingData->vecInertiaMultiplier.x << " " << handlingData->vecInertiaMultiplier.y << " " << handlingData->vecInertiaMultiplier.z);
				LOG("fPercentSubmerged: " << handlingData->fPercentSubmerged);
				LOG("fSubmergedRatio_: " << handlingData->fSubmergedRatio_);
				LOG("fDriveBiasFront: " << handlingData->fDriveBiasFront);
				LOG("fDriveBiasRear: " << handlingData->fDriveBiasRear);
				LOG("nInitialDriveGears: " << handlingData->nInitialDriveGears);
				LOG("fDriveInertia: " << handlingData->fDriveInertia);
				LOG("fClutchChangeRateScaleUpShift: " << handlingData->fClutchChangeRateScaleUpShift);
				LOG("fClutchChangeRateScaleDownShift: " << handlingData->fClutchChangeRateScaleDownShift);
				LOG("fInitialDriveForce: " << handlingData->fInitialDriveForce);
				LOG("fDriveMaxFlatVel_: " << handlingData->fDriveMaxFlatVel_);
				LOG("fInitialDriveMaxFlatVel_: " << handlingData->fInitialDriveMaxFlatVel_);
				LOG("fBrakeForce: " << handlingData->fBrakeForce);
				LOG("N000019CB: " << handlingData->N000019CB);
				LOG("fBrakeBiasFront_: " << handlingData->fBrakeBiasFront_);
				LOG("fBrakeBiasRear_: " << handlingData->fBrakeBiasRear_);
				LOG("fHandBrakeForce2: " << handlingData->fHandBrakeForce2);
				LOG("fSteeringLock_: " << handlingData->fSteeringLock_);
				LOG("fSteeringLockRatio_: " << handlingData->fSteeringLockRatio_);
				LOG("fTractionCurveMax: " << handlingData->fTractionCurveMax);
				LOG("fTractionCurveMaxRatio_: " << handlingData->fTractionCurveMaxRatio_);
				LOG("fTractionCurveMin: " << handlingData->fTractionCurveMin);
				LOG("fTractionCurveRatio_: " << handlingData->fTractionCurveRatio_);
				LOG("fTractionCurveLateral_: " << handlingData->fTractionCurveLateral_);
				LOG("fTractionCurveLateralRatio_: " << handlingData->fTractionCurveLateralRatio_);
				LOG("fTractionSpringDeltaMax: " << handlingData->fTractionSpringDeltaMax);
				LOG("fTractionSpringDeltaMaxRatio_: " << handlingData->fTractionSpringDeltaMaxRatio_);
				LOG("fLowSpeedTractionLossMult: " << handlingData->fLowSpeedTractionLossMult);
				LOG("fCamberStiffness: " << handlingData->fCamberStiffness);
				LOG("fTractionBiasFront_: " << handlingData->fTractionBiasFront_);
				LOG("fTractionBiasRear: " << handlingData->fTractionBiasRear);
				LOG("fTractionLossMult: " << handlingData->fTractionLossMult);
				LOG("fSuspensionForce: " << handlingData->fSuspensionForce);
				LOG("fSuspensionCompDamp: " << handlingData->fSuspensionCompDamp);
				LOG("fSuspensionReboundDamp: " << handlingData->fSuspensionReboundDamp);
				LOG("fSuspensionUpperLimit: " << handlingData->fSuspensionUpperLimit);
				LOG("fSuspensionLowerLimit: " << handlingData->fSuspensionLowerLimit);
				LOG("fSuspensionRaise_: " << handlingData->fSuspensionRaise_);
				LOG("fSuspensionBiasFront_: " << handlingData->fSuspensionBiasFront_);
				LOG("fSuspensionBiasRear_: " << handlingData->fSuspensionBiasRear_);
				LOG("fAntiRollBarForce: " << handlingData->fAntiRollBarForce);
				LOG("fAntiRollBarBiasFront_: " << handlingData->fAntiRollBarBiasFront_);
				LOG("fAntiRollBarBiasRear_: " << handlingData->fAntiRollBarBiasRear_);
				LOG("fRollCentreHeightFront: " << handlingData->fRollCentreHeightFront);
				LOG("fRollCentreHeightRear: " << handlingData->fRollCentreHeightRear);
				LOG("fCollisionDamageMult: " << handlingData->fCollisionDamageMult);
				LOG("fWeaponDamageMult: " << handlingData->fWeaponDamageMult);
				LOG("fDeformationDamageMult: " << handlingData->fDeformationDamageMult);
				LOG("fEngineDamageMult: " << handlingData->fEngineDamageMult);
				LOG("fPetrolTankVolume: " << handlingData->fPetrolTankVolume);
				LOG("fOilVolume: " << handlingData->fOilVolume);



				//handlingData->fSuspensionRaise_ += 0.65;
			}
		}
	}

}

static RegisterEffect registerEffect(EFFECT_IN_THE_HOOD, OnStart, OnStop, OnTick);