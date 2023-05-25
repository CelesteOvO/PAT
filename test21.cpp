#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// 找到一棵树的最深根节点

vector<vector<int>> graph;
// 一个图的邻接表表示形式，其中graph是一个二维向量，graph[i]存储与节点i相邻的节点
vector<int> distances;
// 定义了一个向量distances，用于存储从根节点到每个节点的距离。初始时，将所有节点的距离初始化为-1。
vector<int> deepestRoots;
set<int> s;
bool visit[10010];
int maxDistance = 0;

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

void DFS(int node, int height) {
    if(height > maxDistance) {
        deepestRoots.clear();
        deepestRoots.push_back(node);
        maxDistance = height;
    } else if(height == maxDistance){
        deepestRoots.push_back(node);
    }
    visit[node] = true;
    for(int i : graph[node]) {
        if(!visit[i])
            DFS(i, height + 1);
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
    int s1 = 0, cnt = 0;
    for (int i = 1; i <= N; i++) {
        if(!visit[i]) {
            DFS(i, 1);
            if(i == 1) {
                if (!deepestRoots.empty()) s1 = deepestRoots[0];
                for(int deepestRoot : deepestRoots)
                    s.insert(deepestRoot);
            }
            cnt++;
        }
    }

    if(cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {
        deepestRoots.clear();
        maxDistance = 0;
        fill(visit, visit + 10010, false);
        DFS(s1, 1);
        for(int i = 0; i < deepestRoots.size(); i++)
            s.insert(deepestRoots[i]);
        for(auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}

