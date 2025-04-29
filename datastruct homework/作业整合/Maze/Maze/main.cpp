#include"maze.h"
int main() {
    Maze maze;
    if (GetMaze("mazedata.txt", maze)) {
        bool* visited = new bool[maze.MazeSize + 1](); // 初始化为 false
        if (!Traverse(1, maze, visited)) {
            std::cout << "无法走出迷宫" << std::endl;
        }
        delete[] visited;
        ReleaseMaze(maze);
    }
    return 0;
}

