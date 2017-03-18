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
            std::cout << "━" ;
        }
        for (int i = 0; i < h; i++)
        {
            SetCursorPosition(x - 1, ++y);
            std::cout << "┃" ;
            SetCursorPosition(x - 1 + w * 2, y);
            std::cout << "┃" ;
        }
        SetCursorPosition(x, ++y);
        for(int i = 0; i < w; i++)
        {
            std::cout << "━" ;
        }

        int ix = x + 2;
        int iy = y - 16;
        SetCursorPosition(ix + 20, iy - 2);
        std::cout << "请输入学生证信息" ;
        SetCursorPosition(ix, iy++);
        std::cout << "姓名：" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "一一一一" ;
        SetCursorPosition(ix, iy++);
        std::cout << "性别：" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "一一" ;
        SetCursorPosition(ix, iy++);
        std::cout << "学院：" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "一一一一一一一一" ;
        SetCursorPosition(ix, iy++);
        std::cout << "专业：" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "一一一一一一一一一" ;
        SetCursorPosition(ix, iy++);
        std::cout << "身份：" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "一一一一" ;
        SetCursorPosition(ix, iy++);
        std::cout << "学号：" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "一一一一一一一" ;
        SetCursorPosition(ix, iy++);
        std::cout << "卡号：" ;
        SetCursorPosition(ix + 5, iy++);
        std::cout << "一一一一" ;
        SetCursorPosition(ix, iy++);
        std::cout << "有效期：" ;
        SetCursorPosition(ix + 6, iy++);
        std::cout << "一一一一一一一一" ;

        SetCursorPosition(76, 26);
        std::cout << "确认录入" ;
        SetCursorPosition(88, 26);
        std::cout << "取消" ;

        SetCursorPosition(70, 15);
        std::cout << "日期格式：20xx年xx月xx日" ;
        SetCursorPosition(70, 17);
        std::cout << "输入后按回车键进入下一行" ;
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
            std::cout << "输入的姓名有误，请重新输入！" ;
            return false;
        }
        return true;
    }
    int Select()
    {
        SetColor(11, 8);
        SetCursorPosition(76, 26);
        std::cout << "确认录入" ;

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
                    std::cout << "确认录入" ;

                    SetColor(11);
                    SetCursorPosition(88, 26);
                    std::cout << "取消" ;

                    --tmp_key;
                }
                break;
            case 72://UP
                if (tmp_key > 1)
                {
                    SetColor(11, 8);
                    SetCursorPosition(76, 26);
                    std::cout << "确认录入" ;

                    SetColor(11);
                    SetCursorPosition(88, 26);
                    std::cout << "取消" ;

                    --tmp_key;
                }
                break;
            case 77://RIGHT
                if (tmp_key < 2)
                {
                    SetColor(11, 8);
                    SetCursorPosition(88, 26);
                    std::cout << "取消" ;

                    SetColor(11);
                    SetCursorPosition(76, 26);
                    std::cout << "确认录入" ;

                    ++tmp_key;
                }
                break;
            case 80://DOWN
                if (tmp_key < 2)
                {
                    SetColor(11, 8);
                    SetCursorPosition(88, 26);
                    std::cout << "取消" ;

                    SetColor(11);
                    SetCursorPosition(76, 26);
                    std::cout << "确认录入" ;

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
