#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isContinues(vector<int> number){
    if(number.size() < 1)
        return false;
    sort(number.begin(),number.end());
    int i = 0;
    while(number[i] == 0)
        i++;
    int countzero = i;
    for(;i < number.size();i++){
        if(i < number.size() -1 && number[i] == number[i+1])
            return false;
    }
    for(int j = countzero;j < number.size() - 1;j++){
        if(number[j] + 1 == number[j + 1])
            continue;
        else if(countzero > 0){
                number[j] = number[j] + 1;
                j--;
                countzero--;
        }
        else
            return false;
    }
    return true;
}
bool isContinues1(vector<int> number){
    if(number.size() < 1)
        return false;
    sort(number.begin(),number.end());
    int i = 0;
    while(number[i] == 0)
        i++;
    int countzero = i;
    int countgap = 0;
    int small = countzero;
    int big = countzero + 1;
    while(big < number.size()){
        if(number[big] == number[small])
            return false;
        countgap += number[big] - number[small] - 1;
        small = big;
        big++;
    }
    return countgap > countzero?false:true;
}
void Test(){
    int a[5] = {0,1,3,4,5};
    vector<int> ivec(a,a+5);
    cout<<isContinues1(ivec);
}
