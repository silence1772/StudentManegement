#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "file_io.h"
#include "tools.h"
#include "display.h"
#include "menu.h"
#include "input.h"
#include "modify.h"
#include "query.h"
#include "delete.h"
#include "statistics.h"
#include "users.h"
#include <stdlib.h>

void Controller()
{
    //system("color f4");
    SetWindowSize(106, 36);//设置窗口大小
    SetColor(11);//设置开始动画颜色

    Display *c = new Display();
    c->Action();

    Users u;
    if (!u.Start()) return;

    Menu m = Menu(u.GetName(), u.GetId(), u.GetPms());


    c->PrintMajorInterface();
    delete c;
    m.PrintUserInfo();
    m.PrintMenu();

    int opt;
    bool flag = true;
    while (flag && (opt = m.Select()) )
    {
        switch(opt)
        {
        case 1:
            ClearScreen(30, 6, 36, 26);
            u.SetPsw();
            break;
        case 2:
            flag = false;
            break;
        case 3:
            {
                ClearScreen(30, 6, 36, 26);
                Input i;
                i.Start();
            }
            break;
        case 4:
            {
                ClearScreen(30, 6, 36, 26);
                Modify md;
                md.Start();
            }
            break;
        case 5:
            {
                ClearScreen(30, 6, 36, 26);
                Delete d;
                d.Start();
            }
            break;
        case 6:
            {
                ClearScreen(30, 6, 36, 26);
                Query q;
                q.Start();
            }
            break;
        case 7:
            {
                ClearScreen(30, 6, 36, 26);
                Statistics s;
                s.Start();
            }
            break;
        default:
            flag = false;
            break;
        }
    }
}
#endif
