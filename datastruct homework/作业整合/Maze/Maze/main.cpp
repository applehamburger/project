#include"maze.h"
int main() {
    Maze maze;
    if (GetMaze("mazedata.txt", maze)) {
        bool* visited = new bool[maze.MazeSize + 1](); // ��ʼ��Ϊ false
        if (!Traverse(1, maze, visited)) {
            std::cout << "�޷��߳��Թ�" << std::endl;
        }
        delete[] visited;
        ReleaseMaze(maze);
    }
    return 0;
}

