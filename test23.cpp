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

int main() {
    std::string num;
    std::cin >> num;

    // 将数字字符串转换为整数
    unsigned long long int originalNum = std::stoull(num);
    // stoull函数是C++11中的函数，用于将字符串转换为unsigned long long int类型的整数

    // 将原数字翻倍
    unsigned long long int doubledNum = originalNum * 2;

    // 将原数字和翻倍后的数字转换为字符串
    std::string originalNumStr = std::to_string(originalNum);
    std::string doubledNumStr = std::to_string(doubledNum);

    // 检查翻倍后的数字是否是原数字的排列
    bool isPermutationResult = isPermutation(originalNumStr, doubledNumStr);

    // 输出结果
    if (isPermutationResult) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << doubledNumStr << std::endl;

    return 0;
}
