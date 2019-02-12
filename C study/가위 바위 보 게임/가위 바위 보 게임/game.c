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
	puts("���� (1), ����(2), ��(3) ����(4) ����??", stdout);
	scanf_s("%d", &choice);
	return choice;
}

void whoIsWinner(int com, int you) {
	int outcome = you - com;
	IncreGameTimes();

	switch(outcome)
	{
		case 0:
			puts("�����ϴ�.");
			return;
		case 1: case -2:
			puts("����� �����Դϴ�.");
			IncreYouWinTimes();
			YouWinMoneyAccount();
			return;
	}
	puts("��ǻ�Ͱ� �����̱���!");
	ComWinMoneyAccount();
}

void showRSP(int rsp)
{
	switch (rsp)
	{
	case SCISSORS:
		fputs("����",stdout);
		break;
	case ROCK:
		fputs("����", stdout);
		break;
	case PAPER:
		fputs("��", stdout);
		break;
	}
}