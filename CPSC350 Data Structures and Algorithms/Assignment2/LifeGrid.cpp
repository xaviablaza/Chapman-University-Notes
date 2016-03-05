#include "LifeGrid.h"
LifeGrid::LifeGrid(int mode_, int height_, int width_) {
	genNum = 0;
	mode = mode_;
	height = height_;
	width = width_;
	numElements = height*width;
	stabilized = false;
	arena = new char*[height];
	for (int i=0; i<height; ++i) {
		arena[i] = new char[width];
	}
	nextArena = new char*[height];
	for (int i=0; i<height; ++i) {
		nextArena[i] = new char[width];
	}
}
LifeGrid::LifeGrid(){}
LifeGrid::~LifeGrid() {
	for (int i=0; i<height; ++i) {
		delete [] arena[i];
	}
	delete [] arena;
	for (int i=0; i<height; ++i) {
		delete [] nextArena[i];
	}
	delete [] nextArena;
}
bool LifeGrid::makeInitialMap(ifstream &f) {
	int row = 0;
	string line;
	while (getline(f, line)) {
		if (line.size()!=width) return false;
		if (row>=height) return false;
		for (int i=0; i<line.size(); ++i) {
			if (line[i] == '-') {
				arena[row][i] = '-';
				nextArena[row][i] = '-';
			} else if (line[i] == 'X') {
				arena[row][i] = 'X';
				nextArena[row][i] = 'X';
			}
		}
		row++;
	}
	if (row!=height) return false;
	return true;
}
void LifeGrid::makeInitialMap(double density) {
	int numCells = height*width*density;
	for (int i=0; i<height; ++i) {
		for (int j=0; j<width; ++j) {
			int r = rand() % 2;
			if (r==0) {
				arena[i][j] = '-';
				nextArena[i][j] = '-';
			} else if (r==1) {
				if (numCells==0) {
					arena[i][j] = '-';
					nextArena[i][j] = '-';
				} else {
					arena[i][j] = 'X';
					nextArena[i][j] = 'X';
					numCells--;
				}
			}
		}
	}
}
bool LifeGrid::isEmpty() {
	for (int i=0; i<height; ++i) {
		for (int j=0; j<width; ++j) {
			if (arena[i][j] == 'X') return false;
		}
	}
	return true;
}
bool LifeGrid::isStabilized() {
	return stabilized;
}
void LifeGrid::printGenerationNumber() {
	cout<<genNum<<endl;
}
void LifeGrid::printCurrentGeneration() {
	for (int i=0; i<height; ++i) {
		for (int j=0; j<width; ++j) {
			cout<<arena[i][j];
		}
		cout<<endl;
	}
}
void LifeGrid::makeNextGeneration() {
	int s = 0;
	if (mode == 0) {
		for (int i=0; i<height; ++i) {
			// Check neighbors starting with north and moving clockwise
			for (int j=0; j<width; ++j) {
				int n = 0;

				// Check north neighbor
				if (i-1>=0) {
					if (arena[i-1][j] == 'X') {
						n++;
					}
				}

				// Check northeast neighbor
				if (i-1>=0 && j+1<=width-1) {
					if (arena[i-1][j+1] == 'X') {
						n++;
					}
				}
				
				// Check east neighbor
				if (j+1<=width-1) {
					if (arena[i][j+1] == 'X') {
						n++;
					}
				}

				// Check southeast neighbor
				if (i+1<=height-1 && j+1<=width-1) {
					if (arena[i+1][j+1] == 'X') {
						n++;
					}
				}
				
				// Check south neighbor
				if (i+1<=height-1) {
					if (arena[i+1][j] == 'X') {
						n++;
					}
				}
				
				// Check southwest neighbor
				if (i+1<=height-1 && j-1>=0) {
					if (arena[i+1][j-1] == 'X') {
						n++;
					}
				}
				
				// Check west neighbor
				if (j-1>=0) {
					if (arena[i][j-1] == 'X') {
						n++;
					}
				}
				
				// Check northwest neighbor
				if (i-1>=0 && j-1>=0) {
					if (arena[i-1][j-1] == 'X') {
						n++;
					}
				}

				if (n==0 || n==1 || n>=4) {
					// Cell dies
					nextArena[i][j] = '-';
				} else if (n==3) {
					// Produce cell
					nextArena[i][j] = 'X';
				}
			}
		}
	} else if (mode == 1) {
		for (int i=0; i<height; ++i) {
			// Check neighbors starting with north and moving clockwise
			for (int j=0; j<width; ++j) {
				int n = 0;

				// CHECK NORTH NEIGHBOR
				if (i==0) {
					if (arena[height-1][j] == 'X') n++;
				} else if (arena[i-1][j] == 'X') n++;

				// CHECK NORTHEAST NEIGHBOR
				if (i==0) {
					if (j == width-1 && arena[height-1][0] == 'X') n++;
					else if (arena[height-1][j+1] == 'X') n++;
				} else if (j == width-1 && arena[i-1][0] == 'X') n++;
				else if (arena[i-1][j+1] == 'X') n++;

				// CHECK EAST NEIGHBOR
				if (j==width-1) {
					if (arena[i][0] == 'X') n++;
				} else if (arena[i][j+1] == 'X') n++;

				// CHECK SOUTHEAST NEIGHBOR
				if (i==height-1) {
					if (j == width-1 && arena[0][0] == 'X') n++;
					else if (arena[0][j+1] == 'X') n++;
				} else if (j == width-1 && arena[i+1][0] == 'X') n++;
				else if (arena[i+1][j+1] == 'X') n++;

				// CHECK SOUTH NEIGHBOR
				if (i==height-1) {
					if (arena[0][j] == 'X') n++;
				} else if (arena[i+1][j] == 'X') n++;

				// CHECK SOUTHWEST NEIGHBOR
				if (i==height-1) {
					if (j == 0 && arena[height-1][0] == 'X') n++;
					else if (arena[0][j-1] == 'X') n++;
				} else if (j==0 && arena[i+1][width-1] == 'X') n++;
				else if (arena[i+1][j-1] == 0) n++;

				// CHECK WEST NEIGHBOR
				if (j==0) {
					if (arena[i][width-1] == 'X') n++;
				} else if (arena[i][j-1] == 'X') n++;

				// CHECK NORTHWEST NEIGHBOR
				if (i==0) {
					if (j == 0 && arena[height-1][width-1] == 'X') n++;
					else if (arena[height-1][j-1] == 'X');
				} else if (j==0 && arena[i-1][width-1] == 'X') n++;
				else if (arena[i-1][j-1] == 'X') n++;

				if (n==0 || n==1 || n>=4) {
					// Cell dies
					nextArena[i][j] = '-';
				} else if (n==3) {
					// Produce cell
					nextArena[i][j] = 'X';
				}
			}
		}
	} else if (mode == 2) {
		for (int i=0; i<height; ++i) {
			// Check neighbors starting with north and moving clockwise
			for (int j=0; j<width; ++j) {
				int n;

				// CHECK NORTH NEIGHBOR
				if (i==0) {
					if (arena[i][j] == 'X') n++;
				} else if (arena[i-1][j] == 'X') n++;

				// CHECK NORTHEAST NEIGHBOR
				if (i==0) {
					if (j == width-1 && arena[i][j] == 'X') n++;
					else if (arena[i][j+1] == 'X') n++;
				} else if (j == width-1 && arena[i-1][0] == 'X') n++;
				else if (arena[i-1][j+1] == 'X') n++;

				// CHECK EAST NEIGHBOR
				if (j==width-1) {
					if (arena[i][j] == 'X') n++;
				} else if (arena[i][j+1] == 'X') n++;

				// CHECK SOUTHEAST NEIGHBOR
				if (i==height-1) {
					if (j == width-1 && arena[i][j] == 'X') n++;
					else if (arena[i][j+1] == 'X') n++;
				} else if (j == width-1 && arena[i+1][j] == 'X') n++;
				else if (arena[i+1][j+1] == 'X') n++;

				// CHECK SOUTH NEIGHBOR
				if (i==height-1) {
					if (arena[i][j] == 'X') n++;
				} else if (arena[i+1][j] == 'X') n++;

				// CHECK SOUTHWEST NEIGHBOR
				if (i==height-1) {
					if (j == 0 && arena[i][j] == 'X') n++;
					else if (arena[i][j-1] == 'X') n++;
				} else if (j==0 && arena[i+1][j] == 'X') n++;
				else if (arena[i+1][j-1] == 0) n++;

				// CHECK WEST NEIGHBOR
				if (j==0) {
					if (arena[i][j] == 'X') n++;
				} else if (arena[i][j-1] == 'X') n++;

				// CHECK NORTHWEST NEIGHBOR
				if (i==0) {
					if (j == 0 && arena[0][0] == 'X') n++;
					else if (arena[i][j-1] == 'X');
				} else if (j==0 && arena[i-1][j] == 'X') n++;
				else if (arena[i-1][j-1] == 'X') n++;

				if (n==0 || n==1 || n>=4) {
					// Cell dies
					nextArena[i][j] = '-';
				} else if (n==3) {
					// Produce cell
					nextArena[i][j] = 'X';
				}
			}
		}
	}
	genNum++;
	for (int i=0; i<height; ++i) {
		for (int j=0; j<width; ++j) {
			if (arena[i][j] == nextArena[i][j]) {
					s++;
			}
			arena[i][j] = nextArena[i][j];
		}
	}
	if (s==numElements) stabilized = true;
	else stabilized = false;
}
void LifeGrid::printGenerationsToFile(string oFilePath){
	// file exists, do you want it to be overwritten?
	ofstream o;
	o.open(oFilePath.c_str(), ofstream::out | ofstream::trunc);
	int t = 0;
	while (!(isEmpty())) {
		o<<genNum<<endl;
		for (int i=0; i<height; ++i) {
			for (int j=0; j<width; ++j) {
				o<<arena[i][j];
			}
			o<<endl;
		}
		makeNextGeneration();
		if (isStabilized()) {
			o<<genNum<<endl;
			for (int i=0; i<height; ++i) {
				for (int j=0; j<width; ++j) {
					o<<arena[i][j];
				}
				o<<endl;
			}
			o<<"Grid has stabilized."<<endl;;
			return;
		}
		if (t==999) {
			o<<"Grid has infinitely many generations.";
			return;
		}
		t++;
	}

	o<<genNum<<endl;
	for (int i=0; i<height; ++i) {
		for (int j=0; j<width; ++j) {
			o<<arena[i][j];
		}
		o<<endl;
	}
	o<<"Grid is empty."<<endl;
	o.close();
}