#ifndef QUERY_H
#define QUERY_H

#include "file_io.h"
#include <windows.h>

class Query
{
public:
    Query() : x(45), y(13), w(20), h(8) { }
    Query(string id) : x(45), y(13), w(20), h(8), id_(id) { }
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

        SetCursorPosition(x + 3, y + 2);
        std::cout << "请输入要查询的学生学号或班级编号：" ;
        SetCursorPosition(x + 12, y + 5);
        std::cout << "一一一一一一一" ;

        SetCursorPosition(x + 9, y + 7);
        std::cout << "查询            取消" ;
    }
    void InputInfo()
    {
        SetCursorPosition(x + 13, y + 4);
        std::cin >> id_ ;

        SetColor(11, 8);
        SetCursorPosition(x + 9, y + 7);
        std::cout << "查询" ;
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
                    SetCursorPosition(x + 9, y + 7);
                    std::cout << "查询" ;

                    SetColor(11);
                    SetCursorPosition(x + 24, y + 7);
                    std::cout << "取消" ;

                    --tmp_key;
                }
                break;
            case 72://UP
                if (tmp_key > 1)
                {
                    SetColor(11, 8);
                    SetCursorPosition(x + 9, y + 7);
                    std::cout << "查询" ;

                    SetColor(11);
                    SetCursorPosition(x + 24, y + 7);
                    std::cout << "取消" ;

                    --tmp_key;
                }
                break;
            case 77://RIGHT
                if (tmp_key < 2)
                {
                    SetColor(11);
                    SetCursorPosition(x + 9, y + 7);
                    std::cout << "查询" ;

                    SetColor(11, 8);
                    SetCursorPosition(x + 24, y + 7);
                    std::cout << "取消" ;

                    ++tmp_key;
                }
                break;
            case 80://DOWN
                if (tmp_key < 2)
                {
                    SetColor(11);
                    SetCursorPosition(x + 9, y + 7);
                    std::cout << "查询" ;

                    SetColor(11, 8);
                    SetCursorPosition(x + 24, y + 7);
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
    int Verify()
    {
        if(id_.size() == 12)
            return 1;
        else if (id_.size() == 6)
            return 2;
        else
        {
            ClearScreen(30, 6, 36, 26);
            int ix = x;
            int iy = y;
            int iw = w;
            int ih = h;

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

            SetColor(11);
            SetCursorPosition(ix + 10, iy - 6);
            std::cout << "学号或班级编号不存在！" ;

            SetColor(5, 11);
            SetCursorPosition(ix + 8, iy - 3);
            std::cout << "重新输入" ;
            SetColor(11);
            SetCursorPosition(ix + 28, iy - 3);
            std::cout << "取消" ;




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
            }

            switch (tmp_key)
            {
            case 1:
                return 3;
                break;
            case 2:
                return 4;
                break;
            }
            return 4;
        }
        return 0;
    }
    void FindByStuID()
    {
        IDCardList *L = new IDCardList();
        FileIO *fp = new FileIO();
        fp->read(L);
        delete fp;

        IDCard *ptr;
        ptr = L->head_;
        while (ptr != NULL)
        {
            if (ptr->GetStudentID() == id_)
            {
                SetColor(11);
                SetCursorPosition(32, 6);
                std::cout << "---------------------------------------------------" ;
                ptr->PrintInfo(32, 7);
                return;
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

        SetCursorPosition(tx + 16, ty - 5);
        std::cout << "无记录！" ;
        Sleep(3000);
        ClearScreen(30, 6, 36, 26);
    }
    void FindByClassID()
    {
        IDCardList *L = new IDCardList();
        FileIO *fp = new FileIO();
        fp->read(L);
        delete fp;

        int cnt = 0;
        IDCard *ptr;
        IDCardList *tL = new IDCardList();
        ptr = L->head_;
        while (ptr != NULL)
        {
            if (ptr->GetClassID() == id_)
            {
                IDCard *node = new IDCard(ptr->GetName(), ptr->GetSex(), ptr->GetCollege(), ptr->GetMajor(), ptr->GetIdentity(),
                                          ptr->GetValidity_date(), ptr->GetStudentID(), ptr->GetCard_id());
                tL->Insert(node);
                ++cnt;
                /*
                SetCursorPosition(32, 6);
                std::cout << "---------------------------------------------------" ;
                ptr->PrintInfo(32, 7);
                return 1;*/
            }
            ptr = ptr->next_;
        }

        if (cnt <= 4)
        {
            SetColor(11);
            SetCursorPosition(32, 6);
            std::cout << "---------------------------------------------------" ;

            int i = 0;
            ptr = tL->head_;
            while (ptr != NULL)
            {
                ptr->PrintInfo(32, 7 + i * 6);
                ++i;
                ptr = ptr->next_;
            }

            SetCursorPosition(60, 32);
            std::cout << "1/1页" ;
        }
        else
        {
            SetColor(11);
            SetCursorPosition(32, 6);
            std::cout << "---------------------------------------------------" ;

            int i = 0;
            ptr = tL->head_;
            while (ptr != NULL)
            {
                ptr->PrintInfo(32, 7 + i * 6);
                ptr = ptr->next_;
                if (++i >= 4)
                    break;
            }

            SetCursorPosition(60, 32);
            int sum = (cnt % 4 == 0 ? cnt / 4 : cnt / 4 + 1);
            std::cout << "1/" << sum << "页" ;

            int ch;
            int tmp_key = 1;
            bool flag = false;
            while ((ch = getch()))
            {
                switch(ch)
                {
                case 75:
                    if (tmp_key > 1)
                    {
                        ClearScreen(30, 7, 36, 26);
                        ptr = tL->head_;
                        i = 1;
                        while (i < tmp_key - 1)
                        {
                            for (int j = 0; j < 4 && ptr != NULL; ++j)
                                ptr = ptr->next_;
                            ++i;
                        }
                        for (i = 0; i < 4 && ptr != NULL; ++i)
                        {
                            ptr->PrintInfo(32, 7 + i * 6);
                            ptr = ptr->next_;
                        }
                        SetCursorPosition(60, 32);
                        std::cout << tmp_key - 1 << "/" << sum << "页" ;
                        --tmp_key;
                    }

                    break;
                case 72:
                    if (tmp_key > 1)
                    {
                        ClearScreen(30, 7, 36, 26);
                        ptr = tL->head_;
                        i = 1;
                        while (i < tmp_key - 1)
                        {
                            for (int j = 0; j < 4 && ptr != NULL; ++j)
                                ptr = ptr->next_;
                            ++i;
                        }
                        for (i = 0; i < 4 && ptr != NULL; ++i)
                        {
                            ptr->PrintInfo(32, 7 + i * 6);
                            ptr = ptr->next_;
                        }
                        SetCursorPosition(60, 32);
                        std::cout << tmp_key - 1 << "/" << sum << "页" ;
                        --tmp_key;
                    }

                    break;
                case 77:
                    if (tmp_key < sum)
                    {
                        ClearScreen(30, 7, 36, 26);
                        ptr = tL->head_;
                        i = 1;
                        while (i < tmp_key + 1)
                        {
                            for (int j = 0; j < 4 && ptr != NULL; ++j)
                                ptr = ptr->next_;
                            ++i;
                        }
                        for (i = 0; i < 4 && ptr != NULL; ++i)
                        {
                            ptr->PrintInfo(32, 7 + i * 6);
                            ptr = ptr->next_;
                        }
                        SetCursorPosition(60, 32);
                        std::cout << tmp_key + 1 << "/" << sum << "页" ;
                        ++tmp_key;
                    }

                    break;
                case 80:
                    if (tmp_key < sum)
                    {
                        ClearScreen(30, 7, 36, 26);
                        ptr = tL->head_;
                        i = 1;
                        while (i < tmp_key + 1)
                        {
                            for (int j = 0; j < 4 && ptr != NULL; ++j)
                                ptr = ptr->next_;
                            ++i;
                        }
                        for (i = 0; i < 4 && ptr != NULL; ++i)
                        {
                            ptr->PrintInfo(32, 7 + i * 6);
                            ptr = ptr->next_;
                        }
                        SetCursorPosition(60, 32);
                        std::cout << tmp_key + 1 << "/" << sum << "页" ;
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

        }
    }
    void Start()
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
                case 1:
                    ClearScreen(30, 6, 36, 26);
                    FindByStuID();
                    flag = false;
                    break;
                case 2:
                    ClearScreen(30, 6, 36, 26);
                    FindByClassID();
                    flag = false;
                    break;
                case 3:
                    ClearScreen(30, 6, 36, 26);
                    break;
                case 4:
                    ClearScreen(30, 6, 36, 26);
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
    }
private:
    int x;
    int y;
    int w;
    int h;
    string id_;
};
#endif // QUERY_H
