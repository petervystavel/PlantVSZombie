#include "ShieldBadGuyAction.h"

void ShieldBadGuyAction_Defend::Start(ShieldBadGuy* pShieldBadGuy)
{
	pShieldBadGuy->SetSpeed(0.f);
	pShieldBadGuy->GetShape()->setFillColor(sf::Color::Cyan);
}

void ShieldBadGuyAction_Defend::Update(ShieldBadGuy* pShieldBadGuy)
{
}

void ShieldBadGuyAction_Defend::End(ShieldBadGuy* pShieldBadGuy)
{
	pShieldBadGuy->GetShape()->setFillColor(/*default color*/ sf::Color::Blue);
}

void ShieldBadGuyAction_Roam::Start(ShieldBadGuy* pShieldBadGuy)
{
	pShieldBadGuy->SetDirection(mDirectionX, 0, 50.f);
}

void ShieldBadGuyAction_Roam::Update(ShieldBadGuy* pShieldBadGuy)
{
	int positionX = pShieldBadGuy->GetPosition().x;
	int windowWidth = pShieldBadGuy->GetScene()->GetWindowWidth();

	if (mDirectionX == 1 && pShieldBadGuy->GetX(1.f) < windowWidth  )
		return;

	if (mDirectionX == -1 && pShieldBadGuy->GetX(0.f) > 0)
		return;

	mDirectionX *= -1;
	pShieldBadGuy->SetDirection(mDirectionX, 0);
}

void ShieldBadGuyAction_Roam::End(ShieldBadGuy* pShieldBadGuy)
{
}

void ShieldBadGuyAction_Attack::Start(ShieldBadGuy* pShieldBadGuy)
{
}

void ShieldBadGuyAction_Attack::Update(ShieldBadGuy* pShieldBadGuy)
{
}


void ShieldBadGuyAction_Attack::End(ShieldBadGuy* pShieldBadGuy)
{
}