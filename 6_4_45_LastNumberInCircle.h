//圆圈里最后剩下的数字，约瑟夫环的问题
#include <iostream>
#include <list>

using namespace std;
//经典的环形算法
int LastRemaining(unsigned int n,unsigned int m){
    if(n < 1 || m < -1)
        return -1;
    unsigned int i = 0;
    list<int> numbers;
    for(i = 0; i < n;++i){
        numbers.push_back(i);
    }
     list<int>::iterator current = numbers.begin();
     list<int>::iterator next = numbers.begin();
     while(numbers.size() > 1){
        for(i = 1;i < m;++i){
            ++current;
            if(current == numbers.end())
                current = numbers.begin();
        }
        next = ++current;
        if(current == numbers.end())
            next = numbers.begin();
        current--;
        numbers.erase(current);
        current = next;
     }
     return *(numbers.begin());
}
//数学的方法。
int LastRemaining1(unsigned int n,unsigned int m){
    if(n < 1 || m < 1)
        return -1;
    int last = 0;
    for(int i = 2;i <= n;++i){
        last = (last + m) % i;
    }
    return  last;
}
void Test(){
    int n = 4000;
    int m = 937;
    int r = LastRemaining1(n,m);
    cout<<r<<endl;
}
