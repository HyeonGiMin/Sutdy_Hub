/* Name : phoneFunc.c ver 1.7
   Content : 전화번호 컨트롤 함수
   Implementation : YSW
   
   Last modified 2018/08/29
   */

#include"common.h"
#include"phoneData.h"
#include"screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData* phoneList[LIST_NUM];

/* 함수: void InputPhoneData(void)
   기능: 전화번호 관련 데이터 입력 받아서 저장
   반환: void
*/

void InputPhoneData(void)
{
	phoneData* pData;
	int i;

	if (numOfData >= LIST_NUM)
	{
		puts("메모리 공간이 부족합니다.");
		return;
	}
	pData = (phoneData*)malloc(sizeof(phoneData));

	fputs("이름 입력 :",stdout);
	//gets(data.name);
	gets(pData->name);

	fputs("전화번호 입력 : ",stdout);
	//gets(data.phoneNum);
	gets(pData->phoneNum);

	if (!strcmp(phoneList[i]->name, pData->name) && !strcmp(phoneList[i]->phoneNum, pData->phoneNum))
	{
		puts("이미 입력된 데이터 입니다.");
		free(pData);
		getchar();
		return;
	}

	//phoneList[numOfData] = data;
	phoneList[numOfData] = pData;
	numOfData++;

	//파일 갱신
	StoreDataToFileInStruct();

	puts("입력이 완료되었습니다");
	getchar();

}

/* 함수: void ShowALLData(void)
   기능: 저장된 데이터 전체 출력
   반환: void
*/

void ShowALLData(void)
{
	int i;
	for (i = 0; i < numOfData; i++)
	{
		//ShowPhoneInfo(phoneList[i]);
		ShowPhoneInfoByPtr(phoneList[i]);
	}

	puts("출력이 완료되었습니다");
	getchar();
}

/* 함수: void SearchPhoneData(void)
   기능: 이름을 통한 데이터 검색
   반환: void
*/

void SearchPhoneData(void)
{
	int i;
	int searchSte = 0;   //찾으면 1,못 찾으면 0
	char searchName[NAME_LEN];

	fputs("찾는 이름은? ", stdout);
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
			puts("찾는 이름의 데이터가 존재하지 않습니다.");
		else
			puts("검색이 완료되었습니다.");

	getchar();
}

/* 함수: void DeletePhoneData(void)
   기능: 이름을 참조하여 데이터 삭제
   반환: void
*/

void DeletePhoneData(void)
{
	int i, j;
	char delName[NAME_LEN];

	int idxOfMatchingData[LIST_NUM];
	int matchedCount = 0;
	int selection = 0;
	int delIdx = 0;

	fputs("찾는 이름은? ", stdout);
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
	//		puts("삭제가 완료되었습니다.");
	//		getchar();
	//		return;
	//	}
	//}
	//puts("찾는 이름의 데이터가 존재하지 않습니다.");
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
		puts("찾는 이름의 데이터가 존재하지 않습니다.");
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

		fputs("선택 :", stdout);
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

	//파일 갱신
	StoreDataToFileInStruct();

	puts("삭제가 완료되었습니다.");
	getchar();
}


/* 함수: void StoreDataToFile(void)
   기능: 모든 데이터 파일에 저장
   반환: void
*/

void StoreDataToFile(void)
{
	int i;
	FILE * fp = fopen("phoneData.dat", "w");

	fwrite(&numOfData, sizeof(int), 1, fp);
	for(i=0;i<numOfData;i++)
	{
		//문자열을 구분짓는 문자 \n의 삽입 중요!
		fprintf(fp, "%s\n%s\n",phoneList[i]->name,phoneList[i]->phoneNum);
		free(phoneList[i]);
	}

	fclose(fp);
}

/* 함수: void LoadDataFromFile(void)
   기능: 모든 데이터 파일로부터 복원
   반환: void
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


        //문자열 구분을 위해 입력된 \n 문자 삭제
		sLen = strlen(phoneList[i]->phoneNum);
		phoneList[i]->name[sLen - 1] = 0;

		fgets(phoneList[i]->phoneNum, PHONE_LEN, fp);

		//문자열 구분을 위해 입력된 \n 문자 삭제
		sLen = strlen(phoneList[i]->phoneNum);
		phoneList[i]->phoneNum[sLen - 1] = 0;
		
	}

	fclose(fp);
}

/* 함수: void ChangePhoneData(void)
   기능: 이름을 참조하여 전화번호 변경 
   반환: void
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

	fputs("변경 대상의 이름은? ", stdout);
	gets(searchName);

	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(phoneList[i]->name, searchName))
			idxOfMatchingData[matchedCount++] = i;
	}

	if (matchedCount == 0)
	{
		puts("변경 대상 이름이 존재하지 않습니다.");
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

		fputs("선택 :", stdout);
		scanf_s("%d", &selection);
		while (getchar() != '\n');

		delIdx = idxOfMatchingData[selection - 1];
	}


	fputs("변경할 전화번호는? ", stdout);
	gets(newPhoneNumber);
	strcpy_s(phoneList[delIdx]->phoneNum, strlen(newPhoneNumber) + 1, newPhoneNumber);
	
	//파일 갱신
	StoreDataToFileInStruct();

	puts("변경이 완료되었습니다.");
	getchar();
}

/* 함수: void StoreDataToFileInStruct(void)
   기능: 모든 데이터 파일에 구조체 변수 단위로 저장
   반환: void
*/

void StoreDataToFileInStruct(void)
{
	int i;
	FILE * fp = fopen("phoneDataStruct.dat", "wb");

	fwrute(&numOfData, sizeof(int), 1, fp);

	for (i = 0; i < numOfData; i++)
	{
		//구조체 변수 통째로 삽입
		fwrite(phoneList[i], sizeof(phoneData), 1, fp);
	}

	fclose(fp);
}

/* 함수: void LoadDataFromFileInStruct(void)
   기능: 모든 데이터 파일로부터 구조체 변수 단위로 복원 
   반환: void
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

		//구조체 변수 통째로 복원
		fread(phoneList[i], sizeof(phoneData), 1, fp);
	}

	fclose(fp);
}