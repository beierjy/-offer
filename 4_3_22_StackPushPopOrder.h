//判断一个序列是不是另一个序列的出栈序列，使用辅助栈模拟出栈顺序
#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

bool isStackPopList(int* pushList,int* popList,int length){
	if(pushList == NULL || popList == NULL || length <= 0)
		return false;
	int currPush = 0;int currPop = 0;
	stack<int> tempStack;
	while(currPush < length && pushList[currPush] != popList[currPop]){
			tempStack.push(pushList[currPush]);
			currPush++;
		}
	if(currPush >= length && pushList[currPush] != popList[currPop])
		return false;
	currPop++;currPush++;
	while(currPop < length){
		if(tempStack.top() != popList[currPop] && currPush < length){
				while(currPush < length && pushList[currPush] != popList[currPop]){
					tempStack.push(pushList[currPush]);
					currPush++;
			}
				if(pushList[currPush] == popList[currPop])
					tempStack.push(pushList[currPush]);
		}
		if(currPush >= length)
			return false;
		currPop++;
		tempStack.pop();
	}
	return true;
}
bool IsPopOrder(const int* pPush,const int* pPop,int nLength){
	bool bPossible = false;
	if(pPush != NULL && pPop != NULL && nLength > 0){
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;
		stack<int> stackData;
		while(pNextPop - pPop < nLength){
			while(stackData.empty() || stackData.top() != *pNextPop){
				if(pNextPush - pPush == nLength)//如果序列已到末尾便停止
					break;
				stackData.push(*pNextPush);
				pNextPush++;
			}
			if(stackData.top() != *pNextPop)
				break;
			stackData.pop();
			pNextPop++;
		}
		if(stackData.empty() && pNextPop - pPop == nLength)
			bPossible = true;
	}
	return bPossible;
}

void Test(){
	int a[5] = {1,2,3,4,5};
	int b[6] = {4,5,3,2,1};
	bool c =  IsPopOrder(a,b,5);
	printf("%d",c);
}



