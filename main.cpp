//#include "id_card.h"
#include "file_io.h"
#include "tools.h"
#include "display.h"
#include "menu.h"
#include <stdlib.h>
#include "input.h"
#include "modify.h"
#include "query.h"

int main()
{
    SetWindowSize(106, 36);//设置窗口大小
    SetColor(11);//设置开始动画颜色

    //system("color f4");

    std::cout << "test" << std::endl;

    /*FileIO d;
    IDCard *a = new IDCard("吴泽伟", "男", "数学与信息学院", "计算机科学与技术", "本科生", "2020年6月30日", "201625010622", "106327");
    d.add(a);*/

    Display *c = new Display();
    c->PrintMajorInterface();

    Menu m;
    m.PrintUserInfo();
    m.PrintMenu();
    m.Select();

    /*Input i;
    i.Start();*/

    Modify ww;
    ww.Draw();
    ww.InputInfo();
    ww.Select();

    Query q;
    q.Draw();
    q.InputInfo();
    q.Select();
    q.Find();
    return 0;
}
