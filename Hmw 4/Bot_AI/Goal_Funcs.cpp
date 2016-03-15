#include "Goal_Funcs.h"

#include <algorithm>
#include "Bot.h"
#include "GameManager.h"
#include "BotController.h"
#include <vector>





float Goal_Funcs::Health(Bot * _bot)
{
	return _bot->getHealth() / 100.0f;
}

float Goal_Funcs::Health(int _health)
{
	return _health / 100.0f;
}

float Goal_Funcs::DistanceToItem(Bot * _bot, ITEM_TYPE _type)
{
	std::vector<ItemDrop> drops = GameManager::getItemDrops();

	const float MaxDistance = 500.0f;
	const float MinDistance = 50.0f;

	float distance = MaxDistance;

	for each (ItemDrop drop in drops)
	{
		if (drop.type == _type)
		{
			distance = (_bot->getPos() - drop.pos).mag();
			break;
		}

	}

	//float distance = (_bot->getPos() - _itemPos).mag();

	float val = clamp(distance, MinDistance, MaxDistance);

	return val / MaxDistance;

}


float Goal_Funcs::clamp(float _value, float _min, float _max)
{
	return std::max<float>(_min, std::min<float>(_value, _max));
}


float Goal_Funcs::IndividualWeaponStrength(Bot * _bot, ITEM_TYPE _weaponType)
{
	const float DesiredLaserAmmo = 25.0f;

	float numRoundsLeft = 0.0f;

	switch (_weaponType)
	{
	case ITEM_TYPE::LASER_AMMO:
		numRoundsLeft = (float)_bot->getLaserAmmo();
		break;
	default:
		break;
	}

	return numRoundsLeft / DesiredLaserAmmo;


}


float Goal_Funcs::TotalWeaponStrength(Bot * _bot)
{

	float LaserAmmo = IndividualWeaponStrength(_bot, LASER_AMMO);

	float maxLaserAmmo = 0;
	maxLaserAmmo = clamp(maxLaserAmmo, maxLaserAmmo, LaserDesiredAmount);

	const float tweaker = 0.1f;

	return tweaker + (1 - tweaker)*(LaserAmmo) / (LaserDesiredAmount);


}