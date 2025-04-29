#include"maze.h"

bool GetMaze(const char* mazedata, Maze& M) {
    std::ifstream fin;
    fin.open(mazedata);
    if (!fin) {
        std::cout << "无法打开文件" << std::endl;
        return false;
    }
    fin >> M.MazeSize;
    M.intsec = new Intersection[M.MazeSize + 1];
    for (int i = 1; i <= M.MazeSize; i++)
        fin >> M.intsec[i].left >> M.intsec[i].forwd >> M.intsec[i].right;
    fin >> M.EXIT;
    fin.close();
    return true;
}

void ReleaseMaze(Maze& M) {
    delete[] M.intsec;
}

bool Traverse(int Pos, Maze& M, bool* visited) {
    if (Pos > 0) {
        if (Pos == M.EXIT) {
            std::cout << Pos << "<< ";
            return true;
        }
        else if (!visited[Pos]) {
            visited[Pos] = true;
            if (Traverse(M.intsec[Pos].left, M, visited)) {
                std::cout << Pos << "<< ";
                return true;
            }
            if (Traverse(M.intsec[Pos].forwd, M, visited)) {
                std::cout << Pos << "<< ";
                return true;
            }
            if (Traverse(M.intsec[Pos].right, M, visited)) {
                std::cout << Pos << "<< ";
                return true;
            }
        }
    }
    return false;
}

