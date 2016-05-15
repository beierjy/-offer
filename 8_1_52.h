#include <iostream>
#include <vector>
using namespace std;
void multiply(const vector<double>& array1,vector<double>& array2){
	if(array1.size() <= 0)
		return;
	int len = array1.size();
	double* left = new double[len];
	double* right = new double[len];
	left[0] = 1;right[len - 1] = 1;
	for(int i = 1;i < len;i++)
		left[i] = array1[i - 1] * left[i-1];
	for(int i = len - 2;i >= 0;i--)
		right[i] = array1[i + 1] * right[i+1];
	for(int i = 0;i < len;++i)
		array2.push_back(left[i] * right[i]);
	delete[] left;
	delete[] right;
}
void multiply1(const vector<double>& array1,vector<double>& array2){
	int len1=array1.size();
	int len2=array2.size();
	if(len1==len2 && len1 > 1){
		array2[0] = 1;
		for(int i = 1;i < len1;++i){
			array2[i] = array2[i - 1] * array1[i - 1];
		}
		double temp = 1;
		for(int j = len1 - 2;j >= 0;--j){
			temp *= array1[j + 1];
			array2[j] *= temp;
		}
	}
}
void Test(){
	double a[2] = {1.1,2.2};
	vector<double> v(a,a+2);
	vector<double> v1(a,a+2);
	multiply1(v,v1);
	for(vector<double>::iterator iter = v1.begin();
		iter != v1.end();++iter)
		cout<<*iter<<" ";
}
		