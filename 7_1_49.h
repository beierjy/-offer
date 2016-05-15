#include <iostream>
using namespace std;
enum Status{kValid,kInvalid};
int g_nStatus=kValid;
long long strtoint(char* str,bool minus){
    long long num = 0;
    while(*str != '\0'){
        if(*str > '0'&& *str < '9'){
            int flog = minus ? -1:1;
            num = num * 10 + flog * (*str - '0');
            if((!minus && num > 0x7FFFFFFF) || (minus && num > 0x8000000))
            {
                num = 0;
                break;
            }
            str++;
        }
        else{
            num = 0;
            break;
        }
    }
    if(*str == '\0'){
        g_nStatus = kValid;
    }
    return num;
}
int setatoi(char* str){
    g_nStatus=kInvalid;
    int num=0;
    if(str != NULL && *str != '\0')
    {
        bool minus = false;
        if(*str == '+'){
            ++str;
        }
        if(*str == '-')
        {
            minus = true;
            ++str;
        }
        if(*str != '\0')
        {
            num = strtoint(str,minus);
        }
    }
    return (int)num;
}
void Test(){
    char* str="1234563";
    int a = setatoi(str);
    cout<<a;
}
