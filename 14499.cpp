#include <bits/stdc++.h>
using namespace std;
int N, M, x, y, K;
int up, down, east, west, south, north;
int board[21][21];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

void roll(int dir) {
    if (dir == 1) {
        int u = up;
        up = west;
        west = down;
        down = east;
        east = u;
    } else if (dir == 2) {
        int u = up;
        up = east;
        east = down;
        down = west;
        west = u;
    } else if (dir == 3) {
        int u = up;
        up = south;
        south = down;
        down = north;
        north = u;
    } else {
        int u = up;
        up = north;
        north = down;
        down = south;
        south = u;
    }
}

void checkFloor() {
    if (board[x][y] == 0) {
        board[x][y] = down;
    } else {
        down = board[x][y];
        board[x][y] = 0;
    }
}

bool OOB(int a, int b) {
    return a < 0 || a >= N || b < 0 || b >= M;
}

int main() {
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        cin >> board[i][j];
    }

    while (K--) {
        int dir;
        cin >> dir;
        if (OOB(x + dx[dir], y + dy[dir])) continue;
        x += dx[dir];
        y += dy[dir];
        roll(dir);
        checkFloor();
        cout << up << '\n';
    }
}