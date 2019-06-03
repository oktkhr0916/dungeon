#include "stdafx.h"

#include "explorer.h"
#include "dungeon_core.h"
#include <stdio.h>
#include <iostream>

Explorer::Explorer(Dungeon& r_dungeon) : DungeonCore()
{
    this->p_dungeon = &r_dungeon;
}

void Explorer::displayRootMap()
{
    DungeonMap root_display_map;
    this->initMap(&root_display_map, this->p_dungeon->row, this->p_dungeon->col);
    
    for (auto point = this->root_map.begin(); point != this->root_map.end(); ++point)
    {
        root_display_map[point->first] = 0;
    }
    this->displayMap(&root_display_map, this->p_dungeon->row, this->p_dungeon->col);
}

bool Explorer::explore()
{
    bool is_find_goal = this->findGoal(*this->p_dungeon->p_point_start, 0);
    return is_find_goal;
}

void Explorer::printRoot()
{
//    std::cout << this->root_map.size() << "¥n";
//    for (auto point = this->root_map.begin(); point != this->root_map.end(); point++ )
//    {
//        std::cout << root_map[point->first] << "\n";
//    }
    
    int size = (int)this->root_map.size();
    std::cout << "Size is " << size << ".\n";
    
    for(int i = 0; i < size; i++)
    {
        for (auto point = this->root_map.begin(); point != this->root_map.end(); point++ )
        {
            if (root_map[point->first] == i)
            {
                std::cout << "Point(" << point->first.row << "," << point->first.col << ") is " << i <<"\n";
                break;
            }
        }
    }
}

void Explorer::resetRoot(int reset_point_num)
{
    for (auto point = this->root_map.begin(); point != this->root_map.end(); point++ )
    {
        if(this->root_map[point->first] >= reset_point_num )
        {
            root_map.erase(point);
            break;
        }
    }
}

// Explore Dangeon Goal by Depth First Search
bool Explorer::findGoal(Point& r_point, int root_num)
{
    // If Success to Find Goal.
    if(r_point == *this->p_dungeon->p_point_goal && root_num != 1)
    {
        this->root_map[r_point] = root_num;
        return true;
    };
    
    // Roop for All Actions.
    for(int action : this->action_ary)
    {
        Point next_point = this->getFollowingPoint(r_point, action, 1);
        
        // If Next Point is not wall and the Point is not Passed.
        if (this->isWallInPoint(&this->p_dungeon->dungeon_map, next_point) == false and
            this->root_map.find(next_point) == this->root_map.end())
        {
            this->root_map[r_point] = root_num;
            bool is_find_goal       = findGoal(next_point, root_num + 1);
            if(is_find_goal) {
                return true;
            }
        }
    }
    this->resetRoot(root_num);
    return false;
}
