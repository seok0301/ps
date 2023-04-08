#include <bits/stdc++.h>
using namespace std;
int r, c, t;
int board[52][52];
int diffuseBoard[52][52];
int up, down;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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

void purificate() {
    for (int i = up - 1; i > 0; i--) board[i][0] = board[i - 1][0];
    for (int i = 0; i < c - 1; i++) board[0][i] = board[0][i + 1];
    for (int i = 0; i < up; i++) board[i][c - 1] = board[i + 1][c - 1];
    for (int i = c - 1; i > 0; i--) board[up][i] = board[up][i - 1];
    for (int i = down + 1; i < r - 1; i++) board[i][0] = board[i + 1][0];
    for (int i = 0; i < c - 1; i++) board[r - 1][i] = board[r - 1][i + 1];
    for (int i = r - 1; i > down; i--) board[i][c - 1] = board[i - 1][c - 1];
    for (int i = c - 1; i > 0; i--) board[down][i] = board[down][i - 1];
    board[up][1] = 0;
    board[down][1] = 0;
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

        purificate();
    }

    int ans = 2;
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++)
            ans += board[i][j];
    cout << ans;
}