#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics
{
public:
    Statistics() : x(45), y(13), w(20), h(8), boy_sum_(0), girl_sum_(0) { }
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

        SetColor(11, 8);
        SetCursorPosition(x + 19, y + 7);
        std::cout << "返回" ;
    }
    void Done()
    {
        IDCardList *L = new IDCardList();
        FileIO *fp = new FileIO();
        fp->read(L);
        delete fp;

        IDCard *ptr;
        ptr = L->head_;
        while (ptr != NULL)
        {
            if (ptr->GetSex() == "男")
            {
                ++boy_sum_;
            }
            else
            {
                ++girl_sum_;
            }
            ptr = ptr->next_;
        }
    }
    void Start()
    {
        Draw();
        Done();
        SetColor(11);
        SetCursorPosition(x + 10, y + 2);
        std::cout << "男生人数：" << boy_sum_ ;
        SetCursorPosition(x + 10, y + 4);
        std::cout << "女生人数：" << girl_sum_;

        int ch;
        bool flag = false;
        while ((ch = getch()))
        {
            switch(ch)
            {
            case 13:
                flag = true;
                break;
            default:
                break;
            }

            if(flag)
                break;
        }
    }
private:
    int x;
    int y;
    int w;
    int h;
    int boy_sum_;
    int girl_sum_;
};
#endif // STATISTICS_H
