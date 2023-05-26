#include <iostream>
#include <string>
#include <algorithm>

bool isPermutation(const std::string& num1, const std::string& num2) {
    // 将两个数字的字符进行排序
    std::string sortedNum1 = num1;
    std::string sortedNum2 = num2;
    std::sort(sortedNum1.begin(), sortedNum1.end());
    std::sort(sortedNum2.begin(), sortedNum2.end());

    // 比较排序后的数字是否相等
    return sortedNum1 == sortedNum2;
}

std::string multiplyByTwo(const std::string& num) {
    std::string result; // 用于存储乘以2后的结果
    int carry = 0; // 表示进位。初始化为0

    // 从数字字符串的最后一位开始遍历，即从num.length() - 1到0。这是因为在乘法中，我们从低位到高位进行计算。
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = (num[i] - '0') * 2 + carry; // 我们将当前位的字符转换为数字，然后乘以2，再加上进位
        carry = digit / 10; // 更新进位carry为digit / 10
        result.push_back((digit % 10) + '0'); // 我们将digit的个位数（即digit % 10）转换回字符
    }

    // 如果最后一次计算的结果carry大于0，则将carry转换为字符并添加到result中
    if (carry > 0) {
        result.push_back(carry + '0');
    }

    // 最后，我们使用std::reverse函数将result字符串反转，以得到正确的结果。
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string num;
    std::cin >> num;

    std::string doubledNum = multiplyByTwo(num);

    bool isPermutationResult = isPermutation(num, doubledNum);

    if (isPermutationResult) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << doubledNum << std::endl;

    return 0;
}
