#ifndef EVENT_H
#define EVENT_H

#include "minPQ.h"
#include <iostream>
#include <queue>


using namespace std;

class Event {
public:
	Event(unsigned int t) : time(t) {}
	virtual void processEvent() {}
	unsigned int time;
	
};

class eventComparison {
public:
	bool operator () (Event * left, Event * right) {
		return left->time > right->time;
	}
};


class SimulationFramework {
public:
	SimulationFramework() : eventQueue(), currentTime(0) {} //USE eventQueue(100) if running minPQ

	void scheduleEvent(Event * newEvent) {
		//insert newEvent into eventQueue (Priority Queue)
		//Priority Queue is based on MinHeap using newEvent's time
		eventQueue.push(newEvent);
		//eventQueue.insert(newEvent); //USE THIS IF RUNNING MINPQ
	}
	unsigned int weightedProbability(vector<unsigned int> a);

	void run();
	unsigned int currentTime;
protected:
	priority_queue<Event *, vector<Event *>, eventComparison> eventQueue;
	//minPQ<Event*> eventQueue;
};


void SimulationFramework::run() {
	//execute events until event queue becomes empty
	while (!eventQueue.empty()) {
		//copy & remove min-priority element (min time) from eventQueue
		Event * nextEvent = eventQueue.top(); //.peak?
		//Event * nextEvent = eventQueue.extractMin(); //USE THIS IF RUNNING MINPQ
		eventQueue.pop(); //delete min
		

		//update current time
		currentTime = nextEvent->time;

		//process nextEvent
		nextEvent->processEvent();

		//cleanup NextEvent object
		delete nextEvent;
	}
}

unsigned int SimulationFramework::weightedProbability(vector<unsigned int> a) {
	unsigned int max = 0;
	unsigned int random = rand() % 100;
	for (unsigned int i = 0; i < a.size(); i++) {
		max += a[i];
	}
	if (random > 0 && random < a[0]) {
		return 0;
	}
	if (random > a[0] && random < a[1]) {
		return 1;
	}
	else
		return 2;
}

#endif