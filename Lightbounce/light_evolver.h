#pragma once

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
			grid[(y - 1) * GRID_X + x] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}
		case Down: {
			grid[(y + 1) * GRID_X + (x + 1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}

		case TopLeft: {
			grid[(y - 1) * GRID_X + (x - 1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}
		case TopRight: {
			grid[(y + 1) * GRID_X + (x + 1)] = {
				.is_block = 0,
				.directionality = pixel_selected.directionality,
				.colour = pixel_selected.colour,
				.block_type = Light
			};
		}
		case BottomLeft: {
			grid[(y + 1) * GRID_X + (x - 1)] = {
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
