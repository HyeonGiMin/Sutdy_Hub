/* Name : main.c Ver1.4
   Content : main함수
   Implementation : YSW

   Last modified 2018/08/28
*/

#include "common.h";
#include"screenOut.h";
#include"phoneFunc.h";


enum { INPUT = 1, SHOWALL, SEARCH,DELETE,CHANGE,QUIT };
/* 함수: int main(void)
   기능: 사용자 선택 처리
   반환: 정상 종료시 0

 */


int main(void)
{
	int inputMenu = 0;

	//프로그램 시작과 동시에 데이터 Load!
	//LoadDataFromFile();
	LoadDataFromFileInStruct();

	while (1)
	{
		ShowMenu();
		fputs("선택하세요 : ", stdout);
		scanf_s("%d", &inputMenu);
		while (getchar() != '\n"');

		switch (inputMenu)
		{
		case INPUT:
			InputPhoneData();
			break;
		case SHOWALL:
			ShowALLData();
			break;
		case SEARCH:
			SearchPhoneData();
			break;
		case DELETE:
			DeletePhoneData();
			break;
		case CHANGE:
			ChangePhoneData();
			break;
		}

		if (inputMenu == QUIT)
		{
			//프로그램 종료 시 데이터 Store!
			//StoreDataToFile();
			StoreDataToFileInStruct();
			puts("이용해 주셔서 고마워요~");
			break;
		}
		return 0;
	}
}