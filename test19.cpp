#include <iostream>
#include <vector>
using namespace std;

bool isPalindromic(const vector<int>& digits) {
    int left = 0, right = digits.size() - 1;
    while (left < right) {
        if (digits[left] != digits[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

vector<int> convertToBase(int num, int base) {
    vector<int> digits;
    if (num == 0) {
        digits.push_back(0);
        return digits;
    }
    while (num > 0) {
        digits.push_back(num % base);
        num /= base;
    }
    return digits;
}

int main() {
    int N, b;
    cin >> N >> b;

    vector<int> digits = convertToBase(N, b);
    bool isPalin = isPalindromic(digits);

    cout << (isPalin ? "Yes" : "No") << endl;
    for (int i = digits.size() - 1; i >= 0; i--) {
        cout << digits[i];
        if (i != 0) {
            cout << " ";
        }
    }

    return 0;
}
