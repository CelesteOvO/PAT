#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Customer {
    int id;  // 客户编号
    int time;  // 客户处理时间
    int endTime;  // 完成时间
};

int main() {
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    vector<queue<Customer>> windows(N);  // 每个窗口的等待队列
    queue<Customer> lineOutside;  // 黄线外的等待队列

    vector<int> finishTime(K + 1, 0);  // 每个客户的完成时间，默认为0，表示未完成

    for (int i = 0; i < K; i++) {
        int time;
        cin >> time;
        Customer customer = {i + 1, time, 0};

        if (i < N * M) {
            // 将前N*M个客户依次加入到各个窗口的等待队列中
            int minSize = windows[0].size();
            int minIndex = 0;
            for (int j = 1; j < N; j++) {
                if (windows[j].size() < minSize) {
                    minSize = windows[j].size();
                    minIndex = j;
                }
            }
            windows[minIndex].push(customer);
        } else {
            // 将剩余的客户加入到黄线外的等待队列中
            lineOutside.push(customer);
        }
    }

    // 处理黄线外的等待队列中的客户
    while (!lineOutside.empty()) {
        // 找到等待队列最短的窗口
        int shortestWindow = 0;
        int shortestSize = windows[0].size();
        for (int i = 1; i < N; i++) {
            if (windows[i].size() < shortestSize) {
                shortestSize = windows[i].size();
                shortestWindow = i;
            }
        }

        // 将黄线外的客户加入到最短等待队列中
        Customer customer = lineOutside.front();
        lineOutside.pop();
        windows[shortestWindow].push(customer);
    }

    // 计算每个客户的完成时间
    for (int i = 0; i < N; i++) {
        int curTime = 0;  // 当前时间
        while (!windows[i].empty()) {
            Customer customer = windows[i].front();
            windows[i].pop();
            curTime = max(curTime, finishTime[customer.id]);  // 当前时间取决于前一个客户的完成时间
            customer.endTime = curTime + customer.time;  // 计算客户的完成时间
            finishTime[customer.id] = customer.endTime;  // 更新客户的完成时间
            curTime = customer.endTime;  // 更新当前时间
        }
    }

    // 处理查询
    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;

        if (finishTime[query] > 540) {
            // 超过17:00，输出 "Sorry"
            cout << "Sorry" << endl;

        } else {
            // 输出客户的完成时间
            int hours = 8 + finishTime[query] / 60;
            int minutes = finishTime[query] % 60;
            printf("%02d:%02d\n", hours, minutes);
        }
    }

    return 0;
}
