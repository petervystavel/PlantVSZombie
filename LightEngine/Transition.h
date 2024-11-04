#pragma once

#include <vector>
#include "Condition.h"

template<typename T>
class Transition
{
protected:
    std::vector<Condition<T>*> mConditions;

public:
    void AddCondition(Condition<T>* pCondition);
	bool Try(T* owner);
};

template<typename T>
void Transition<T>::AddCondition(Condition<T>* pCondition)
{
	mConditions.push_back(pCondition);
}

template<typename T>
bool Transition<T>::Try(T* owner)
{
	for (const auto& c : mConditions)
	{
		if (c->Test(owner))
			return true;
	}

	return false;
}