#include <iostream>
#include <string>
#include <algorithm>

bool isPalindromic(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return str == reversed;
}

std::string addReversed(const std::string& num) {
    std::string reversed = num;
    std::reverse(reversed.begin(), reversed.end());

    std::string sum;
    int carry = 0;

    for (size_t i = 0; i < num.length(); i++) {
        int digit = (num[i] - '0') + (reversed[i] - '0') + carry;
        carry = digit / 10;
        sum.push_back((digit % 10) + '0');
    }

    if (carry > 0) {
        sum.push_back(carry + '0');
    }

    return sum;
}

int main() {
    long long N;
    int K;
    std::cin >> N >> K;

    std::string num = std::to_string(N);
    int steps = 0;

    while (!isPalindromic(num) && steps < K) {
        num = addReversed(num);
        steps++;
    }

    reverse(num.begin(), num.end());

    std::cout << num << std::endl;
    std::cout << steps << std::endl;

    return 0;
}
