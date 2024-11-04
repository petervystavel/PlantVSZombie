#include "Plant.h"

Plant::Plant(float x, float y, float radius, const sf::Color& color) : Entity(x, y, radius, color)
{
	//IDLE
	{
		Behaviour<Plant>* pIdle = mStateMachine.CreateBehaviour();

		Action<Plant>* pAction = pIdle->CreateAction();

	}

}

void Plant::OnCollision(Entity* collidedWith)
{
}
