#include <stdio.h>
#include <stdlib.h>

int AddFrom1Ton_Recursive(int n){
	return n <= 0 ? 0 : n + AddFrom1Ton_Recursive(n - 1);
}
int AddFrom1Ton_Interative(int n){
	int result = 0;
	for (int i = 1; i <= n; i++)
		result += i;
	return result;
}
//计算Fibonaccis数列
long long Fabonaccis(unsigned int n){
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fabonaccis(n - 1) + Fabonaccis(n - 2);
}
long long Fabonaccis1(unsigned int n){
	int result[2] = { 0, 1 };
	if (n < 2)return result[n];
	long long fibMinusOne = 1;
	long long fibMinusTwo = 0;
	long long fibn;
	for (unsigned int i = 2; i <= n; ++i)
	{
		fibn = fibMinusOne + fibMinusTwo;
		fibMinusOne = fibn;
		fibMinusTwo = fibMinusOne;
	}
	return fibn;
}
void Test()
{
	int a = 50;
	long long f = Fabonaccis1(a);
	printf("%lld\n",f);//打印长整形的方法
	printf("exit");
}