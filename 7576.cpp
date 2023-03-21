#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, state;
    cin >> m >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    queue<pair<int, int>> Q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 1)
                Q.push({i, j});
    
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        state = board[cur.X][cur.Y];

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != 0) continue;
            Q.push({nx, ny});
            board[nx][ny] = state + 1;
        }
    }

    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0) {
                flag = true;
                break;
            }
        if (flag) break;
    }

    if (flag) cout << -1;
    else cout << state - 1;
}