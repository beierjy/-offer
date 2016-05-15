#include<iostream>
#include <vector>
using namespace std;
#if 0
int getNumberOfKcore(vector<int>data,int length,int k,int start,int last){
        if(start < 0 || last < 0 || length < 1){
            return 0;
        }
        if(length == 1 && data[start] == k){
            return 1;
        }
        else if(length == 1 && data[start] != k){
            return 0;
        }
        int count = 0;
        int mid = (last + start)/2;
        if(data[mid] == k){
            int left = getNumberOfKcore(data,mid-start,k,start,mid-1);
            int right = getNumberOfKcore(data,last-mid,k,mid+1,last);
            count = left + right + 1;
        }
        else if(data[mid] > k){
            count = getNumberOfKcore(data,mid-start,k,start,mid-1);
        }
        else{
            count = getNumberOfKcore(data,last-mid,k,mid+1,last);
        }
        return count;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0)
            return 0;
        int count = getNumberOfKcore(data,data.size(),k,0,data.size()-1);
        return count;
    }
    #endif // 0
    int GetFirstK(vector<int>data,int k,int start,int last){
        if(start > last)
            return -1;
        unsigned int middleIndex = (start+ last)/2;
        int middleData = data[middleIndex];
        if(middleData == k){
            if((middleIndex > 0 && data[middleIndex - 1] != k) ||middleIndex == 0){
                return middleIndex;
            }
            else
                last = middleIndex-1;
        }
        else if(middleData > k)
            last = middleIndex - 1;
        else
            start = middleIndex + 1;
        return GetFirstK(data,k,start,last);
    }
    int GetLastK(vector<int>data,int k,int start,int last){
        if(start > last)
            return -1;
        unsigned int middleIndex = (start+ last)/2;
        int middleData = data[middleIndex];
        if(middleData == k){
            if((middleIndex > 0 && data[middleIndex + 1] != k) || middleIndex == data.size() - 1){
                return middleIndex;
            }
            else
                start = middleIndex + 1;
        }
        else if(middleData > k)
            last = middleIndex - 1;
        else
            start = middleIndex + 1;
        return GetLastK(data,k,start,last);
    }
    int GetNumberOfK(vector<int> data,int k){
        int number = 0;
        if(data.size() != 0){
            int first = GetFirstK(data,k,0,data.size()-1);
            int last = GetLastK(data,k,0,data.size()- 1);
            if(first != -1 && last != -1){
                number = last - first + 1;
            }
        }
        return number;
    }
    void Test(){
        int a[8] = {1,2,3,3,3,3,4,5};
        vector<int> ivec(a,a+8);
        int c = GetNumberOfK(ivec,3);
        cout<<c<<endl;

    }

