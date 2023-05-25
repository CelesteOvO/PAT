#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 找到一棵树的最深根节点

vector<vector<int>> graph;
// 一个图的邻接表表示形式，其中graph是一个二维向量，graph[i]存储与节点i相邻的节点
vector<int> distances;
// 定义了一个向量distances，用于存储从根节点到每个节点的距离。初始时，将所有节点的距离初始化为-1。

// 使用广度优先搜索（BFS）算法遍历图。
// 从根节点开始，将根节点加入队列，并将其距离设置为0。
// 然后，进行循环，直到队列为空。
// 在循环中，取出队列中的节点，并遍历其相邻节点。
// 对于每个未访问过的相邻节点，我们将其距离设置为当前节点的距离加1，并将其加入队列。
void BFS(int start) {
    queue<int> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    // Initialize graph and distances
    graph.resize(N + 1);
    distances.resize(N + 1, -1);

    // Build the graph
    for (int i = 0; i < N - 1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    // Perform BFS from node 1
    BFS(1);

    // Find the node with maximum distance
    int maxDistance = 0;
    vector<int> deepestRoots;

    for (int i = 1; i <= N; i++) {
        if (distances[i] > maxDistance) {
            maxDistance = distances[i];
            // 通过遍历distances向量，找到具有最大距离的节点，并将其存储在maxDistance中。
            deepestRoots.clear();
            deepestRoots.push_back(i);
        } else if (distances[i] == maxDistance) {
            deepestRoots.push_back(i);
            // 遍历所有节点，找到与最大距离相等的节点，并将其存储在deepestRoots向量中。
        }
    }

    // Check if the graph is a tree
    bool isTree = true;
    // 检查图是否是一棵树。
    // 遍历distances向量，如果发现某个节点的距离为-1，则表示该节点无法从根节点访问到，因此图不是一棵树。
    for (int i = 1; i <= N; i++) {
        if (distances[i] == -1) {
            isTree = false;
            break;
        }
    }

    // Output the result
    if (isTree) {
        for (int root : deepestRoots) {
            cout << root << endl;
        }
    } else {
        cout << "Error: " << N - deepestRoots.size() << " components" << endl;
    }

    return 0;
}

