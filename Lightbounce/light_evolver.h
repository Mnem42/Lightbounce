#pragma once
#include <cmath>
#include "static_macros.h"
#include "pixels.h"
#include "pixel_enums.h"

//Note: this does no bounds checking
void evolve_pixel(Pixel grid[GRID_SZ], GRID_T x, GRID_T y) {
	Pixel pixel_selected = get_pixel(grid, x, y);
	if (pixel_selected.block_type == Light) {
		switch (pixel_selected.directionality) {
		case Left: {
			grid[get_index(x-1,y)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
			break;
		}
		case Right: {
			grid[get_index(x+1,y)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
			break;
		}
		case Up: {
			grid[get_index(x,y-1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
			break;
		}
		case Down: {
			grid[get_index(x,y+1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
			break;
		}

		case TopLeft: {
			grid[get_index(x-1,y-1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
			break;
		}
		case TopRight: {
			grid[get_index(x-1,y+1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
			break;
		}
		case BottomLeft: {
			grid[get_index(x-1,y+1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
			break;
		}
		case BottomRight: {
			grid[get_index(x+1,y+1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
			break;
		}
		}
	}
}
