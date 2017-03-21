#ifndef USERS_H
#define USERS_H

#include <fstream>
#include <sstream>

class Users
{
public:
    Users() : x(32), y(11), w(20), h(11), permission_(0) { }
    void Draw()
    {
        ClearScreen(x, y, w, h);
        int tx = x;
        int ty = y;
        SetColor(11);
        SetCursorPosition(tx, ty);
        for(int i = 0; i < w; i++)
        {
            std::cout << "��" ;
        }
        for (int i = 0; i < h; i++)
        {
            SetCursorPosition(tx - 1, ++ty);
            std::cout << "��" ;
            SetCursorPosition(tx - 1 + w * 2, ty);
            std::cout << "��" ;
        }
        SetCursorPosition(tx, ++ty);
        for(int i = 0; i < w; i++)
        {
            std::cout << "��" ;
        }

        SetCursorPosition(x + 17, y + 2);
        std::cout << "���¼" ;

        SetCursorPosition(x + 7, y + 5);
        std::cout << "�˺ţ�" ;
        SetCursorPosition(x + 13, y + 6);
        std::cout << "һһһһһһһһ" ;
        SetCursorPosition(x + 7, y + 7);
        std::cout << "���룺" ;
        SetCursorPosition(x + 13, y + 8);
        std::cout << "һһһһһһһһ" ;


        SetCursorPosition(x + 10, y + 10);
        std::cout << "��¼" ;
        SetCursorPosition(x + 25, y + 10);
        std::cout << "�˳�" ;
    }
    void inputPassword()//�������벢����*Ϊ����
    {
        string psw;
        int length = 0;

        char temp_c;
        while(true)
        {
            temp_c = getch();  //����һ���ַ�
            if(temp_c != char(13))  //�жϸ��ַ��ǲ�Ϊ�س�����������˳�while
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
                    std::cout<<"*"; //��������ϲ���������ַ������Ϊcout<<"";���޻���
                    psw += temp_c;//�����ַ�����
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
        std::cin >> name_ ;

        SetCursorPosition(x + 14, y + 7);
        inputPassword();

        SetColor(11, 8);
        SetCursorPosition(x + 10, y + 10);
        std::cout << "��¼" ;
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
                    SetCursorPosition(x + 10, y + 10);
                    std::cout << "��¼" ;

                    SetColor(11);
                    SetCursorPosition(x + 25, y + 10);
                    std::cout << "�˳�" ;

                    --tmp_key;
                }
                break;
            case 72://UP
                if (tmp_key > 1)
                {
                    SetColor(11, 8);
                    SetCursorPosition(x + 10, y + 10);
                    std::cout << "��¼" ;

                    SetColor(11);
                    SetCursorPosition(x + 25, y + 10);
                    std::cout << "�˳�" ;

                    --tmp_key;
                }
                break;
            case 77://RIGHT
                if (tmp_key < 2)
                {
                    SetColor(11);
                    SetCursorPosition(x + 10, y + 10);
                    std::cout << "��¼" ;

                    SetColor(11, 8);
                    SetCursorPosition(x + 25, y + 10);
                    std::cout << "�˳�" ;

                    ++tmp_key;
                }
                break;
            case 80://DOWN
                if (tmp_key < 2)
                {
                    SetColor(11);
                    SetCursorPosition(x + 10, y + 10);
                    std::cout << "��¼" ;

                    SetColor(11, 8);
                    SetCursorPosition(x + 25, y + 10);
                    std::cout << "�˳�" ;

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
    bool Verify()
    {
        std::ifstream fin;
        std::string line;

        fin.open("user_data.txt");
        if (!fin.is_open())
        {
            std::cout << "�޷��������ݣ�" << std::endl;
            return 0;
        }
        else ;
        while (std::getline(fin, line))
        {
            std::istringstream record(line);
            string tmp_name, tmp_psw;
            int tmp_per;
            record >> tmp_name >> tmp_psw >> tmp_per ;

            if (tmp_name == name_ && tmp_psw == password_)
            {
                permission_ = tmp_per;
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
                    return true;
                }
                else
                {
                    ClearScreen(x + 2, y + 1, w - 4, h - 2);
                    SetCursorPosition(x + 8, y + 6);
                    std::cout << "�û��������ڻ��������" ;
                    Sleep(3000);

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
    string password_;

};
#endif // USERS_H
