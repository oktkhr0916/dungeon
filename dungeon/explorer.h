#pragma once
#include <stdio.h>
#include "const.h"
#include "dungeon.h"
#include "point.h"

class Explorer : public DungeonCore
{
public:
    Explorer(Dungeon& r_dungeon);

    Dungeon*   p_dungeon;
    DungeonMap root_map;

    void displayRootMap();
    bool explore();
    void printRoot();

protected:
private:
    int action_ary[4] = {UP, RIGHT, DOWN, LEFT};

    void resetRoot(int reset_point_num);
    bool findGoal(Point& r_point, int root_num);
};
