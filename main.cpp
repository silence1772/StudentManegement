//#include "id_card.h"
#include "file_io.h"
#include "tools.h"
#include "display.h"

int main()
{
    /*IDCard *a = new IDCard("吴泽伟", "男", "数学与信息学院", "计算机科学与技术", "本科生", "2020年6月30日", 201625010622, 106327);
    IDCard *c = new IDCard("吴泽伟", "男", "数学与信息学院", "计算机科学与技术", "本科生", "2020年6月30日", 201625010622, 106327);
    IDCardList *b = new IDCardList();
    b->Insert(a);
    b->Insert(c);
    b->Load();
    delete b;
    return 0;*/
    SetWindowSize(100, 36);//设置窗口大小
    SetColor(11);//设置开始动画颜色
    std::cout << "test" << std::endl;
    FileIO d;
    IDCard *a = new IDCard("吴泽伟", "男", "数学与信息学院", "计算机科学与技术", "本科生", "2020年6月30日", "201625010622", "106327");
    d.add(a);
    Display *c = new Display();
    c->PrintMajorInterface();
    return 0;
}
