#pragma once
#include <cmath>
#include "static_macros.h"
#include "pixels.h"
#include "pixel_enums.h"

typedef void(*Blockcb)(GRID_T x, GRID_T y, Pixel grid[GRID_SZ],Pixel block_px);
struct BlockDataEntry {
	Blockcb callback;
};
typedef BlockDataEntry BlockDataSet[UNIQUE_BLOCK_COUNT];
typedef uint8_t err_t;

//Note: this does no bounds checking
err_t evolve_pixel(Pixel grid[GRID_SZ], GRID_T x, GRID_T y, BlockDataSet block_cb_set) {
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
	if (pixel_selected.block_type == Block) {
		if (pixel_selected.block_type > UNIQUE_BLOCK_COUNT||
			block_cb_set[pixel_selected.block_type].callback == NULL) {
			return 1;
		}
		else {
			block_cb_set[pixel_selected.block_type]
				.callback(x, y, grid, pixel_selected);
		}
	}
	return 0;
}
