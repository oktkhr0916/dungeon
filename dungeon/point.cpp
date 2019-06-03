#include "stdafx.h"
#include "point.h"
#include <tuple>
#include <iostream>

Point::Point(int row, int col)
{
    this->row = row;
    this->col = col;
}

bool Point::operator==(const Point& r_point) const
{
    const Point& l_point = *this;
    return l_point.row == r_point.row && l_point.col == r_point.col;
}

bool Point::operator!=(const Point& r_point) const
{
    return !(this->operator==(r_point));
}

bool Point::operator<(const Point& r_point) const
{
    const Point& l_point = *this;
    return std::tie(l_point.row, l_point.col) < std::tie(r_point.row, r_point.col);
}
