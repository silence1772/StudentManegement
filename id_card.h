#ifndef ID_CARD_H
#define ID_CARE_H

#include <iostream>
#include <cstring>

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
           validity_date_(validity_date), student_id_(student_id), card_id_(card_id) { }

    class IDCard *next_;
    void PrintInfo()
    {
        std::cout << "������" << name_ << std::endl;
        std::cout << "�Ա�" << sex_ << "                 ѧԺ��" << college_ << std::endl;
        std::cout << "רҵ��" << major_ << std::endl;
        std::cout << "��ݣ�" << identity_ << "             ѧ�ţ�" << student_id_ << std::endl;
        std::cout << "���ţ�" << card_id_ << "             ��Ч�ڣ�" << validity_date_ << std::endl;
        std::cout << "-----------------------------------------------" <<std::endl;
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
};
#endif // ID_CARD_H
