#include <iostream>
#include <cmath>
using namespace std;

// 判断素数
bool isPrime(int num) {
    if (num <= 1) { // 0 和 1 不是素数
        return false;
    }
    int sqrtNum = sqrt(num); // 只需要判断到 sqrt(num) 即可
    for (int i = 2; i <= sqrtNum; i++) { // 从 2 开始判断
        if (num % i == 0) { // 如果能被整除，则不是素数
            return false;
        }
    }
    return true;
}

// 判断可逆素数
bool isReversiblePrime(int num, int radix) {
    // 转换为给定进制的反转数字
    int reversedNum = 0; // 反转后的数字
    int temp = num;
    while (temp > 0) {
        reversedNum = reversedNum * radix + temp % radix;
        // 从给定的数字 n 的个位开始，每次取出个位的数字，将其乘以进制数 radix，然后加到 reversed 上。
        temp /= radix;
        // 每次取出个位的数字后，将 n 除以 radix，这样就可以取出下一位的数字。
    }
    return isPrime(num) && isPrime(reversedNum);
}
// 例如，假设给定的数字 n 为 73，进制 radix 为 10：
// 初始时，reversed 为 0。
// 第一次循环：取出个位的数字 3，将其乘以 10 加到 reversed 上，此时 reversed 变为 3。
// 第二次循环：将 73 除以 10，得到商 7，丢弃个位 3，继续下一次循环。
// 第三次循环：取出个位的数字 7，将其乘以 10 加到 reversed 上，此时 reversed 变为 37。
// 最终得到的 reversed 为 37，即为数字 73 反转后的结果。


int main() {
    int N, D;
    while (cin >> N && N >= 0) {
        cin >> D;
        if (isReversiblePrime(N, D)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

