#ifndef FILE_IO_H
#define FILE_IO_H

#include <fstream>
#include <sstream>
#include <stdio.h>
#include "id_card_list.h"

class FileIO
{
public:
    int read(IDCardList *L)
    {
        /*fin.open("student_data.txt");
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
        fin.close();*/

        FILE *fp;
        if ((fp = fopen("student_data.txt", "r")) == NULL )
        {
            std::cout << "无法加载数据！" << std::endl;
            return 0;
        }
        char s1[100],s2[100],s3[100],s4[100],s5[100],s6[100],s7[100],s8[100];
        while (!feof(fp))
        {
            fscanf(fp, "%s%s%s%s%s%s%s%s", s1,s2,s3,s4,s5,s6,s7,s8);
            string name, sex, college, major, identity, validity_date, student_id, card_id;
            name=s1;
            sex=s2;
            college=s3;
            major=s4;
            identity=s5;
            validity_date=s6;
            student_id=s7;
            card_id=s8;
            if (!feof(fp))
            {
                IDCard *node = new IDCard(name, sex, college, major, identity, validity_date, student_id, card_id);
                L->Insert(node);
            }
        }
        fclose(fp);

        return 0;
    }
    int write(IDCardList *L)
    {
        /*fout.open("student_data.txt", std::ios::out);
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
        fout.close();*/

        FILE *fp;
        if ((fp = fopen("student_data.txt", "w")) == NULL )
        {
            std::cout << "无法加载数据！" << std::endl;
            return 0;
        }
        IDCard *ptr;
        ptr = L->head_;
        while (ptr != NULL)
        {
            const char *s1,*s2,*s3,*s4,*s5,*s6,*s7,*s8;
            s1 = ptr->GetName().c_str();
            s2 = ptr->GetSex().c_str();
            s3 = ptr->GetCollege().c_str();
            s4 = ptr->GetMajor().c_str();
            s5 = ptr->GetIdentity().c_str();
            s6 = ptr->GetValidity_date().c_str();
            s7 = ptr->GetStudentID().c_str();
            s8 = ptr->GetCardID().c_str();
            fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", s1,s2,s3,s4,s5,s6,s7,s8);
            ptr = ptr->next_;
        }
        fclose(fp);

        return 0;
    }
    int add(IDCard *node)
    {
        /*fout.open("student_data.txt", std::ios::app);
        if (!fout.is_open())
        {
            std::cout << "无法打开文件！" << std::endl;
            return 0;
        }
        fout << node->GetInfoString() << std::endl;
        return 0;*/

        FILE *fp;
        if ((fp = fopen("student_data.txt", "a")) == NULL )
        {
            std::cout << "无法加载数据！" << std::endl;
            return 0;
        }

            const char *s1,*s2,*s3,*s4,*s5,*s6,*s7,*s8;
            s1 = node->GetName().c_str();
            s2 = node->GetSex().c_str();
            s3 = node->GetCollege().c_str();
            s4 = node->GetMajor().c_str();
            s5 = node->GetIdentity().c_str();
            s6 = node->GetValidity_date().c_str();
            s7 = node->GetStudentID().c_str();
            s8 = node->GetCardID().c_str();
            fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", s1,s2,s3,s4,s5,s6,s7,s8);

        fclose(fp);

        return 0;
    }
private:
    std::ifstream fin;
    std::ofstream fout;
    std::string line;

};
#endif // FILE_IO_H
