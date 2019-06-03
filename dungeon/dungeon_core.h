#pragma once
#include <map>
#include "point.h"

typedef std::map<Point, int> DungeonMap;

class DungeonCore
{
public:
    DungeonCore();

protected:
    void  displayMap(DungeonMap* map, int row, int col);
    Point getFollowingPoint(Point& r_point, int action, int following_num);
    void  initMap(DungeonMap* map, int row, int col);
    bool  isWallInPoint(DungeonMap* map, Point& r_point);
};
