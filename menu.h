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

        SetColor(5);
        SetCursorPosition(5, 7);
        std::cout << "欢迎您：" << name_ << std::endl;
        SetCursorPosition(5, 9);
        std::cout << "账号：" << id_ << std::endl;
        SetCursorPosition(5, 11);
        std::cout << "权限：" << (permission_==1?"管理员":"游客") << std::endl;

        SetColor(6);
        SetCursorPosition(10, 13);
        std::cout << "修改密码" << std::endl;
        SetCursorPosition(10, 14);
        std::cout << "一一一一" << std::endl;
        SetCursorPosition(10, 15);
        std::cout << "退出系统" << std::endl;
        SetCursorPosition(10, 16);
        std::cout << "一一一一" << std::endl;

        SetCursorPosition(4, 17);
        std::cout << "--------------------" << std::endl;
    }
    void PrintMenu()
    {
        int x = position_x_;
        int y = position_y_;
        SetColor(8, 11);
        SetCursorPosition(x, (++y) * 2);
        std::cout << "⊙录入信息" << std::endl;
        SetColor(8);
        SetCursorPosition(x, (++y) * 2);
        std::cout << "⊙修改信息" << std::endl;
        SetCursorPosition(x, (++y) * 2);
        std::cout << "⊙删除信息" << std::endl;
        SetCursorPosition(x, (++y) * 2);
        std::cout << "⊙查询信息" << std::endl;
        SetCursorPosition(x, (++y) * 2);
        std::cout << "⊙统计信息" << std::endl;
    }
    int Select()
    {
        /*上下方向键选择模块*/
        int ch;//记录键入值

        bool flag = false;//记录是否键入Enter键标记，初始置为否
        while ((ch = getch()))
        {
            switch (ch)//检测输入键
            {
                case 72://UP上方向键
                    if (key_ > 1)//当此时选中项为第一项时，UP上方向键无效
                    {
                        switch (key_)
                        {
                        case 2:
                            SetColor(1, 5);
                            SetCursorPosition(10, 13);
                            std::cout << "修改密码" ;
                            SetCursorPosition(10, 14);
                            std::cout << "一一一一" ;

                            SetColor(6);
                            SetCursorPosition(10, 15);
                            std::cout << "退出系统" ;
                            SetCursorPosition(10, 16);
                            std::cout << "一一一一" ;

                            --key_;
                            break;
                        case 3:
                            SetColor(1, 5);
                            SetCursorPosition(10, 15);
                            std::cout << "退出系统" ;
                            SetCursorPosition(10, 16);
                            std::cout << "一一一一" ;

                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "⊙录入信息" ;

                            --key_;
                            break;
                        case 4:
                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "⊙录入信息" ;

                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "⊙修改信息" ;

                            --key_;
                            break;
                        case 5:
                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "⊙修改信息" ;

                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "⊙删除信息" ;

                            --key_;
                            break;
                        case 6:
                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "⊙删除信息" ;

                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "⊙查询信息" ;

                            --key_;
                            break;
                        case 7:
                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "⊙查询信息" ;

                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 5) * 2);
                            std::cout << "⊙统计信息" ;

                            --key_;
                            break;
                        }

                    }
                    break;
                case 80://DOWN下方向键
                    if (key_ < 7)//当此时选中项为第一项时，UP上方向键无效
                    {
                        switch (key_)
                        {
                        case 1:
                            SetColor(6);
                            SetCursorPosition(10, 13);
                            std::cout << "修改密码" ;
                            SetCursorPosition(10, 14);
                            std::cout << "一一一一" ;

                            SetColor(1, 5);
                            SetCursorPosition(10, 15);
                            std::cout << "退出系统" ;
                            SetCursorPosition(10, 16);
                            std::cout << "一一一一" ;

                            ++key_;
                            break;
                        case 2:
                            SetColor(6);
                            SetCursorPosition(10, 15);
                            std::cout << "退出系统" ;
                            SetCursorPosition(10, 16);
                            std::cout << "一一一一" ;

                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "⊙录入信息" ;

                            ++key_;
                            break;
                        case 3:
                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 1) * 2);
                            std::cout << "⊙录入信息" ;

                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "⊙修改信息" ;

                            ++key_;
                            break;
                        case 4:
                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 2) * 2);
                            std::cout << "⊙修改信息" ;

                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "⊙删除信息" ;

                            ++key_;
                            break;
                        case 5:
                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 3) * 2);
                            std::cout << "⊙删除信息" ;

                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "⊙查询信息" ;

                            ++key_;
                            break;
                        case 6:
                            SetColor(8);
                            SetCursorPosition(position_x_, (position_y_ + 4) * 2);
                            std::cout << "⊙查询信息" ;

                            SetColor(8, 11);
                            SetCursorPosition(position_x_, (position_y_ + 5) * 2);
                            std::cout << "⊙统计信息" ;

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
            if (flag) break;//输入Enter回车键确认，退出检查输入循环
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
