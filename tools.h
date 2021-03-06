#ifndef TOOLS_H
#define TOOLS_H

#include <windows.h>
#include <stdio.h>

void SetWindowSize(const int cols, const int lines)//设置窗口大小
{
    system("title 学生证管理系统");//设置窗口标题
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", cols, lines);
    system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void SetCursorPosition(const int x, const int y)//设置光标位置
{
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetCursorPosition2(const int x, const int y)//设置两倍光标位置，因为“■”占两个字符
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(unsigned short forecolor, unsigned short backcolor = 0)//设置文本颜色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), forecolor + backcolor *0x10);
}

void ClearScreen(const int x, const int y, const int width, const int height)
{
    SetColor(5);
    for (int i = 0; i < height + 2; ++i)
    {
        SetCursorPosition(x, y + i);
        for(int j = 0; j < width; ++j)
            printf("  ");
    }

}

#endif // TOOLS_H
