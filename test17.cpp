#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Customer
{
    int arriveTime{};
    int processTime{};
};
int main()
{
    int N,K;
    cin >> N >> K;
    vector<Customer> customers;
    for(int i = 0; i < N; i++)
    {
        int hour, minute, second, processingTime;
        char colon;
        cin >> hour >> colon >> minute >> colon >> second;
        cin >> processingTime;
        int time = hour * 3600 + minute * 60 + second;
        if(time > 61200) continue; // 17:00:00 = 61200
        Customer customer;
        customer.arriveTime = time;
        customer.processTime = processingTime * 60;
        customers.push_back(customer);
    }

    sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b) {
        return a.arriveTime < b.arriveTime;
    });

    int total = 0;
    priority_queue<int, vector<int>, greater<> > q;
    for (int i = 0; i < K; ++i) q.push(28800);
    for(auto & customer : customers)
    {
        if (q.top() <= customer.arriveTime) {
            q.push(customer.arriveTime + customer.processTime);
            q.pop();
        } else {
            total += q.top() - customer.arriveTime;
            q.push(q.top() + customer.processTime);
            q.pop();
        }
    }
    cout << fixed << setprecision(1) << total / (60.0 * customers.size()) << endl;
    return 0;
}
