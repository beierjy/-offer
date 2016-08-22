/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
#if 0
const int g_MaxNumberLength = 10;
char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

int compare(const void* strNumber1,const void* strNumber2);
void PrintMinNumber(int* numbers,int length){
	if(numbers == NULL || length <= 0)
		return;
	char** strNumbers = (char**)(new int[length]);
	for(int i = 0;i < length;++i){
		strNumbers[i] = (char*) (new char[g_MaxNumberLength + 1]);
		sprintf(strNumbers[i],"%d",numbers[i]);
	}
	qsort(strNumbers,length,sizeof(char*),compare);
	for(int i = 0;i < length;++i)
		printf("%s",strNumbers[i]);
	printf("\n");

	for(int i = 0;i < length;++i)
		delete []strNumbers[i];
	delete strNumbers;
}
int compare(const void* strNumber1,const void* strNumber2){
	strcpy(g_StrCombine1,*(const char**)strNumber1);
	strcat(g_StrCombine1,*(const char**)strNumber2);

	strcpy(g_StrCombine2,*(const char**)strNumber2);
	strcat(g_StrCombine2,*(const char**)strNumber1);

	return strcmp(g_StrCombine1,g_StrCombine2);
}
#endif
const int g_max = 10;
char* g_com1 = new char[g_max * 2 + 1];
char* g_com2 = new char[g_max * 2 + 1];

static int compare(const void* str1,const void* str2){
    strcpy(g_com1,*(char **)str1);
    strcat(g_com1,*(char **)str2);
    strcpy(g_com2,*(char **)str2);
    strcat(g_com2,*(char **)str1);
    return strcmp(g_com1,g_com2); 
}
string PrintMinNumber(vector<int> numbers) {
    string strResult;
    if(numbers.size() <= 0)
        return strResult;
    char** strNum = (char**)(new int [numbers.size() + 1]);
    int i = 0;
    for(vector<int>::iterator iter = numbers.begin();iter != numbers.end();++iter){
        strNum[i] = new char[g_max + 1];
        sprintf(strNum[i],"%d",*iter);
        ++i;
    }
    qsort(strNum,numbers.size(),sizeof(char*),compare);
    for(unsigned int i = 0;i < numbers.size();++i){
		string ss = strNum[i];
		 strResult += ss;
    }
	for(int i = 0;i < numbers.size();++i){
        delete[] strNum[i];
	}
    delete[] strNum;
	strNum = NULL;
    return strResult;
}
void Test(){
	int nums[] = {1,2,3,123,4};
	vector<int> vec(nums,nums+5);
	string str;
	str = PrintMinNumber(vec);
	cout<<str;
}
	



