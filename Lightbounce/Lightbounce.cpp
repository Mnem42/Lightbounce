// Lightbounce.cpp : Defines the entry point for the application.
//

#define GRID_X 4
#define GRID_Y 4
#define UNIQUE_BLOCK_COUNT 16

#include "Lightbounce.h"
#include <iostream>

using namespace std;

void block_test(GRID_T x, GRID_T y, lightbounce_lib::Pixel grid[GRID_SZ], lightbounce_lib::Pixel block_px) {
	std::cout << "yay";
}

lightbounce_lib::BlockDataSet cbs{
	{},
	{block_test}
};

int main()
{
	lightbounce_lib::Pixel grid[GRID_SZ]{};

	grid[1*GRID_X+1] = {false,lightbounce_lib::BottomRight,lightbounce_lib::Green,lightbounce_lib::Light};
	grid[2 * GRID_X + 2] = { true, NULL, NULL, 1 };
	
	for (int n = 0; n < 100;n++) {
		for (int x = 0; x < (GRID_X); x++) {
			for (int y = 0; y < (GRID_Y); y++) {
				lightbounce_lib::evolve_pixel(grid, x, y, cbs);
			}
		}
	}

	return 0;
}
