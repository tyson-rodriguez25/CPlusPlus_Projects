#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Maze.h"
#include "MazeInterface.h"
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
	cout << "output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
	}

	int height;
	int width;
	int layer;
	int value;
	in >> height >> width >> layer;
	Maze maze(height, width, layer);
	// Outputs the first maze output with the "_" and "X"
	out << "Solve Maze:" << endl;
		for (int i = 0; i < layer; i++) {
			out << "Layer " << i + 1 << endl;
			for (int j = 0; j < height; j++) {
				for (int k = 0; k < width;++k) {
					in >> value;
					if (value == 0) {
						out << "_ ";
					}
					else {
						out << "X ";
					}
					maze.setValue(j, k, i, value);
				}
				out << endl;
			}
			out << endl;
		}
		// Checks to see if there is a solution to the maze
		if (maze.find_maze_path()) {
			out << maze.toString();
		}
		else {
			out << "No Solution Exists!" << endl;
		}

	return 0;
}