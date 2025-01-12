#pragma once

#include <vector>

#include "Action.h"

template<typename T>
class StateMachine
{
	std::vector<Action<T>*> mActions;
	int mCurrentState;

	T* mOwner;

public:
	StateMachine(T* owner, int stateCount);
	~StateMachine();

	void Update();
	void SetState(int state);
	int GetCurrentState() const { return mCurrentState; }

	template<typename U>
	U* CreateAction(int state);
};

#include "StateMachine.inl"

