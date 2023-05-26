#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct student
{
    string registration_number;
    int score;
    int final_rank;
    int location_number;
    int local_rank;
};

bool cmp(const student& a, const student& b) {
    return a.score != b.score ? a.score > b.score : a.registration_number < b.registration_number;
}

int main()
{
    int n;
    cin >> n;
    vector<student> students;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<student> students_local(k);
        for(int j = 0; j < k; j++)
        {
            cin >> students_local[j].registration_number >> students_local[j].score;
            students_local[j].location_number = i + 1;
        }
        sort(students_local.begin(), students_local.end(), [](const student& a, const student& b) { return a.score > b.score; });
        for(int j = 0; j < k; j++)
        {
            students_local[j].local_rank = j + 1;
            if(j > 0 && students_local[j].score == students_local[j-1].score)
                students_local[j].local_rank = students_local[j-1].local_rank;
            students.push_back(students_local[j]);
        }
    }

    // 按分数排序
    sort(students.begin(), students.end(), cmp);

    // 补充final_rank
    for(int i = 0; i < students.size(); i++)
    {
        students[i].final_rank = i + 1;
        if(i > 0 && students[i].score == students[i-1].score)
            students[i].final_rank = students[i-1].final_rank;
    }

    cout << students.size() << endl;
    for(auto & student : students)
    {
        cout << student.registration_number << " " << student.final_rank << " " << student.location_number << " " << student.local_rank << endl;
    }
    return 0;
}
