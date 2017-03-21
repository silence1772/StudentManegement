#ifndef DISPLAY_H
#define DISPLAY_H

#include "point.h"
#include <vector>
#include <deque>
#include <windows.h>

class Display
{
public:
    Display() : pause_time_(35) { }
    void Init()
    {
        int x = -60;
        int y = 16;
        startsnake.emplace_back(Point(0,14));//蛇
        startsnake.emplace_back(Point(1,14));
        startsnake.emplace_back(Point(2,15));
        startsnake.emplace_back(Point(3,16));
        startsnake.emplace_back(Point(4,17));
        startsnake.emplace_back(Point(5,18));
        startsnake.emplace_back(Point(6,17));
        startsnake.emplace_back(Point(7,16));
        startsnake.emplace_back(Point(8,15));
        startsnake.emplace_back(Point(9,14));

        text.emplace_back(Point(x, y-4));//H
        text.emplace_back(Point(x, y-3));
        text.emplace_back(Point(x, y-2));
        text.emplace_back(Point(x, y-1));
        text.emplace_back(Point(x, y-0));
        text.emplace_back(Point(x, y+1));
        text.emplace_back(Point(x, y+2));
        text.emplace_back(Point(x+2, y-1));
        text.emplace_back(Point(x+4, y-1));
        text.emplace_back(Point(x+6, y-1));
        text.emplace_back(Point(x+8, y-1));
        text.emplace_back(Point(x+10, y-4));
        text.emplace_back(Point(x+10, y-3));
        text.emplace_back(Point(x+10, y-2));
        text.emplace_back(Point(x+10, y-1));
        text.emplace_back(Point(x+10, y-0));
        text.emplace_back(Point(x+10, y+1));
        text.emplace_back(Point(x+10, y+2));

        text.emplace_back(Point(x+14, y-4));//E
        text.emplace_back(Point(x+16, y-4));
        text.emplace_back(Point(x+18, y-4));
        text.emplace_back(Point(x+20, y-4));
        text.emplace_back(Point(x+22, y-4));
        text.emplace_back(Point(x+14, y-1));
        text.emplace_back(Point(x+16, y-1));
        text.emplace_back(Point(x+18, y-1));
        text.emplace_back(Point(x+20, y-1));
        text.emplace_back(Point(x+22, y-1));
        text.emplace_back(Point(x+14, y+2));
        text.emplace_back(Point(x+16, y+2));
        text.emplace_back(Point(x+18, y+2));
        text.emplace_back(Point(x+20, y+2));
        text.emplace_back(Point(x+22, y+2));
        text.emplace_back(Point(x+14, y-3));
        text.emplace_back(Point(x+14, y-2));
        text.emplace_back(Point(x+14, y));
        text.emplace_back(Point(x+14, y+1));


        text.emplace_back(Point(x+26, y-4));//L
        text.emplace_back(Point(x+26, y-3));
        text.emplace_back(Point(x+26, y-2));
        text.emplace_back(Point(x+26, y-1));
        text.emplace_back(Point(x+26, y-0));
        text.emplace_back(Point(x+26, y+1));
        text.emplace_back(Point(x+26, y+2));
        text.emplace_back(Point(x+28, y+2));
        text.emplace_back(Point(x+30, y+2));
        text.emplace_back(Point(x+32, y+2));
        text.emplace_back(Point(x+34, y+2));

        text.emplace_back(Point(x+26+12, y-4));//L
        text.emplace_back(Point(x+26+12, y-3));
        text.emplace_back(Point(x+26+12, y-2));
        text.emplace_back(Point(x+26+12, y-1));
        text.emplace_back(Point(x+26+12, y-0));
        text.emplace_back(Point(x+26+12, y+1));
        text.emplace_back(Point(x+26+12, y+2));
        text.emplace_back(Point(x+28+12, y+2));
        text.emplace_back(Point(x+30+12, y+2));
        text.emplace_back(Point(x+32+12, y+2));
        text.emplace_back(Point(x+34+12, y+2));

        text.emplace_back(Point(x+50, y-1));
        text.emplace_back(Point(x+51, y));
        text.emplace_back(Point(x+53, y+1));
        text.emplace_back(Point(x+54, y+2));
        text.emplace_back(Point(x+51, y-2));
        text.emplace_back(Point(x+53, y-3));
        text.emplace_back(Point(x+54, y-4));

        text.emplace_back(Point(x+60, y-1));
        text.emplace_back(Point(x+59, y));
        text.emplace_back(Point(x+57, y+1));
        text.emplace_back(Point(x+56, y+2));
        text.emplace_back(Point(x+59, y-2));
        text.emplace_back(Point(x+58, y-3));
        text.emplace_back(Point(x+56, y-4));

    }
    void Print2First()//蛇从左边出现到完全出现的过程
    {
        for (auto& point : startsnake)
        {
            point.Print2();
            Sleep(pause_time_);
        }
    }
    void Print2Second()//蛇从左向右移动的过程
    {
        for (int i = 10; i != 52; ++i) //蛇头需要从10移动到40
        {
            /*计算蛇头的下一个位置，并将其压入startsnake中，绘制出来，将蛇尾去掉*/
            int j = ( ((i-2)%8) < 4 )?( 15 + (i-2)%8 ) : ( 21 - (i-2)%8 );
            startsnake.emplace_back( Point(i, j) );
            startsnake.back().Print2();
            startsnake.front().Clear2();
            startsnake.pop_front();
            Sleep(pause_time_);
        }
    }
    void Print2Third()//蛇从接触右边到消失的过程
    {
        while ( !startsnake.empty() || text.back().GetX() < 76 ) //当蛇还没消失或文字没移动到指定位置
        {
            if ( !startsnake.empty() ) //如果蛇还没消失，继续移动
            {
                startsnake.front().Clear2();
                startsnake.pop_front();
            }
            ClearText();//清除已有文字
            PrintText();//绘制更新位置后的文字
            Sleep(pause_time_);
        }
    }
    void PrintText()
    {
        for (auto& point : text)
        {
            if (point.GetX() >= 0)
                point.Print();
        }
    }
    void ClearText()
    {
        for (auto& point : text) //清除的同时将文字整体向右移动一格
        {
            if (point.GetX() >= 0)
            point.Clear();
            point.ChangePosition(point.GetX() + 2, point.GetY());
        }
    }
    void Action()
    {
        Init();
        Print2First();
        Print2Second();
        Print2Third();
        SetCursorPosition(40, 29);
        std::cout << "欢迎使用学生证管理系统！" ;
        SetCursorPosition(42, 31);
        system("pause");
        ClearScreen(10, 6, 56, 26);
    }
    void PrintMajorInterface()
    {
        SetColor(11);
        SetCursorPosition(44, 2);
        std::cout << "学生证管理系统 V1.0" ;
        int x = 0;
        int y = 5;
        int w = 12;
        int h = 29;
        std::vector<Point> majorinterface;

        for (int i = 0; i < w; ++i)
        {
            majorinterface.emplace_back(Point(++x, y));
        }
        for (int i = 0; i < h; ++i)
        {
            majorinterface.emplace_back(Point(x, ++y));
        }
        for (int i = 0; i < w - 1; ++i)
        {
            majorinterface.emplace_back(Point(--x, y));
        }
        for (int i = 0; i < h - 1; ++i)
        {
            majorinterface.emplace_back(Point(x, --y));
        }

        for(auto &point : majorinterface)
        {
            point.Print2();
        }

        x = 13;
        y = 5;
        w = 38;
        h = 29;
        std::vector<Point>().swap(majorinterface);
        for (int i = 0; i < w; ++i)
        {
            majorinterface.emplace_back(Point(++x, y));
        }
        for (int i = 0; i < h; ++i)
        {
            majorinterface.emplace_back(Point(x, ++y));
        }
        for (int i = 0; i < w - 1; ++i)
        {
            majorinterface.emplace_back(Point(--x, y));
        }
        for (int i = 0; i < h - 1; ++i)
        {
            majorinterface.emplace_back(Point(x, --y));
        }

        for(auto &point : majorinterface)
        {
            point.Print2();
        }


    }

private:
    std::deque<Point> startsnake;//开始动画中的蛇
    std::vector<Point> text;//开始动画中的文字
    int pause_time_;
};
#endif // DISPLAY_H
