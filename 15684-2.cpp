#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, h, ans = 4;
int board[32][12];

void go(int lev) {
    for (int i = 1; i <= n; i++) {
        int cur = i;
        for (int height = 1; height <= h; height++) {
            if (board[height][cur] == 1) cur++;
            else if (board[height][cur - 1] == 1) cur--;
        }
        if (cur != i) return;
    }
    ans = min(lev, ans);
}

int main() {
    cin >> n >> m >> h;
    while (m--) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
        if (b - 1 > 0) board[a][b - 1] = -1;
        if (b + 1 <= n) board[a][b + 1] = -1;
    }

    vector<pair<int, int>> v;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j < n; j++)
            if (board[i][j] == 0)
                v.push_back({i, j});
    int cnt = v.size();
    int lev = 0;

    go(lev);
    lev++;
    for (int i = 0; i < cnt; i++) {
        board[v[i].X][v[i].Y] = 1;
        if (v[i].Y - 1 > 0) board[v[i].X][v[i].Y - 1] = -1;
        if (v[i].Y + 1 <= n) board[v[i].X][v[i].Y + 1] = -1;
        go(lev);
        lev++;
        for (int j = i + 1; j < cnt; j++) {
            if (board[v[j].X][v[j].Y] == -1) continue;
            board[v[j].X][v[j].Y] = 1;
            if (v[j].Y - 1 > 0) board[v[j].X][v[j].Y - 1] = -1;
            if (v[j].Y + 1 <= n) board[v[j].X][v[j].Y + 1] = -1;
            go(lev);
            lev++;
            for (int k = j + 1; k < cnt; k++) {
                if (board[v[k].X][v[k].Y] == -1) continue;
                board[v[k].X][v[k].Y] = 1;
                go(lev);
                board[v[k].X][v[k].Y] = 0;
            }
            lev--;
            board[v[j].X][v[j].Y] = 0;
            if (v[j].Y - 1 > 0) board[v[j].X][v[j].Y - 1] = 0;
            if (v[j].Y + 1 <= n) board[v[j].X][v[j].Y + 1] = 0;
        }
        lev--;
        board[v[i].X][v[i].Y] = 0;
        if (v[i].Y - 1 > 0) board[v[i].X][v[i].Y - 1] = 0;
        if (v[i].Y + 1 <= n) board[v[i].X][v[i].Y + 1] = 0;
    }
    ans == 4 ? cout << -1 : cout << ans;
}