#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"

void menu(void)
{
    printf("*******************************\n");
    printf("*****  1. play 0. exit  *******\n");
    printf("*******************************\n");
}


void game(void)
{
    char ret = 0;
    char board[ROW][COL] = {0};
    //初始化棋盘函数
    InitBoard(board, ROW, COL);
    //打印
    DispalyBoard(board, ROW, COL);
    //下棋
    while (1)
    {
        //玩家下棋
        PlayerMove(board, ROW,COL);
        //判断输赢
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        DispalyBoard(board, ROW, COL);
        //电脑下棋
        ComputerMove(board, ROW, COL);
        //判断输赢
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        DispalyBoard(board, ROW, COL);
    }
    if (ret == '*')
    {
        printf("玩家赢\n");
    }
    else if (ret == '#')
    {
        printf("电脑赢\n");
    }
    else
    {
        printf("平局\n");
    }
    DispalyBoard(board, ROW,COL);
}

int main(void)
{
    //设置随机数的生成起点
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        menu();
        printf("请选择：");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    }
    while (input);
}
