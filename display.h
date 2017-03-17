#ifndef DISPLAY_H
#define DISPLAY_H

#include "point.h"
#include <vector>

class Display
{
public:
    Display() : pause_time_(0) { }
    void PrintMajorInterface()
    {
        int x = 11;
        int y = 5;
        std::vector<Point> majorinterface;
        for (int i = 0; i < 37; ++i)
        {
            majorinterface.emplace_back(Point(++x, y));
        }
        for (int i = 0; i < 27; ++i)
        {
            majorinterface.emplace_back(Point(x, ++y));
        }
        for (int i = 0; i < 36; ++i)
        {
            majorinterface.emplace_back(Point(--x, y));
        }
        for (int i = 0; i < 26; ++i)
        {
            majorinterface.emplace_back(Point(x, --y));
        }

        for(auto &point : majorinterface)
        {
            point.Print();
        }
    }

private:
    int pause_time_;
};
#endif // DISPLAY_H
