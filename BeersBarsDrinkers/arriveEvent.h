#ifndef ARRIVEEVENT_H
#define ARIVEEVENT_H
#include "Event.h"
#include "SoftwareGurusBar.h"
#include "orderEvent.h"
//START OF ARRIVE EVENT
class arriveEvent : public Event {
public:
	arriveEvent(unsigned int time, unsigned int gs) : Event(time), groupSize(gs) {}
	virtual void processEvent();

protected:
	unsigned int groupSize;
};

void arriveEvent::processEvent() {
	if (theBar.canSeat(groupSize)) {
		//place an order within 2 & 10 minutes
		theSimulation.scheduleEvent(new orderEvent(theSimulation.currentTime + randBetween(2, 10), groupSize));
	}

}
//END OF ARRIVE EVENT

#endif // !ARRIVEEVENT_H



