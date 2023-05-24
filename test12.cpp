#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
    string id;
    int best;
    int score[4];
    int rank[4];

};
int main()
{
    int n,m;
    cin >> n >> m;
    vector<student> Students(n);
    for(int i = 0; i < n; i++)
    {
        cin >> Students[i].id >> Students[i].score[1] >> Students[i].score[2] >> Students[i].score[3];
        Students[i].score[0] = (Students[i].score[1] + Students[i].score[2] + Students[i].score[3]) / 3.0 + 0.5;
    }

    for(int flag = 0; flag <= 3; flag++) {
        sort(Students.begin(), Students.end(), [flag](student a, student b) { return a.score[flag] > b.score[flag]; });
        // 先排序
        Students[0].rank[flag] = 1;
        for(int i = 1; i < n; i++) {
            Students[i].rank[flag] = i + 1;
            if(Students[i].score[flag] == Students[i-1].score[flag]) // 如果当前分数和上一个分数相同，则排名相同
                Students[i].rank[flag] = Students[i-1].rank[flag]; // 排名相同
        }
    }

    for(int i = 0; i < n; i++) {
        Students[i].best = 0;
        int minRank = Students[i].rank[0];
        for(int j = 1; j <= 3; j++) {
            if(Students[i].rank[j] < minRank) {
                minRank = Students[i].rank[j];
                Students[i].best = j; // 是第几门最小 按顺序 A C M E
            }
        }
    }

    vector<string> queryIDs(m);
    for(int i = 0; i < m; i++) {
        cin >> queryIDs[i];
    }
    char c[4] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < m; i++) {
        int flag = 0;
        for(int j = 0; j < n; j++)
        {
            if(Students[j].id == queryIDs[i])
            {
                flag = 1;
                cout << Students[j].rank[Students[j].best] << " " << c[Students[j].best] << endl;
                // 输出最好排名科目的排名和最好排名科目
            }
        }
        if(flag == 0)
            cout << "N/A" << endl;
    }
    return 0;
}
