#include <iostream>
using namespace std;
class Temp{
public:
    Temp(){
        ++N;
        sum += N;
    }
    static void Reset(){N = 0; sum = 0};
    static unsigned int GetSum(){return sum;}
private:
    static unsigned int N;
    static unsigned int sum;
}

unsigned int Temp::N = 0;
unsigned int Temp::sum = 0;

unsigned int Sum_Solution1(unsigned int n){
    Temp::Reset();
    Temp* a = new Temp[n];
    delete[] a;
    return Temp::GetSum();
}
class A;
A* array[2];
class A{
public:
    virtual unsigned int Sum(unsigned int n){
        return 0;
    }
};
class B:public A{
    unsigned int Sum(unsigned int n){
        return array[!!n]->Sum(n - 1) + n;
    }
};
int Sum_Solution2(int n){
    A a;
    B b;
    array[0] = &a;
    array[1] = &b;
    int value = array[1]->Sum(n);
    return value;
}
typedef unsigned int (*fun)(unsigned int);
unsigned int Solution3_Teminator(unsigned int n){
    return 0;
}
unsigned int Sum_Solution3(unsigned int n){
    static fun f[2]={Solution3_Teminator,Sum_Solution3};
    return n+f[n!!](n-1);
}
template <unsigned int n>struct Sum_Solution4{
    enum Value{N = Sum_Solution4<n-1>::N + n};
}
template <>struct Sum_Solution4<1>{
    enum Value{N = 1};
}
