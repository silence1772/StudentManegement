#ifndef MENU_H
#define MENU_H

#include "tools.h"
#include <iostream>
#include <conio.h>

class Menu
{
public:
    Menu(string name, string id, int pms) : position_x_(6), position_y_(9), key_(3),
     name_(name), id_(id), permission_(pms) { }
    void PrintUserInfo()
    {

        SetColor(11);
        SetCursorPosition(5, 7);
        std::cout << "��ӭ����" << name_ << std::endl;
        SetCursorPosition(5, 9);
        std::cout << "�˺ţ�" << id_ << std::endl;
        SetCursorPosition(5, 11);
        std::cout << "Ȩ�ޣ�" << (permission_==1?"����Ա":"�ο�") << std::endl;

        SetColor(15);
        SetCursorPosition(10, 13);
        std::cout << "�޸�����" << std::endl;
        SetCursorPosition(10, 14);
        std::cout << "һһһһ" << std::endl;
        SetCursorPosition(10, 15);
        SetColor(12);
        std::cout << "�˳�ϵͳ" << std::endl;
        SetCursorPosition(10, 16);
        std::cout << "һһһһ" << std::endl;

        SetColor(11);
        SetCursorPosition(4, 17);
        //std::cout << "--------------------" << std::endl;
        std::cout << "��������������������" << std::endl;
    }
    void PrintMenu()
    {
        int x = position_x_;
        int y = position_y_;
        SetColor(8, 11);
        SetCursorPosition(x, (++y) * 2);
        std::cout << "��¼����Ϣ" << std::endl;
        SetColor(15);
        SetCursorPosition(x, (++y) * 2);
        std::cout << "���޸���Ϣ" << std::endl;
        SetCursorPosition(x, (++y) * 2);
        std::cout << "��ɾ����Ϣ" << std::endl;
        SetCursorPosition(x, (++y) * 2);
        std::cout << "�Ѳ�ѯ��Ϣ" << std::endl;
        SetCursorPosition(x, (++y) * 2);
        std::cout << "��ͳ����Ϣ" << std::endl;
    }
    int Select()
    {
        SetCursorPosition(0, 35);
        /*���·����ѡ��ģ��*/
        int ch;//��¼����ֵ
        bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
        while ((ch = getch()))
        {
            switch (ch)//��������
            {
                case 72://UP�Ϸ����
                    if (key_ > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
                    {
                        switch (key_)
                        {
                        case 2:
                            SetColor(0, 11);
                            SetCursorPosition(10, 13);
                            std::cout << "�޸�����" ;
                            SetCursorPosition(10, 14);
                            std::cout << "һһһһ" ;

                            SetColor(12);
                            SetCursorPosition(10, 15);
                            std::cout << "�˳�ϵͳ" ;
                            SetCursorPosition(10, 16);
                            std::cout << "һһһһ" ;

                            --key_;
                            break;
                        case 3:
                            SetColor(0, 12);
                            SetCursorPosition(10, 15);
                            std::cout << "�˳�ϵͳ" ;
                            SetCursorPosition(10, 16);
                            std::cout << "һһһһ" ;

                            SetColor(15);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "��¼����Ϣ" ;

                            --key_;
                            break;
                        case 4:
                            SetColor(0, 11);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "��¼����Ϣ" ;

                            SetColor(15);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "���޸���Ϣ" ;

                            --key_;
                            break;
                        case 5:
                            SetColor(0, 11);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "���޸���Ϣ" ;

                            SetColor(15);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "��ɾ����Ϣ" ;

                            --key_;
                            break;
                        case 6:
                            SetColor(0, 11);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "��ɾ����Ϣ" ;

                            SetColor(15);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "�Ѳ�ѯ��Ϣ" ;

                            --key_;
                            break;
                        case 7:
                            SetColor(0, 11);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "�Ѳ�ѯ��Ϣ" ;

                            SetColor(15);
                            SetCursorPosition(position_x_, (position_y_ + 5) * 2);
                            std::cout << "��ͳ����Ϣ" ;

                            --key_;
                            break;
                        }

                    }
                    break;
                case 80://DOWN�·����
                    if (key_ < 7)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
                    {
                        switch (key_)
                        {
                        case 1:
                            SetColor(15);
                            SetCursorPosition(10, 13);
                            std::cout << "�޸�����" ;
                            SetCursorPosition(10, 14);
                            std::cout << "һһһһ" ;

                            SetColor(0, 12);
                            SetCursorPosition(10, 15);
                            std::cout << "�˳�ϵͳ" ;
                            SetCursorPosition(10, 16);
                            std::cout << "һһһһ" ;

                            ++key_;
                            break;
                        case 2:
                            SetColor(12);
                            SetCursorPosition(10, 15);
                            std::cout << "�˳�ϵͳ" ;
                            SetCursorPosition(10, 16);
                            std::cout << "һһһһ" ;

                            SetColor(0, 11);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "��¼����Ϣ" ;

                            ++key_;
                            break;
                        case 3:
                            SetColor(15);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "��¼����Ϣ" ;

                            SetColor(0, 11);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "���޸���Ϣ" ;

                            ++key_;
                            break;
                        case 4:
                            SetColor(15);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "���޸���Ϣ" ;

                            SetColor(0, 11);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "��ɾ����Ϣ" ;

                            ++key_;
                            break;
                        case 5:
                            SetColor(15);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "��ɾ����Ϣ" ;

                            SetColor(0, 11);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "�Ѳ�ѯ��Ϣ" ;

                            ++key_;
                            break;
                        case 6:
                            SetColor(15);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "�Ѳ�ѯ��Ϣ" ;

                            SetColor(0, 11);
                            SetCursorPosition(position_x_, (position_y_ + 5) * 2);
                            std::cout << "��ͳ����Ϣ" ;

                            ++key_;
                            break;
                        }
                    }
                    break;
                case 13:
                    flag = true;
                    break;
                default:
                    break;
            }
            if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
            SetCursorPosition(0, 35);
        }

        switch(key_)
        {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 4:
            return 4;
            break;
        case 5:
            return 5;
            break;
        case 6:
            return 6;
            break;
        case 7:
            return 7;
            break;
        }
        return 0;
    }
private:
    int position_x_;
    int position_y_;
    int key_;

    string name_;
    string id_;
    int permission_;
};
#endif // MENU_H
