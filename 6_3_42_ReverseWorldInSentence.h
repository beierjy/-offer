/*
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，
写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，
有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原
来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/
#include <iostream>
#include <string.h>

using namespace std;
void swap(char& a,char& b){
    char temp = a;
    a = b;
    b = temp;
}
void Reverse(char* pBegin,char* pEnd){
    if(pBegin == NULL || pEnd == NULL)
        return;
    while(pBegin < pEnd){
        swap(*pBegin,*pEnd);
        pBegin++;
        pEnd--;
    }
}
char* ReverseSentence(char* pData){
    if(pData == NULL)
        return NULL;
    char* pBegin = pData;
    char* pEnd = pData;
    while(*pEnd != '\0')
        pEnd++;
    pEnd--;
    Reverse(pBegin,pEnd);
    pBegin = pData;
    pEnd = pData;
    while(*pEnd != '\0'){
        while(*pBegin == ' '){
        if(*pBegin == '\0')
            break;
            pBegin++;
            pEnd++;
    }
        while(*pEnd != ' '){
            if(*pEnd == '\0')
              break;
            pEnd++;
        }
        pEnd--;
        Reverse(pBegin,pEnd);
        if(*(pEnd+1) == '\0')
            break;
        pBegin=pEnd+2;pEnd=pBegin;
    }
    return pData;
}
//左旋字符串
char* LeftRotateString(char* pStr,int n){
    if(pStr != NULL)
    {
        int nLength = static_cast<int>(strlen(pStr));
        if(nLength > 0 &&n>0&&n<nLength)
        {
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n -1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr +nLength-1;
            Reverse(pFirstStart,pFirstEnd);
            Reverse(pSecondFirst,pSecondEnd);
            Reverse(pFirstStart,pSecondEnd);
        }
    }
    return pStr;
}
void Test(){
    char str[20] ="I am a   student.";
    char* str1 = ReverseSentence(str);
    cout<<str1<<endl;
}
