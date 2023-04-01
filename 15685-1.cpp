#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

tuple<int, int, int> dragon(int x, int y, int d, int g) {
    d %= 4;
    if (g == 0) {
        board[y][x] = 1;
        board[y + dy[d]][x + dx[d]] = 1;
        return {x + dx[d], y + dy[d], d};
    }
    int nx, ny, nd;
    tie(nx, ny, nd) = dragon(x, y, d, g - 1);
    dragon(nx - y + ny, ny + x - nx, d + 3, g - 1);
    return {nx - y + ny, ny + x - nx, d + 3};
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        dragon(x, y, d, g);
    }

    int ans = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] == 1) ans++;
    cout << ans;
}