// dungeon.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//



#pragma once
#include "stdafx.h"

#include <stdio.h>
#include "point.h"
#include "dungeon_core.h"

class Dungeon : public DungeonCore
{
public:
	Dungeon(int row, int col, Point& r_point_start, Point& r_point_goal);

	int    row;
	int    col;
	Point* p_point_start;
	Point* p_point_goal;

	DungeonMap dungeon_map;

	void displayDungeonMap();
	void make_dangeon();
	bool mergeDungeon(Dungeon* merged_dungeon, Point& r_point_start, Point& r_point_goal, bool is_close = true);

protected:

private:

	void  digPath(Point& r_point);
	bool  enableToMakePath(Point& r_point, int action);
	void  getShuffledActionAry(int ary[], int size);
	Point getStartPoint();
	void  initDungeon();
	bool  isOutOfRange(Point& r_point);
};