#ifndef INPUT_H
#define INPUT_H

#include "file_io.h"

class Input
{
public:
    Input() : x(36), y(10), w(30), h(19) { }
    void Draw()
    {
        SetColor(11);
        SetCursorPosition(x, y);
        for(int i = 0; i < w; i++)
        {
            std::cout << "��" ;
        }
        for (int i = 0; i < h; i++)
        {
            SetCursorPosition(x - 1, ++y);
            std::cout << "��" ;
            SetCursorPosition(x - 1 + w * 2, y);
            std::cout << "��" ;
        }
        SetCursorPosition(x, ++y);
        for(int i = 0; i < w; i++)
        {
            std::cout << "��" ;
        }

        int ix = x + 2;
        int iy = y - 16;
        SetCursorPosition(ix + 20, iy - 2);
        std::cout << "������ѧ��֤��Ϣ" ;
        SetCursorPosition(ix, iy++);
        std::cout << "������" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "һһһһ" ;
        SetCursorPosition(ix, iy++);
        std::cout << "�Ա�" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "һһ" ;
        SetCursorPosition(ix, iy++);
        std::cout << "ѧԺ��" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "һһһһһһһһ" ;
        SetCursorPosition(ix, iy++);
        std::cout << "רҵ��" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "һһһһһһһһһ" ;
        SetCursorPosition(ix, iy++);
        std::cout << "��ݣ�" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "һһһһ" ;
        SetCursorPosition(ix, iy++);
        std::cout << "ѧ�ţ�" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "һһһһһһһ" ;
        SetCursorPosition(ix, iy++);
        std::cout << "���ţ�" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "һһһһ" ;
        SetCursorPosition(ix, iy++);
        std::cout << "��Ч�ڣ�" ;
        SetCursorPosition(ix + 6, iy++);
        std::cout << "һһһһһһһһ" ;

        SetCursorPosition(76, 26);
        std::cout << "ȷ��¼��" ;
        SetCursorPosition(88, 26);
        std::cout << "ȡ��" ;

        SetCursorPosition(70, 15);
        std::cout << "���ڸ�ʽ��20xx��xx��xx��" ;
        SetCursorPosition(70, 17);
        std::cout << "����󰴻س���������һ��" ;
    }
    void InputInfo()
    {
        int ix = x + 8;
        int iy = y - 16;

        SetCursorPosition(ix, iy++);
        std::cin >> name;
        iy++;
        SetCursorPosition(ix, iy++);
        std::cin >> sex;
        iy++;
        SetCursorPosition(ix, iy++);
        std::cin >> college;
        iy++;
        SetCursorPosition(ix, iy++);
        std::cin >> major;
        iy++;
        SetCursorPosition(ix, iy++);
        std::cin >> identity;
        iy++;
        SetCursorPosition(ix, iy++);
        std::cin >> validity_date;
        iy++;
        SetCursorPosition(ix, iy++);
        std::cin >> student_id;
        iy++;
        SetCursorPosition(ix + 2, iy++);
        std::cin >> card_id;


    }
    bool verify()
    {
        if (name.size() < 3 || name.size() > 10)
        {
            std::cout << "����������������������룡" ;
            return false;
        }
        return true;
    }
    int Select()
    {
        SetColor(11, 8);
        SetCursorPosition(76, 26);
        std::cout << "ȷ��¼��" ;

        int ch;
        int tmp_key = 1;
        bool flag = false;
        while ((ch = getch()))
        {
            switch((ch = getch()))
            {
            case 75://LEFT
                if (tmp_key > 1)
                {
                    SetColor(11, 8);
                    SetCursorPosition(76, 26);
                    std::cout << "ȷ��¼��" ;

                    SetColor(11);
                    SetCursorPosition(88, 26);
                    std::cout << "ȡ��" ;

                    --tmp_key;
                }
                break;
            case 72://UP
                if (tmp_key > 1)
                {
                    SetColor(11, 8);
                    SetCursorPosition(76, 26);
                    std::cout << "ȷ��¼��" ;

                    SetColor(11);
                    SetCursorPosition(88, 26);
                    std::cout << "ȡ��" ;

                    --tmp_key;
                }
                break;
            case 77://RIGHT
                if (tmp_key < 2)
                {
                    SetColor(11, 8);
                    SetCursorPosition(88, 26);
                    std::cout << "ȡ��" ;

                    SetColor(11);
                    SetCursorPosition(76, 26);
                    std::cout << "ȷ��¼��" ;

                    ++tmp_key;
                }
                break;
            case 80://DOWN
                if (tmp_key < 2)
                {
                    SetColor(11, 8);
                    SetCursorPosition(88, 26);
                    std::cout << "ȡ��" ;

                    SetColor(11);
                    SetCursorPosition(76, 26);
                    std::cout << "ȷ��¼��" ;

                    ++tmp_key;
                }
                break;
            case 13:
                flag = true;
                break;
            default:
                break;
            }
            if (flag == true)
                break;
        }
        verify();
        switch (tmp_key)
        {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        }
        return 0;
    }
private:
    int x;
    int y;
    int w;
    int h;
    string name;
    string sex;
    string college;
    string major;
    string identity;
    string validity_date;
    string student_id;
    string card_id;
};
#endif // INPUT_H
