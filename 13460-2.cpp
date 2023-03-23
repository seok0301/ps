#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
pair<int, int> red, blue;
char board[12][12];
int dist[12][12][12][12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                fill(dist[i][j][k], dist[i][j][k] + m, -1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                red = {i, j};
                board[i][j] = '.';
            }
            if (board[i][j] == 'B') {
                blue = {i, j};   
                board[i][j] = '.';
            }
        }
    }

    queue<tuple<int, int, int, int>> q;
    q.push({red.X, red.Y, blue.X, blue.Y});
    dist[red.X][red.Y][blue.X][blue.Y] = 0;

    while (!q.empty()) {
        int rx, ry, bx, by;
        tie(rx, ry, bx, by) = q.front(); q.pop();
        int curDist = dist[rx][ry][bx][by];

        if (curDist >= 10) {
            cout << -1;
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int n_rx = rx, n_ry = ry, n_bx = bx, n_by = by;

            while (board[n_bx + dx[dir]][n_by + dy[dir]] == '.') {
                n_bx += dx[dir];
                n_by += dy[dir];
            }

            if (board[n_bx + dx[dir]][n_by + dy[dir]] == 'O') {
                continue;
            }
            
            while (board[n_rx + dx[dir]][n_ry + dy[dir]] == '.') {
                n_rx += dx[dir];
                n_ry += dy[dir];
            }

            if (board[n_rx + dx[dir]][n_ry + dy[dir]] == 'O') {
                cout << curDist + 1;
                return 0;
            }

            if ((n_rx == n_bx) && (n_ry == n_by)) {
                if (dir == 0) {
                    rx > bx ? n_bx-- : n_rx--;
                } else if (dir == 1) {
                    ry > by ? n_by-- : n_ry--;
                } else if (dir == 2) {
                    rx > bx ? n_rx++ : n_bx++;
                } else {
                    ry > by ? n_ry++ : n_by++;
                }
            }

            if (dist[n_rx][n_ry][n_bx][n_by] != -1) continue;

            q.push({n_rx, n_ry, n_bx, n_by});
            dist[n_rx][n_ry][n_bx][n_by] = curDist + 1;
        }
    }
    cout << -1;
    return 0;
}