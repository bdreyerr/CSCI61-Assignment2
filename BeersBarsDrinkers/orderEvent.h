#ifndef ORDEREVENT_H
#define ORDEREVENT_H
#include "leaveEvent.h"
#include "Event.h"
#include "SoftwareGurusBar.h"

class orderEvent : public Event {
public:
	orderEvent(unsigned int time, unsigned int gs) : Event(time), groupSize(gs) {}
	virtual void processEvent();

protected:
	unsigned int groupSize;
};

void orderEvent::processEvent() {
	//each member of the group orders a beer(type 1, 2, 3)
	vector<unsigned int> a = { 15, 25, 60 };
	for (unsigned int i = 0; i < groupSize; i++) {
		theBar.order(theSimulation.weightedProbability(a));
	}
	int t = theSimulation.currentTime + randBetween(15, 35);
	//schedule a leaveEvent for this group of drinkers
	theSimulation.scheduleEvent(new leaveEvent(t, groupSize));
	//The group leaves

}
#endif // !ORDEREVENT

