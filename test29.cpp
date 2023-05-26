#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> sequence;
    for(int i = 0; i < 2; i++)
    {
        long int N;
        cin >> N;
        for(int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            sequence.push_back(num);
        }
    }
    sort(sequence.begin(),sequence.end());
    cout << sequence[(sequence.size() - 1) / 2] << endl;
    return 0;
}
