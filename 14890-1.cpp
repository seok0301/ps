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

    int lev = arr[0];
    bool bridge[102] = {};
    for (int i = 1; i < n; i++) {
        if (arr[i] == lev) continue;
        if (abs(arr[i] - lev) > 1) return 0;
        if (arr[i] > lev) {
            for (int j = i - l; j < i; j++) {
                if (j < 0 || bridge[j] || arr[j] != lev) return 0;
            }
            lev++;
        } else {
            for (int j = i; j < i + l; j++) {
                if (j >= n || arr[j] != lev - 1) return 0;
                bridge[j] = true;
            }
            lev--;
            i += l;
            i--;
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