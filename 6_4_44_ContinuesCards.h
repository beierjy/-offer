/*
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,
他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....
LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。
LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,
然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。
*/
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
