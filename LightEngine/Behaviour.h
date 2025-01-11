#pragma once

#include <vector>

template<typename T>
class Transition;

template<typename T>
class Action
{
	std::vector<Transition<T>*> mTransitions;

private:
    int Update(T* pOwner);

public:
    ~Action();

    Transition<T>* CreateTransition(int state);

protected:
	virtual void OnStart(T* pOwner) = 0;
	virtual void OnUpdate(T* pOwner) = 0;
	virtual void OnEnd(T* pOwner) = 0;

	template<typename T>
	friend class StateMachine;
};

#include "Action.inl"