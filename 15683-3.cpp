#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int board[10][10];
vector<pair<pair<int, int>, int>> v;
int n, m, ans = 64;

bool cctvImpossible(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == -1);
}

void cctv(int x, int y, int dir, int plus) {
    while (true) {
        x += dx[dir];
        y += dy[dir];
        if (cctvImpossible(x, y)) return;
        board[x][y] += plus;
    }
}

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

    if (cctvNum == 1) {
        cctv(cctvX, cctvY, 0, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 0, -1);

        cctv(cctvX, cctvY, 1, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 1, -1);

        cctv(cctvX, cctvY, 2, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 2, -1);

        cctv(cctvX, cctvY, 3, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 3, -1);
    } else if (cctvNum == 2) {
        cctv(cctvX, cctvY, 0, 1);
        cctv(cctvX, cctvY, 2, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 0, -1);
        cctv(cctvX, cctvY, 2, -1);

        cctv(cctvX, cctvY, 1, 1);
        cctv(cctvX, cctvY, 3, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 1, -1);
        cctv(cctvX, cctvY, 3, -1);
    } else if (cctvNum == 3) {
        cctv(cctvX, cctvY, 0, 1);
        cctv(cctvX, cctvY, 1, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 0, -1);
        cctv(cctvX, cctvY, 1, -1);

        cctv(cctvX, cctvY, 1, 1);
        cctv(cctvX, cctvY, 2, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 1, -1);
        cctv(cctvX, cctvY, 2, -1);

        cctv(cctvX, cctvY, 2, 1);
        cctv(cctvX, cctvY, 3, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 2, -1);
        cctv(cctvX, cctvY, 3, -1);

        cctv(cctvX, cctvY, 3, 1);
        cctv(cctvX, cctvY, 0, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 3, -1);
        cctv(cctvX, cctvY, 0, -1);
    } else if (cctvNum == 4) {
        cctv(cctvX, cctvY, 0, 1);
        cctv(cctvX, cctvY, 1, 1);
        cctv(cctvX, cctvY, 2, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 0, -1);
        cctv(cctvX, cctvY, 1, -1);
        cctv(cctvX, cctvY, 2, -1);
        
        cctv(cctvX, cctvY, 1, 1);
        cctv(cctvX, cctvY, 2, 1);
        cctv(cctvX, cctvY, 3, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 1, -1);
        cctv(cctvX, cctvY, 2, -1);
        cctv(cctvX, cctvY, 3, -1);

        cctv(cctvX, cctvY, 2, 1);
        cctv(cctvX, cctvY, 3, 1);
        cctv(cctvX, cctvY, 0, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 2, -1);
        cctv(cctvX, cctvY, 3, -1);
        cctv(cctvX, cctvY, 0, -1);

        cctv(cctvX, cctvY, 3, 1);
        cctv(cctvX, cctvY, 0, 1);
        cctv(cctvX, cctvY, 1, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 3, -1);
        cctv(cctvX, cctvY, 0, -1);
        cctv(cctvX, cctvY, 1, -1);
    } else if (cctvNum == 5) {
        cctv(cctvX, cctvY, 0, 1);
        cctv(cctvX, cctvY, 1, 1);
        cctv(cctvX, cctvY, 2, 1);
        cctv(cctvX, cctvY, 3, 1);
        bt(k + 1);
        cctv(cctvX, cctvY, 0, -1);
        cctv(cctvX, cctvY, 1, -1);
        cctv(cctvX, cctvY, 2, -1);
        cctv(cctvX, cctvY, 3, -1);
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