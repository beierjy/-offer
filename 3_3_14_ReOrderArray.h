//将所有的奇数移到偶数前面
#include <stdio.h>
#include <stdlib.h>

void swap(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
//普通的交换的方法
void reorderOddEven(int* pData,int length){
	if(pData == NULL || length <= 0)
		return;
	int optr = 0,eptr = length - 1;
	while(optr < eptr)
	{
		while((pData[optr] & 0x1) != 0 && optr < eptr)
			++optr;
		while((pData[eptr] & 0x1) == 0 && optr < eptr)
			--eptr;
		if(optr != eptr)
			swap(pData[optr],pData[eptr]);
	}
}
//使用函数指针
void Reorder(int *pData,unsigned int length,bool (*func)(int)){
	if(pData == NULL || length <= 0)//注意这里的测试需要length如果大于数组的话也会出现问题
		return;
	int* pBegin = pData;
	int* pEnd = pData + length - 1;
	while(pBegin < pEnd){
		while(pBegin < pEnd && !func(*pBegin))
			++pBegin;
		while(pBegin < pEnd && func(*pEnd))
			--pEnd;
		if(pBegin < pEnd){
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}
bool isEven(int n)
{
	return (n & 0x1) == 0;
}
void ReorderOddEven(int *pData,unsigned int length){
	Reorder(pData,length,isEven);
}
void Test(){
	int a[] = {1,2 ,3,4,5,6,7,8,9};
	//int a[] = {4,2 ,6,8,1,3,7,5,9};
	//int a[] = {1,3,7,5,9,2,4,6,8};
	ReorderOddEven(a,20);
	//reorderOddEven(a,9);
	for(int i = 0; i < 9;++i)
		printf("%d ",a[i]);
}
