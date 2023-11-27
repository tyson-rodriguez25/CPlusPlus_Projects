#include "Maze.h"
// Constructors
Maze::Maze(int height, int width, int layer) {
	this->height = height;
	this->width = width;
	this->layer = layer;
	maze = new int**[height];
	for (int i = 0; i < height; ++i)
	{
		maze[i] = new int*[width];

		for (int j = 0;j < width;++j)
		{
			maze[i][j] = new int[layer];
		}
	}
}

// Deletes memory
Maze::~Maze() {
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			delete[] maze[i][j];
		}
		delete[] maze[i];
	}
	delete[] maze;
}

// Sets values to each space in the maze
void Maze::setValue(int height, int width, int layer, int value) {
	maze[height][width][layer] = value;
}

// Wrapper Function
bool Maze::find_maze_path() {
	return find_maze_path(0,0,0);
}

// Goes through the Maze
bool Maze::find_maze_path(int x, int y, int z) {
	if ((x < 0) || x >= height || (y < 0) || y >= width || (z < 0) || z >= layer) {
		return false;
	}
	else if (maze[x][y][z] != OPEN) {
		return false;
	}
	else if ((x == height - 1) && (y == width - 1) && (z == layer - 1)) {
		maze[x][y][z] = EXIT;
		return true;
	}
	else {
		maze[x][y][z] = PATH;
		if (find_maze_path(x - 1, y, z) || find_maze_path(x + 1, y, z) || find_maze_path(x, y - 1, z) || find_maze_path(x, y + 1, z) || find_maze_path(x, y, z - 1) || find_maze_path(x, y, z + 1)) {
			return true;
		}
		else {
			maze[x][y][z] = TEMPORARY;
			return false;
		}
	}
}

// Outputs the solution if there is one
string Maze::toString() const {
	stringstream out;
	
	out << "Solution: " << endl;
	for (int i = 0; i < layer; i++) {
		out << "Layer " << i + 1 << endl;
			for (int j = 0; j < height; j++) {
				for (int k = 0; k < width;++k) {
					if (maze[j][k][i] == EXIT) {
							out << "3 ";
						}
					else if (maze[j][k][i] == PATH) {
							out << "2 ";
						}
					else if (maze[j][k][i] == TEMPORARY || maze[j][k][i] == OPEN) {
						out << "_ ";
					}
					else {
						out << "X ";
					}
				}
				out << endl;
			}
			out << endl;
		}
	return out.str();
}
