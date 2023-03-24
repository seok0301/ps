#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, ans;
int board[505][505];

int arr[19][4][4] = {{{1, 1, 1, 1}}, {{1, 1}, {1, 1}}, {{0, 0, 1}, {1, 1, 1}}, {{1, 1, 1}, {1, 0, 0}}, {{1, 0, 0}, {1, 1, 1}}, {{1, 1, 1}, {0, 0, 1}}, {{0, 1, 1}, {1, 1, 0}}, {{1, 1, 0}, {0, 1, 1}}, {{1, 1, 1}, {0, 1, 0}}, {{0, 1, 0}, {1, 1, 1}}, {{1}, {1}, {1}, {1}}, {{1, 0}, {1, 0}, {1, 1}}, {{1, 1}, {0, 1}, {0, 1}}, {{0, 1}, {0, 1}, {1, 1}}, {{1, 1}, {1, 0}, {1, 0}}, {{1, 0}, {1, 1}, {0, 1}}, {{0, 1}, {1, 1}, {1, 0}}, {{0, 1}, {1, 1}, {0, 1}}, {{1, 0}, {1, 1}, {1, 0}}};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int iter = 0; iter < 19; iter++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = 0;
                for (int a = 0; a < 4; a++)
                    for (int b = 0; b < 4; b++)
                        val += board[i + a][j + b] * arr[iter][a][b];
                ans = max(val, ans);
            }
        }
    }
    
    cout << ans;
}