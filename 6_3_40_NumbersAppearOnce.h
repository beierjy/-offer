/*一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
*/
#include <iostream>
#include <vector>
using namespace std;

unsigned int FindFirstBitIs1(int num){
    int indexBit = 0;
    while(((num & 1) == 0)&&(indexBit < 8 * sizeof(int))){
        num = num >> 1;
        indexBit++;
    }
    return indexBit;
}
bool isBit1(int num,unsigned int indexBit){
    num = num >> indexBit;
    return (num&1);
}
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2){
    if(data.size() == 0 ||data.size()&1 == 1)
        return;
    int resultExclusiveOR = 0; //任何数异或0等于它自己
    for(int i = 0;i < data.size();++i){
        resultExclusiveOR ^= data[i];
    }
    unsigned int index = FindFirstBitIs1(resultExclusiveOR);//找到第一个为1 的分界点
    *num1 = *num2 = 0;
    for(int i = 0;i < data.size();++i){
        if(isBit1(data[i],index)){//用这个分界点来将数字不同的数字分开成两个组
            *num1 ^= data[i];
        }
        else{
            *num2 ^= data[i];
        }
    }
}
void Test(){
    int a[8] = {2,4,3,6,3,2,5,5};
    vector<int> ivec(a,a+8);
    int num1,num2;
    FindNumsAppearOnce(ivec,&num1,&num2);
    cout<<num1<<" "<<num2<<endl;
}
