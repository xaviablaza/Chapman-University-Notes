#include "GenQueue.h"
#include "Arrival.h"
class Registrar {
	private:
		GenQueue<Arrival> *genQueue;
	public:
		Registrar();
		~Registrar();

		// Constructor to specify totalWindows and GenQueue<Arrival> *arrivalQueue
		// after parseFile() in InputHandler
		Registrar(int totWindows, GenQueue<Arrival> *arrivalQueue);

		// Calculates mean student wait time (SWT), median SWT, longest SWT,
		// number of students waiting over 10 ticks, mean window idle time (WIT),
		// longest WID, and number of windows idle for over 5 ticks and prints
		// all statistics to standard output
		void calculateStats(int studAmt);
		int totWindows;
		int windowsOpen;
};