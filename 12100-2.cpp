#include <bits/stdc++.h>
using namespace std;
#define num first
#define idx second
int n;
int board[30][30];
int ans[30][30];

void rotate() {
    int tempArr[30][30];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tempArr[i][j] = ans[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = tempArr[j][n - i - 1];
        }
    }
}

void tilt(int dir) {
    while (dir--) rotate();
    for (int row = 0; row < n; row++) {
        int res[30] = {};
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (ans[row][i] == 0) continue;
            if (res[index] == 0) res[index] = ans[row][i];
            else if (res[index] == ans[row][i]) res[index++] *= 2;
            else res[++index] = ans[row][i];
        }
        for (int i = 0; i < n; i++) ans[row][i] = res[i];
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int val = 0;
    for (int iter = 0; iter < 1024; iter++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = board[i][j];

        int brute = iter;
        for (int turn = 0; turn < 5; turn++) {
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }

        int mx = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mx = max(mx, ans[i][j]);
        val = max(val, mx);
    }
    cout << val;
}