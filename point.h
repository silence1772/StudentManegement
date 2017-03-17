#ifndef POINT_H
#define POINT_H

#include "tools.h"
#include <iostream>

class Point
{
public:
    Point(){}

    Point(const int x, const int y) : x(x), y(y) {}

    void Print()//输出方块
    {
        SetCursorPosition2(x, y);
        std::cout << "■" ;
    }

    void PrintCircular()//输出圆形
    {
        SetCursorPosition2(x, y);
        std::cout << "●" ;
    }

    void Clear()//清除输出
    {
        SetCursorPosition2(x, y);
        std::cout << "  " ;
    }

    void ChangePosition(const int x, const int y)//改变坐标
    {
        this->x = x;
        this->y = y;
    }

    bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
    int GetX(){ return this->x; }
    int GetY(){ return this->y; }
private:
    int x, y;
};
#endif // POINT_H
