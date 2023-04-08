#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, l, r;
int board[51][51], vis[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= n;
}

int calcDist(int x1, int y1, int x2, int y2) {
    return abs(board[x1][y1] - board[x2][y2]);
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    int ans = 0;
    while (true) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            fill(vis[i], vis[i] + n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 1) continue;
                cnt++;

                queue<pair<int, int>> bfs;
                vector<pair<int, int>> pos;
                int people = 0;
                pos.push_back({i, j});
                bfs.push({i, j});
                vis[i][j] = 1;
                people += board[i][j];

                while (!bfs.empty()) {
                    auto cur = bfs.front(); bfs.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (OOB(nx, ny) || vis[nx][ny] != 0) continue;
                        if (calcDist(cur.X, cur.Y, nx, ny) < l || calcDist(cur.X, cur.Y, nx, ny) > r) continue;
                        pos.push_back({nx, ny});
                        bfs.push({nx, ny});
                        vis[nx][ny] = 1;
                        people += board[nx][ny];
                    }
                }
                int avg = people / pos.size();
                for (auto cur : pos)
                    board[cur.X][cur.Y] = avg;
            }
        }
        if (cnt == n * n) {
            cout << ans;
            return 0;
        }
        ans++;
    }
}