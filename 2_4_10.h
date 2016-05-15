#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int NumberOf1(int n){
	int count = 0;
	int flag = 1;
	while (flag){
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}
int NumberOf2(int n){
	int count = 0;
	while (n){
		count++;
		n = (n - 1) & n;
	}
	return count;
}
void Test(){
	int n = 0x80000000;
	int count = NumberOf1(n);
	printf("%d\n", count);
}