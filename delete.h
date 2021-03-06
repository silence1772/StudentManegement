#ifndef DELETE_H
#define DELETE_H

class Delete
{
public:
    Delete() : x(45), y(13), w(20), h(8) { }
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

        SetCursorPosition(x + 6, y + 2);
        std::cout << "请输入要删除的学生学号：" ;
        SetCursorPosition(x + 12, y + 5);
        std::cout << "一一一一一一一" ;

        SetCursorPosition(x + 9, y + 7);
        std::cout << "查询            取消" ;
    }
    void InputInfo()
    {
        SetCursorPosition(x + 13, y + 4);
        std::cin >> student_id_ ;

        SetColor(11, 8);
        SetCursorPosition(x + 9, y + 7);
        std::cout << "查找" ;
        SetCursorPosition(0, 35);
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
                    std::cout << "查找" ;

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
                    std::cout << "查找" ;

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
                    std::cout << "查找" ;

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
                    std::cout << "查找" ;

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
    int Verify()
    {
        if(student_id_.size() == 12)
            return 1;
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
            std::cout << "输入的学号不存在！" ;

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
                return 2;
                break;
            case 2:
                return 3;
                break;
            }
            return 3;
        }
        return 0;
    }
    void DeleteInfo()
    {
        IDCardList *L = new IDCardList();
        FileIO *fp = new FileIO();
        fp->read(L);


        if (L->Find(student_id_))
        {
            if(Confirm())
            {
                L->Delete(student_id_);
                fp->write(L);
            }
            ClearScreen(30, 6, 36, 26);
        }
        else
        {
            ClearScreen(30, 6, 36, 26);
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
            SetCursorPosition(0, 35);
            Sleep(1000);
            ClearScreen(30, 6, 36, 26);
        }
    }
    bool Confirm()
    {
        ClearScreen(x, y, w, h);
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

        SetCursorPosition(x + 10, y + 3);
        std::cout << "是否删除该学生信息？" ;

        SetCursorPosition(x + 24, y + 7);
        std::cout << "取消" ;
        SetColor(11, 8);
        SetCursorPosition(x + 9, y + 7);
        std::cout << "确认删除" ;
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
                    SetColor(11, 8);
                    SetCursorPosition(x + 9, y + 7);
                    std::cout << "确认删除" ;

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
                    std::cout << "确认删除" ;

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
                    std::cout << "确认删除" ;

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
                    std::cout << "确认删除" ;

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
            SetCursorPosition(0, 35);
        }

        switch (tmp_key)
        {
        case 1:
            ClearScreen(x+2, y+1, w-4, h-2);
            SetColor(11);
            SetCursorPosition(x + 16, y + 4);
            std::cout << "删除成功！" ;
            Sleep(3000);
            ClearScreen(30, 6, 36, 26);
            return true;
            break;
        case 2:
            ClearScreen(30, 6, 36, 26);
            return false;
            break;
        }
        return false;


        return false;
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
                    DeleteInfo();
                    flag = false;
                    break;
                case 2:
                    ClearScreen(x, y, w, h);
                    break;
                case 3:
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
    }
private:
    int x;
    int y;
    int w;
    int h;
    string student_id_;
};
#endif // DELETE_H
