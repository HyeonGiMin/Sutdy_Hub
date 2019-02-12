/* Name : phoneFunc.c ver 1.7
   Content : ��ȭ��ȣ ��Ʈ�� �Լ�
   Implementation : YSW
   
   Last modified 2018/08/29
   */

#include"common.h"
#include"phoneData.h"
#include"screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData* phoneList[LIST_NUM];

/* �Լ�: void InputPhoneData(void)
   ���: ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
   ��ȯ: void
*/

void InputPhoneData(void)
{
	phoneData* pData;
	int i;

	if (numOfData >= LIST_NUM)
	{
		puts("�޸� ������ �����մϴ�.");
		return;
	}
	pData = (phoneData*)malloc(sizeof(phoneData));

	fputs("�̸� �Է� :",stdout);
	//gets(data.name);
	gets(pData->name);

	fputs("��ȭ��ȣ �Է� : ",stdout);
	//gets(data.phoneNum);
	gets(pData->phoneNum);

	if (!strcmp(phoneList[i]->name, pData->name) && !strcmp(phoneList[i]->phoneNum, pData->phoneNum))
	{
		puts("�̹� �Էµ� ������ �Դϴ�.");
		free(pData);
		getchar();
		return;
	}

	//phoneList[numOfData] = data;
	phoneList[numOfData] = pData;
	numOfData++;

	//���� ����
	StoreDataToFileInStruct();

	puts("�Է��� �Ϸ�Ǿ����ϴ�");
	getchar();

}

/* �Լ�: void ShowALLData(void)
   ���: ����� ������ ��ü ���
   ��ȯ: void
*/

void ShowALLData(void)
{
	int i;
	for (i = 0; i < numOfData; i++)
	{
		//ShowPhoneInfo(phoneList[i]);
		ShowPhoneInfoByPtr(phoneList[i]);
	}

	puts("����� �Ϸ�Ǿ����ϴ�");
	getchar();
}

/* �Լ�: void SearchPhoneData(void)
   ���: �̸��� ���� ������ �˻�
   ��ȯ: void
*/

void SearchPhoneData(void)
{
	int i;
	int searchSte = 0;   //ã���� 1,�� ã���� 0
	char searchName[NAME_LEN];

	fputs("ã�� �̸���? ", stdout);
	gets(searchName);

	for (i = 0; i < numOfData; i++)
	{
		//if (!strcmp(phoneList[i].name, searchName))
		if (!strcmp(phoneList[i]->name, searchName))
		{
			//ShowPhoneInfo(phoneList[i]);
			ShowPhoneInfoByPtr(phoneList[i]);

			//getchar();
			//return;
			searchSte = 1;
		}
	}

		if (searchSte == 0)
			puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
		else
			puts("�˻��� �Ϸ�Ǿ����ϴ�.");

	getchar();
}

/* �Լ�: void DeletePhoneData(void)
   ���: �̸��� �����Ͽ� ������ ����
   ��ȯ: void
*/

void DeletePhoneData(void)
{
	int i, j;
	char delName[NAME_LEN];

	int idxOfMatchingData[LIST_NUM];
	int matchedCount = 0;
	int selection = 0;
	int delIdx = 0;

	fputs("ã�� �̸���? ", stdout);
	gets(delName);

	//for (i = 0; i < numOfData; i++)
	//{
	//	//if (!strcmp(phoneList[i].name, delName))
	//	if (!strcmp(phoneList[i]->name, delName))
	//	{
	//		free(phoneList[i]);

	//		for (j = i; j < numOfData - 1; j++)
	//		{
	//			phoneList[j] = phoneList[j + 1];
	//		}
	//		numOfData--;
	//		puts("������ �Ϸ�Ǿ����ϴ�.");
	//		getchar();
	//		return;
	//	}
	//}
	//puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
	//getchar();

	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(phoneList[i]->name, delName))
		{
			idxOfMatchingData[matchedCount++] = i;
		}
	}

	if (matchedCount == 0)
	{
		puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
		getchar();
		return;
	}
	else if (matchedCount == 1)
	{
		delIdx = idxOfMatchingData[0];
	}
	else
	{
		for (i = 0; i < matchedCount; i++)
		{
			printf("NUM. %d \n", i + 1);
			ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
		}

		fputs("���� :", stdout);
		scanf_s("%d", &selection);
		while (getchar() != '\n');

		delIdx = idxOfMatchingData[selection - 1];
	}

	free(phoneList[delIdx]);

	for(i=delIdx;i<numOfData-1;i++)
	{
		phoneList[i] = phoneList[i + 1];
	}
	numOfData--;

	//���� ����
	StoreDataToFileInStruct();

	puts("������ �Ϸ�Ǿ����ϴ�.");
	getchar();
}


