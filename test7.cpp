#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K;
    cin >> K;

    vector<int> sequence(K);
    for (int i = 0; i < K; i++) {
        cin >> sequence[i];
    }

    int maxSum = 0;
    int currentSum = 0;
    int start = 0;
    int end = K - 1;
    int tempStart = 0;

    for (int i = 0; i < K; i++) {
        currentSum += sequence[i]; // 累加当前元素
        if (currentSum < 0) { // 如果累加结果小于 0，说明当前元素不能作为最大子序列的起始元素
            currentSum = 0; // 将累加结果清零
            tempStart = i + 1; // 将起始元素更新为下一个元素
        } else if (currentSum > maxSum) { // 如果累加结果大于当前最大子序列的和，则更新最大子序列的和、起始元素和结束元素
            maxSum = currentSum; // 更新最大子序列的和
            start = tempStart; // 更新最大子序列的起始元素
            end = i; // 更新最大子序列的结束元素
        }
    }

    if (maxSum == 0) {
        cout << "0 " << sequence[0] << " " << sequence[K - 1] << endl;
    } else {
        cout << maxSum << " " << sequence[start] << " " << sequence[end] << endl;
    }

    return 0;
}

// 这段代码使用了一种称为"Kadane's algorithm"（卡登算法）的方法来计算最大子序列的和。
// 它的基本思想是在遍历序列的过程中，维护两个变量：currentSum 表示当前子序列的和，maxSum 表示最大子序列的和。
// 对于每个元素 sequence[i]，将其加到 currentSum 上。
// 如果 currentSum 变成负数（即当前子序列的和小于零），说明当前子序列不可能是最大子序列的一部分，因此将 currentSum 重置为零，并更新 tempStart 为下一个可能的起始位置。
// 如果 currentSum 大于 maxSum，则更新 maxSum 为 currentSum，并更新 start 和 end 为 tempStart 和当前位置 i，即记录当前最大子序列的起始和结束位置。
// 继续遍历序列中的下一个元素，重复步骤 1-3。
// 通过这种方法，我们在遍历过程中不断调整当前子序列的起始位置，以确保我们只考虑连续的子序列，并始终保持记录最大和的变量 maxSum 更新为当前找到的最大和。
// 最后，如果 maxSum 为零，表示序列中的所有数字都是负数，此时最大子序列为空，因此输出整个序列的第一个数字和最后一个数字。
// 否则，输出最大和、最大子序列的起始数字和结束数字。