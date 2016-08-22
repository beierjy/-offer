/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,
常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
*/
#include <stdio.h>
#include <stdlib.h>

bool g_InvalidInput = false;
int FindGreatestSubArray(int* pData,int nLength){
	if(pData == NULL || (nLength <= 0)){
		g_InvalidInput = true;
		return 0;
	}
	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;
	for(int i = 0;i < nLength;++i){
		if(nCurSum <= 0)
			nCurSum = pData[i];
		else
			nCurSum += pData[i];
		if(nCurSum > nGreatestSum)
			nGreatestSum = nCurSum;
	}
	return nGreatestSum;
}

void Test(){
	int a[] = {1,-2,3,10,-4,7,2,-5};
	int b = FindGreatestSubArray(a,8);
	printf("%d ",b);
}
