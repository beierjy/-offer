/*
找出字符串中第一个只出现一次的字符
详细描述：
接口说明
原型：
bool FindChar(char* pInputString, char* pChar);
输入参数：
char* pInputString：字符串
输出参数（指针指向的内存区域保证有效）：
char* pChar：第一个只出现一次的字符
如果无此字符 请输出'.'
*/
#include <iostream>

using namespace std;

char FirstNotRepeatingChar(char* str){
    if(str == NULL)
        return '\0';
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for(unsigned int i = 0;i < tableSize;++i)
        hashTable[i] = 0;
    char* pHashKey = str;
    while(*pHashKey != '\0')
        hashTable[*(pHashKey++)]++;
    pHashKey = str;
    while(*pHashKey != '\0'){
        if(hashTable[*(pHashKey)] == 1){
            return *pHashKey;
        }
            pHashKey++;
    }
    return '\0';
}

void Test(){
    char c[10] = "hdjskdfhd";
    char d = FirstNotRepeatingChar(c);
    cout<<d<<endl;
}
