#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;  // 一个较大的值，表示无穷大
struct Edge {
    int destination;
    int length;
};

vector<vector<Edge>> graph;  // 存储城市间的道路信息
vector<int> teams;  // 存储每个城市的救援队数量
vector<int> shortestPaths;  // 存储最短路径数量
vector<int> maxTeams;  // 存储可以召集的最大救援队数量

void Dijkstra(int startCity, int endCity)
{
    int cityCount = graph.size();
    vector<int> distance(cityCount, INF);  // 存储起点到每个城市的最短距离
    vector<int> count(cityCount, 0);  // 存储起点到每个城市的最短路径数量
    vector<int> teamCount(cityCount, 0);  // 存储起点到每个城市可以召集的最大救援队数量

    distance[startCity] = 0;  // 起点到自身的距离为0
    count[startCity] = 1;  // 起点到自身的最短路径数量为1
    teamCount[startCity] = teams[startCity];  // 起点可以召集的救援队数量为起点城市的救援队数量

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // pair<int, int> 是优先队列中元素的类型，vector<pair<int, int>> 是底层容器的类型，greater<pair<int, int>> 是元素的比较准则。
    // pair<int, int> 表示优先队列中的元素类型，它是一个由两个整数组成的对，用来存储距离和城市编号。第一个整数表示距离，第二个整数表示城市编号。
    // vector<pair<int, int>> 表示底层容器的类型，它是一个存储 pair<int, int> 元素的向量（或动态数组）。
    // greater<pair<int, int>> 是一个比较准则，用于确定优先队列中元素的优先级。它表示按照元素的距离进行比较，距离小的元素优先级高。
    // greater 是一个函数对象，用于定义严格的弱序比较。在这个例子中，greater<pair<int, int>> 表示按照距离较小的顺序进行排序。

    pq.push(make_pair(0, startCity)); // 将起点加入优先队列
    // make_pair 创建一个距离为 0、城市编号为起点的元素，并将其加入优先队列中。
    // 由于使用了 greater<pair<int, int>> 作为排序准则，所以距离为 0 的元素会被放在优先队列的前面。

    // 在之后的算法中，可以通过 pq.top() 来访问优先队列中优先级最高（即最小距离）的元素，并使用 pq.pop() 将该元素从队列中移除。
    // 这样可以逐步取出最小距离的元素进行处理，以达到 Dijkstra 算法的目的。
    while (!pq.empty()) {
        int currCity = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        // 如果当前城市的距离已经大于最短路径中的某个路径，则跳过
        if (currDist > distance[currCity]) {
            continue;
        }

        // 遍历当前城市相邻的城市
        for (const auto& edge : graph[currCity]) {
            int nextCity = edge.destination;
            int nextDist = currDist + edge.length;

            // 如果到达下一个城市的距离更短，则更新最短距离和路径数量
            if (nextDist < distance[nextCity]) {
                distance[nextCity] = nextDist;
                count[nextCity] = count[currCity];
                teamCount[nextCity] = teamCount[currCity] + teams[nextCity];
                pq.push(make_pair(nextDist, nextCity));
            }
                // 如果到达下一个城市的距离与当前最短距离相等，则累加路径数量和救援队数量
            else if (nextDist == distance[nextCity]) {
                count[nextCity] += count[currCity];
                teamCount[nextCity] = max(teamCount[nextCity], teamCount[currCity] + teams[nextCity]);
            }
        }
    }

    shortestPaths[endCity] = count[endCity];
    maxTeams[endCity] = teamCount[endCity];
}

int main() {
    int N, M, startCity, endCity;
    cin >> N >> M >> startCity >> endCity;

    graph.resize(N);
    teams.resize(N);
    shortestPaths.resize(N);
    maxTeams.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> teams[i];
    }

    for (int i = 0; i < M; i++) {
        int c1, c2, L;
        cin >> c1 >> c2 >> L;
        graph[c1].push_back({c2, L});
        graph[c2].push_back({c1, L});
    }

    Dijkstra(startCity, endCity);

    cout << shortestPaths[endCity] << " " << maxTeams[endCity] << endl;

    return 0;
}
