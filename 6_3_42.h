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
void Test(){
    char str[20] ="I am a   student.";
    char* str1 = ReverseSentence(str);
    cout<<str1<<endl;
}
