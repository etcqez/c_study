//
// Created by f on 2024/12/8.
//

#include "game.h"

#include <stdio.h>
#include <stdlib.h>

void InitBoard(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void DispalyBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (int i = 0; i < row; ++i)
    {
        // printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        for (int j = 0; j < col; ++j)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        // printf("---|---|---\n");
        if (i < row - 1)
        {
            for (int j = 0; j < col; ++j)
            {
                printf("---");
                if (j < col - 1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("玩家下棋：\n");
    while (1)
    {
        printf("请输入坐标");

        scanf("%d %d", &x, &y);
        //不能超出边界
        //对于玩家来说行列从1 开始
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            //是不有下
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("坐标被占用，请选择其他位置\n");
            }
        }
        else
        {
            printf("坐标非法，请重新输入\n");
        }
    }
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
    printf("电脑下棋：\n");

    int x = 0;
    int y = 0;

    while (1)
    {
        //生成0 1 2
        x = rand() % row;
        y = rand() % col;

        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

/**
 *
 * @param str
 * @return 如果满了就返回1
 *         不满返回0
 */
int ifFull(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;

}

char IsWin(char board[ROW][COL], int row, int col)
{
    //行
    for (int i = 0; i < row; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }

    //列
    for (int j = 0; j < col; ++j)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
        {
            return board[0][j];
        }
    }

    //对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
    {
        return board[1][1];
    }

    //没有人赢，就要平局
    if (ifFull(board, row, col))
    {
        return 'Q';

    }

    //游戏继续
    return 'C';
}
