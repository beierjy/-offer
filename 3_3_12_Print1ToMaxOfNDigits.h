/*
输入数字n,打印从1到n位最大的正整数。
陷阱：n可能是个很大的数
*/
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

bool Increment(char* num)
{
	bool isOverFlow = false;
	int nTakeOver = 0;
	int nLength = strlen(num);
	for(int i = nLength - 1;i >= 0;i--)
	{
		int nSum = num[i] - '0' + nTakeOver;
		if(i == nLength - 1)
			nSum++;
		if(nSum >= 10){
			if(i == 0)
				isOverFlow = true;
			else{
				nSum -= 10;
				nTakeOver = 1;
				num[i] = '0'+ nSum;
			}
		}
		else{
			num[i] = '0' + nSum;
			break;
		}
	}
	return isOverFlow;
}
void PrintNumber(char* number)
{
	if(number == NULL)
		return;
	bool isBeginning0 = true;
	int length = strlen(number);
	for(int i = 0;i < length;++i)
	{
		if(isBeginning0 && number[i] != '0')
			isBeginning0 = false;
		if(!isBeginning0)
			printf("%c",number[i]);
	}
	printf("\t");
}


void Print1ToMaxOfNDigits(const int n){
	if(n <= 0)
		return;
	char* number = (char*)malloc(sizeof(char)*(n+1));
	memset(number,'0',n);
	number[n] = '\0';
	while(!Increment(number))
	{
		PrintNumber(number);
	}
	free (number);
}
//全排列，每一位都全排列
void Print1ToMaxOfDigitsRecursively(char* number,int length,int index){
	if(index == length - 1){
		PrintNumber(number);
		return;
	}
	 for(int i = 0; i< 10;++i)
	 {
		 number[index + 1] = i + '0';
		 Print1ToMaxOfDigitsRecursively(number,length,index + 1);
	 }
}

void Print1ToMaxOfNDigits1(int n){
	if(n <= 0)
		return;
	char* number = (char*)malloc(sizeof(char)*(n+1));
	number[n] = '\0';
	for(int i = 0; i < 10;++i){
		number[0] = i + '0';
		Print1ToMaxOfDigitsRecursively(number,n,0);
	}
	free (number);
}
void Test(){
	int n = -1;
	Print1ToMaxOfNDigits1(n);
}
