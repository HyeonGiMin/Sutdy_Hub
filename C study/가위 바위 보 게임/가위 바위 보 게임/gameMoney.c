#include"common.h";

static int moneyCom;
static int moneyYou;

static int gamlingTableMoney;

void SetComMoney(int money) {
	if (money < 0) {
		printf("에러입니다");
		return;
	}
	moneyCom = money;
}

int GetCurrentComMoney(void) {
	return moneyCom;
}

void SetYouMoney(int money) {
	if (money < 0) {
		printf("에러입니다");
		return;
	}
	moneyYou = money;
}

int GetCurrentYouMoney(void) {
	return moneyYou;
}

void SetGamblingTableMoney(int money) {
	if (money < 0)
		gamlingTableMoney = 0;
	else
		gamlingTableMoney = money;
}

void ComWinMoneyAccount(void) {
	moneyYou -= gamlingTableMoney;
	moneyCom += gamlingTableMoney;
}

void YouWinMoneyAccount(void) {
	moneyCom -= gamlingTableMoney;
	moneyYou += gamlingTableMoney;
}

int SetGamblingTableMoneyByGamer(int money) {
	if (money > moneyYou)
		return 0;
	else if (money > moneyCom)
		return -1;

	SetGamblingTableMoney(money);
	return 1;
}

void StoreGameMoneyToFile(FILE *fp) {
	fwrite(&moneyCom, sizeof(int), 1, fp);
	fwrite(&moneyYou, sizeof(int), 1, fp);
}

void LoadGameMoneyFromFile(FILE *fp)
{
	int readCnt1, readCnt2;

	readCnt1 = fread(&moneyCom, sizeof(int), 1, fp);
	readCnt2 = fread(&moneyYou, sizeof(int), 1, fp);

	if (readCnt1 != 1 || readCnt2 != 1) {
		moneyCom = 1000;
		moneyYou = 1000;
	}
}