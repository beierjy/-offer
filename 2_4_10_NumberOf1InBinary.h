//注意：算法移位时候，右移高位添加1，容易形成死循环

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int NumberOf1(int n){
	int count = 0;
	unsigned int flag = 1;
	while (flag){ //当flag变成0时候，移动了机器数位数
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}
//当把一个数减去1时候，那么它的最右边那个1变成0
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
