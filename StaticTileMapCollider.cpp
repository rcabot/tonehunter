#include "StaticTileMapCollider.h"
#include <iostream>
constexpr int TEST_TILES_WITHIN = 13;

StaticTileMapCollider::StaticTileMapCollider(const int* tbm, int bmw, int bmh, float tw, float th) : Collider()
{
	bitmapWidth = bmw;
	bitmapHeight = bmh;
	tileBitmap = tbm;
	tileWidth = tw;
	tileHeight = th;
}

StaticTileMapCollider::~StaticTileMapCollider()
{
	Collider::~Collider();
}

bool StaticTileMapCollider::detectCollisionAgainstBox(const BoxExtents& otherExtents)
{
	int left_tile = (int)round((otherExtents.left) / ((float)bitmapWidth)) - TEST_TILES_WITHIN;
	int right_tile = (int)round((otherExtents.right) / ((float)bitmapWidth)) + TEST_TILES_WITHIN;
	int top_tile = (int)round((otherExtents.top) / ((float)bitmapHeight)) - TEST_TILES_WITHIN;
	int bottom_tile = (int)round((otherExtents.bottom) / ((float)bitmapHeight)) + TEST_TILES_WITHIN;

	if (left_tile < 0) left_tile = 0;
	if (right_tile > bitmapWidth) right_tile = bitmapWidth;
	if (top_tile < 0) top_tile = 0;
	if (bottom_tile > bitmapHeight) bottom_tile = bitmapHeight;

	//left_tile = 0;
	//right_tile = bitmapWidth;
	//top_tile = 0;
	//bottom_tile = bitmapHeight;

	bool collision = false;
	for (int i = left_tile; i < right_tile; i++)
	{
		for (int j = top_tile; j < bottom_tile; j++)
		{
			int tile = tileBitmap[i + j* bitmapHeight];
			if (isWall(tile)) {
				auto tileExtents = getTileExtents(i,j);
				if (Collider::compareBoxExtents(otherExtents, tileExtents)) {
					return true;
				}
			}
		}
	}
	return false;
}

bool StaticTileMapCollider::isWall(int tile)
{
	return tile!= 11;
}

BoxExtents StaticTileMapCollider::getTileExtents(int i, int j)
{
	// define its 4 corners
	BoxExtents extents;
	extents.left = i * tileWidth;
	extents.right = (i + 1) * tileWidth;
	extents.top = j * tileHeight;
	extents.bottom = (j + 1) * tileHeight;
	extents.width = tileWidth;
	extents.height = tileHeight;
	return extents;
}
