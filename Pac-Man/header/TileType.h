#pragma once
struct TileType
{
	enum Type 
	{ 
		EmptySpace = 0, 
		Wall = 1, 
		SmallDot = 2, 
		BigDot = 3, 
		Warp = 4, 
		GhostGate = 5, 
		PacManSpawnPoint = 6, 
		RedGhostSpawnPoint = 7, 
		PinkGhostSpawnPoint = 8, 
		OrangeGhostSpawnPoint = 9, 
		BlueGhostSpawnPoint = 10, 
	};
};

