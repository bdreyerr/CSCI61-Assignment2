#ifndef SOFTWAREGURUSBAR_H
#define SOFTWAREGURUSBAR_H

#include <iostream>
#include <time.h>
#include <vector>
#include "Event.h"
using namespace std;


class randomInteger {
public:
	unsigned int operator () (unsigned int max);
}randomizer;

unsigned int randomInteger::operator () (unsigned int max) {
	
	unsigned int rval = rand();
	return rval % max; // returns a random integer between 0 and max
}

unsigned int randBetween(int low, int high) {
	
	return low + randomizer(high - low);
}



class SoftwareGurusBar {
public:
	SoftwareGurusBar() : freeChairs(50), profit(0.0) {} //Default bar setup: 50 chairs

	bool canSeat(unsigned int numberOfPeople);
	void order(unsigned int beerType);
	void leave(unsigned int numberOfPeople);
	

	unsigned int freeChairs;
	double profit;
};

SoftwareGurusBar theBar;
SimulationFramework theSimulation;

bool SoftwareGurusBar::canSeat(unsigned int numberOfPeople) {
	//if there are enough seats, then seat the customer
	cout << "Time: " << theSimulation.currentTime << endl;
	cout << "Group of " << numberOfPeople << " customers arrives";
	if (numberOfPeople < freeChairs) {
		cout << " Group is being seated" << endl;
		freeChairs -= numberOfPeople;
		return true;
	}
	else {
		cout << "No room for the group" << endl;
		return false;	
	}
}

void SoftwareGurusBar::order(unsigned int beerType) {
	//serve beer
	cout << "Time: " << theSimulation.currentTime << endl;
	cout << "Beer type " << beerType << " ordered." << endl;
	//update profit based on the beerType chosen
	if (beerType == 1) {
		theBar.profit += 2;
	}
	else if (beerType == 2) {
		theBar.profit += 3;
	}
	else if (beerType == 3) {
		theBar.profit += 4;
	}
}

void SoftwareGurusBar::leave(unsigned int numberOfPeople) {
	//people leave and chairs free up
	cout << "Time: " << theSimulation.currentTime << endl;
	cout << "The group of size " << numberOfPeople << " leaves" << endl;
	freeChairs += numberOfPeople;
}



#endif