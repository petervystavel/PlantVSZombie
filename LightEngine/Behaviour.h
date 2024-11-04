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
    void Update();
    void End();

    Action<T>* CreateAction();
    Transition<T>* CreateTransition();
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
Transition<T>* Behaviour<T>::CreateTransition()
{
	Transition<T>* pTransition = new Transition<T>();
    mTransitions.push_back(pTransition);

	return pTransition;
}

template<typename T>
Action<T>* Behaviour<T>::CreateAction()
{
	Action<T>* pAction = new Action<T>();

    mActions.push_back(pAction);

	return pAction;
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
void Behaviour<T>::Update()
{
    for (const auto& a : mActions)
    {
        a->Update(mOwner);
    }

    for (const auto& t : mTransitions)
    {
        if (t->Try(mOwner))
            break;
    }
}


template<typename T>
void Behaviour<T>::End()
{
    for (const auto& a : mActions)
    {
        a->End(mOwner);
    }
}