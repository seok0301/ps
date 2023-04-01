#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, h;
int board[32][12];
int ansBoard[32][12];

bool go(int k) {
    for (int i = 1; i <= n; i++) {
        int cur = i;
        for (int height = 1; height <= h; height++) {
            if (ansBoard[height][cur] == 1) cur++;
            else if (ansBoard[height][cur - 1] == 1) cur--;
        }
        if (cur != i) return false;
    }
    cout << k;
    return true;
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
    int p[4][400] = {};
    p[1][cnt - 1] = 1;
    p[2][cnt - 1] = 1; p[2][cnt - 2] = 1;
    p[3][cnt - 1] = 1; p[3][cnt - 2] = 1; p[3][cnt - 3] = 1;

    for (int k = 0; k < 4; k++) {
        do {
            bool isPossible = true;
            for (int i = 1; i <= h; i++)
                for (int j = 1; j < n; j++)
                    ansBoard[i][j] = board[i][j];
            for (int i = 0; i < cnt; i++) {
                if (p[k][i] == 1) {
                    int x, y;
                    tie(x, y) = v[i];
                    if (ansBoard[x][y] == -1) {
                        isPossible = false;
                        break;
                    }
                    ansBoard[x][y] = 1;
                    if (y - 1 > 0) ansBoard[x][y - 1] = -1;
                    if (y + 1 <= n) ansBoard[x][y + 1] = -1;
                }
            }
            if (!isPossible) continue;
            if (go(k)) return 0;
        } while (next_permutation(p[k], p[k] + cnt));
    }
    cout << -1;
}