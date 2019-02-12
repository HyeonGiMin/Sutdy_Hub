
#include"common.h";
#include"game.h";
#include"gameTimes.h"
#include"gameMoney.h"
#include"gameContinue.h"

int main(void) {
	
	int com;
	int you;
	int youMoney;
	int tableMoney;
	int ret;

	if(!DoYouWantToContinue()){
	puts("자! 게임을 시작합니다.");
	puts("");


	SetComMoney(1000);

	fputs("당신의 머니를 입력하세요 : ", stdout);
	scanf_s("%d", &youMoney);
	if (youMoney <= 0) {
		puts("절적치 못한 입력으로 프로그램을 종료합니다.");
		return -1;
	}
	SetYouMoney(youMoney);

	}
	printf_s("게이머 머니: %d \n", GetCurrentYouMoney());
	printf_s("컴퓨터 머니: %d \n\n", GetCurrentComMoney());

	while (1) {

		puts("판돈 설정합니다!");
		fputs("판돈 입력:", stdout);
		scanf_s("%d", &tableMoney);
		puts("");

		ret = SetGamblingTableMoneyByGamer(tableMoney);
		if (ret == 0 || ret == -1) {
			if (ret == 0) {
				puts("소유하고 있는 금액 내에서 거세요!");
				printf_s("게이머 머니: %d \n", GetCurrentYouMoney());
			}
			else {
				puts("컴퓨터 소유 금액 초과입니다!");
				printf_s("컴퓨터 머니: %d \n\n", GetCurrentComMoney());
			}
			continue;
		}
		puts("--------------대결!!-------------");
		com = choiceOfCom();
		you = choiceOfMe();
		puts("");

		if (you == EXIT)
			break;


		puts("--------------결과!!-------------");
		whoIsWinner(com, you);

		fputs("컴퓨터의 선택: ", stdout);
		showRSP(com);
		puts(" ");


		fputs("당신의 선택: ", stdout);
		showRSP(you);
		puts("");
		printf_s("승률 : %d %% \n\n", GetPercenOfVicotry());
		printf_s("게이머 머니: %d \n", GetCurrentYouMoney());
		printf_s("컴퓨터 머니: %d \n\n", GetCurrentComMoney());

		if (GetCurrentComMoney() <= 0 || GetCurrentYouMoney <= 0)
			break;
	
	}

	puts("--------------최종 결과!!-------------");
	printf_s("승률 : %d %% \n", GetPercenOfVicotry());

	if (GetCurrentComMoney() != 0 && GetCurrentYouMoney() != 0)
		DoYouWantToStore();
	else
		ClearContinueInfo();


	puts("이용해주셔서 감사합니다");
	return 0;
}