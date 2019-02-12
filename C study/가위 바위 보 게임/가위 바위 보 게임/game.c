#include<time.h>
#include"common.h";
#include"game.h";
#include"gameTimes.h"

int choiceOfCom(void) {
	srand((unsigned int)time(NULL));
	return rand() % 3 + 1;
}

int choiceOfme(void) {
	int choice;
	puts("가위 (1), 바위(2), 보(3) 종료(4) 선택??", stdout);
	scanf_s("%d", &choice);
	return choice;
}

void whoIsWinner(int com, int you) {
	int outcome = you - com;
	IncreGameTimes();

	switch(outcome)
	{
		case 0:
			puts("비겼습니다.");
			return;
		case 1: case -2:
			puts("당신이 승자입니다.");
			IncreYouWinTimes();
			YouWinMoneyAccount();
			return;
	}
	puts("컴퓨터가 승자이군요!");
	ComWinMoneyAccount();
}

void showRSP(int rsp)
{
	switch (rsp)
	{
	case SCISSORS:
		fputs("가위",stdout);
		break;
	case ROCK:
		fputs("바위", stdout);
		break;
	case PAPER:
		fputs("보", stdout);
		break;
	}
}