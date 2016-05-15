#include<stdio.h>
#include <stdlib.h>
#define MAX  2000
long minimum(long a,long b,long c){
	if(a <= b && a <= c)
	return a;
	else if(b < a && b <= c)
	return b;
	else
	return c;
}
int GetUglyNumber(int index){
	if(index <= 0){
		return 0;
	}
	long* tempUgly = (long*)malloc(sizeof(long)*MAX);
	int T2 = 0;int T3 = 0;int T5 = 0;
	int mul2,mul3,mul5;
	tempUgly[0] = 1;int last = 0;
	while(last < index - 1){
		mul2 = tempUgly[T2] * 2;
		mul3 = tempUgly[T3] * 3;
		mul5 = tempUgly[T5] * 5;
		last++;
		tempUgly[last] = minimum(mul2,mul3,mul5);
		while(tempUgly[T2] * 2 <= tempUgly[last]){
			T2++;
		}
		while(tempUgly[T3] * 3 <= tempUgly[last]){
			T3++;
		}
		while(tempUgly[T5] * 5 <= tempUgly[last]){
			T5++;
		}
	}
	long Ugly = tempUgly[last];
	free (tempUgly);
	return Ugly;
}
int GetUglyNumber_Solution2(int index){
    if(index <= 0)
        return 0;
    int *pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;
    int* pMultiply2 = pUglyNumbers;
    int* pMultiply3 = pUglyNumbers;
    int* pMultiply5 = pUglyNumbers;
    while(nextUglyIndex < index){
        int min1 = minimum(*pMultiply2* 2,*pMultiply3*3,*pMultiply5*5);
        pUglyNumbers[nextUglyIndex] = min1;
        while(*pMultiply2*2 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply2;
        while(*pMultiply3*3 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply3;
        while(*pMultiply5*5 <= pUglyNumbers[nextUglyIndex])
            ++pMultiply5;
        ++nextUglyIndex;
        }
        int ugly = pUglyNumbers[index - 1];
        delete[] pUglyNumbers;
        return ugly;
}
void Test(){
	int index = 1500;
	long result1 = GetUglyNumber(index);
	long result = GetUglyNumber_Solution2(index);
	printf("%ld %ld",result,result1);
}


