/*给定一个double类型的浮点数base和int类型的整数exponent。
求base的exponent次方。
*/
#include <stdlib.h>
#include <stdio.h>

bool g_InvalidInput = false;//设置全局变量来记录是否非法输入
//注意非整数的不能直接比较等于
bool equal(double num1, double num2){
	if (num1 - num2 > -0.000001
		&& num1 - num2 < 0.000001)
		return true;
	else
		return false;
}
/无符号正整数次幂的Power，直接递归求解
double PowerWithUnsignedExponet(double base, unsigned int exponent){
	double result = 1.0;
	if (exponent == 0)
		return 1;
	else
		return base;
	//这里将减少乘法的计算次数
	result = PowerWithUnsignedExponet(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1 == 1)
		result *= base;
	return result;
}
double Power(double base, int exponent){
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		perror("invalid input\n");
		return 0.0;
	}
	int absExponent = exponent;
	if (exponent < 0)
		absExponent = -exponent;
	double result = PowerWithUnsignedExponet(base, absExponent);//最后全部化为无符号的正整数幂
	if (exponent < 0)
		result = 1 / result;
	return result;
}
void Test(){
	int a = 3.0;
	int b = -1;
	double result = Power(a, b);
	printf("%e\n", result);
}
