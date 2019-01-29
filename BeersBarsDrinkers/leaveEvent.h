#ifndef LEAVEEVENT_H
#define LEAVEEVENT_H
#include "Event.h"
#include "SoftwareGurusBar.h"
class leaveEvent : public Event {
public:
	leaveEvent(unsigned int time, unsigned int gs) : Event(time), groupSize(gs) {}
	virtual void processEvent();
protected:
	unsigned int groupSize;

};

void leaveEvent::processEvent() {
	theBar.leave(groupSize);
}
#endif // !LEAVEEVENT_H
