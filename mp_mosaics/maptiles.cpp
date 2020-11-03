/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
    vector<Point<3>> points;
    map<Point<3>, TileImage*> m;
    for (auto i = theTiles.begin(); i != theTiles.end(); i++) {
        LUVAPixel pixel = i->getAverageColor();
        Point<3> point = convertToXYZ(pixel);
        points.push_back(point);
        m[point] = &*i;
    }
    KDTree<3> kdtree_ = KDTree<3>(points);
    MosaicCanvas * c = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
    for (int i = 0; i < c->getRows(); i++) {
        for (int j = 0; j < c->getColumns(); j++) {
            Point<3> average = convertToXYZ(theSource.getRegionColor(i, j));
            Point<3> match = kdtree_.findNearestNeighbor(average);
            TileImage* match_tile = m[match];
            c->setTile(i, j, match_tile);
        }
    }
    return c;
}

