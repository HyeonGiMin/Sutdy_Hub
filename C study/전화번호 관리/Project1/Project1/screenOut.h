/* Name : screenOut.h Ver 1.1
   Content : 콘솔 출력을 위한 함수 선언
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