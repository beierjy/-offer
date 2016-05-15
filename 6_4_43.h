#include <iostream>
#include <vector>
#include <math.h>
#include <cstdio>

using namespace std;
int g_maxValue = 6;
//#if 0
void Probability(int number,int* pProbability);
void Probability(int original,int current,int sum,int*pProbability);
void PrintProbability(int number){
    if(number < 1)
        return;
    int maxSum = g_maxValue * number;
    int* pProbability = new int[maxSum - number + 1];
    for(int i = number;i <= maxSum;++i)
        pProbability[i - number] = 0;
    Probability(number,pProbability);
    int total = pow(double(g_maxValue),number);

    for(int i = number;i <= maxSum;++i){
        double ratio = (double)pProbability[i - number] /total;
        printf("%d: %e\n",i,ratio);
    }
    delete[]pProbability;
}
void Probability(int number,int* pProbability){
    for(int i = 1;i <= g_maxValue;i++)
        Probability(number,number,i,pProbability);
}

void Probability(int original,int current,int sum,int*pProbability){
    if(current == 1)
        pProbability[sum - original]++;
    else{
        for(int i = 1;i <= g_maxValue;++i){
            Probability(original,current-1,i+sum,pProbability);
        }
    }
}
//#endif
#if 0
void PrintProbability(int number){
    if(number < 1){
        return;
    }
    int* pProbability[2];
    pProbability[0] = new int[g_maxValue* number + 1];
    pProbability[1] = new int[g_maxValue* number  + 1];
    for(int i = 0;i <= g_maxValue;++i){
        pProbability[0][i] = 0;
        pProbability[1][i] = 0;
    }
    int flog =1;
    for(int i = 1;i <= g_maxValue;++i){
        pProbability[flog][i] = 1;
    }
    for(int k = 2;k <= number;k++){
        for(int i = 0;i < k;++i)
            pProbability[1-flog][i] = 0;
        for(int i = k;i <= g_maxValue * k;++i){
            pProbability[1-flog][i] = 0;
            for(int j = 1;j <= i && j <= g_maxValue;j++){
                pProbability[1-flog] += pProbability[flog][i-j];
            }
        flog = 1-flog;
        }
    }
    double total = pow((double)g_maxValue,number);
    for(int i = number;i <= number*g_maxValue;++i){
        printf("%d : %e\n",i,pProbability[flog][i]/total);
    }
    delete[] pProbability[0];
    delete[] pProbability[1];
}
#endif // 0
void Test(){
    int num;
    cin>> num;
    PrintProbability(num);
}
