#ifndef ID_CARD_LIST_H
#define ID_CARD_LIST_H

#include "id_card.h"

class IDCard;
class IDCardList
{
public:
    IDCardList() : head_(NULL), length_(0) { }
    friend class FileIO;
    friend class Query;
    friend class Modify;
    friend class Input;
    friend class Statistics;
    void Insert(IDCard *p)
    {
        if (head_ != NULL)
        {
            p->next_ = head_;
            head_ = p;
            ++length_;
        }
        else
        {
            head_ = p;
            p->next_ = NULL;
            ++length_;
        }
    }
    void Load()
    {
        IDCard *ptr;
        ptr = head_;
        while (ptr != NULL)
        {
            ptr->PrintInfo(13,5);
            ptr = ptr->next_;
        }
    }
    bool Find(string student_id)
    {
        IDCard *ptr;
        ptr = head_;
        while (ptr != NULL)
        {
            if (ptr->GetStudentID() == student_id)
            {
                SetColor(11);
                SetCursorPosition(32, 6);
                std::cout << "---------------------------------------------------" ;
                ptr->PrintInfo(32, 7);
                return true;;
            }
            else
                ptr = ptr->next_;
        }
        return false;
    }
    bool Delete(string student_id)
    {
        if (head_ != NULL && head_->GetStudentID() == student_id)
        {
            head_ = head_->next_;
        }
        else
        {
            IDCard *ptr, *pre;
            ptr = head_->next_;
            pre = head_;
            while (ptr != NULL)
            {
                if (ptr->GetStudentID() == student_id)
                {
                    pre->next_ = ptr->next_;
                    ptr->next_ = NULL;
                    return true;
                }
                else
                {
                    ptr = ptr->next_;
                    pre = pre->next_;
                }
            }
        }
        return false;
    }
private:
    IDCard *head_;
    int length_;
};
#endif // ID_CARD_LIST_H
