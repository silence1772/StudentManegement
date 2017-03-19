#ifndef QUERY_H
#define QUERY_H

#include "file_io.h"

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
            int ix = x + 10;
            int iy = y + 5;
            int iw = w - 10;
            int ih = h - 10;
        }
    }
    int FindByStuID()
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
                return 1;
            }
            else
                ptr = ptr->next_;
        }
        return 2;
    }
    int FindByClassID()
    {

    }
private:
    int x;
    int y;
    int w;
    int h;
    string id_;
};
#endif // QUERY_H
