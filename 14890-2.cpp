#include <bits/stdc++.h>
using namespace std;
int n, l, board[102][102], ans;
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int solve(int step, int dir) {
    int x = dx[dir] * step;
    int y = dy[dir] * step;
    int arr[102];
    for (int i = 0; i < n; i++) {
        arr[i] = board[x][y];
        x += dy[dir]; y += dx[dir];
    }
    
    int idx = 0, cnt = 1;
    while (idx < n - 1) {
        int cur = arr[idx]; int nxt = arr[idx + 1];
        if (cur == nxt) {
            idx++; cnt++;
        }
        else if (abs(cur - nxt) > 1) return 0;
        else if (nxt == cur + 1) {
            if (cnt < l) return 0;
            idx++;
            cnt = 1;
        } else {
            if (idx + l > n - 1) return 0;
            for (int i = idx + 1; i < idx + l; i++)
                if (arr[i] != arr[i + 1]) return 0;
            idx += l;
            cnt = 0;
        }
    }
    return 1;
}

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    for (int step = 0; step < n * 2; step++) ans += solve(step % n, step / n);
    cout << ans;
}