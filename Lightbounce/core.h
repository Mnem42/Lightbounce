#include <cmath>

#pragma region default macros
//if these don't get defined, use these defaults
#ifndef GRID_X
#define GRID_X 16
#endif // !GRID_X
#ifndef GRID_Y
#define GRID_Y 16
#endif // !GRID_Y
#ifndef GRID_T
#define GRID_T uint8_t
#endif // !GRID_Y

#define GRID_SZ GRID_X*GRID_Y
#pragma endregion

#pragma region simulation pixels
struct Pixel {
	unsigned int is_block       : 1;
	unsigned int directionality : 3;
	unsigned int colour         : 3;
	unsigned int block_type     : 9;
};

inline Pixel get_pixel(Pixel grid[GRID_SZ], GRID_T x, GRID_T y){
	return grid[y * GRID_X + x];
}

inline void set_pixel(Pixel grid[GRID_SZ], Pixel value, GRID_T x, GRID_T y) {
	grid[y * GRID_X + x];
}
#pragma endregion

#pragma region enums for the pixels
enum PixelTypes {
	Block,
	Light
};

enum Colours {
		//Colours that aren't mixes
		Black,
		Red,
		Green,
		Blue,

		//Mixes of colours
		Orange,
		Cyan,
		Magenta,
		White
	};

enum Directionalities {
	//"flat" directions
	Left,
	Right,
	Up,
	Down,

	//Diagonals
	TopLeft,
	TopRight,
	BottomLeft,
	BottomRight
};
#pragma endregion

#pragma region simulation stuff
//Note: this does no bounds checking
void evolve_pixel(Pixel grid[GRID_SZ], GRID_T x, GRID_T y) {
	Pixel pixel_selected = get_pixel(grid, x, y);
	if (pixel_selected.block_type == Light) {
		switch (pixel_selected.directionality) {
		case Left: {
			grid[y * GRID_X + (x - 1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}
		case Right: {
			grid[y * GRID_X + (x + 1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}
		case Up: {
			grid[(y-1) * GRID_X + x] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}
		case Down: {
			grid[(y+1) * GRID_X + (x + 1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}

		case TopLeft: {
			grid[(y-1) * GRID_X + (x - 1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}
		case TopRight: {
			grid[(y +1)* GRID_X + (x + 1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}
		case BottomLeft: {
			grid[(y + 1) * GRID_X + (x-1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}
		case BottomRight: {
			grid[(y + 1) * GRID_X + (x + 1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}
		}
	}
}
#pragma endregion