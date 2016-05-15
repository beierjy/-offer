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

