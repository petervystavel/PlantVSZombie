#pragma once

#include <vector>

#include "Behaviour.h"

template<typename T>
class StateMachine
{
	std::vector<Behaviour<T>*> mBehaviours;
	int mCurrentState;

	T* mOwner;

public:
	StateMachine(T* owner, int stateCount);
	~StateMachine();

	void Update();
	void SetState(int state);
	int GetCurrentState() const { return mCurrentState; }

	Behaviour<T>* CreateBehaviour(int state);
};

template<typename T>
StateMachine<T>::StateMachine(T* owner, int stateCount)
{
	mOwner = owner;
	mCurrentState = -1;
	mBehaviours.resize(stateCount);
}

template<typename T>
StateMachine<T>::~StateMachine()
{
	for (Behaviour<T>* pBehaviour : mBehaviours)
		delete pBehaviour;
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
	if(mCurrentState == -1)
		return;

	int transitionState = mBehaviours[mCurrentState]->Update();
	
	if (transitionState == -1)
		return;

	SetState(transitionState);
}

template<typename T>
Behaviour<T>* StateMachine<T>::CreateBehaviour(int state)
{
	_ASSERT(state >= 0 && state < mBehaviours.size());

	Behaviour<T>* pBehaviour = new Behaviour<T>(mOwner);
	mBehaviours[state] = pBehaviour;

	return pBehaviour;
}

