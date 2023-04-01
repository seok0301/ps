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
        v.push_back(d);

        while (g--) {
            int vSize = v.size();
            for (int i = vSize - 1; i >= 0; i--) {
                v.push_back((v[i] + 1) % 4);
            }
        }
        
        board[x][y] = 1;
        for (auto dir : v) {
            x += dx[dir];
            y += dy[dir];
            board[x][y] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) {
            if (board[i][j] == 0) continue;
            if (board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) ans++;
        }
    cout << ans;
}