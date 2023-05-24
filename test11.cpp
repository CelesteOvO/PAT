#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    vector<string> results = { "W", "T", "L" };
    vector<vector<double>> odds(3, vector<double>(3));

    for (int i = 0; i < 3; i++) {
        cin >> odds[i][0] >> odds[i][1] >> odds[i][2];
    }

    double maxProfit = 1.0;
    string bestBet;

    for (int i = 0; i < 3; i++) {
        int index;
        double maxOdd = 0.0;

        for (int j = 0; j < 3; j++) {
            if (odds[i][j] > maxOdd) {
                maxOdd = odds[i][j];
                index = j;
            }
        }

        bestBet += results[index];
        maxProfit *= maxOdd;
    }

    maxProfit = (maxProfit * 0.65 - 1.0) * 2.0;

    for(int i = 0; i < bestBet.length(); i++)
        cout << bestBet[i] << " ";
    cout << fixed << setprecision(2) << maxProfit << endl;

    return 0;
}

