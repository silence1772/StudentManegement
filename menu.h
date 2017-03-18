#ifndef MENU_H
#define MENU_H

#include "tools.h"
#include <iostream>
#include <conio.h>

class Menu
{
public:
    Menu() : position_x_(6), position_y_(9), key_(3) { }
    void PrintUserInfo()
    {

        SetColor(5);
        SetCursorPosition(5, 7);
        std::cout << "��ӭ��������ΰ" << std::endl;
        SetCursorPosition(5, 9);
        std::cout << "�˺ţ�201625010622" << std::endl;
        SetCursorPosition(5, 11);
        std::cout << "Ȩ�ޣ�����Ա" << std::endl;

        SetColor(6);
        SetCursorPosition(6, 13);
        std::cout << "�޸�����" << std::endl;
        SetCursorPosition(6, 14);
        std::cout << "һһһһ" << std::endl;
        SetCursorPosition(6, 15);
        std::cout << "�˳�ϵͳ" << std::endl;
        SetCursorPosition(6, 16);
        std::cout << "һһһһ" << std::endl;

        SetCursorPosition(4, 17);
        std::cout << "--------------------" << std::endl;
    }
    void PrintMenu()
    {
        int x = position_x_;
        int y = position_y_;
        SetColor(8, 11);
        SetCursorPosition(x, (++y) * 2);
        std::cout << "��¼����Ϣ" << std::endl;
        SetColor(8);
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
                            SetColor(1, 5);
                            SetCursorPosition(6, 13);
                            std::cout << "�޸�����" ;
                            SetCursorPosition(6, 14);
                            std::cout << "һһһһ" ;

                            SetColor(6);
                            SetCursorPosition(6, 15);
                            std::cout << "�˳�ϵͳ" ;
                            SetCursorPosition(6, 16);
                            std::cout << "һһһһ" ;

                            --key_;
                            break;
                        case 3:
                            SetColor(1, 5);
                            SetCursorPosition(6, 15);
                            std::cout << "�˳�ϵͳ" ;
                            SetCursorPosition(6, 16);
                            std::cout << "һһһһ" ;

                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "��¼����Ϣ" ;

                            --key_;
                            break;
                        case 4:
                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "��¼����Ϣ" ;

                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "���޸���Ϣ" ;

                            --key_;
                            break;
                        case 5:
                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "���޸���Ϣ" ;

                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "��ɾ����Ϣ" ;

                            --key_;
                            break;
                        case 6:
                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "��ɾ����Ϣ" ;

                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "�Ѳ�ѯ��Ϣ" ;

                            --key_;
                            break;
                        case 7:
                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "�Ѳ�ѯ��Ϣ" ;

                            SetColor(8);
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
                            SetColor(6);
                            SetCursorPosition(6, 13);
                            std::cout << "�޸�����" ;
                            SetCursorPosition(6, 14);
                            std::cout << "һһһһ" ;

                            SetColor(1, 5);
                            SetCursorPosition(6, 15);
                            std::cout << "�˳�ϵͳ" ;
                            SetCursorPosition(6, 16);
                            std::cout << "һһһһ" ;

                            ++key_;
                            break;
                        case 2:
                            SetColor(6);
                            SetCursorPosition(6, 15);
                            std::cout << "�˳�ϵͳ" ;
                            SetCursorPosition(6, 16);
                            std::cout << "һһһһ" ;

                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "��¼����Ϣ" ;

                            ++key_;
                            break;
                        case 3:
                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "��¼����Ϣ" ;

                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "���޸���Ϣ" ;

                            ++key_;
                            break;
                        case 4:
                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "���޸���Ϣ" ;

                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "��ɾ����Ϣ" ;

                            ++key_;
                            break;
                        case 5:
                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "��ɾ����Ϣ" ;

                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "�Ѳ�ѯ��Ϣ" ;

                            ++key_;
                            break;
                        case 6:
                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "�Ѳ�ѯ��Ϣ" ;

                            SetColor(8, 11);
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
};
#endif // MENU_H
