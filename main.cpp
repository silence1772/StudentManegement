//#include "id_card.h"
#include "file_io.h"
#include "tools.h"
#include "display.h"

int main()
{
    /*IDCard *a = new IDCard("����ΰ", "��", "��ѧ����ϢѧԺ", "�������ѧ�뼼��", "������", "2020��6��30��", 201625010622, 106327);
    IDCard *c = new IDCard("����ΰ", "��", "��ѧ����ϢѧԺ", "�������ѧ�뼼��", "������", "2020��6��30��", 201625010622, 106327);
    IDCardList *b = new IDCardList();
    b->Insert(a);
    b->Insert(c);
    b->Load();
    delete b;
    return 0;*/
    SetWindowSize(100, 36);//���ô��ڴ�С
    SetColor(11);//���ÿ�ʼ������ɫ
    std::cout << "test" << std::endl;
    FileIO d;
    IDCard *a = new IDCard("����ΰ", "��", "��ѧ����ϢѧԺ", "�������ѧ�뼼��", "������", "2020��6��30��", "201625010622", "106327");
    d.add(a);
    Display *c = new Display();
    c->PrintMajorInterface();
    return 0;
}
