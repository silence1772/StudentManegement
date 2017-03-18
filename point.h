#ifndef POINT_H
#define POINT_H

#include "tools.h"
#include <iostream>

class Point
{
public:
    Point(){}

    Point(const int x, const int y) : x(x), y(y) {}

    void Print()//�������
    {
        SetCursorPosition2(x, y);
        std::cout << "��" ;
    }

    void PrintCircular()//���Բ��
    {
        SetCursorPosition2(x, y);
        std::cout << "��" ;
    }

    void Clear()//������
    {
        SetCursorPosition2(x, y);
        std::cout << "  " ;
    }

    void ChangePosition(const int x, const int y)//�ı�����
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
