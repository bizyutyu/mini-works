// A025:動物の体調管理
// 未クリア
#include <stdio.h>
#define MAX_N 35

int countResults(int a[][2], int s, int t, int currentDay, int n);
int main(void){
    int n;
    int s,t;
    int cd = 0;
    
    scanf("%d %d %d", &n, &s, &t);
    
    int a[n][2];
    for(int i=0; i<n; i++){
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    
    // for (int i = 0; i < MAX_N; i++) {
    //     for (int j = 0; j < 2; j++) {
    //         memo[i][j] = -1;
    //     }
    // }
    
    int result = countResults(a, s, t, cd, n);
    
    printf("%d\n", result);
    
    return 0;
}

// すべてのA_iの和はSよりも小さい
// よって、s-a[currentDay][i]が負になることはないので、その条件は不要
int countResults(int a[][2], int s, int t, int currentDay, int n){
    
    if(currentDay >= n){
        return 1;
    }
    
    int counter=0;
    
    if(s + a[currentDay][1] <= t){
        int next_s = s + a[currentDay][1];
        int cd1 = currentDay + 1;
        counter += countResults(a, next_s, t, cd1, n);
    }
    
    int next_s = s - a[currentDay][0];
    int cd2 = currentDay + 1;
    counter += countResults(a, next_s, t, cd2, n);
    
    return counter;
    
}