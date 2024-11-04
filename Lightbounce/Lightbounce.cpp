// Lightbounce.cpp : Defines the entry point for the application.
//

#include "Lightbounce.h"

using namespace std;

int main()
{
	Pixel grid[256]{};

	grid[2*16+2] = {false,BottomLeft,Green,Light};
	evolve_pixel(grid, 2, 2);

	return 0;
}
