#include "ShieldBadGuyCondition.h"
#include "SampleScene.h"
#include "DummyEntity.h"

bool ShieldBadGuyCondition_PlayerIsForward::OnTest(ShieldBadGuy* owner)
{
	SampleScene* pScene = owner->GetScene<SampleScene>();
	DummyEntity* pPlayer = pScene->GetPlayer();

	if (owner->GetDirection().x == 1)
	{
		return pPlayer->GetX() > owner->GetX();
	}
	else
	{
		return pPlayer->GetX() < owner->GetX();
	}
}

bool ShieldBadGuyCondition_PlayerInsideDistance::OnTest(ShieldBadGuy* owner)
{
	SampleScene* pScene = owner->GetScene<SampleScene>();
	DummyEntity* pPlayer = pScene->GetPlayer();

	float distance = std::abs(pPlayer->GetX() - owner->GetX());

	return distance < mDistance;
}
