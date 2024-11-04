#pragma once
#include <cmath>
#include "static_macros.h"

struct Pixel {
	unsigned int is_block : 1;
	unsigned int directionality : 3;
	unsigned int colour : 3;
	unsigned int block_type : 9;
};

inline Pixel get_pixel(Pixel grid[GRID_SZ], GRID_T x, GRID_T y) {
	return grid[y * GRID_X + x];
}

inline void set_pixel(Pixel grid[GRID_SZ], Pixel value, GRID_T x, GRID_T y) {
	grid[y * GRID_X + x];
}

inline int get_index(GRID_T x, GRID_T y) {
	return y * GRID_X + x;
}