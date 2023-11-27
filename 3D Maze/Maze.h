#ifndef DEQUE_H
#define DEQUE_H
using namespace std;
enum mazeSpot { OPEN, BLOCKED, PATH, EXIT, TEMPORARY };
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "MazeInterface.h"
class Maze :
	public MazeInterface
{
private:
	mazeSpot mazePlace;
	int*** maze;
	int height;
	int width;
	int layer;
public:
	Maze(int height, int width, int layer);
	~Maze();
	virtual void setValue(int height, int width, int layer, int value);
	virtual bool find_maze_path();
	bool find_maze_path(int height, int width, int layer);
	virtual string toString() const;

};
#endif

