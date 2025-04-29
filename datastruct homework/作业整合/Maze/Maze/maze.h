#pragma once
#include <fstream>
#include <iostream>

struct Intersection {
    int left;
    int forwd;
    int right;
};

struct Maze {
    int MazeSize;
    int EXIT;
    Intersection* intsec;
};

bool GetMaze(const char* mazedata, Maze& M);

void ReleaseMaze(Maze& M);

bool Traverse(int Pos, Maze& M, bool* visited);
