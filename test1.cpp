#include <iostream>
#include <string>

using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        cout << s[i];
        if (s[i] == '-')
            continue;
        if ((i + 1) % 3 == len % 3 && i != len - 1)
            cout << ",";
    }
    return 0;
}

// (i + 1) % 3：这是取变量 i + 1 除以 3 的余数。它用于确定当前字符在每三个字符的分组中的位置。
// len % 3：这是取字符串长度 len 除以 3 的余数。它用于确定字符串的总长度在每三个字符的分组中的位置。
// i != len - 1：这是检查当前字符是否是字符串的最后一个字符。len - 1 表示字符串最后一个字符的索引，因为字符串的索引是从 0 开始的。
// 如果当前字符是每三个字符的分组中的最后一个字符，并且不是字符串的最后一个字符，那么需要插入千位分隔符。
