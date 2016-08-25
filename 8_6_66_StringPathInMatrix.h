#include <iostream>
#include <cstring>
using namespace std;
bool hasPathCore(char* matrix,int rows,int cols,int row,int col,char* str,int &PathLength,bool* visited);
bool hasPath(char* matrix,int rows,int cols,char* str){
	if(matrix == NULL || rows < 1 || cols < 1 || str == NULL)
		return false;
	bool *visited = new bool[rows * cols];
	memset(visited,0,rows * cols);
	int PathLength = 0;
	for(int row = 0;row < rows;++row)
	{
		for(int col = 0;col < cols;++ col)
		{
			if(hasPathCore(matrix,rows,cols,row,col,str,PathLength,visited))
				return true;
		}
	}
	delete visited;
	return false;
}
bool hasPathCore(char* matrix,int rows,int cols,int row,int col,char* str,int &PathLength,bool* visited){
	if(str[PathLength] == '\0')
		return true;
	bool hasPath = false;
	if(row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[PathLength] && !visited[row * cols + col])
	{
		++PathLength;
		visited[row * cols + col] = true;
		hasPath = hasPathCore(matrix,rows,cols,row+1,col,str,PathLength,visited) ||
			hasPathCore(matrix,rows,cols,row - 1,col,str,PathLength,visited) || 
			hasPathCore(matrix,rows,cols,row,col - 1,str,PathLength,visited) ||
			hasPathCore(matrix,rows,cols,row,col + 1,str,PathLength,visited);
		if(!hasPath)
		{
			--PathLength;
			visited[row * cols + col] = false;
		}
	}
	return hasPath;
}
void Test(){
	char matrix[12] = {'a','b','c','e','s','f','c','s','a','d','e','e'};
	char* str = "abcd";
	bool c = hasPath(matrix,3,4,str);
	cout<<c<<endl;
}
