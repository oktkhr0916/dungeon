#pragma once

class Point
{
    public:
    Point(int row ,int col);

    int row;
    int col;

    bool operator==(const Point& r_point) const;
    bool operator!=(const Point& r_point) const;
    bool operator<(const Point& r_point) const;

    protected:
    private:
};

