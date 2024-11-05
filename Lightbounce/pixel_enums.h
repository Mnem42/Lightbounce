#pragma once

enum PixelTypes {
	Null,
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