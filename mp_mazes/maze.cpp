/* Your code here! */
#include<vector>

#include "maze.h"

SquareMaze::SquareMaze() {}

bool SquareMaze::canTravel(int x, int y, int dir) const {return true;}

PNG * SquareMaze::drawMaze(	) const {return new PNG();}

PNG * SquareMaze::drawMazeWithSolution() {return new PNG();}

void SquareMaze::makeMaze(int width, int height) {}

void SquareMaze::setWall(int x, int y, int dir, bool exists) {}

std::vector<int> SquareMaze::solveMaze() {
    std::vector<int> to_return;
    return to_return;
}