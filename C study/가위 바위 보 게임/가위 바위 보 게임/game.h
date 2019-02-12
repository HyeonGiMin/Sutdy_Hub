#ifndef __GAME_H__
#define __GAME_H__

enum { SCISSORS = 1, ROCK, PAPER,EXIT};

int choiceOfCom(void);
int choiceOfMe(void);
void whoIsWinner(int com, int you);
void showRSP(int rsp);

#endif