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
