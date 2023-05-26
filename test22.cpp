#include <iostream>
#include <vector>
#include <string>

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
        switch(type) {
            case 1:
                for(int j = 0; j < N; j++) {
                    if(books[j].title == query)
                        result.push_back(books[j]);
                }
                break;
            case 2:
                for(int j = 0; j < N; j++) {
                    if(books[j].author == query)
                        result.push_back(books[j]);
                }
                break;
            case 3:
                for(int j = 0; j < N; j++) {
                    for(int k = 0; k < books[j].keywords.size(); k++) {
                        if(books[j].keywords[k] == query) {
                            result.push_back(books[j]);
                            break;
                        }
                    }
                }
                break;
            case 4:
                for(int j = 0; j < N; j++) {
                    if(books[j].publisher == query)
                        result.push_back(books[j]);
                }
                break;
            case 5:
                for(int j = 0; j < N; j++) {
                    if(books[j].year == stoi(query))
                        result.push_back(books[j]);
                }
                break;
        }
        if(result.empty())
            cout << "Not Found" << endl;
        else {
            for(auto & j : result) {
                cout << j.ID << endl;
            }
        }
    }

    return 0;
}