// A055:脱出ゲーム
// 未完成
#include <stdio.h>
#include <string.h>
#define MAX_HW 100

int memo[MAX_HW][MAX_HW];
int returnAns(char s[][100], int h, int w, int st_h, int st_w);
int main(void){
    int h,w;
    
    scanf("%d %d\n", &h, &w);
    
    char s[h][w];
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(j<w-1){
                scanf("%c", &s[i][j]);
            }else{
                scanf("%c\n", &s[i][j]);
            }
        }
    }
    
    // スタートの座標を調べる。
    int st_h=0;
    int st_w=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j]=='S'){
                st_h = i;
                st_w = j;
                goto exit_loops;
            }
        }
    }
    
    exit_loops:
    
    // メモテーブル初期化
    for(int i=0; i<MAX_HW; i++){
        for(int j=0; j<MAX_HW; j++){
            memo[i][j] = -1;
        }
    }
    
    printf("%d %d %d %d\n", h, w, st_h, st_w);
    
    int ans = returnAns(s, h, w, st_h, st_w);
    
    if(ans==0){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    
    return 0;
}

int returnAns(char s[][100], int h, int w, int y, int x){
    
    int mv_up = y-1;
    int mv_right = x+1;
    int mv_down = y+1;
    int mv_left = x-1;
    
    int ans = 0;
    
    if(mv_up<0 || mv_right>=w || mv_down>=h || mv_left<0){
        ans = 1;
        printf("gg");
        return ans;
    }
    
    if(s[mv_up][x]=='.'){
        printf("↑");
        ans = returnAns(s, h, w, mv_up, x);
    }
    
    if(s[y][mv_right]=='.'){
        printf("→");
        ans = returnAns(s, h, w, y, mv_right);
    }
    
    if(s[mv_down][x]=='.'){
        printf("↓");
        ans = returnAns(s, h, w, mv_down, x);
    }
    
    if(s[y][mv_left]=='.'){
        printf("←");
        ans = returnAns(s, h, w, y, mv_left);
    }
    
    printf("aa");
    
    return ans;
}