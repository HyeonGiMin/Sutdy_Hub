/* Name : screenOut.c ver 1.2
Content : 콘솔 출력을 위한 함수 정의
Implementation : YSW

Last modified 2018/08/28
*/

#include"common.h"
#include"phoneData.h"

/* 함수: void ShowMenu(void)
   기능: 선택을 위한 메뉴 출력
   반환: void
*/
void SHowMenu(void)
{
	system("cls");   //stdlib.h

	printf("------------메뉴---------------------\n");
	printf(" 1. 전화번호 입력 \n");
	printf(" 2. 전체 정보 출력 \n");
	printf(" 3. 전화번호 검색 \n");
	printf(" 4. 전화번호 삭제 \n");
	printf(" 5. 전화번호 변경 \n");
	printf(" 6. 종료\n");
	printf("-------------------------------------\n");
	printf("선택>");
}

/* 함수: void ShowPhoneInfo(phoneData phone)
   기능: 이름과 전화번호 정보 출력
   반환: void
*/
void ShowPhoneInfo(phoneData phone)
{
	printf("---------------------------\n");
	printf("|  ▶이름 : %s \n", phone.name);
	printf("|  ▶전화번호 : %s \n", phone.phoneNum);
	printf("---------------------------\n\n");
}

/* 함수: void ShowPhoneInfoByPtr(phoneData* phone)
기능: 이름과 전화번호 정보 출력
반환: void
*/
void ShowPhoneInfo(phoneData* pPhone)
{
	printf("---------------------------\n");
	printf("|  ▶이름 : %s \n", pPhone->name);
	printf("|  ▶전화번호 : %s \n", pPhone->phoneNum);
	printf("---------------------------\n\n");
}
