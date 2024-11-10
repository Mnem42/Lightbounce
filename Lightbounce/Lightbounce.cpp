// Lightbounce.cpp : Defines the entry point for the application.
//

#include "Lightbounce.h"

using namespace std;

void block_tes(GRID_T x, GRID_T y, lightbounce_lib::Pixel grid[GRID_SZ], lightbounce_lib::Pixel block_px) {

}

int main()
{
	lightbounce_lib::Pixel grid[GRID_SZ]{};

	grid[1*GRID_X+1] = {false,lightbounce_lib::BottomRight,lightbounce_lib::Green,lightbounce_lib::Light};
	
	for (int n = 0; n < 100;n++) {
		for (int x = 0; x < (GRID_X); x++) {
			for (int y = 0; y < (GRID_Y); y++) {
				lightbounce_lib::evolve_pixel(grid, x, y);
			}
		}
	}

	return 0;
}
