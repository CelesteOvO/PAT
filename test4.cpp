//通过递归遍历树的方式统计每个层级的叶子节点数。
// 使用一个二维向量 tree 来表示树的结构，每个节点的子节点存储在 tree 中对应的位置。
// 在统计过程中，将每个层级的叶子节点数存储在 levels 向量中。

#include <iostream>
#include <vector>
using namespace std;

vector<int> levels;

// 递归遍历树，统计每个层级的叶子节点数
void countLeafNodes(vector<vector<int>>& tree, int node, int level) {
    if (tree[node].empty()) { // 如果当前节点没有子节点，说明它是叶子节点
        if (levels.size() <= level) {
            levels.resize(level + 1); // 如果 levels 的大小不够表示当前层级的叶子节点数，则进行扩展
        }
        levels[level]++; // 将当前层级的叶子节点数加一
        return;
    }

    for (int child : tree[node]) { // 遍历当前节点的每个子节点，递归调用 countLeafNodes
        countLeafNodes(tree, child, level + 1);
    }
}

int main() {
    int N, M;
    while (cin >> N && N != 0) {
        cin >> M;
        vector<vector<int>> tree(N);
        // 第一个 vector 表示外层的容器，它存储了内层 vector 的集合。外层的 vector 被命名为 tree。
        // 第二个 vector 表示内层的容器，它存储了整数元素。内层的 vector 存储了与每个节点直接相连的子节点的编号。

        for (int i = 0; i < M; i++) {
            int ID, K;
            cin >> ID >> K;
            for (int j = 0; j < K; j++) {
                int child;
                cin >> child;
                tree[ID].push_back(child);
            }
        }

        levels.clear();
        countLeafNodes(tree, 1, 0);

        for (int i = 0; i < levels.size(); i++) {
            cout << levels[i];
            if (i != levels.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
