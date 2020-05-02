#pragma once
#include "Collider.h"
#include "BoxExtents.h"
#include <memory>
class StaticTileMapCollider : public Collider
{
public:
	StaticTileMapCollider(const int* tileBitmap, int bitmapWidth,int bitmapHeight,float tileWidth,float tileHeight);
	~StaticTileMapCollider();
	void update() {};
	bool detectCollisionAgainstBox(const BoxExtents& otherExtents);
private:
	bool isWall(int tile);
	BoxExtents getTileExtents(int i, int j);

	const int* tileBitmap;
	int bitmapWidth;
	int bitmapHeight;
	float tileWidth;
	float tileHeight;
};
