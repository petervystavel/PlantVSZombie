#pragma once

#include "Behaviour.h"

#include "Transition.h"
#include "Condition.h"

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