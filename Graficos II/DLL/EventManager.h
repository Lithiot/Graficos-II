#pragma once
#include "Exports.h"
#include <vector>

using namespace std;

enum EventType
{
	CHANGE_INT, CHANGE_FLOAT, CHANGE_BOOL, COUNT
};

struct Event
{
	int key;
	EventType type;

	int intChangedValue;
	int* intValueToChange;

	float floatChangedValue;
	float* floatValueToChange;

	bool boolChangedValue;
	bool* boolValueToChange;

	Event(int eventKey, int value, int* valueToChange);
	Event(int eventKey, float value, float* valueToChange);
	Event(int eventKey, bool value, bool* valueToChange);
};

class ENGINE_API EventManager
{
private:
	static EventManager* instance;
	vector<Event> createdEvents;
public:
	EventManager();
	~EventManager();

	void AddNewEvent(int key, int value, int* valueToChange);
	void AddNewEvent(int key, float value, float* valueToChange);
	void AddNewEvent(int key, bool value, bool* valueToChange);

	void ExecuteEvent(int key);

	static EventManager* Instance()
	{
		if (instance == NULL)
		{
			instance = new EventManager();
		}
		return instance;
	}
};

