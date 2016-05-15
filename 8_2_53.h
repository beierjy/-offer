#include <iostream>
#include <string.h>
#include <string>
using namespace std;

bool match1(char* str1,char* str2){
	if((str1 == NULL && str2 != NULL)||(str1 != NULL && str2 == NULL))
		return false;
	if(str1 == NULL && str2== NULL)
		return true;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i = len1-1;
	int j = len2-1;
	while(i >= 0 && j >= 0){
		int counti = 0;int countj = 0;
		if(str2[j] != '*' && str2[j] != '.'){
			if(str1[i] != str2[j])
				return false;
			else{
				i--; j--;
			}
		}
		else if(str2[j] == '.'){
			i--;j--;
		}
		else if(str2[j] == '*'){
			j--;
			if(str2[j] != str1[i] && str2[j] != '.'){
				j--;
				continue;
			}
			else if(str2[j] == str1[i] || str2[j] == '.'){
				int count_ = 1;
				int posi = i;int posj = j;
				while(str1[posi] == str1[i] && posi >= 0){
					counti++;
					posi--;
				}
				while(posj >= 0 && (str2[posj] == '*' || str2[posj] == str2[j]))
				{
					if(str2[posj] == str2[j]){
						countj++;
						posj--;
					}
					else if(str2[posj] == '*' && str2[posj + 1] != '*'){
						count_++;
						posj--;
					}
					else if(str2[posj] == '*' && str2[posj + 1] == '*'){
						while(str2[posj] == '*')
							posj--;
					}
					while(posj >= 0 && str2[posj] == '.' && (str2[posj-1] == str2[j] ||str2[posj-1] == '.')){
						countj++;
						posj--;
					} 
				}
				if(counti >= (countj - count_)){
					i = posi;
					j = posj;
				}
				else {
					return false;
				}
			}
		}
	}
	if(i != j)
		return false;
	return true;
}

bool matchCore(char* str,char* pattern);
bool match(char *str,char* pattern)
{
	if(str == NULL || pattern == NULL)
		return false;
	return matchCore(str,pattern);
}
bool matchCore(char* str,char* pattern){
	if(*str == '\0' && *pattern == '\0')
		return true;
	if(*str != '\0' && *pattern == '\0')
		return false;
	if(*(pattern + 1) == '*'){
		if(*pattern == *str ||(*pattern == '.' && *str != '\0'))
			return matchCore(str+1,pattern+2) || matchCore(str+1,pattern) || matchCore(str,pattern + 2);
		else
			return match(str,pattern+2);
	}
	if(*str == *pattern ||(*pattern == '.' && *str != '\0'))
		return matchCore(str + 1,pattern + 1);
	return false;
}
static string& str(){
	static string res="12";
	return res;
}
void Test(){
	char* str1 = "aaa";
	char str3[6]={'a','b','c','d','e','f'};
	char* str2 = "a.*a*a";
	bool c = match(str1,str2);
	//cout<<c<<endl;
	cout<<str();
}


