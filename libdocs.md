# Lightbounce library

## Pixel grid

The pixel grid is technically a 1d array, but it stores things as 2d. This works because it has a fixed size. For example, if this is the 2d array:

```
+--+--+--+--+
|a0|a1|a2|a3|
+--+--+--+--+
|b0|b1|b2|b3|
+--+--+--+--+
|c0|c1|c2|c3|
+--+--+--+--+
|d0|d1|d2|d3|
+--+--+--+--+
```

It would be represented as a 1d array like

```
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
|a0|a1|a2|a3|b0|b1|b2|b3|c0|c1|c2|c3|d0|d1|d2|d3|
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
```

So access has to be done like `grid[y*SIZE_X+x]` to get the value, rather than `grid[x][y]`, or with the helper functions `set_pixel()` and `get_pixel()`.

## Block system

Blocks are the static components that either do something with the light or just exist as a static object. Each block has a block data struct, which contains the `callback` item, for callbacks.

## Callback system

The callback system is based on an array of callbacks, with the size configurable with the `UNIQUE_BLOCK_COUNT` macro. If there are less callbacks added than that number, it may cause errors, due to it attempting to access a callback that doesn't actually exist. The callback function signature must be something like `void foo(GRID_T x, GRID_T y, Pixel grid[GRID_SZ],Pixel block_px)`, and it should modify the pixel grid directly, if necessary. The function pointer is typedeffed as `BlockCb`, and the callback is stored in a `BlockDataEntry` as the `callback` item. The `BlockDataEntry` is gotten from the fixed length array `BlockDataSet`.

This can *technically* be dynamically allocated, but it's a bad idea.