#include"common.h"
#include"gameTimes.h"
#include"gameMoney.h"

#define FILE_NAME "gamecont_info.dat"
#define FILE_DEL_CMD "del gamecont_info.dat"

int DoYouWantToContinue(void) {
	FILE * fp;
	int conti;

	if (!AvailContinue())
		return 0;
	fputs("게임을 이어서 하시겠습니까? (Yes 1, NO 0): ", stdout);
	scanf_s("%d", &conti);

	if (conti == 0)
		return 0;

	fp = fopen(FILE_NAME, "rb");
	if (fp == NULL) {
		puts("이어서 할 데이터가 존재하지 않습니다");
		return 0;
	}

	LocalGmeTimesFromFile(fp);

	LoadGameMoneyFromFile(fp);

	fclose(fp);

	return 1;
}

int DoYouWantToStore(void) {
	FILE * fp;
	int cont;

	fputs("게임내을 저장하시겠습니까? (Yes 1, NO 0): ", stdout);
	scanf_s("%d", &cont);

	if (cont == 0)
		return 0;

	fp = fopen(FILE_NAME, "wb");

	StoreGameTimesToFile(fp);
	StoreGameMoneyToFile(fp);
	fclose(fp);
	return 1;
}

int AvailContinue(void) {
	FILE *fp;
	fp = fopen(FILE_NAME, "rb");
	if (fp == NULL)
		return 0;
	else {
		fclose(fp);
		return 1;
	}
}

void ClearContinueInfo(void) {
	FILE *fp;
	fp = fopen(FILE_NAME, "rb");

	if (fp != NULL) {
		fclose(fp);
		system(FILE_DEL_CMD);

	}
}