#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "const.h"
#include "dungeon_core.h"
#include "point.h"

DungeonCore::DungeonCore()
{
    
}

void DungeonCore::displayMap(DungeonMap* map, int row, int col)
{
    for(int row_i = row - 1; row_i >= 0; row_i--)
    {
        for(int col_i = 0; col_i < col; col_i++)
        {
            std::cout<< std::to_string((*map)[Point(row_i, col_i)]) + " ";
        }
        std::cout<< "\n";
    }
    std::cout<< "\n";
}

Point DungeonCore::getFollowingPoint(Point& r_point, int action, int following_num)
{
    switch(action){
        case UP:
            return Point(r_point.row, r_point.col + following_num);
        case RIGHT:
            return Point(r_point.row + following_num, r_point.col);
        case DOWN:
            return Point(r_point.row, r_point.col - following_num);
        default: //LEFT
            return Point(r_point.row - following_num, r_point.col);
    }
}

void DungeonCore::initMap(DungeonMap* map, int row, int col)
{
    for(int row_i = 0; row_i < row; row_i++)
    {
        for(int col_i = 0; col_i < col; col_i++)
        {
            (*map)[Point(row_i, col_i)] = 1;
        }
    }
}

bool DungeonCore::isWallInPoint(DungeonMap* map, Point& r_point)
{
    if ((*map)[r_point] == 1)return true;
    return false;
}
