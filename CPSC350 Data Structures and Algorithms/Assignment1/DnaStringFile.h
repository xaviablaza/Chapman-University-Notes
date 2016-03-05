#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#define PI 3.14159265358979323846266
#include <sys/stat.h>
#include <string.h>
using namespace std;
class DnaStringFile {
	private:
		ifstream f;
		int numChars;
		double mean;
		double variance;
		double stdDeviation;
		double pA;
		double pC;
		double pT;
		double pG;
		double pAA;
		double pAC;
		double pAT;
		double pAG;
		double pCA;
		double pCC;
		double pCT;
		double pCG;
		double pTA;
		double pTC;
		double pTT;
		double pTG;
		double pGA;
		double pGC;
		double pGT;
		double pGG;		
	public:
		DnaStringFile();
		~DnaStringFile();
		bool open(string path);
		void close();
		void computeStatistics();
		void printStatisticsToFile();
		void printGaussianDnaString(int amount);
};
