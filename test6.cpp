#include <iostream>
#include <string>

using namespace std;

int main() {
    int M;
    cin >> M;

    string firstUnlockID;
    string lastLockID;
    string firstUnlockTime = "23:59:59";
    string lastLockTime = "00:00:00";

    for (int i = 0; i < M; i++) {
        string ID, signInTime, signOutTime;
        cin >> ID >> signInTime >> signOutTime;

        // signInTime 和 firstUnlockTime 是以 "HH:MM:SS" 的格式存储的字符串，它们可以进行直接的比较运算符的比较。
        // 因为时间是按照从大到小的顺序排列的，所以可以使用比较运算符来比较字符串的大小关系。
        // 比较字符串时，比较的是字符串的字符顺序。
        // 例如，"12:34:56" 小于 "13:45:00"，因为在第一个字符 "1" 相等的情况下，第二个字符 "2" 小于 "3"
        if (signInTime < firstUnlockTime) {
            firstUnlockTime = signInTime;
            firstUnlockID = ID;
        }

        if (signOutTime > lastLockTime) {
            lastLockTime = signOutTime;
            lastLockID = ID;
        }
    }

    cout << firstUnlockID << " " << lastLockID << endl;

    return 0;
}
