// Lightbounce.cpp : Defines the entry point for the application.
//

#include "Lightbounce.h"

extern "C" {
#include "core.h"
}

using namespace std;

int main()
{
	Pixel grid[256]{};

	grid[2*16+2] = {false,Left,Green,Light};
	evolve_pixel(grid, 2, 2);

	return 0;
}
