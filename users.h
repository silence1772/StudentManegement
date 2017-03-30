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
        std::cin >> id_ ;

        SetCursorPosition(x + 14, y + 7);
        inputPassword();

        SetColor(11, 8);
        SetCursorPosition(x + 10, y + 10);
        std::cout << "��¼" ;
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
            std::cout << "�޷��������ݣ�" << std::endl;
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
                    std::cout << "�û��������ڻ��������" ;
                    SetCursorPosition(0, 35);
                    Sleep(1000);

                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }
    void ResetPsw(string& password)
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
        password = psw;
    }
    void ModifyPsw(string psw)
    {
        typedef struct node
        {
            char name[38];
            char id[38];
            char password[38];
            int permission;
            struct node *next;
        }Node;

        Node *head, *p, *tail;
        head = (Node*)malloc(sizeof(Node));
        head->next = NULL;
        tail = head;

        FILE *fp;
        if ((fp = fopen("user_data.txt", "r")) == NULL )
        {
            std::cout << "�޷��������ݣ�" << std::endl;
            return ;
        }
        while (!feof(fp))
        {
            p = (Node*)malloc(sizeof(Node));
            fscanf(fp, "%s%s%s%d", p->name, p->id, p->password, &p->permission);

            if (!feof(fp))
            {
                p->next = NULL;
                tail->next = p;
                tail = p;
            }

        }
        fclose(fp);

        p = head->next;
        while (p != NULL)
        {
            if (p->id == id_)
            {
                const char *tmp = psw.c_str();
                strcpy(p->password, tmp);
                break;
            }
            p = p->next;
        }

        //FILE *fp;
        if ((fp = fopen("user_data.txt", "w")) == NULL )
        {
            std::cout << "�޷��������ݣ�" << std::endl;
            return ;
        }

        p = head->next;
        while (p != NULL)
        {
            fprintf(fp, "%s\t%s\t%s\t%d\n", p->name, p->id, p->password, p->permission);
            p = p->next;
        }
        fclose(fp);

        int x = 45;
        int y = 11;
        int tx = x;
        int ty = y;
        int w = 20;
        int h = 10;
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

        ClearScreen(46, 12, 16, 8);
        SetColor(11);
        SetCursorPosition(x + 16, y + 6);
        std::cout << "�޸ĳɹ���" ;

        SetCursorPosition(0, 35);
        Sleep(1000);
    }
    void SetPsw()
    {
        string old_psw,new_psw1,new_psw2;

        int x = 45;
        int y = 11;
        int tx = x;
        int ty = y;
        int w = 20;
        int h = 10;
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

        SetColor(11);
        SetCursorPosition(x + 1, y + 2);
        std::cout << "����������룺" ;
        SetCursorPosition(x + 1, y + 4);
        std::cout << "�����������룺" ;
        SetCursorPosition(x + 1, y + 6);
        std::cout << "�����������룺" ;
        SetCursorPosition(x + 8, y + 9);
        std::cout << "ȷ���޸�" ;
        SetCursorPosition(x + 27, y + 9);
        std::cout << "ȡ��" ;
        SetCursorPosition(0, 35);

        SetCursorPosition(x + 15, y + 2);
        ResetPsw(old_psw);
        SetCursorPosition(x + 15, y + 4);
        ResetPsw(new_psw1);
        SetCursorPosition(x + 15, y + 6);
        ResetPsw(new_psw2);
        SetColor(11, 8);
        SetCursorPosition(x + 8, y + 9);
        std::cout << "ȷ���޸�" ;
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
                    SetCursorPosition(x + 8, y + 9);
                    std::cout << "ȷ���޸�" ;

                    SetColor(11);
                    SetCursorPosition(x + 27, y + 9);
                    std::cout << "ȡ��" ;

                    --tmp_key;
                }
                break;
            case 72://UP
                if (tmp_key > 1)
                {
                    SetColor(11, 8);
                    SetCursorPosition(x + 8, y + 9);
                    std::cout << "ȷ���޸�" ;

                    SetColor(11);
                    SetCursorPosition(x + 27, y + 9);
                    std::cout << "ȡ��" ;

                    --tmp_key;
                }
                break;
            case 77://RIGHT
                if (tmp_key < 2)
                {
                    SetColor(11);
                    SetCursorPosition(x + 8, y + 9);
                    std::cout << "ȷ���޸�" ;

                    SetColor(11, 8);
                    SetCursorPosition(x + 27, y + 9);
                    std::cout << "ȡ��" ;

                    ++tmp_key;
                }
                break;
            case 80://DOWN
                if (tmp_key < 2)
                {
                    SetColor(11);
                    SetCursorPosition(x + 8, y + 9);
                    std::cout << "ȷ���޸�" ;

                    SetColor(11, 8);
                    SetCursorPosition(x + 27, y + 9);
                    std::cout << "ȡ��" ;

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
            //return 1;
            if (Verify2(old_psw, new_psw1, new_psw2))
                ModifyPsw(new_psw1);
            break;
        case 2:
            break;
        }
        ClearScreen(30, 6, 36, 26);
    }
    bool Verify2(string old_psw, string new_psw1, string new_psw2)
    {
        if (old_psw == password_ && new_psw1 == new_psw2)
        {
            return true;
        }
        else
        {
            ClearScreen(30, 6, 36, 26);
            int x = 45;
            int y = 11;
            int tx = x;
            int ty = y;
            int w = 20;
            int h = 10;
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

            SetColor(11);
            SetCursorPosition(x + 13, y + 5);
            if (old_psw != password_)
                std::cout << "ԭʼ�������" ;
            else
                std::cout << "�������벻һ�£�" ;
            SetCursorPosition(0, 35);
        }
        Sleep(1000);
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
