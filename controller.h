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

void Controller()
{
    SetWindowSize(106, 36);//���ô��ڴ�С
    SetColor(11);//���ÿ�ʼ������ɫ

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
            break;
        case 2:
            flag = false;
            break;
        case 3:
            {
                Input i;
                i.Start();
            }
            break;
        case 4:
            {
                Modify md;
                md.Start();
            }
            break;
        case 5:
            {
                Delete d;
                d.Start();
            }
            break;
        case 6:
            {
                Query q;
                q.Start();
            }
            break;
        case 7:
            {
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
