#include <stdlib.h>
#include <stdio.h>

bool g_InvalidInput = false;
bool equal(double num1, double num2){
	if (num1 - num2 > -0.000001
		&& num1 - num2 < 0.000001)
		return true;
	else
		return false;
}
//改进成高效的算法
double PowerWithUnsignedExponet(double base, unsigned int exponent){
	double result = 1.0;
	if (exponent == 0)
		return 1;
	else
		return base;
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
	double result = PowerWithUnsignedExponet(base, absExponent);
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