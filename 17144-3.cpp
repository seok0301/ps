#include <bits/stdc++.h>
using namespace std;
int r, c, t;
int board[52][52];
int diffuseBoard[52][52];
int airPos[2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dxs[2][4] = {{0, -1, 0, 1}, {0, 1, 0, -1}};
int dys[2][4] = {{1, 0, -1, 0}, {1, 0, -1, 0}};

void diffuse(int x, int y) {
    int cnt = 0;
    int spread = board[x][y] / 5;
    for (int dir = 0; dir < 4; dir ++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] == -1) continue;
        diffuseBoard[nx][ny] += spread;
        cnt++;
    }
    diffuseBoard[x][y] -= cnt * spread;
}

int main() {
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) airPos[1] = i;
        }
    airPos[0] = airPos[1] - 1;

    while (t--) {
        for (int i = 0; i < r; i++) fill(diffuseBoard[i], diffuseBoard[i] + c, 0);
        
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (board[i][j] > 0) diffuse(i, j);
        
        for (int i = 0; i < r; i++) 
            for (int j = 0; j < c; j++)
                board[i][j] += diffuseBoard[i][j];

        for (int i = 0; i < 2; i++) {
            int x = airPos[i], y = 1;
            int dust = board[x][y];
            int prev_dust = 0;
            int dir = 0;
            
            while (true) {
                if (board[x][y] == -1) break;

                dust = board[x][y];
                board[x][y] = prev_dust;
                prev_dust = dust;
                int nx = x + dxs[i][dir];
                int ny = y + dys[i][dir];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    dir++;
                    nx = x + dxs[i][dir];
                    ny = y + dys[i][dir];
                }
                x = nx; y = ny;
            }
        }
    }

    int ans = 2;
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++)
            ans += board[i][j];
    cout << ans;
}