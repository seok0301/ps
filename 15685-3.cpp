#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> v;
        while (g--) {
            v.push_back(1);
            for (int i = v.size() - 2; i >= 0; i--) {
                v[i] == 1 ? v.push_back(3) : v.push_back(1);
            }
        }

        board[x][y] = 1;
        x += dx[d];
        y += dy[d];
        for (auto dir : v) {
            board[x][y] = 1;
            d = (d + dir) % 4;
            x += dx[d];
            y += dy[d];
        }
        board[x][y] = 1;
    }

    int ans = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) {
            if (board[i][j] == 0) continue;
            if (board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) ans++;
        }
    cout << ans;
}