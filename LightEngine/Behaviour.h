#pragma once

#include <vector>
#include "Action.h"
#include "Transition.h"

template<typename T>
class Behaviour
{
	std::vector<Action<T>*> mActions;
	std::vector<Transition<T>*> mTransitions;
	T* mOwner;

public:
    Behaviour(T* owner);
    ~Behaviour();

    void Start();
    int Update();
    void End();

    void AddAction(Action<T>* action);
    Transition<T>* CreateTransition(int state);
};


template<typename T>
Behaviour<T>::Behaviour(T* owner)
{
    mOwner = owner;
}

template<typename T>
Behaviour<T>::~Behaviour()
{
    for (auto it : mActions)
    {
        delete it;
    }

    for (auto it : mTransitions)
    {
        delete it;
    }
}

template<typename T>
Transition<T>* Behaviour<T>::CreateTransition(int state)
{
	Transition<T>* pTransition = new Transition<T>(state);
    mTransitions.push_back(pTransition);

	return pTransition;
}

template<typename T>
void Behaviour<T>::AddAction(Action<T>* pAction)
{
    mActions.push_back(pAction);
}

template<typename T>
void Behaviour<T>::Start()
{
    for (const auto& a : mActions)
    {
        a->Start(mOwner);
    }
}

template<typename T>
int Behaviour<T>::Update()
{
    for (const auto& a : mActions)
    {
        a->Update(mOwner);
    }

    for (const auto& t : mTransitions)
    {
        if (t->Try(mOwner)) 
        {
			return t->GetTransitionState();
        }
    }

	return -1;
}


template<typename T>
void Behaviour<T>::End()
{
    for (const auto& a : mActions)
    {
        a->End(mOwner);
    }
}