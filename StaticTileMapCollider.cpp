#include "StaticTileMapCollider.h"

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
	for (unsigned int i = 0; i < bitmapWidth; i++)
	{
		for (unsigned int j = 0; j < bitmapHeight; j++)
		{
			int tile = tileBitmap[i + j];
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
	return extents;
}
