#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    int n = str.length();

    // n1：上部分的长度，即垂直线上方的字符数。
    // n2：底部横线的长度，即 U 形底部横线的字符数。
    // n3：下部分的长度，即垂直线下方的字符数。
    int n1 = (n + 2) / 3;
    int n3 = n1;
    int n2 = n - n1 - n3 + 2;

    // 根据题目中的条件，n1、n2 和 n3 满足以下条件：
    // n1 = n3
    // n1 + n2 + n3 - 2 = N
    // 代入第一个条件，我们可以得到：
    // 2 * n1 + n2 - 2 = N
    // 移项整理得到：
    // n2 = N - 2 * n1 + 2
    // 根据题目中的条件，我们希望 U 字形尽可能地接近正方形，即 n1、n2 和 n3 的值尽可能接近。
    // 所以最好有 n2 = N - 2 * n1 + 2 = n1
    // 由此可以得到 3 * n1 + 2 = N，整理得到：
    // n1 = (N + 2) / 3

    // 打印 U 形
    for (int i = 0; i < n1 - 1; i++) {
        std::cout << str[i];
        for (int j = 0; j < n2 - 2; j++) {
            std::cout << " ";
        }
        std::cout << str[n - i - 1] << std::endl;
    }

    // 打印底部线
    for (int i = n1 - 1; i < n1 + n2 - 1; i++) {
        std::cout << str[i];
    }

    std::cout << std::endl;

    return 0;
}
