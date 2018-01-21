#pragma once
#include <list>
#include "Observer.h"

using namespace std;

class Subject
{
	list<Observer*> observers;

public:
	void notifyObservers()
	{
		for each (Observer *observer in observers)
		{
			observer->update();
		}
	}
	void addObserver(Observer *observer)
	{
		observers.push_back(observer);
	}
	void deleteObserver(Observer *observer)
	{
		observers.remove(observer);
	}

};

