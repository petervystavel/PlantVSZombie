#include "StateMachine.h"

template<typename T>
StateMachine<T>::StateMachine(T* owner, int stateCount)
{
	mOwner = owner;
	mCurrentState = -1;
	mActions.resize(stateCount);
}

template<typename T>
StateMachine<T>::~StateMachine()
{
	for (Action<T>* pAction : mActions)
		delete pAction;
}

template<typename T>
void StateMachine<T>::SetState(int state)
{
	if (mCurrentState > 0 && mCurrentState < mActions.size())
		mActions[mCurrentState]->End(mOwner);

	mCurrentState = state;

	mActions[mCurrentState]->Start(mOwner);
}

template<typename T>
void StateMachine<T>::Update()
{
	mActions[mCurrentState]->Update(mOwner);
}

template<typename T>
template<typename U>
void StateMachine<T>::AddAction(int state)
{
	_ASSERT(state >= 0 && state < mActions.size());

	U* pAction = new U();
	mActions[state] = pAction;
}