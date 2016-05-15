#include<iostream>
#include<cstring>

using namespace std;
int movingcountCore(int threshold,int rows,int cols,int row,int col,bool* visited);
bool check(int threshold,int rows,int cols,int row,int col,bool* visited);
int getDigitSum(int number);

int movingCount(int threshold,int rows,int cols){
	bool *visited = new bool [rows * cols];
	memset(visited,0,rows*cols);
	int count = movingcountCore(threshold,rows,cols,0,0,visited);
	delete[] visited;
	return count;
}
int movingcountCore(int threshold,int rows,int cols,int row,int col,bool* visited){
	int count = 0;
	if(check(threshold,rows,cols,row,col,visited)){
		visited[row * cols + col] = true;
		count = 1 + movingcountCore(threshold,rows,cols,row + 1,col,visited)
			+ movingcountCore(threshold,rows,cols,row - 1,col,visited) 
			+ movingcountCore(threshold,rows,cols,row,col + 1,visited)
			+ movingcountCore(threshold,rows,cols,row,col - 1,visited);
	}
	return count;
}
bool check(int threshold,int rows,int cols,int row,int col,bool* visited){
	if(row >= 0 && row <rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row * cols + col])
		return true;
	else
		return false;
}
int getDigitSum(int number){
	int sum = 0;
	while(number > 0){
		sum += number % 10;
		number = number / 10;
	}
	return sum;
}

void Test(){
	int a = movingCount(5,20,30);
	cout<<a<<endl;
}
