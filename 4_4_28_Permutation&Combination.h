#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
//排列的问题
template<typename T>
void Permutation(T* pStr,unsigned startpos,vector<T*>& pvec,size_t N){
	if(startpos == N - 1){

		//解决的是正方体对角线问题
		/*if(((pStr[0] + pStr[1] + pStr[2] + pStr[3]) == (pStr[4] + pStr[5] + pStr[6] + pStr[7]))&&
			((pStr[0] + pStr[2] + pStr[4] + pStr[6]) == (pStr[1] + pStr[3] + pStr[5] + pStr[7]))&&
			((pStr[0] + pStr[1] + pStr[4] + pStr[5]) == (pStr[2] + pStr[3] + pStr[6] + pStr[7]))){
				T* a = (T*)malloc(sizeof(T) * N);
				for(int j = 0;j < N;j++)
					a[j] = pStr[j];
				pvec.push_back(a);
		}*/

		//解决的是八皇后问题
		bool isbreak = false;
		for(size_t i = 0;i < N;i++){
			for(size_t j = 0;j < N ;j++)
				if(i != j && (i - j == pStr[i] - pStr[j] || i - j == pStr[j] - pStr[i])){
					isbreak = true;
					break;
				}
				if(isbreak)
					break;
		}
		if(!isbreak){
			T* a = (T*)malloc(sizeof(T) * N);
			for(int k = 0;k < N;k++)
				a[k] = pStr[k];
			pvec.push_back(a);
		}
	}
	else{
			for(unsigned i = startpos;i < N;++i)
			{
				T temp = pStr[i];
				pStr[i] = pStr[startpos];
				pStr[startpos] = temp;
				Permutation(pStr,startpos + 1,pvec,N);
				temp = pStr[i];      //只是为了恢复原来的数组
				pStr[i] = pStr[startpos];
				pStr[startpos] = temp;

			}
	}

}
template<typename T>
void Permutation(T* pstr,vector<T*>& pvec,size_t N){
	if(pstr == NULL)
		return;
	Permutation(pstr,0,pvec,N);
}

//组合的问题
void Combination(char* pstr,int i,vector<char>& cvec){
	if(pstr == NULL || (*pstr == '\0' && i !=0))
		return;
	if(i == 0){
		for(vector<char>::iterator iter = cvec.begin();iter != cvec.end();++iter)
			printf("%c",*iter);
		printf("\n");
		return;
	}
	cvec.push_back(*pstr);
	Combination(pstr + 1,i - 1,cvec);
	cvec.pop_back();
	Combination(pstr + 1,i,cvec);
}

void Combination(char* pstr){
	if(pstr == NULL)
		return;
	int length = strlen(pstr);
	for(int i = 1;i <= length;++i){
		vector<char> cvec;
		Combination(pstr,i,cvec);
		printf("\n");
	}
}
//求取正方形上角的问题，并且使得对面的和相同
template<typename T,size_t F>
void PermutationQuestion(T (&pstr)[F]){
	if(pstr == NULL)
		return;
	vector<T*> pvec;
	Permutation(pstr,pvec,F);
	for(vector<T*>::iterator iter = pvec.begin();iter != pvec.end();++iter){
		for(int j = 0;j < F;j++)
				printf("%d ",(*iter)[j]);
			printf("\t");
	}
}

void Test(){
	char d[3] = {'a','b','c'};
	int c[8] = {0,1,2,3,4,5,6,7};
	//Permutation(c);
	//Combination(c);
	PermutationQuestion(c);
}
