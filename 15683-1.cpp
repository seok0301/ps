#include <bits/stdc++.h>
using namespace std;
int board[8][8];
vector<pair<pair<int, int>, int>> v;
int n, m, ans = 64;

void bt(int k) {
    if (k == v.size()) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 0) cnt++;
        ans = min(cnt, ans);
        return;
    }
    auto cur = v[k];
    int cctvX = cur.first.first;
    int cctvY = cur.first.second;
    int cctvNum = cur.second;

    if (cctvNum == 1)
    {
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        bt(k + 1);
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }

        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        bt(k + 1);
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }

        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        bt(k + 1);
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }

        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        bt(k + 1);
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
    }
    else if (cctvNum == 2)
    {
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        bt(k + 1);
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }

        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        bt(k + 1);
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
    }
    else if (cctvNum == 3)
    {
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        bt(k + 1);
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }

        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        bt(k + 1);
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }

        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        bt(k + 1);
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }

        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        bt(k + 1);
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }           
    }
    else if (cctvNum == 4) {
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        bt(k + 1);
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }
        
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        bt(k + 1);
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }

        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        bt(k + 1);
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }

        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        bt(k + 1);
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
    }
    else if (cctvNum == 5) {
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]++;
        }
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]++;
        }
        bt(k + 1);
        for (int y = cctvY; y < m; y++) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }
        for (int x = cctvX; x >= 0; x--) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
        for (int y = cctvY; y >= 0; y--) {
            if (board[cctvX][y] == -1) break;
            board[cctvX][y]--;
        }
        for (int x = cctvX; x < n; x++) {
            if (board[x][cctvY] == -1) break;
            board[x][cctvY]--;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 6) board[i][j] = -1;
            else if (tmp != 0) {
                board[i][j] = 10;
                v.push_back({{i, j}, tmp});
            }
        }
    bt(0);
    cout << ans;
}