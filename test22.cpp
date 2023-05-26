#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct book
{
    string ID;
    string title;
    string author;
    vector<string> keywords;
    string publisher;
    int year;
};

int main()
{
    int N;
    cin >> N;
    vector<book> books(N);
    for(int i = 0; i < N; i++) {
        cin >> books[i].ID;
        getchar();
        getline(cin, books[i].title);
        getline(cin, books[i].author);
        string keyword;
        while(cin >> keyword) {
            books[i].keywords.push_back(keyword);
            if(getchar() == '\n')
                break;
        }
        getline(cin, books[i].publisher);
        cin >> books[i].year;
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int type;
        string query;
        cin >> type;
        getchar();
        getchar();
        getline(cin, query);
        vector<book> result;
        cout << type << ": " << query << endl;
        if(type == 3) {
            stringstream ss(query);
            vector<string> keywords;
            string word;
            while(ss >> word) {
                keywords.push_back(word);
            }
            for(const auto& b : books) {
                bool allMatched = true;
                for(const auto& key : keywords) {
                    bool matched = false;
                    for(const auto& k : b.keywords) {
                        if(k == key) {
                            matched = true;
                            break;
                        }
                    }
                    if(!matched) {
                        allMatched = false;
                        break;
                    }
                }
                if(allMatched)
                    result.push_back(b);
            }
        }
        else {
            for(const auto& b : books) {
                if(type == 1 && b.title == query)
                    result.push_back(b);
                else if(type == 2 && b.author == query)
                    result.push_back(b);
                else if(type == 4 && b.publisher == query)
                    result.push_back(b);
                else if(type == 5 && b.year == stoi(query))
                    result.push_back(b);
            }
        }
        if(result.empty())
            cout << "Not Found" << endl;
        else {
            sort(result.begin(), result.end(), [](book a, book b) { return a.ID < b.ID; });
            for(const auto& b : result) {
                cout << b.ID << endl;
            }
        }
    }

    return 0;
}
