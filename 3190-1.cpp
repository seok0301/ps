#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define TIME first
#define DIR second
int n, k, l;
int board[102][102];
queue<pair<int, char>> direction;
queue<tuple<int, int, int>> joint;
pair<int, int> head, tail;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

int main() {
    cin >> n;
    cin >> k;

    while (k--) {
        int a, b;
        cin >> a >> b;
        board[a - 1][b - 1] = 1;
    }

    cin >> l;
    while (l--) {
        int x;
        char c;
        cin >> x >> c;
        direction.push({x, c});
    }

    board[0][0] = -1;
    int time = 0;
    int dir = 0;
    int tailDir = 0;
    head = {0, 0};
    tail = {0, 0};

    while (true) {
        if (direction.front().TIME == time) {
            char curDir = direction.front().DIR; direction.pop();

            if (dir == 0) {
                curDir == 'L' ? dir = 1 : dir = 3;
            } else if (dir == 1) {
                curDir == 'L' ? dir = 2 : dir = 0;
            } else if (dir == 2) {
                curDir == 'L' ? dir = 3 : dir = 1;
            } else {
                curDir == 'L' ? dir = 0 : dir = 2;
            }

            joint.push({head.X, head.Y, dir});
        }

        int nx = head.X + dx[dir];
        int ny = head.Y + dy[dir]; 
        if (OOB(nx, ny) || board[nx][ny] == -1) {
            cout << time + 1;
            return 0;
        }

        if (board[nx][ny] == 0) {
            if (!joint.empty()) {
                int jx, jy, jDir;
                tie(jx, jy, jDir) = joint.front();

                board[tail.X][tail.Y] = 0;
                if (tail.X == jx && tail.Y == jy) {
                    tailDir = jDir;
                    joint.pop();
                }
            }

            board[tail.X][tail.Y] = 0;
            tail = {tail.X + dx[tailDir], tail.Y + dy[tailDir]};
        }

        head = {nx, ny};
        board[nx][ny] = -1;
        time++;
    }
}