#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, k, ans;
int board[50][50];
int stickers[102][12][12];
vector<pair<int, int>> stickerSize;

bool matching(int x, int y, int i, int j, int sticker[12][12]) {
    for (int row = 0; row < x; row++)
        for (int col = 0; col < y; col++)
            if (sticker[row][col] && board[i + row][j + col]) return false;

    for (int row = 0; row < x; row++)
        for (int col = 0; col < y; col++)
            if (sticker[row][col] == 1) board[i + row][j + col] = 1;
    return true;
}

bool match(int x, int y, int sticker[12][12]) {
    for (int i = 0; i <= n - x; i++)
        for (int j = 0; j <= m - y; j++)
            if (matching(x, y, i, j, sticker)) return true;
    return false;
}

void rotate(int x, int y, int sticker[12][12]) {
    int tempSticker[12][12];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            tempSticker[i][j] = sticker[i][j];

    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            sticker[i][j] = tempSticker[x - j - 1][i];
    swap(x, y);
}

void test(int x, int y, int stickerNum) {
    int sticker[12][12];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            sticker[i][j] = stickers[stickerNum][i][j];

    for (int i = 0; i < 4; i++) {
        if (match(x, y, sticker)) return;
        rotate(x, y, sticker);
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        stickerSize.push_back({r, c});
        for (int row = 0; row < r; row++)
            for (int col = 0; col < c; col++)
                cin >> stickers[i][row][col];
    }

    for (int stickerNum = 0; stickerNum < k; stickerNum++) {
        auto sticker = stickerSize[stickerNum];
        test(sticker.X, sticker.Y, stickerNum);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans += (board[i][j] == 1);

    cout << ans;
}