//Ben Dreyer
//Computer Science 61 
//11.17.18
//Assignment 2

#include "stdafx.h"
#include <iostream>
#include "Event.h"
#include "SoftwareGurusBar.h"	
#include "arriveEvent.h"

//Currently this application is using the STL implementation of Priroity Queue, When using the minPQ that I wrote, a nullprt exception is thrown.

int main()
{
	srand(time(NULL));
	//load priroity queue with intial arrive events then run simulation
	unsigned int t = 0;

	//load 4 hours of arrive events (240 mins)
	while (t < 240) {
		
		//new group comes every 2-5 mins
		t += randBetween(2, 5);

		//group size ranges from 1 to 5
		theSimulation.scheduleEvent(new arriveEvent(t, randBetween(1, 5)));
	}

	//run simulation and print the profits
	theSimulation.run();
	cout << "Total profit: " << theBar.profit << endl;
	
	cin >> t;
    return 0;
}

