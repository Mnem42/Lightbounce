#pragma once
#include <cmath>
#include "static_macros.h"

struct Pixel {
	unsigned int is_block;
	unsigned int directionality;
	unsigned int colour;
	unsigned int block_type;
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