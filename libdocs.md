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