#include <iostream>
#include <limits>

using namespace std;

char FirstAppearingOnce(const char* str){
	if(str == NULL)
		return '\0';
	char ch = '\0';
	int* Hash =  new int[256];
	for(int i = 0;i < 256;++i)
		Hash[i] = -1;
	int j = 0;
	while(str[j] != '\0'){
		if(Hash[(int)(str[j])] == -1)
			Hash[(int)(str[j])] = j;
		else
			Hash[(int)(str[j])] = -2;
		j++;
	}
	int min = 257;
	for(int k = 0;k < 256;k++){
		if(Hash[k] >= 0 && Hash[k] < min){
			min = Hash[k];
		}
	}
	if(min >= 0 && min < 256)
		ch = str[min];
	return ch;
}
class CharStatistics
{
public:
	CharStatistics():index(0)
	{
		for(int i = 0;i < 256;++i)
			occurrence[i] = -1;
	}
	void Insert(char ch){
		int i = (int)ch;
		if(occurrence[i] == -1)
			occurrence[i] = index;
		else if(occurrence[i] >= 0)
			occurrence[i] = -2;
		index++;
	}
	char FirstAppearingOnce(){
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();
		for(int i = 0; i < 256;++i){
			if(occurrence[i] >= 0 && occurrence[i] < minIndex)
			{
				ch = (char)i;
				minIndex = occurrence[i];
			}
		}
			return ch;
	}
private:
	int occurrence[256];
	int index;
};


void Test(){
	CharStatistics s;
	char* str = "google";
	for(int i = 0; str[i] != '\0';++i)
		s.Insert(str[i]);
	cout<<s.FirstAppearingOnce();
	char c = FirstAppearingOnce(str);
	cout<<c<<endl;
}



