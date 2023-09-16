// 回る教習車
#include <iostream>
#include <list>
using namespace std;
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    int n;
    list<int> carList;
    int count = -1;
    int minimum = 1;
    
    // 台数を取得
    scanf("%d\n", &n);
    
    // リストを作成
    while(n > 0){
        int x;
        scanf("%d\n", &x);
        carList.push_back(x);
        n--;
    }
    
    // 
    while(!carList.empty()){
        for(auto itr = carList.begin(); itr != carList.end(); ++itr){
            if(*itr == minimum){
                itr = carList.erase(itr);
                --itr;
                minimum++;
            }
        }
        count++;
    }
    
    cout << count << endl;
    return 0;
}
