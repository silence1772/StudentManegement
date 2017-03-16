#ifndef FILE_IO_H
#define FILE_IO_H

#include <fstream>
#include <sstream>
#include "id_card_list.h"

class FileIO
{
public:

    int read()
    {
        /*string name, sex, college, major, identity, validity_date;
        long long student_id, card_id;
        FILE *fp;
        fp = fopen("student_data.txt","r");
        if (fp == NULL)
        {
            std::cout << "无法加载数据！" << std::endl;
            return 0;
        }
        while (!feof(fp))
        {
            fscanf(fp, "%s%s%s%s%s%s%lld%lld", &name, &sex, &college, &major, &identity, &validity_date, &student_id, &card_id);
            IDCardList *a = new IDCardList();
            IDCard *b = new IDCard(name, sex, college, major, identity, validity_date, student_id, card_id);
            a->Insert(b);
            a->Load();
        }*/
        std::ifstream fin;
        std::string line;
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

            IDCardList *a = new IDCardList();
            IDCard *b = new IDCard(name, sex, college, major, identity, validity_date, student_id, card_id);
            a->Insert(b);
            a->Load();
        }
        return 0;
    }

private:

};
#endif // FILE_IO_H
