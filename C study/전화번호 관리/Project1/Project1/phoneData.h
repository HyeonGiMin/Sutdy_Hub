/* Name : phoneData.h Ver 1.0
   Content : 구조체 phoneData의 선언 및 정의
   Implementation : YSW
   
   Last modified 2018/08/28
   */

#ifndef __PHONEDATA_H__
#define __PHONEDATA_H__

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __phoneData
{
	char name[NAME_LEN]; //이름
	char phoneNum[PHONE_LEN]; //전화번호
}phoneData;

#endif