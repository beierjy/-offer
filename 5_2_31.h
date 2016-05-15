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