#ifndef USERS_H
#define USERS_H

#include <fstream>
#include <sstream>

class Users
{
public:
    Users() : x(32), y(11), w(20), h(11), permission_(0) { }
    int GetPms()
    {
        return permission_;
    }
    string GetName()
    {
        return name_;
    }
    string GetId()
    {
        return id_;
    }
    void Draw()
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

        SetCursorPosition(x + 17, y + 2);
        std::cout << "请登录" ;

        SetCursorPosition(x + 7, y + 5);
        std::cout << "账号：" ;
        SetCursorPosition(x + 13, y + 6);
        std::cout << "一一一一一一一一" ;
        SetCursorPosition(x + 7, y + 7);
        std::cout << "密码：" ;
        SetCursorPosition(x + 13, y + 8);
        std::cout << "一一一一一一一一" ;


        SetCursorPosition(x + 10, y + 10);
        std::cout << "登录" ;
        SetCursorPosition(x + 25, y + 10);
        std::cout << "退出" ;
    }
    void inputPassword()//用于输入并回显*为密码
    {
        string psw;
        int length = 0;

        char temp_c;
        while(true)
        {
            temp_c = getch();  //输入一个字符
            if(temp_c != char(13))  //判断该字符是不为回车，如果是则退出while
            {
                switch  (temp_c)
                {
                case 8:
                    if(length != 0)
                    {
                        std::cout << "\b \b";
                        psw = psw.substr(0,length-1);
                        length--;
                    }
                    else ;
                    break;
                default:
                    std::cout<<"*"; //可用用你喜欢的任意字符，如改为cout<<"";则无回显
                    psw += temp_c;//连成字符串；
                    length++;
                    break;
                }
            }
            else break;
        }
        password_ = psw;
    }
    void InputInfo()
    {
        SetCursorPosition(x + 14, y + 5);
        std::cin >> id_ ;

        SetCursorPosition(x + 14, y + 7);
        inputPassword();

        SetColor(11, 8);
        SetCursorPosition(x + 10, y + 10);
        std::cout << "登录" ;
    }
    int Select()
    {
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
                    SetCursorPosition(x + 10, y + 10);
                    std::cout << "登录" ;

                    SetColor(11);
                    SetCursorPosition(x + 25, y + 10);
                    std::cout << "退出" ;

                    --tmp_key;
                }
                break;
            case 72://UP
                if (tmp_key > 1)
                {
                    SetColor(11, 8);
                    SetCursorPosition(x + 10, y + 10);
                    std::cout << "登录" ;

                    SetColor(11);
                    SetCursorPosition(x + 25, y + 10);
                    std::cout << "退出" ;

                    --tmp_key;
                }
                break;
            case 77://RIGHT
                if (tmp_key < 2)
                {
                    SetColor(11);
                    SetCursorPosition(x + 10, y + 10);
                    std::cout << "登录" ;

                    SetColor(11, 8);
                    SetCursorPosition(x + 25, y + 10);
                    std::cout << "退出" ;

                    ++tmp_key;
                }
                break;
            case 80://DOWN
                if (tmp_key < 2)
                {
                    SetColor(11);
                    SetCursorPosition(x + 10, y + 10);
                    std::cout << "登录" ;

                    SetColor(11, 8);
                    SetCursorPosition(x + 25, y + 10);
                    std::cout << "退出" ;

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
    bool Verify()
    {
        std::ifstream fin;
        std::string line;

        fin.open("user_data.txt");
        if (!fin.is_open())
        {
            std::cout << "无法加载数据！" << std::endl;
            return 0;
        }
        else ;
        while (std::getline(fin, line))
        {
            std::istringstream record(line);
            string tmp_name, tmp_id, tmp_psw;
            int tmp_per;
            record >> tmp_name >> tmp_id >> tmp_psw >> tmp_per ;

            if (tmp_id == id_ && tmp_psw == password_)
            {
                permission_ = tmp_per;
                name_ = tmp_name;
                fin.close();
                return true;
            }
            else ;
        }

        fin.close();
        return false;
    }
    bool Start()
    {
        ClearScreen(30, 6, 36, 26);
        while (true)
        {
            Draw();
            InputInfo();
            int option = Select();
            if (option == 1)
            {
                if (Verify())
                {
                    ClearScreen(30, 6, 36, 26);
                    return true;
                }
                else
                {
                    ClearScreen(x + 2, y + 1, w - 4, h - 2);
                    SetCursorPosition(x + 8, y + 6);
                    SetColor(11);
                    std::cout << "用户名不存在或密码错误！" ;
                    SetCursorPosition(0, 35);
                    Sleep(2000);

                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }

private:
    int x;
    int y;
    int w;
    int h;
    int permission_;
    string name_;
    string id_;
    string password_;


};
#endif // USERS_H
