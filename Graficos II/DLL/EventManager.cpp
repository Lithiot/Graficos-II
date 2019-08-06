#include "EventManager.h"

EventManager* EventManager::instance = NULL;

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}

void EventManager::AddNewEvent(int key, int value, int* valueToChange)
{
	Event aux(key, value, valueToChange);
	createdEvents.push_back(aux);
}

void EventManager::AddNewEvent(int key, float value, float* valueToChange)
{
	Event aux(key, value, valueToChange);
	createdEvents.push_back(aux);
}

void EventManager::AddNewEvent(int key, bool value, bool* valueToChange)
{
	Event aux(key, value, valueToChange);
	createdEvents.push_back(aux);
}

void EventManager::ExecuteEvent(int key)
{
	for (int i = 0; i < createdEvents.size(); i++)
	{
		Event aux = createdEvents.at(i);

		if (aux.key == key)
		{
			switch (aux.type)
			{
			case CHANGE_INT:
				*aux.intValueToChange = aux.intChangedValue;
				break;
			case CHANGE_FLOAT:
				*aux.floatValueToChange = aux.floatChangedValue;
				break;
			case CHANGE_BOOL:
				*aux.boolValueToChange = aux.boolChangedValue;
				break;
			}
		}
	}
}

Event::Event(int eventKey, int value, int* valueToChange)
{
	key = eventKey;
	type = CHANGE_INT;
	intChangedValue = value;
	intValueToChange = valueToChange;
}

Event::Event(int eventKey, float value, float* valueToChange)
{
	key = eventKey;
	type = CHANGE_FLOAT;
	floatChangedValue = value;
	floatValueToChange = valueToChange;
}

Event::Event(int eventKey, bool value, bool* valueToChange)
{
	key = eventKey;
	type = CHANGE_BOOL;
	boolChangedValue = value;
	boolValueToChange = valueToChange;
}

