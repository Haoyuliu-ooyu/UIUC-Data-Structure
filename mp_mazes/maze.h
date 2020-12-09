/* Your code here! */



#include "cs225/PNG.h"

using namespace cs225;

class SquareMaze 
{
    public:
        SquareMaze();
        bool canTravel(int x, int y, int dir) const;
        PNG * drawMaze(	) const;
        PNG * drawMazeWithSolution();
        void makeMaze(int width, int height);
        void setWall(int x, int y, int dir, bool exists );
        std::vector< int > solveMaze();
};

