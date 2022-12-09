#pragma once
struct WallType
{
	enum Type {
		Horizontal = 0, 
		Vertical = 1,
		TopLeft = 2, 
		TopRight = 3, 
		BottomRight = 4,
		BottomLeft = 5, 
		HorizontalLeftEnd = 6,
		HorizontalRightEnd = 7, 
		VerticalTopEnd = 8, 
		VerticalBottomEnd = 9,
		JointBottom = 10,
		JointTop = 11, 
		JointRight = 12, 
		JointLeft = 13
	};
};

