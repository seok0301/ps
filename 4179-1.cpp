#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int vis[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C, state, ans = 1000002;
    cin >> R >> C;

    for (int i = 0; i < R; i++) cin >> board[i];
    queue<pair<int, int>> Q;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (board[i][j] == 'J') {
                Q.push({i, j});
                vis[i][j] = 1;
            }
    
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'F') {
                Q.push({i, j});
                vis[i][j] = -1;
            } else if (board[i][j] == '#') {
                vis[i][j] = -1;
            } else if (board[i][j] == '.') {
                vis[i][j] = 0;
            }
        }
    
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        state = vis[cur.X][cur.Y];

        if (state == -1) {
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (vis[nx][ny] == -1) continue;
                Q.push({nx, ny});
                vis[nx][ny] = -1;
            }
        } else {
            if (vis[cur.X][cur.Y] == -1) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                    cout << state;
                    return 0;
                }
                if (vis[nx][ny] != 0) continue;
                Q.push({nx, ny});
                vis[nx][ny] = state + 1;
            }
        }
    }

    cout << "IMPOSSIBLE";
}