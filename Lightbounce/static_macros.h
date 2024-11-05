// A few defaults

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

#ifndef GRID_SZ
#define GRID_SZ GRID_X*GRID_Y
#endif

#ifndef UNIQUE_BLOCK_COUNT
#define UNIQUE_BLOCK_COUNT 16
#pragma warning "It's a good idea to set UNIQUE_BLOCK_COUNT manually"
#endif