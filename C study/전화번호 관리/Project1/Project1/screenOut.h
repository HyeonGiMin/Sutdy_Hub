/* Name : screenOut.h Ver 1.1
   Content : �ܼ� ����� ���� �Լ� ����
   Implementation : YSW
   
   Last modified 2018/08/28
*/

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "phoneData.h";

void ShowMenu(void);
void ShowPhoneInfo(phoneData phone);
void ShowPhoneInfoByPtr(phoneData* pPhone);

#endif