/* �Լ�: void StoreDataToFile(void)
   ���: ��� ������ ���Ͽ� ����
   ��ȯ: void
*/

void StoreDataToFile(void)
{
	int i;
	FILE * fp = fopen("phoneData.dat", "w");

	fwrite(&numOfData, sizeof(int), 1, fp);
	for(i=0;i<numOfData;i++)
	{
		//���ڿ��� �������� ���� \n�� ���� �߿�!
		fprintf(fp, "%s\n%s\n",phoneList[i]->name,phoneList[i]->phoneNum);
		free(phoneList[i]);
	}

	fclose(fp);
}

/* �Լ�: void LoadDataFromFile(void)
   ���: ��� ������ ���Ϸκ��� ����
   ��ȯ: void
*/
void LoadDataFromFile(void)
{
	int i, sLen;
	FILE * fp = fopen("phoneData.dat", "r");
	if (fp == NULL)
		return;

	fread(&numOfData, sizeof(int), 1, fp);

	for (i = 0; i < numOfData; i++)
	{
		phoneList[i] = (phoneData*)malloc(sizeof(phoneData));
		fgets(phoneList[i]->name, NAME_LEN, fp);


        //���ڿ� ������ ���� �Էµ� \n ���� ����
		sLen = strlen(phoneList[i]->phoneNum);
		phoneList[i]->name[sLen - 1] = 0;

		fgets(phoneList[i]->phoneNum, PHONE_LEN, fp);

		//���ڿ� ������ ���� �Էµ� \n ���� ����
		sLen = strlen(phoneList[i]->phoneNum);
		phoneList[i]->phoneNum[sLen - 1] = 0;
		
	}

	fclose(fp);
}

/* �Լ�: void ChangePhoneData(void)
   ���: �̸��� �����Ͽ� ��ȭ��ȣ ���� 
   ��ȯ: void
*/

void ChangePhoneData(void)
{
	int i;
	char searchName[NAME_LEN];
	char newPhoneNumber[PHONE_LEN];

	int idxOfMatchingData[LIST_NUM];
	int matchedCount = 0;
	int selection = 0;
	int delIdx = 0;

	fputs("���� ����� �̸���? ", stdout);
	gets(searchName);

	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(phoneList[i]->name, searchName))
			idxOfMatchingData[matchedCount++] = i;
	}

	if (matchedCount == 0)
	{
		puts("���� ��� �̸��� �������� �ʽ��ϴ�.");
		getchar();
		return;
	}
	else if (matchedCount == 1)
	{
		delIdx = idxOfMatchingData[0];
	}
	else
	{
		for (i = 0; i < matchedCount; i++)
		{
			printf("NUM. %d \n", i + 1);
			ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
		}

		fputs("���� :", stdout);
		scanf_s("%d", &selection);
		while (getchar() != '\n');

		delIdx = idxOfMatchingData[selection - 1];
	}


	fputs("������ ��ȭ��ȣ��? ", stdout);
	gets(newPhoneNumber);
	strcpy_s(phoneList[delIdx]->phoneNum, strlen(newPhoneNumber) + 1, newPhoneNumber);
	
	//���� ����
	StoreDataToFileInStruct();

	puts("������ �Ϸ�Ǿ����ϴ�.");
	getchar();
}

/* �Լ�: void StoreDataToFileInStruct(void)
   ���: ��� ������ ���Ͽ� ����ü ���� ������ ����
   ��ȯ: void
*/

void StoreDataToFileInStruct(void)
{
	int i;
	FILE * fp = fopen("phoneDataStruct.dat", "wb");

	fwrute(&numOfData, sizeof(int), 1, fp);

	for (i = 0; i < numOfData; i++)
	{
		//����ü ���� ��°�� ����
		fwrite(phoneList[i], sizeof(phoneData), 1, fp);
	}

	fclose(fp);
}

/* �Լ�: void LoadDataFromFileInStruct(void)
   ���: ��� ������ ���Ϸκ��� ����ü ���� ������ ���� 
   ��ȯ: void
*/
void LoadDataFromFileInStruct(void)
{
	int i;

	FILE * fp=fopen("phoneDataStruct.dat", "rb");

	if (fp == NULL)
		return;

	fread(&numOfData, sizeof(int), 1, fp);

	for (i = 0; i < numOfData; i++)
	{
		phoneList[i] = (phoneData*)malloc(sizeof(phoneData));

		//����ü ���� ��°�� ����
		fread(phoneList[i], sizeof(phoneData), 1, fp);
	}

	fclose(fp);
}