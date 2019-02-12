/* Name : main.c Ver1.4
   Content : main�Լ�
   Implementation : YSW

   Last modified 2018/08/28
*/

#include "common.h";
#include"screenOut.h";
#include"phoneFunc.h";


enum { INPUT = 1, SHOWALL, SEARCH,DELETE,CHANGE,QUIT };
/* �Լ�: int main(void)
   ���: ����� ���� ó��
   ��ȯ: ���� ����� 0

 */


int main(void)
{
	int inputMenu = 0;

	//���α׷� ���۰� ���ÿ� ������ Load!
	//LoadDataFromFile();
	LoadDataFromFileInStruct();

	while (1)
	{
		ShowMenu();
		fputs("�����ϼ��� : ", stdout);
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
			//���α׷� ���� �� ������ Store!
			//StoreDataToFile();
			StoreDataToFileInStruct();
			puts("�̿��� �ּż� ������~");
			break;
		}
		return 0;
	}
}