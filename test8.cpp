#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int totalTime = 0;
    int currentFloor = 0;

    for (int i = 0; i < N; i++) {
        int floor;
        cin >> floor;

        if (floor > currentFloor) {
            totalTime += (floor - currentFloor) * 6;
        } else {
            totalTime += (currentFloor - floor) * 4;
        }

        totalTime += 5;  // Time spent at each stop
        currentFloor = floor;  // Update current floor
    }

    cout << totalTime << endl;

    return 0;
}