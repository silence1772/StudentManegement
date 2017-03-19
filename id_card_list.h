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
private:
    IDCard *head_;
    int length_;
};
#endif // ID_CARD_LIST_H
