#ifndef FILE_IO_H
#define FILE_IO_H

#include <fstream>
#include <sstream>
#include "id_card_list.h"

class FileIO
{
public:
    int read(IDCardList *L)
    {
        fin.open("student_data.txt");
        if (!fin.is_open())
        {
            std::cout << "无法加载数据！" << std::endl;
            return 0;
        }
        while (std::getline(fin, line))
        {
            std::istringstream record(line);
            string name, sex, college, major, identity, validity_date, student_id, card_id;
            record >> name >> sex >> college >> major >> identity >> validity_date >> student_id >> card_id;
            IDCard *node = new IDCard(name, sex, college, major, identity, validity_date, student_id, card_id);
            L->Insert(node);
        }
        //L->Load();
        fin.close();
        return 0;
    }
    int write(IDCardList *L)
    {
        fout.open("student_data1.txt", std::ios::out);
        if (!fout.is_open())
        {
            std::cout << "无法打开文件！" << std::endl;
            return 0;
        }
        IDCard *ptr;
        ptr = L->head_;
        while (ptr != NULL)
        {
            fout << ptr->GetInfoString() << std::endl;
            ptr = ptr->next_;
        }
        fout.close();
        return 0;
    }
    int add(IDCard *node)
    {
        fout.open("student_data1.txt", std::ios::app);
        if (!fout.is_open())
        {
            std::cout << "无法打开文件！" << std::endl;
            return 0;
        }
        fout << node->GetInfoString() << std::endl;
        return 0;
    }
private:
    std::ifstream fin;
    std::ofstream fout;
    std::string line;
};
#endif // FILE_IO_H
