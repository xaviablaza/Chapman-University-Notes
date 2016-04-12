#include "Registrar.h"
#include <algorithm>
Registrar::Registrar(){}
Registrar::~Registrar() {
	delete genQueue;
}

Registrar::Registrar(int totWindows, GenQueue<Arrival> *arrivalQueue) {
	totWindows = totWindows;
	windowsOpen = totWindows;
	genQueue = arrivalQueue;
}

void Registrar::calculateStats(int studAmt) {

	// Tick counter
	int tickCount = 0;

	// Array of ints representing number of windows open
	// and how many ticks each window has before it will open again
	int *winOccupiedTime = new int[windowsOpen];
	for (int m=0; m<windowsOpen; ++m) {
		winOccupiedTime[m] = 0;
	}

	// Array of bools representing number of windows that have idled
	// for more than 5 mins
	bool *winIdleOver5Mins = new bool[windowsOpen];
	for (int w=0; w<windowsOpen; ++w) {
		winIdleOver5Mins[w] = false;
	}

	// Used to calculate means
	int waitedMinSum = 0;
	int totStuds = 0;
	int windowIdleSum = 0;

	// Used to find longest wait time
	int longestWaitTime = 0;

	// Used to find longest window idle time
	int longestWindowIdle = 0;

	// Used to count how many students waited strictly more than 10 ticks
	int numStudsLongWait = 0;

	// Used to count how many windows idle for over 5 ticks
	int numWinIdle = 0;

	// Queue to represent a line of students waiting for a window at the registrar
	GenQueue<Student> *waitQueue = new GenQueue<Student>();

	// Wait times of each student stored here with accompanying pointer
	int *toSort = new int[studAmt];
	int arr = 0;

	while (genQueue->getSize() != 0) {

		// If in the current clock tick there are no students that arrive,
		// increase empty window idle ticks (negative numbers)
		// decrease occupied window ticks (positive numbers)
		if (genQueue->peekHead()->clockTick != tickCount) {
			tickCount++;
			for (int i=0; i<windowsOpen; ++i) {
				winOccupiedTime[i] = winOccupiedTime[i]-1;
			}
			continue;
		}

		// Queue of students arrived at the back of the line to the registrar
		Arrival *a = genQueue->dequeue();

		// Count how many students were in the arrival
		totStuds+=a->numStuds;

		// For every student that arrived, add them to the wait queue
		for (int idxArrival=0; idxArrival<a->numStuds; ++idxArrival) {
			Student *studPointer = &a->students[idxArrival];
			waitQueue->enqueue(studPointer);
		}

		// Loop through the waitqueue
		// Assign windows with students until all windows are occupied
		while (true) {

			// Dequeue a student from the waitQueue
			Student *student = waitQueue->dequeue();

			// Flag if an open window was found for a student in waitqueue
			bool found = false;

			// Used to track time the next person in line will go to the window
			// if all windows are occupied
			int lowestTimeIdx = 0;

			// Loop through array of windows
			for (int i=0; i<windowsOpen; ++i) {

				// Window has time of 0 or less if it's empty, so
				if (winOccupiedTime[i] <= 0) {

					// Empty window has been found
					found = true;

					// Record idx
					lowestTimeIdx = i;

					// Set the window's occupied ticks to amount of minutes that student needs
					winOccupiedTime[i] = student->minsNeeded;

					// If the window's occupied ticks are 0 or below and if it's lower than the longest window idle
					if (winOccupiedTime[i] <= 0 && winOccupiedTime[i] < longestWindowIdle) {
						longestWindowIdle = winOccupiedTime[i];
					}

					// Count how many windows are idle for over 5 mins
					for (int w=0; w<windowsOpen; ++w) {
						if (winOccupiedTime[w] < -5) winIdleOver5Mins[w] = true;
					}

				// If it's occupied, find the lowest time
				} else if (winOccupiedTime[lowestTimeIdx] < winOccupiedTime[i]) {
					lowestTimeIdx = i;
				}
			}

			// If all windows are occupied (no empty windows found)
			if (!found) {

				// Calculate longest wait time
				if (longestWaitTime < winOccupiedTime[lowestTimeIdx]) longestWaitTime = winOccupiedTime[lowestTimeIdx];

				// Calculate how many students are waiting more than 10 ticks;
				if (winOccupiedTime[lowestTimeIdx] > 10) numStudsLongWait++;

				// Add student wait time to array
				toSort[arr++] = winOccupiedTime[lowestTimeIdx];

				// Add student wait time to sum count
				waitedMinSum += winOccupiedTime[lowestTimeIdx];

				break;
			} else {
				// Add student wait time to array
				toSort[arr++] = 0;
			}

			// end loop, tries to dequeue another student from the waitQueue
		}

		// Advance tick count
		tickCount++;
	}

	// Mean student wait time
	double meanWaitTime = (double)waitedMinSum/(double)totStuds;
	meanWaitTime = meanWaitTime;
	cout<<"Mean student wait time:              "<<meanWaitTime<<" "<<"mins"<<endl;

	// Median student wait time; need some sorting algo or median of medians algo
	double medianWaitTime = 0.0;
	sort(toSort, toSort+studAmt);
	if (studAmt % 2 == 0) {
		// If size is even
		int midRightIdx = studAmt/2;
		int midLeftIdx = midRightIdx-1;
		medianWaitTime = ((double)toSort[midLeftIdx] + (double)toSort[midRightIdx])/2.0;
	} else {
		int medianIdx = studAmt/2;
		medianWaitTime = (double)toSort[medianIdx];
	}
	cout<<"Median student wait time:            "<<medianWaitTime<<" mins"<<endl;

	// Longest student wait time
	cout<<"Longest student wait time:           "<<longestWaitTime<<" "<<"mins"<<endl;

	// Number of students waiting strictly over 10 minutes
	cout<<"Number of students waiting >10 mins: "<<numStudsLongWait<<" students"<<endl;

	// The mean window idle time
	double meanWindowIdleTime = (double)windowIdleSum/(double)windowsOpen;
	meanWindowIdleTime = meanWindowIdleTime;
	cout<<"Mean window idle time:               "<<meanWindowIdleTime<<" mins"<<endl;

	// Longest window idle time
	cout<<"Longest window idle time:            "<<longestWindowIdle<<" mins"<<endl;

	int winIdleCount = 0;
	for (int w=0; w<windowsOpen; ++w) {
		if (winIdleOver5Mins[w]) winIdleCount++;
	}

	// Number of windows idle for over 5 minutes.
	cout<<"Number of windows idle for >5 mins:  "<<winIdleCount<<" windows"<<endl;

	delete [] winOccupiedTime;
	delete [] winIdleOver5Mins;
	delete waitQueue;
	delete [] toSort;
}