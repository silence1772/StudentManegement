#ifndef DISPLAY_H
#define DISPLAY_H

#include "point.h"
#include <vector>
#include <windows.h>

class Display
{
public:
    Display() : pause_time_(0) { }
    void PrintMajorInterface()
    {
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
            point.PrintCircular();
            Sleep(pause_time_);
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
            point.PrintCircular();
            Sleep(pause_time_);
        }


    }

private:
    int pause_time_;
};
#endif // DISPLAY_H
