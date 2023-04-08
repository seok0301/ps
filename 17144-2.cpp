#include <bits/stdc++.h>
using namespace std;
int r, c, t;
int board[52][52];
int diffuseBoard[52][52];
int up, down;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dx1[4] = {0, -1, 0, 1};
int dy1[4] = {1, 0, -1, 0};
int dx2[4] = {0, 1, 0, -1};
int dy2[4] = {1, 0, -1, 0};

void clean1(int x, int y, int dir, int dust) {
    if (board[x][y] == -1) return;
    int next_dust = board[x][y];
    board[x][y] = dust;

    int i = x + dx1[dir];
    int j = y + dy1[dir];
    if (i < 0 || i >= r || j < 0 || j >= c) {
        dir++;
        i = x + dx1[dir];
        j = y + dy1[dir];
    }
    clean1(i, j, dir, next_dust);
}

void clean2(int x, int y, int dir, int dust) {
    if (board[x][y] == -1) return;
    int next_dust = board[x][y];
    board[x][y] = dust;

    int i = x + dx2[dir];
    int j = y + dy2[dir];
    if (i < 0 || i >= r || j < 0 || j >= c) {
        dir++;
        i = x + dx2[dir];
        j = y + dy2[dir];
    }
    clean2(i, j, dir, next_dust);
}

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
            if (board[i][j] == -1) down = i;
        }
    up = down - 1;

    while (t--) {
        for (int i = 0; i < r; i++) fill(diffuseBoard[i], diffuseBoard[i] + c, 0);
        
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (board[i][j] > 0) diffuse(i, j);
        
        for (int i = 0; i < r; i++) 
            for (int j = 0; j < c; j++)
                board[i][j] += diffuseBoard[i][j];

        clean1(up, 1, 0, 0);
        clean2(down, 1, 0, 0);
    }

    int ans = 2;
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++)
            ans += board[i][j];
    cout << ans;
}