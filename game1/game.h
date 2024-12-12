//
// Created by f on 2024/12/8.
//

#ifndef GAME_H
#define GAME_H

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
void DispalyBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row,int col);
void ComputerMove(char board[ROW][COL], int row,int col);
/**
 * 玩家赢 *
 * 电脑赢 #
 * 平局 Q
 * 继续 C
 * @return
 */
char IsWin(char board[ROW][COL], int row, int col);
#endif //GAME_H
