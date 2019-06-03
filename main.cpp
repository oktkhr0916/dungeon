#include <iostream>
#include "dungeon.h"
#include "point.h"
#include "explorer.h"

int main(int argc, const char * argv[]) {
    
    int   dungeon_row    = 13; // Odd Number
    int   dungeon_col    = dungeon_row * 2 - 1;
    
    Point s_point_d1     = Point(dungeon_row - 2, 1);
    Point g_point_d1     = Point(dungeon_row - 2, dungeon_col - 2);
    
    Point s_point_d2     = Point(1, dungeon_col - 2);
    Point g_point_d2     = Point(1, 1);
    
    Dungeon dungeon_1(dungeon_row, dungeon_col, s_point_d1, g_point_d1);
    Dungeon dungeon_2(dungeon_row, dungeon_col, s_point_d2, g_point_d2);
    dungeon_1.make_dangeon();
    dungeon_2.make_dangeon();
    
    Point goal_point = Point(dungeon_row - 1, 1);
    dungeon_1.mergeDungeon(&dungeon_2, s_point_d1, goal_point);
    dungeon_1.displayDungeonMap();
    
    Explorer explorer_1(dungeon_1);
    explorer_1.explore();
    explorer_1.displayRootMap();
    explorer_1.printRoot();
    
    return 0;
    
}
