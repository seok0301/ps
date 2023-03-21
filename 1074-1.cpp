#include <bits/stdc++.h>
using namespace std;
int R, C, cnt;
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};

void z(int x, int y, int n) {
    if (n == 1) {
        for (int dir = 0; dir < 4; dir++) {
            if (x + dx[dir] == R && y + dy[dir] == C) {
                cnt += dir;
                return;
            }
        }
    } else {
        for (int dir = 0; dir < 4; dir++) {
            if (R < x + (dx[dir] + 1) * pow(2, n - 1) && C < y + (dy[dir] + 1) * pow(2, n - 1)) {
                cnt += dir * pow(2, 2 * n - 2);
                z(x + dx[dir] * pow(2, n - 1), y + dy[dir] * pow(2, n - 1), n - 1);
                break;
            }
        }
    }
}

int main() {
    int n;
    cin >> n >> R >> C;
    z(0, 0, n);
    cout << cnt;
}