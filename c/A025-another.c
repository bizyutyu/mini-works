// A025:動物の体調管理
// 未クリア
#include <stdio.h>

int countPlans(long long int a[][2], int n, int s, int t) {
    int plans = 0;
    // ビットシフト(<<)を用いて問題を解く方法
    // 1ビットの左シフトは、2倍するのと同義
    // これにより、配列を使わずに解ける
    // 2^N 通りの組み合わせを試す
    for (long long int i = 0; i < (1 << n); i++) {
        int currentWeight = s;

        // 各日におけるダイエット・怠けの処理
        for (long long j = 0; j < n; j++) {
            if (i & (1 << j)) {
                // ダイエットをする
                currentWeight -= a[j][0];
            } else {
                // 何もしない
                currentWeight += a[j][1];
            }

            // 体重が制限を超えたら終了
            if (currentWeight > t) {
                break;
            }
        }

        // 体重が制限を超えない場合、有効な計画としてカウント
        if (currentWeight <= t) {
            plans++;
        }
    }

    return plans;
}

int main() {
    int n, s, t;
    scanf("%d %d %d", &n, &s, &t);

    long long int a[n][2];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }

    int result = countPlans(a, n, s, t);
    printf("%d\n", result);

    return 0;
}
