#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
bool vis[200002];

int main() {
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({n, 0});

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        vis[cur.X] = true;
        if (cur.X == k) {
            cout << cur.Y;
            return 0;
        }

        if (cur.X <= 100000 && !vis[cur.X + 1]) q.push({cur.X + 1, cur.Y + 1});
        if (cur.X <= 100000 && !vis[cur.X * 2]) q.push({cur.X * 2, cur.Y + 1});
        if (cur.X > 0 && !vis[cur.X - 1]) q.push({cur.X - 1, cur.Y + 1});
    }
}   