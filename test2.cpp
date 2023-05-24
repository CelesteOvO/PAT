#include <iostream>
using namespace std;
int main() {
    float c[1001] = {0};
    int m, n, t;
    float num;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t >> num;
        c[t] += num;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> num;
        c[t] += num;
    }

    int cnt = 0; // 计数非零项的个数
    for (int i = 0; i < 1001; i++) {
        if (c[i] != 0) // 检查当前项的系数是否为非零
            cnt++; // 输出非零项的个数
    }
    cout << cnt;
    // 因为N都是正数所以不会出现两个多项式的N相加是0的情况，所以可以这样计算

    for (int i = 1000; i >= 0; i--) {
        if (c[i] != 0.0)
            printf(" %d %.1f", i, c[i]);
    }
    return 0;
}
