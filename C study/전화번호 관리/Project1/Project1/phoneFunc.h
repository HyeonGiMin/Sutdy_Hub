/* Name : phoneFunc.h Ver 1.3
Content : ��ȭ��ȣ ��Ʋ�� �Լ����� ����
Implementation : YSW

Last modified 2018/08/29
*/

#ifndef __PHONEFUNC_H__
#define __PHONEFUNC_H__

#include"phoneData.h"

void InputPhoneData(void);
void ShowALLData(void);

void SearchPhoneData(void);
void DeletePhoneData(void);
void ChangePhoneData(void);

void StoreDataToFile(void);
void LoadDataFromFile(void);

void LoadDataFromFileInStruct(void);
void StoreDataToFileInStruct(void);


#endif