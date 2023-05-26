#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Student {
    string id;
    string name;
    int grade;
};

bool cmp1(const Student& a, const Student& b)
{
    return a.id < b.id;
}

bool cmp2(const Student& a, const Student& b)
{
    return a.name != b.name ? a.name < b.name : a.id < b.id;
}

bool cmp3(const Student& a, const Student& b)
{
    return a.grade != b.grade ? a.grade < b.grade : a.id < b.id;
}

int main()
{
    int N, C;
    cin >> N >> C;
    vector<Student> students(N);
    for (int i = 0; i < N; i++) {
        cin >> students[i].id >> students[i].name >> students[i].grade;
    }

    switch(C){
        case 1:
            sort(students.begin(), students.end(), cmp1);
            break;
        case 2:
            sort(students.begin(), students.end(), cmp2);
            break;
        case 3:
            sort(students.begin(), students.end(), cmp3);
            break;
    }

    for(auto & student : students)
    {
        cout << student.id << " " << student.name << " " << student.grade << endl;
    }

    return 0;
}
