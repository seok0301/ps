#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};

int z(int R, int C, int n) {
    if (n == 0) return 0;
    int half = 1 << (n - 1);

    for (int dir = 0; dir < 4; dir++)
        if (R < (dx[dir] + 1) * half && C < (dy[dir] + 1) * half)
            return dir * (1 << (2 * n - 2)) + z(R - dx[dir] * half, C - dy[dir] * half, n - 1);
    return -1;
}

int main() {
    int R, C, n;
    cin >> n >> R >> C;
    cout << z(R, C, n);
}