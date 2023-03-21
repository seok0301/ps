#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> q;

void hanoi(int begin, int station, int end, int n) {
    if (n == 1) {
        q.push({begin, end});
    } else {
        hanoi(begin, end, station, n - 1);
        q.push({begin, end});
        hanoi(station, begin, end, n - 1);
    }
}

int main() {
    int n;
    cin >> n;
    hanoi(1, 2, 3, n);
    
    cout << q.size() << '\n';
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        cout << cur.first << ' ' << cur.second << '\n';
    }
}