#include <stdio.h>
#define MAX_W 1000

// メモ化用の配列
int memo[MAX_W][MAX_W];

int calcMaxPoit(int s[][MAX_W], int h, int w, int x, int y);
int main(void){
    
    int h, w;
    
    scanf("%d %d\n", &h, &w);
    
    int s[1000][1000];
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(i<h-1){
                scanf("%d ", &s[i][j]);
            }else{
                scanf("%d\n", &s[i][j]);
            }
        }
    }
    
    for (int i = 0; i < MAX_W; i++) {
        for (int j = 0; j < MAX_W; j++) {
            memo[i][j] = -1;
        }
    }
    
    int max_point=0;
    
    for(int j=0; j<w; j++){
        int tmp = calcMaxPoit(s, h, w, 0, j);
        if (tmp > max_point) {
            max_point = tmp;
        }
    }
    
    printf("%d\n", max_point);
    
    return 0;
}

// 1つのスタートに対しての最大値を計算
int calcMaxPoit(int s[][MAX_W], int h, int w, int x, int y){
    
    int max=0;
    
    // 配列の範囲外なら0を返す
    if (x >= h || y < 0 || y >= w) {
        return 0;
    }

    // メモが存在するなら再計算せずにその結果を返す
    if (memo[x][y] != -1) {
        return memo[x][y];
    }
    
    for(int count=-1; count<=1; count++){
        int tmp = 0;
        int next_x = x+1;
        int next_y = y + count;
        if(0 <= next_y && next_y < w){
            tmp = s[x][y] + calcMaxPoit(s, h, w, next_x, next_y);
            if (tmp > max) {
            max = tmp;
            }
        }
        
    }
    
    // 計算結果をメモしておく
    memo[x][y] = max;

    return max;
    
}