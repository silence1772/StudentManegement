#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "menu.h"
#include "input.h"
#include "modify.h"
#include "query.h"
#include "delete.h"
#include "statistics.h"
#include "users.h"


void Controller()
{
    bool flag  = true;
    while (flag)
    {
        Users u;
        if (u.Start())
        {
            Menu m;
            while (true)
            {

            }
        }
        else
        {
            flag = false;
        }
    }
}
#endif
