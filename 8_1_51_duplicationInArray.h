/*在一个长度为n的数组里的所有数字都在0到n-1的范围内。
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。
*/
#include <iostream>
using namespace std;

bool duplicate(int number[],int length,int& duplication){
	if(number == NULL || length < 2){
		duplication = -1;
		return false;
	}
	for(int i = 0;i < length;++i)
	{
		if(number[i] < 0 || number[i] > length -1){
			duplication = -1;
			return false;
		}
	}
	int i = 0;
	int m;
	while(i < length){
		m = number[i];
		if(m == i)
		    i++;
		else if(m != i)
		{
			if(number[m] == m){
				duplication = m;
				return true;
			}
			else{
				int temp = number[i];
				number[i] = number[m];
				number[m] = temp;
			}
		}
	}
	return false;
}
void Test(){
	int  a[7] = {0,3,1,3,2,5,7};
	int c;
	duplicate(a,7,c);
	cout<<c<<endl;
}

