#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int>> num;
    stack<pair<int, int>> s;
    int n;
    cin >> n;
    int arr[500005] = {0};

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        num.push({i, k});
    }
    
    s.push(num.top());
    num.pop();

    while (!num.empty()) {
        while (!s.empty() && num.top().second > s.top().second) {
            arr[s.top().first] = num.top().first;
            s.pop();
        }

        s.push(num.top());
        num.pop();
    }
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';