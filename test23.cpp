#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> number;
vector<pair<char,bool>> IsFind;

int findIndex(char i)
{
    for(int j = 0; j < IsFind.size(); j++)
    {
        if(i == IsFind[j].first)
        {
            return j;
        }
    }

    return -1;
}

int main()
{
    string s;
    cin >> s;

    for(char i : s){
        if(number.empty())
        {
            number.push_back(i);
        }else{
            bool find = false;
            for(auto n : number)
            {
                if(i == n)
                {
                    find = true;
                }
            }
            if(!find)
            {
                number.push_back(i);
            }
        }
    }

    unsigned long long int num;
    num = 2 * stoull(s);
    string str = to_string(num);

    for(auto n : number)
    {
        IsFind.emplace_back(n, false);
    }

    for(char i : str)
    {
        for(auto n : number)
        {
            if(i == n)
            {
                int index = findIndex(i);
                if(index != -1)
                    IsFind[index].second = true;
            }
        }
    }

    int count = 0;
    for(auto n : IsFind)
    {
        if(!n.second)
        {
            cout << "No" << endl;
            cout << num;
            return 0;
        }else{
            count++;
            if(count == IsFind.size())
            {
                cout << "Yes" << endl;
                cout << num;
                return 0;
            }
        }
    }

    return 0;
}
