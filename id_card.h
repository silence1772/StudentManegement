#ifndef ID_CARD_H
#define ID_CARE_H

#include <iostream>
#include <cstring>
#include "tools.h"

using std::string;

class IDCard
{
public:
    IDCard();
    IDCard(const string &name, const string &sex, const string &college,
           const string &major, const string &identity, const string &validity_date,
           const string &student_id, const string &card_id)
           : next_(NULL),
           name_(name), sex_(sex), college_(college), major_(major), identity_(identity),
           validity_date_(validity_date), student_id_(student_id), card_id_(card_id)
           {
                string tmp;
                int i = 0;
                for (auto c : student_id_)
                {
                    if (i > 3 && i < 10)
                        tmp += c;
                    ++i;
                }
                class_id_ = tmp;
           }
    class IDCard *next_;


    void PrintInfo(const int x, const int y)
    {
        SetColor(11);
        SetCursorPosition(x, y);
        std::cout << "姓名：" << name_ ;
        SetCursorPosition(x, y + 1);
        std::cout << "性别：" << sex_ << "                    学院：" << college_ ;
        SetCursorPosition(x, y + 2);
        std::cout << "专业：" << major_ ;
        SetCursorPosition(x, y + 3);
        std::cout << "身份：" << identity_ << "                学号：" << student_id_ ;
        SetCursorPosition(x, y + 4);
        std::cout << "卡号：" << card_id_ << "                有效期：" << validity_date_ ;
        SetCursorPosition(x, y + 5);
        std::cout << "---------------------------------------------------" ;
    }
    string GetInfoString()
    {
        string info_str = name_ + " " + sex_ + " " + college_ + " " + major_ + " " + identity_ + " " + validity_date_ + " " + student_id_ + " " + card_id_;
        return info_str;
    }
    string GetName()
    {
        return name_;
    }
    string GetSex()
    {
        return sex_;
    }
    string GetCollege()
    {
        return college_;
    }
    string GetMajor()
    {
        return major_;
    }
    string GetIdentity()
    {
        return identity_;
    }
    string GetValidity_date()
    {
        return validity_date_;
    }
    string GetStudentID()
    {
        return student_id_;
    }
    string GetCard_id()
    {
        return card_id_;
    }
    string GetClassID()
    {
        return class_id_;
    }

private:
    string name_;
    string sex_;
    string college_;
    string major_;
    string identity_;
    string validity_date_;
    string student_id_;
    string card_id_;
    string class_id_;
};
#endif // ID_CARD_H
