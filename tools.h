#ifndef TOOLS_H
#define TOOLS_H

#include <windows.h>
#include <stdio.h>

void SetWindowSize(const int cols, const int lines)//���ô��ڴ�С
{
    system("title ѧ��֤����ϵͳ");//���ô��ڱ���
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", cols, lines);
    system(cmd);//system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�
}

void SetCursorPosition(const int x, const int y)//���ù��λ��
{
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetCursorPosition2(const int x, const int y)//�����������λ�ã���Ϊ������ռ�����ַ�
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(unsigned short forecolor, unsigned short backcolor = 0)//�����ı���ɫ
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), forecolor + backcolor *0x10);
}


#endif // TOOLS_H
