#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, k, r, c;
int board[50][50];
int sticker[12][12];

bool matching(int i, int j) {
    for (int row = 0; row < r; row++)
        for (int col = 0; col < c; col++)
            if (sticker[row][col] && board[i + row][j + col]) return false;

    for (int row = 0; row < r; row++)
        for (int col = 0; col < c; col++)
            if (sticker[row][col] == 1) board[i + row][j + col] = 1;
    return true;
}

bool match() {
    for (int i = 0; i <= n - r; i++)
        for (int j = 0; j <= m - c; j++)
            if (matching(i, j)) return true;
    return false;
}

void rotate() {
    int tempSticker[12][12];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tempSticker[i][j] = sticker[i][j];

    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            sticker[i][j] = tempSticker[r - j - 1][i];
    swap(r, c);
}

int main() {
    cin >> n >> m >> k;

    while (k--) {
        cin >> r >> c;
        for (int row = 0; row < r; row++)
            for (int col = 0; col < c; col++)
                cin >> sticker[row][col];
        for (int rot = 0; rot < 4; rot++) {
            if (match()) break;
            rotate();
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans += (board[i][j] == 1);

    cout << ans;
}