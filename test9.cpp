#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int K1, K2;
    cin >> K1;
    vector<int> exp1(K1);
    vector<double> coeff1(K1);
    for (int i = 0; i < K1; i++) {
        cin >> exp1[i] >> coeff1[i];
    }

    cin >> K2;
    vector<int> exp2(K2);
    vector<double> coeff2(K2);
    for (int i = 0; i < K2; i++) {
        cin >> exp2[i] >> coeff2[i];
    }

    int maxExp = exp1[0] + exp2[0];
    vector<double> product(maxExp + 1, 0);

    for (int i = 0; i < K1; i++) {
        for (int j = 0; j < K2; j++) {
            int exp = exp1[i] + exp2[j];
            double coeff = coeff1[i] * coeff2[j];
            product[exp] += coeff;
        }
    }

    int count = 0;
    for (int i = maxExp; i >= 0; i--) {
        if (product[i] != 0) {
            count++;
        }
    }

    cout << count;
    for (int i = maxExp; i >= 0; i--) {
        if (product[i] != 0) {
            cout << " " << i << " " << fixed << setprecision(1) << product[i];
        }
    }
    cout << endl;

    return 0;
}
