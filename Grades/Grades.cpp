#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif


int main(int argc, char* argv[]) {
	VS_MEM_CHECK
		if (argc < 3)
		{
			cerr << "Please provide name of input and output files";
			return 1;
		}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 1;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
	}
	int numStudents;
	int numExams;
	int examGrades;
	double examAverage = 0.0;
	double examTotal = 0.0;
	in >> numStudents >> numExams;
	string* studentNames = new string[numStudents];
	int** examScores = new int*[numStudents];
	for (int i = 0; i < numStudents;++i) {
		string firstName;
		string lastName;
		in >> firstName >> lastName;
		studentNames[i] = firstName + lastName;

		examScores[i] = new int[numExams];
		for (int j = 0; j < numExams; ++j) {
				in >> examGrades;
				examScores[i][j] = examGrades;
				if (j == numExams) {
					break;
				}
		}

	}
	
	
	double* examAverages = new double[numExams];
	out << "Exam Averages:" << endl;
	for (int i = 0; i < numExams;++i) { //Every iteration will be one line
		int k = 0;
		const int EXAM_COUNTER = 1;
		out << "Exam " << i + EXAM_COUNTER << " average =";
		examTotal = 0;
		for (int j = 0; j < numStudents; ++j) {
			examTotal = examScores[j][i] + examTotal;
		
		}
		examAverage = examTotal / numStudents;
		examAverages[i] = examAverage;
		int aCounter = 0;
		int bCounter = 0;
		int cCounter = 0;
		int dCounter = 0;
		int eCounter = 0;
			for (int m = 0; m < numStudents; ++m) {
				
				if (examScores[m][i] <= (examAverage + 5) && examScores[m][i] >= (examAverage - 5)) {
					++cCounter;
				}
				else if ((examScores[m][i] > (examAverage + 5)) && (examScores[m][i] < (examAverage + 15))) {
					++bCounter;
				}
				else if ((examScores[m][i] < (examAverage - 5)) && (examScores[m][i] > (examAverage - 15))) {
					++dCounter;
				}
				else if ((examScores[m][i] > (examAverage + 15)) ){
					++aCounter;
				}
				else if ((examScores[m][i] < (examAverage - 15)) ){
					++eCounter;
				}
			}
		out << fixed << setprecision(1) << setw(3) << examAverage;
		out << "  " << aCounter << "(A)" << "   " << bCounter << "(B)" << "   " << cCounter << "(C)" << "   ";
		out << dCounter << "(D)" << "   " << eCounter << "(E)" << "   " << endl;
	}
	out << endl;
	out << "Student Exam Grades:" << endl;
	for (int k = 0; k < numStudents; ++k) {
		out << setw(20) << studentNames[k] << " ";
		for (int l = 0; l < numExams; ++l) {

			out << fixed << setprecision(0) << setw(3) << examScores[k][l];
			if (examScores[k][l] <= (examAverages[l] + 5) && examScores[k][l] >= (examAverages[l] - 5)) {
				out << "(C) ";
			}
			else if ((examScores[k][l] >(examAverages[l] + 5)) && (examScores[k][l] < (examAverages[l] + 15))) {
				out << "(B) ";
			}
			else if ((examScores[k][l] < (examAverages[l] - 5)) && (examScores[k][l] > (examAverages[l] - 15))) {
				out << "(D) ";
			}
			else if ((examScores[k][l] > (examAverages[l] + 15))) {
				out << "(A) ";
			}
			else if ((examScores[k][l] < (examAverages[l] - 15))) {
				out << "(E) ";
			}

		}
		out << std::endl;
	}
	for (int i = 0; i < numStudents;++i) {
			delete[] examScores[i];
	}
	delete[] examScores;
	
	delete[] studentNames;
	delete[] examAverages;

	return 0;
}