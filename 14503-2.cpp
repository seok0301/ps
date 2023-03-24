#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, r, c, d, ans, board[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    while (true) {
        if (board[r][c] == 0) {
            board[r][c] = 2;
            ans++;
        }

        bool cleaned = true;
        for (int dir = 0; dir < 4; dir++) {
            int nx = r + dx[dir];
            int ny = c + dy[dir];
            if (board[nx][ny] == 0) {
                cleaned = false;
                break;
            }
        }

        if (cleaned) {
            int nx = r - dx[d];
            int ny = c - dy[d];
            if (board[nx][ny] == 1) {
                cout << ans;
                return 0;
            } else {
                r = nx;
                c = ny;
            }
        } else {
            d = (d + 3) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];
            if (board[nx][ny] == 0) {
                r = nx;
                c = ny;
            }
        }
    }
}