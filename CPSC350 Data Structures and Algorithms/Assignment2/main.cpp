#include "LifeGrid.h"
#include "InputHandler.h"
#include <unistd.h>
using namespace std;
int main(int argc, char** argv) {
	// Prompt for settings
	InputHandler ih;
	int modeNum = ih.promptOptionInt("Classic (0), Doughnut (1) or Mirror Mode (2): ","mode",3);
	cout<<"For each generation result: Short pause before next result (0),"<<endl;
	int outputNum = ih.promptOptionInt("Press Enter for next result (1), or Print All to File (2): ","output type",3);
	int inputNum = ih.promptOptionInt("Map file (0) or random assignment (1): ","input type",2);

	// LifeGrid pointer
	LifeGrid *lg;

	// If map file is chosen
	if (inputNum == 0) {
		// Init and prompt for file
		ifstream f;
		string iFilePath = ih.promptPath("Enter path of map file: ");
		// File exists after this line, so open it
		f.open(iFilePath.c_str());

		// Get the height and width from the first two lines
		string line;
		getline(f, line);
		int height;
		height = atoi(line.c_str());
		getline(f, line);
		int width;
		width = atoi(line.c_str());

		// Init LifeGrid and have pointer point to it
		lg = new LifeGrid(modeNum, height, width);

		cout<<"Generating initial map..."<<endl;

		// Generate the initial map and checks if bad file
		if (!(lg->makeInitialMap(f))) {
			cout<<"Bad file. Exiting..."<<endl;
			delete lg;
			return 0;
		}
		f.close();

	// If random assignment is chosen
	} else if (inputNum == 1) {
		// Prompt for height, width and density
		int height = ih.promptInt("Enter map height: ");
		int width = ih.promptInt("Enter map width: ");

		// Init LifeGrid and have pointer point to it
		lg = new LifeGrid(modeNum, height, width);

		double density = ih.promptDouble("Enter initial population density (0<c<=1): ");
		
		cout<<"Generating initial map..."<<endl;

		// Generate the initial map
		lg->makeInitialMap(density);
	}

	// If brief pause is chosen
	if (outputNum == 0) {
		while (!(lg->isEmpty())) {
			lg->printGenerationNumber();
			lg->printCurrentGeneration();
			lg->makeNextGeneration();
			sleep(1);
			if (lg->isStabilized()) {
				lg->printGenerationNumber();
				lg->printCurrentGeneration();
				cout<<"Grid has stabilized. Exiting..."<<endl;
				return 0;
			}
		}
		lg->printGenerationNumber();
		lg->printCurrentGeneration();
		cout<<"Grid is empty. Exiting..."<<endl;

	// If print to console is chosen
	} else if (outputNum == 1) {
		while (!(lg->isEmpty())) {
			lg->printGenerationNumber();
			lg->printCurrentGeneration();
			cout<<"Press [Enter] to continue... "<<flush;
			system("read");
			lg->makeNextGeneration();
			if (lg->isStabilized()) {
				lg->printGenerationNumber();
				lg->printCurrentGeneration();
				cout<<"Grid has stabilized. Exiting..."<<endl;
				return 0;
			}
		}
		lg->printGenerationNumber();
		lg->printCurrentGeneration();
		cout<<"Grid is empty. Exiting..."<<endl;

	// If print to file is chosen
	} else if (outputNum ==2) {
		// Prompt for file name
		cout<<"Enter output file name: ";
		string oFileName;
		cin>>oFileName;
		lg->printGenerationsToFile(oFileName);
	}
	delete lg;
	return 0;
}
