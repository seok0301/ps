#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, r, c, d, ans;
int board[51][51];
stack<pair<int, int>> s;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    s.push({r, c});
    while(!s.empty()) {
        auto cur = s.top(); s.pop();
        if (board[cur.X][cur.Y] == 0) {
            board[cur.X][cur.Y] = 2;
            ans++;
        }

        bool clean = true;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (board[nx][ny] == 0) {
                clean = false;
                break;
            }
        }

        if (clean) {
            int nx = cur.X - dx[d];
            int ny = cur.Y - dy[d];
            if (board[nx][ny] == 1) {
                cout << ans;
                return 0;
            } else
                s.push({nx, ny});
        } else {
            d = (d + 3) % 4;
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            if (board[nx][ny] == 0)
                s.push({nx, ny});
            else
                s.push({cur.X, cur.Y});
        }
    }
}