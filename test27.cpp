#include <iostream>
#include <string>

std::string decimalToThirteen(int num) {
    std::string thirteen;
    const std::string digits = "0123456789ABC";

    if (num == 0) {
        return "0";
    }

    while (num > 0) {
        int remainder = num % 13;
        thirteen = digits[remainder] + thirteen;
        num /= 13;
    }

    return thirteen;
}

int main() {
    int r, g, b;
    std::cin >> r >> g >> b;

    std::string marsRGB = "#";
    marsRGB += (decimalToThirteen(r).size() == 1) ? "0" + decimalToThirteen(r) : decimalToThirteen(r);
    marsRGB += (decimalToThirteen(g).size() == 1) ? "0" + decimalToThirteen(g) : decimalToThirteen(g);
    marsRGB += (decimalToThirteen(b).size() == 1) ? "0" + decimalToThirteen(b) : decimalToThirteen(b);

    std::cout << marsRGB << std::endl;

    return 0;
}
