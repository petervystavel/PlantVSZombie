#pragma once

#include <vector>

#include "Behaviour.h"

template<typename T>
class StateMachine
{
	std::vector<Behaviour<T>*> mBehaviours;
	int mCurrentState;

public:
	StateMachine();

	void Update();
	void SetState(int state);
	Behaviour<T>* CreateBehaviour();
};

template<typename T>
StateMachine<T>::StateMachine()
{
	mCurrentState = 0;
}

template<typename T>
void StateMachine<T>::SetState(int state)
{
	if(mCurrentState > 0 && mCurrentState < mBehaviours.size())
		mBehaviours[mCurrentState]->End();

	mCurrentState = state;

	mBehaviours[mCurrentState]->Start();
}

template<typename T>
void StateMachine<T>::Update()
{
	mBehaviours[mCurrentState]->Update();
}

template<typename T>
Behaviour<T>* StateMachine<T>::CreateBehaviour()
{
	Behaviour<T>* pBehaviour = new Behaviour<T>();
	mBehaviours.push_back(pBehaviour);

	return pBehaviour;
}

