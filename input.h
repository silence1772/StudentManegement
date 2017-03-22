#ifndef INPUT_H
#define INPUT_H

#include "file_io.h"
#include "tools.h"
#include <windows.h>

class Input
{
public:
    Input() : x(36), y(10), w(30), h(19) { }
    void Draw()
    {
        int tx = x;
        int ty = y;
        SetColor(11);
        SetCursorPosition(tx, ty);
        for(int i = 0; i < w; i++)
        {
            std::cout << "━" ;
        }
        for (int i = 0; i < h; i++)
        {
            SetCursorPosition(tx - 1, ++ty);
            std::cout << "┃" ;
            SetCursorPosition(tx - 1 + w * 2, ty);
            std::cout << "┃" ;
        }
        SetCursorPosition(tx, ++ty);
        for(int i = 0; i < w; i++)
        {
            std::cout << "━" ;
        }

        int ix = x + 2;
        int iy = y + 4;
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
        std::cout << "有效期：    年  月  日" ;
        SetCursorPosition(ix + 6, iy++);
        std::cout << "一一一一一一一一" ;

        SetCursorPosition(x + 40, y + 16);
        std::cout << "确认录入" ;
        SetCursorPosition(x + 52, y + 16);
        std::cout << "取消" ;

        SetCursorPosition(x + 34, y + 5);
        std::cout << "日期格式：20xx年xx月xx日" ;
        SetCursorPosition(x + 34, y + 7);
        std::cout << "输入后按回车键进入下一行" ;


    }
    void Draw(string student_id_)
    {
        IDCardList *L = new IDCardList();
        FileIO *fp = new FileIO();
        fp->read(L);
        delete fp;

        IDCard *ptr;
        ptr = L->head_;
        while (ptr != NULL)
        {
            if (ptr->GetStudentID() == student_id_)
            {
                SetColor(8);
                SetCursorPosition(44, 14);
                std::cout << ptr->GetName();
                SetCursorPosition(44, 16);
                std::cout << ptr->GetSex();
                SetCursorPosition(44, 18);
                std::cout << ptr->GetCollege();
                SetCursorPosition(44, 20);
                std::cout << ptr->GetMajor();
                SetCursorPosition(44, 22);
                std::cout << ptr->GetIdentity();
                SetCursorPosition(44, 24);
                std::cout << ptr->GetStudentID();
                SetCursorPosition(44, 26);
                std::cout << ptr->GetCardID();
                SetColor(7);
                SetCursorPosition(70, 21);
                std::cout << "请输入修改后的信息" ;

                break;
            }
            else
                ptr = ptr->next_;
        }


        int tx = x;
        int ty = y;
        SetColor(11);
        SetCursorPosition(tx, ty);
        for(int i = 0; i < w; i++)
        {
            std::cout << "━" ;
        }
        for (int i = 0; i < h; i++)
        {
            SetCursorPosition(tx - 1, ++ty);
            std::cout << "┃" ;
            SetCursorPosition(tx - 1 + w * 2, ty);
            std::cout << "┃" ;
        }
        SetCursorPosition(tx, ++ty);
        for(int i = 0; i < w; i++)
        {
            std::cout << "━" ;
        }

        int ix = x + 2;
        int iy = y + 4;
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
        std::cout << "有效期：    年  月  日" ;
        SetCursorPosition(ix + 6, iy++);
        std::cout << "一一一一一一一一" ;

        SetCursorPosition(x + 40, y + 16);
        std::cout << "确认录入" ;
        SetCursorPosition(x + 52, y + 16);
        std::cout << "取消" ;

        SetCursorPosition(x + 34, y + 5);
        std::cout << "日期格式：20xx年xx月xx日" ;
        SetCursorPosition(x + 34, y + 7);
        std::cout << "输入后按回车键进入下一行" ;


    }
    void InputInfo()
    {
        int ix = x + 8;
        int iy = y + 4;
        //freopen("test.txt","r", stdin);
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
        std::cin >> student_id;
        iy++;
        SetCursorPosition(ix, iy++);
        std::cin >> card_id;
        iy++;
        SetCursorPosition(ix + 2, iy);
        std::cin >> year;
        SetCursorPosition(ix + 8, iy);
        std::cin >> month;
        SetCursorPosition(ix + 12, iy);
        std::cin >> day;
        validity_date = year + "年" + month + "月" + day + "日" ;

        SetColor(11, 8);
        SetCursorPosition(x + 40, y + 16);
        std::cout << "确认录入" ;
        SetCursorPosition(0, 35);
    }
    int Verify()
    {
        int ix = x + 10;
        int iy = y + 5;
        int iw = w - 10;
        int ih = h - 10;

        if (name.size() < 3 || name.size() > 10)
        {
            ClearScreen(ix, iy, iw, ih);
            SetCursorPosition(x + 18, y + 9);
            std::cout << "输入的姓名有误，请重新输入！" ;
        }
        else if (sex != "男" && sex != "女")
        {
            ClearScreen(ix, iy, iw, ih);
            SetCursorPosition(x + 18, y + 9);
            std::cout << "输入的性别有误，请重新输入！" ;
        }
        else if (college.size() < 6 || college.size() > 14)
        {
            ClearScreen(ix, iy, iw, ih);
            SetCursorPosition(x + 18, y + 9);
            std::cout << "输入的学院有误，请重新输入！" ;
        }
        else if (major.size() < 4 || major.size() > 20)
        {
            ClearScreen(ix, iy, iw, ih);
            SetCursorPosition(x + 18, y + 9);
            std::cout << "输入的专业有误，请重新输入！" ;
        }
        else if (identity != "本科生" && identity != "研究生")
        {
            ClearScreen(ix, iy, iw, ih);
            SetCursorPosition(x + 18, y + 9);
            std::cout << "输入的身份有误，请重新输入！" ;
        }
        else if (student_id.size() != 12)
        {
            ClearScreen(ix, iy, iw, ih);
            SetCursorPosition(x + 18, y + 9);
            std::cout << "输入的学号有误，请重新输入！" ;
        }
        else if (card_id.size() != 6)
        {
            ClearScreen(ix, iy, iw, ih);
            SetCursorPosition(x + 18, y + 9);
            std::cout << "输入的卡号有误，请重新输入！" ;
        }
        else if (year.size() != 4 || month.size() != 2 || day.size() != 2)
        {
            ClearScreen(ix, iy, iw, ih);
            SetCursorPosition(x + 18, y + 9);
            std::cout << "输入的日期有误，请重新输入！" ;
        }
        else
        {
            return 0;
        }



        SetColor(11);
        SetCursorPosition(ix, iy);
        for(int i = 0; i < iw; i++)
        {
            std::cout << "━" ;
        }
        for (int i = 0; i < ih; i++)
        {
            SetCursorPosition(ix - 1, ++iy);
            std::cout << "┃" ;
            SetCursorPosition(ix - 1 + iw * 2, iy);
            std::cout << "┃" ;
        }
        SetCursorPosition(ix, ++iy);
        for(int i = 0; i < iw; i++)
        {
            std::cout << "━" ;
        }

        SetColor(5, 11);
        SetCursorPosition(ix + 8, iy - 3);
        std::cout << "重新输入" ;
        SetColor(11);
        SetCursorPosition(ix + 28, iy - 3);
        std::cout << "取消" ;
        SetCursorPosition(0, 35);



        int ch;
        int tmp_key = 1;
        bool flag = false;
        while ((ch = getch()))
        {
            switch(ch)
            {
            case 75://LEFT
                if (tmp_key > 1)
                {
                    SetColor(5, 11);
                    SetCursorPosition(ix + 8, iy - 3);
                    std::cout << "重新输入" ;

                    SetColor(11);
                    SetCursorPosition(ix + 28, iy - 3);
                    std::cout << "取消" ;

                    --tmp_key;
                }
                break;
            case 72://UP
                if (tmp_key > 1)
                {
                    SetColor(5, 11);
                    SetCursorPosition(ix + 8, iy - 3);
                    std::cout << "重新输入" ;

                    SetColor(11);
                    SetCursorPosition(ix + 28, iy - 3);
                    std::cout << "取消" ;

                    --tmp_key;
                }
                break;
            case 77://RIGHT
                if (tmp_key < 2)
                {
                    SetColor(11);
                    SetCursorPosition(ix + 8, iy - 3);
                    std::cout << "重新输入" ;

                    SetColor(5, 11);
                    SetCursorPosition(ix + 28, iy - 3);
                    std::cout << "取消" ;

                    ++tmp_key;
                }
                break;
            case 80://DOWN
                if (tmp_key < 2)
                {
                    SetColor(11);
                    SetCursorPosition(ix + 8, iy - 3);
                    std::cout << "重新输入" ;

                    SetColor(5, 11);
                    SetCursorPosition(ix + 28, iy - 3);
                    std::cout << "取消" ;

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
            SetCursorPosition(0, 35);
        }

        switch (tmp_key)
        {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        }
        return 2;
    }
    int Select()
    {
        int ch;
        int tmp_key = 1;
        bool flag = false;
        while ((ch = getch()))
        {
            switch(ch)
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
            SetCursorPosition(0, 35);
        }

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
    void Submit()
    {
        ClearScreen(x, y, w, h);

        FileIO *fp = new FileIO();
        IDCard *node = new IDCard(name, sex, college, major, identity, validity_date, student_id, card_id);
        SetColor(11);
        SetCursorPosition(32, 6);
        std::cout << "---------------------------------------------------" ;
        node->PrintInfo(32, 7);
        fp->add(node);
        delete fp;


        int tx = x + 14;
        int ty = y + 5;
        int tw = 10;
        int th = 6;
        SetColor(11);
        SetCursorPosition(tx, ty);
        for(int i = 0; i < tw; i++)
        {
            std::cout << "━" ;
        }
        for (int i = 0; i < th; i++)
        {
            SetCursorPosition(tx - 1, ++ty);
            std::cout << "┃" ;
            SetCursorPosition(tx - 1 + tw * 2, ty);
            std::cout << "┃" ;
        }
        SetCursorPosition(tx, ++ty);
        for(int i = 0; i < tw; i++)
        {
            std::cout << "━" ;
        }

        SetCursorPosition(tx + 5, ty - 4);
        std::cout << "录入成功！" ;
        SetCursorPosition(0, 35);
        Sleep(3000);
        ClearScreen(tx, ty - th - 1, tw, th);

    }
    void Submit(string student_id_)
    {
        ClearScreen(x, y, w, h);

        FileIO *fp = new FileIO();
        IDCardList *L = new IDCardList();
        fp->read(L);
        IDCard *node = new IDCard(name, sex, college, major, identity, validity_date, student_id, card_id);

        SetColor(11);
        SetCursorPosition(32, 6);
        std::cout << "---------------------------------------------------" ;
        node->PrintInfo(32, 7);
        L->Delete(student_id_);
        fp->write(L);
        fp->add(node);
        delete fp;


        int tx = x + 14;
        int ty = y + 5;
        int tw = 10;
        int th = 6;
        SetColor(11);
        SetCursorPosition(tx, ty);
        for(int i = 0; i < tw; i++)
        {
            std::cout << "━" ;
        }
        for (int i = 0; i < th; i++)
        {
            SetCursorPosition(tx - 1, ++ty);
            std::cout << "┃" ;
            SetCursorPosition(tx - 1 + tw * 2, ty);
            std::cout << "┃" ;
        }
        SetCursorPosition(tx, ++ty);
        for(int i = 0; i < tw; i++)
        {
            std::cout << "━" ;
        }

        SetCursorPosition(tx + 5, ty - 4);
        std::cout << "录入成功！" ;
        Sleep(3000);
        ClearScreen(tx, ty - th - 1, tw, th);

    }
    bool Start()
    {
        ClearScreen(30, 6, 36, 26);
        bool flag = true;
        while (flag)
        {
            Draw();
            InputInfo();
            int option = Select();
            if (option == 1)
            {
                switch(Verify())
                {
                case 0:
                    Submit();
                    flag = false;
                    return true;
                case 1:
                    ClearScreen(x, y, w, h);
                    break;
                case 2:
                    ClearScreen(x, y, w, h);
                    flag = false;
                    break;
                }
            }
            else
            {
                ClearScreen(x, y, w, h);
                flag = false;
            }
        }
        return false;
    }
    bool Start(string student_id_)
    {
        ClearScreen(30, 6, 36, 26);
        bool flag = true;
        while (flag)
        {
            Draw(student_id_);
            InputInfo();
            int option = Select();
            if (option == 1)
            {
                switch(Verify())
                {
                case 0:
                    Submit(student_id_);
                    flag = false;
                    return true;
                case 1:
                    ClearScreen(x, y, w, h);
                    break;
                case 2:
                    ClearScreen(x, y, w, h);
                    flag = false;
                    break;
                }
            }
            else
            {
                ClearScreen(x, y, w, h);
                flag = false;
            }
        }
        return false;
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
    string student_id;
    string card_id;
    string validity_date;
    string year;
    string month;
    string day;
};
#endif // INPUT_H
