#include "StateMachine.h"

#include "Action.h"

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
		mActions[mCurrentState]->OnEnd(mOwner);

	mCurrentState = state;

	mActions[mCurrentState]->OnStart(mOwner);
}

template<typename T>
void StateMachine<T>::Update()
{
	if (mCurrentState == -1)
		return;

	int transitionState = mActions[mCurrentState]->Update(mOwner);

	if (transitionState == -1)
		return;

	SetState(transitionState);
}

template<typename T>
template<typename U>
U* StateMachine<T>::CreateAction(int state)
{
	_ASSERT(state >= 0 && state < mActions.size());
	_ASSERT(mActions[state] == nullptr);

	static_assert(std::is_base_of<Action<T>, U>::value, "U must derive from Action<T>");

	U* pAction = new U();

	mActions[state] = pAction;
	
	return pAction;
}