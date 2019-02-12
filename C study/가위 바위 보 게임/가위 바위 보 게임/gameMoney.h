#ifndef __GAMEMONEY_H__
#define __GAMEMONEY_H__

void SetComMoney(int money);
int GetCurrentComMoney(void);

void SetYouMoney(int money);
int GetCurrentYouMoney(void);

void SetGamblingTableMoney(int money);

void ComWinMoneyAccount(void);
void YouWinMoneyAccount(void);

#endif