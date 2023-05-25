// 定义一个结构体或类来表示电话记录，包括客户名、通话时间和日期、通话类型（上线/离线）等信息。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

struct CallRecord { // 记录一条通话记录
    string customerName;
    int month{};
    int day{};
    int hour{};
    int minute{};
    string status;
    int time{};
};

// 比较函数 cmp 用于对电话记录进行排序。它首先按照姓名（name 字段）进行比较，如果姓名不相同，则按照时间（time 字段）进行比较。
// 如果两条记录的姓名不相同，将按照姓名的字典序进行排序，即按照姓名的字符串比较结果进行排序。
// 如果两条记录的姓名相同，将按照时间进行排序，即按照时间的整数值进行比较。
bool compareRecords(const CallRecord& a, const CallRecord& b) {
    return a.customerName != b.customerName ? a.customerName < b.customerName : a.time < b.time;
}


// 计算从零点开始的通话费用
double billFromZero(const CallRecord& call, const int* rate) {
    double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
    // rate[call.hour] * call.minute 表示在通话的那个小时内的分钟费用。
    // rate[24] * 60 * call.day 表示在通话日期所在的一整天内的费用。
    // 先算，后面两个相减，实际上不会有打一整天下情况
    for (int i = 0; i < call.hour; i++)
        total += rate[i] * 60; // 循环遍历通话时间的小时数 call.hour 之前的每个小时，累加每个小时的分钟费用
    return total / 100.0; // 将累加的总费用 total 除以 100.0，得到以美元为单位的最终费用
}


int main() {
    // Read rate structure
    int rate[25] = {0};
    for (int i = 0; i < 24; i++) {
        cin >> rate[i];
        rate[24] += rate[i];
        // 这样设计费率数组的目的是方便计算通话日期所在的一整天的费用，可以直接使用 rate[24] 来表示全天的费率，而不需要对每个小时的费率进行累加。
    }

    // Read call records
    int n;
    cin >> n;
    vector<CallRecord> callRecords(n);
    for (int i = 0; i < n; i++) {
        cin >> callRecords[i].customerName;
        char colon;
        cin >> callRecords[i].month >> colon >> callRecords[i].day >> colon >> callRecords[i].hour >> colon >> callRecords[i].minute;
        cin >> callRecords[i].status;
        callRecords[i].time = callRecords[i].day * 24 * 60 + callRecords[i].hour * 60 + callRecords[i].minute;
    }

    // Sort call records by customer name
    sort(callRecords.begin(), callRecords.end(), compareRecords);

    map<string, vector<CallRecord> > custom; // 使用 map 存储每个客户的记录
    // 遍历记录，将配对的记录存储到 custom 中
    for (int i = 1; i < n; i++) {
        if (callRecords[i].customerName == callRecords[i-1].customerName && callRecords[i - 1].status == "on-line" && callRecords[i].status == "off-line") {
            custom[callRecords[i - 1].customerName].push_back(callRecords[i - 1]);
            custom[callRecords[i].customerName].push_back(callRecords[i]);
        }
    }

    // 遍历每个客户的记录，计算费用并输出结果
    for (const auto& it : custom) {
        vector<CallRecord> temp = it.second;
        cout << it.first;
        printf(" %02d\n", temp[0].month);
        double total = 0.0;
        for (int i = 1; i < temp.size(); i += 2) {
            double t = billFromZero(temp[i], rate) - billFromZero(temp[i - 1], rate);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }

    return 0;
}
