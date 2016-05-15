#include <iostream>

using namespace std;
int And(int num1,int num2){
    int sum,carry;
    do{
        sum = num1 ^ num2;
        carry = (num1 & num2)<<1;

        num1 = sum;
        num2 = carry;
    }while(carry != 0);
    return num1;
}
void Test(){
    cout<<And(5,9);
}
