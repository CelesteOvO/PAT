#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long convertToDecimal(const string& number, int radix) {
    long long result = 0;
    for (char ch : number) {
        result = result * radix; // 乘以进制 相当于将前面的位数向左移动
        if (ch >= '0' && ch <= '9') { // 如果是数字字符
            result += ch - '0'; // 加上数字字符的值
        } else if (ch >= 'a' && ch <= 'z') { // 如果是字母字符
            result += ch - 'a' + 10; // 加上字母字符的值
        }
    }
    return result;
}
// convertToDecimal 函数用于将给定进制的数字转换为十进制。
// 它遍历输入的数字字符串，并根据当前字符的值和进制进行计算，得到十进制表示的结果。
// 举个例子，假设进制为 16（十六进制），输入的数字字符串为 "1a2"。首先，将结果 result 初始化为 0。开始遍历字符：
// 第一个字符 '1'，其对应的数值是 1，将结果 result 更新为 0 * 16 + 1 = 1。
// 第二个字符 'a'，其对应的数值是 10，将结果 result 更新为 1 * 16 + 10 = 26。
// 第三个字符 '2'，其对应的数值是 2，将结果 result 更新为 26 * 16 + 2 = 418。
// 最终得到的结果是 418，表示将十六进制数字字符串 "1a2" 转换为十进制表示的结果。

int findRadix(const string& number, long long target) {
    char maxChar = *max_element(number.begin(), number.end());
    // 首先，函数通过 max_element 函数找到数字字符串中的最大字符 maxChar，即字符串中的最大值。
    // 根据最大字符的类型（数字字符或小写字母字符），确定了进制的最小值 minRadix。
    int minRadix = (isdigit(maxChar) ? maxChar - '0' : maxChar - 'a' + 10) + 1;

    int left = minRadix;
    int right = max(target, (long long)minRadix) + 1;
    // 初始时，左边界 left 被设置为最小进制值，右边界 right 被设置为目标值 target 和最小进制值的较大值加 1。

    while (left <= right) {
        int mid = (left + right) / 2;
        long long value = convertToDecimal(number, mid);
        if (value == target) {
            return mid;
        } else if (value < 0 || value > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}
// findRadix 函数用于在给定数字字符串和目标十进制数之间寻找适合的进制。
// 它使用二分查找的方法，从最小可能的进制开始，逐步调整进制，计算转换后的值与目标值之间的关系。
// 如果找到了适合的进制，就返回该进制值；如果不存在适合的进制，就返回-1。

int main() {
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;

    if (tag == 1) { // N1 是已知进制的数字，N2 是待求进制的数字
        long long value = convertToDecimal(N1, radix);
        int result = findRadix(N2, value);
        if (result != -1) {
            cout << result << endl;
        } else {
            cout << "Impossible" << endl;
        }
    } else { // N2 是已知进制的数字，N1 是待求进制的数字
        long long value = convertToDecimal(N2, radix);
        int result = findRadix(N1, value);
        if (result != -1) {
            cout << result << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}

