#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[10][10];
int ansBoard[10][10];
vector<pair<int, int>> cctv;
int n, m, ans;

bool OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}

void upd(int x, int y, int dir) {
    dir %= 4;
    while (true) {
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y) || ansBoard[x][y] == 6) break;
        if (ansBoard[x][y] != 0) continue;
        ansBoard[x][y] = 7;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6) cctv.push_back({i, j});
            if (board[i][j] == 0) ans++;
        }

    for (int iter = 0; iter < (1 << (2 * cctv.size())); iter++) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ansBoard[i][j] = board[i][j];

        int brute = iter;
        for (int i = 0; i < cctv.size(); i++) {
            int dir = brute % 4;
            brute /= 4;

            int x = cctv[i].X;
            int y = cctv[i].Y;
            int cctvNum = ansBoard[x][y];

            if (cctvNum == 1) {
                upd(x, y, dir);
            } else if (cctvNum == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            } else if (cctvNum == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            } else if (cctvNum == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            } else {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }
        int mn = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                mn += (ansBoard[i][j] == 0);
        ans = min(ans, mn);
    }

    cout << ans;
}