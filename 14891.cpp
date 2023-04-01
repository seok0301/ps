#include <bits/stdc++.h>
using namespace std;
#define N first
#define DIR second
string s;
deque<int> gear[5];

int main() {
    for (int i = 1; i <= 4; i++) {
        cin >> s;
        for (auto c : s) gear[i].push_back(c - '0');
    }

    int k;
    cin >> k;

    while (k--) {
        int n, dir;
        cin >> n >> dir;
        queue<pair<int, int>> q;
        int step[5] = {};
        q.push({n, dir});
        
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            step[cur.N] = cur.DIR;
            int pre = cur.N - 1, nxt = cur.N + 1, d;
            cur.DIR == 1 ? d = -1 : d = 1;
            if (pre >= 1 && step[pre] == 0 && gear[pre][2] != gear[cur.N][6])
                q.push({pre, d});
            if (nxt <= 4 && step[nxt] == 0 && gear[cur.N][2] != gear[nxt][6])
                q.push({nxt, d});
        }

        for (int i = 1; i <= 4; i++) {
            if (step[i] == 1) {
                gear[i].push_front(gear[i].back()); gear[i].pop_back();
            } else if (step[i] == -1) {
                gear[i].push_back(gear[i].front()); gear[i].pop_front();
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 4; i++)
        ans += gear[i][0] * (1 << (i - 1));
    cout << ans;
}