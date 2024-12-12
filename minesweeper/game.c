//
// Created by f on 2024/12/10.
//
#include "game.h"

#include <stdio.h>
#include <stdlib.h>

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    printf("-------扫雷游戏------\n");
    //打印行号
    for (int j = 0; j <= col; ++j)
    {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 1; i <= row; ++i)
    {
        //打印列号
        printf("%d ", i);
        for (int j = 1; j <= col; ++j)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("-------扫雷游戏------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % row + 1;

        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
    return (board[x - 1][y] + board[x - 1][y - 1] + board[x][y - 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x +
        1][y + 1] + board[
        x][y +
        1] + board[x - 1][y + 1] - 8 * '0');
}

void FindMine(char mine[11][11], char show[11][11], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;

    while (win<row*col-EASY_COUNT)
    {
        printf("请输入要排查的坐标：");
        scanf("%d%d", &x, &y);
        //判断输入是否合法
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (show[x][y] != '*')
            {
                printf("该坐标被排查过了，不能重复排查\n");
                continue;
            }

            //如果是雷
            if (mine[x][y] == '1')
            {
                printf("很遗憾，你被炸死了\n");
                DisplayBoard(mine, ROW, COL);
                break;
            }
            else
            //如果不是雷
            {
                win++;
                int count = get_mine_count(mine, x, y);
                //数字转换成数字字符
                show[x][y] = count + '0';
                DisplayBoard(show,ROW, COL);
            }
        }
        else
        {
            printf("输入的坐标非法，请重新输入\n");
        }
    }
    if(win==row*col-EASY_COUNT)
    {
        printf("恭喜你，排雷成功\n");
        DisplayBoard(show,ROW, COL);
    }
}
