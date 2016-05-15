#include<stdio.h>
//求解一个矩阵里面数的问题
int find(int *matrix,int rows,int cols,int number){
	int found = 0;
	int column = cols - 1;
	if(matrix!=0 && rows != 0 && cols != 0){
		int row = 0;
		int col = cols-1;
		while(row<rows&&col>=0){
		if(matrix[row*cols+col]==number)
		{
			found=1;
			break;
		}
		else if(matrix[row*cols+col]>number)
			--col;
		else
			++row;
		}
	}
	return found;
}
void Test()
{
	int a[]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	int result=find(NULL,4,4,3);
	printf("%d\n",result);
}
