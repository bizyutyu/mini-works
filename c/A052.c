// A052:階段登り
#include <stdio.h>
#define MAX_N 200000

int *stairsInfo(int *s, int n, int a, int b, int step);
int main(void){
    int n;
    int a,b;
    
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    
    int stairs[MAX_N] = {0};
    
    int *resultStairs = stairsInfo(stairs, n, a, b, -1);
    
    int result_sum = 0;
    
    for(int i=0; i<n; i++){
        if(resultStairs[i]==0){
            result_sum++;
        }
    }
    
    printf("%d\n", result_sum);
    
    return 0;
}

int *stairsInfo(int *s, int n, int a, int b, int step){
    
    int currentStep = 0;
    
    int d = n - step;
    
    if(d >= b){
        currentStep = step + b;
        if(s[currentStep] == 0){
        s[currentStep] = 1;
        s = stairsInfo(s, n, a, b, currentStep);
        }
    }
    
    if(d >= a){
        currentStep = step + a;
        if(s[currentStep] == 0){
        s[currentStep] = 1;
        s = stairsInfo(s, n, a, b, currentStep);
        }
    }
    
    if(s[n-1]==0){
        s[n-1]=1;
    }
    
    return s;
    
}