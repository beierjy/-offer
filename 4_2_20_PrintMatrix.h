//打印矩阵，按照顺时针的方向
#include <stdio.h>
#include <stdlib.h>

void PrintMatrixInCircle(int** number,int columns,int rows,int start);
void printMatrixClockwisely(int** numbers,int columns,int rows){
	if(numbers == NULL || columns <= 0 || rows <= 0)
		return;
	int start = 0;
	while(columns > start * 2 && rows > start * 2){
		PrintMatrixInCircle(numbers,columns,rows,start);
		++ start;
	}
}

void PrintMatrixInCircle(int** number,int columns,int rows,int start){
	int srows = start;int erows = rows - 1 - start;
	int scols = start;int ecols = columns - 1 - start;
	int sTrows = start;int eTrows = rows - 1 - start;
	int sTcols = start;int eTcols = columns - 1 - start;
	while(sTcols <= ecols)
		printf("%d\t",number[srows][sTcols++]);

	if(erows > srows){
		++sTrows;
		while(sTrows <= erows)
			printf("%d\t",number[sTrows++][ecols]);
	}
	if(ecols > scols && erows > srows){
		--eTcols;
		while(eTcols >= scols)
			printf("%d\t",number[erows][eTcols--]);
	}
	if(erows > srows + 1 && ecols > scols){   
		--eTrows;
		while(eTrows > srows)
			printf("%d\t",number[eTrows--][scols]);
	}
}

void Test(){
	int **n = (int**)malloc(sizeof(int*) * 4);
	for(int i = 0;i < 4;i++)
		n[i] = (int*)malloc(sizeof(int)*5);
	int count = 1;
	for(int i = 0;i < 4;++i)
		for(int j = 0;j < 5; j++)
			n[i][j] = count++;
	for(int i = 0;i < 4;++i){
		for(int j = 0;j < 5; j++)
			printf("%d\t",n[i][j]);
		printf("\n");
	}
	printMatrixClockwisely(n,5,4);
	for(int i = 0;i < 4;i++)
		free (n[i]);
	free (n);
}
