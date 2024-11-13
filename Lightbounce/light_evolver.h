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

void set_if_valid(Pixel grid[GRID_SZ], GRID_T x, GRID_T y, Pixel to_set) {
	if (grid[get_index(x, y)].is_block == false) {
		grid[get_index(x, y)] = to_set;
	}
}

//Note: this does no bounds checking
err_t evolve_pixel(Pixel grid[GRID_SZ], GRID_T x, GRID_T y, BlockDataSet block_cb_set) {
	Pixel pixel_selected = get_pixel(grid, x, y);
	if (pixel_selected.is_block != 0) {
		if (pixel_selected.block_type > UNIQUE_BLOCK_COUNT ||
			block_cb_set[pixel_selected.block_type].callback == NULL) {
			return 1;
		}
		else {
			block_cb_set[pixel_selected.block_type]
				.callback(x, y, grid, pixel_selected);
			return 0;
		}
		return 123;
	}
	if (pixel_selected.is_block==0 && pixel_selected.block_type==Light) {
		switch (pixel_selected.directionality) {
		case Left: {
			set_if_valid(grid, x - 1, y, {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			});
			break;
		}
		case Right: {
			set_if_valid(grid, x + 1, y, {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			});
			break;
		}
		case Up: {
			set_if_valid(grid, x, y-1, {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
				});
			break;
		}
		case Down: {
			set_if_valid(grid, x, y+1, {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			});
			break;
		}

		case TopLeft: {
			set_if_valid(grid, x - 1, y - 1, {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
				});
			break;
		}
		case TopRight: {
			set_if_valid(grid, x - 1, y + 1, {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			});
			break;
		}
		case BottomLeft: {
			set_if_valid(grid, x + 1, y - 1, {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
				});
			break;
		}
		case BottomRight: {
			set_if_valid(grid, x + 1, y + 1, {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			});
			break;
		}
		}
	}
	return 0;
}