#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int cmax, n, sp, m;
int minNeed = INF, minBack = INF;
int e[510][510], dis[510], weight[510]; // e: edge, dis: distance, weight: weight of each station
bool visit[510]; // whether the station is visited
std::vector<int> pre[510], path, tempPath; // pre: previous station, path: shortest path, tempPath: temporary path

void dfs(int v) {
    tempPath.push_back(v); // 把当前节点加入临时路径
    if (v == 0) {
        int need = 0, back = 0;
        for (int i = tempPath.size() - 1; i >= 0; i--) { // 从终点开始遍历临时路径
            int id = tempPath[i]; // 当前节点
            if (weight[id] > 0) { // 如果当前节点的自行车数大于0
                // 如果该节点的自行车数量weight[id]大于0，表示当前节点的自行车数量超过需求，将其加入归还量back中。
                back += weight[id]; // 把当前节点的自行车数加到back中
            } else { // 如果该节点的自行车数量weight[id]小于等于0，表示当前节点的自行车数量不足，需要从归还量中补充，或者从前面的节点借用。
                if (back > (0 - weight[id])) {
                    // 如果归还量back大于等于当前节点的自行车数量的绝对值，说明可以从归还量中补充，将其加入归还量back中。
                    back += weight[id];
                } else { // 如果归还量back小于当前节点的自行车数量的绝对值，需要从PBMC借用，将其加入需求量need中，并将归还量back置为0。
                    need += ((0 - weight[id]) - back);
                    back = 0; // back置为0
                }
            }
        }
        // 在遍历完所有节点后，得到当前路径的需求量need和归还量back。
        // 然后，通过比较当前路径的需求量和归还量与全局最优值minNeed和minBack的大小，更新最优值和最优路径。
        if (need < minNeed) { // 如果当前路径的需求量need小于全局最优值minNeed，更新最优值和最优路径。
            minNeed = need;
            minBack = back;
            path = tempPath;
        } else if (need == minNeed && back < minBack) { // 如果当前路径的需求量need等于全局最优值minNeed，且归还量back小于全局最优值minBack，更新最优值和最优路径。
            minBack = back;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for (int i : pre[v]) // 遍历当前节点的所有前驱节点
        dfs(i); // 递归遍历
    tempPath.pop_back();
}

int main() {
    std::fill(&e[0][0], &e[0][0] + 510 * 510, INF);
    std::fill(dis, dis + 510, INF);

    std::cin >> cmax >> n >> sp >> m;

    for (int i = 1; i <= n; i++) {
        std::cin >> weight[i];
        weight[i] = weight[i] - cmax / 2; // i站点自行车的数量减去cmax的一半，表示多余的或者缺少的自行车的数量
        // weight是正数，表示多余的自行车的数量；weight是负数，表示缺少的自行车的数量。
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        std::cin >> e[a][b]; // a站点到b站点的距离
        e[b][a] = e[a][b];
    }

    dis[0] = 0;  // 起点
    for (int i = 0; i <= n; i++) {
        int u = -1, minn = INF; // u: 当前最短路径的顶点，minn: 当前最短路径的长度
        for (int j = 0; j <= n; j++) {
            if (!visit[j] && dis[j] < minn) { // 未访问过的顶点，且距离更短
                u = j; // 更新最短路径的顶点
                minn = dis[j]; // 更新最短路径的长度
            }
        }
        if (u == -1) break; // 所有顶点都已访问过
        visit[u] = true; // 标记u为已访问
        for (int v = 0; v <= n; v++) {
            if (!visit[v] && e[u][v] != INF) { // 未访问过的顶点，且u到v有边
                if (dis[v] > dis[u] + e[u][v]) { // 从u到v的距离更短
                    dis[v] = dis[u] + e[u][v]; // 更新从起点到v的距离
                    pre[v].clear(); // 清空v的前驱
                    pre[v].push_back(u); // 更新v的前驱
                } else if (dis[v] == dis[u] + e[u][v]) { // 从u到v的距离与当前最短路径的距离相同
                    pre[v].push_back(u); // 更新v的前驱
                }
            }
        }
    }

    dfs(sp);

    std::cout << minNeed << " 0";
    for (int i = path.size() - 2; i >= 0; i--)
        std::cout << "->" << path[i];
    std::cout << " " << minBack;

    return 0;
}
