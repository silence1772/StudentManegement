//#include "id_card.h"
#include "file_io.h"
#include "tools.h"
#include "display.h"
#include "menu.h"
#include <stdlib.h>
#include "input.h"
#include "modify.h"
#include "query.h"
#include "delete.h"
#include "statistics.h"

int main()
{
    SetWindowSize(106, 36);//���ô��ڴ�С
    SetColor(11);//���ÿ�ʼ������ɫ

    //system("color f4");

    std::cout << "test" << std::endl;

    /*FileIO d;
    IDCard *a = new IDCard("����ΰ", "��", "��ѧ����ϢѧԺ", "�������ѧ�뼼��", "������", "2020��6��30��", "201625010622", "106327");
    d.add(a);*/

    Display *c = new Display();
    c->PrintMajorInterface();

    Menu m;
    m.PrintUserInfo();
    m.PrintMenu();
    m.Select();

    /*Input i;
    i.Start();*/

    /*Modify ww;
    ww.Start();*/

    /*Delete d;
    d.Start();*/

    Statistics s;
    s.Start();

    /*Query q;
    q.Start();
    return 0;*/
}
