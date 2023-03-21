#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, ans = 11;
char board[12][12];
char ansBoard[12][12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
pair<int, int> redPos;
pair<int, int> bluePos;

string tilt(int dir) {
    if (((dx[dir] == 0) && (redPos.X == bluePos.X)) || ((dy[dir] == 0) && (redPos.Y == bluePos.Y))) {
        if ((dir == 0 && redPos.X > bluePos.X) || (dir == 1 && redPos.Y > bluePos.Y) || (dir == 2 && redPos.X < bluePos.X) || (dir == 3 && redPos.Y < bluePos.Y)) {
            bool check = false;
            while (true) {
                char nextSymbol = ansBoard[redPos.X + dx[dir]][redPos.Y + dy[dir]];
                if (nextSymbol == '.') {
                    ansBoard[redPos.X][redPos.Y] = '.';
                    redPos.X += dx[dir];
                    redPos.Y += dy[dir];
                    ansBoard[redPos.X][redPos.Y] = 'R';
                } else if (nextSymbol == '#') {
                    break;
                } else if (nextSymbol == 'O') {
                    ansBoard[redPos.X][redPos.Y] = '.';
                    check = true;
                    break;
                }
            }
            while (true) {
                char nextSymbol = ansBoard[bluePos.X + dx[dir]][bluePos.Y + dy[dir]];
                if (nextSymbol == '.') {
                    ansBoard[bluePos.X][bluePos.Y] = '.';
                    bluePos.X += dx[dir];
                    bluePos.Y += dy[dir];
                    ansBoard[bluePos.X][bluePos.Y] = 'B';
                } else if (nextSymbol == '#') {
                    if (check) return "success";
                    else return "continue";
                } else if (nextSymbol == 'R') {
                    return "continue";
                } else if (nextSymbol == 'O') {
                    return "fail";
                }
            }
        } else {
            bool check = false;
            while (true) {
                char nextSymbol = ansBoard[bluePos.X + dx[dir]][bluePos.Y + dy[dir]];
                if (nextSymbol == '.') {
                    ansBoard[bluePos.X][bluePos.Y] = '.';
                    bluePos.X += dx[dir];
                    bluePos.Y += dy[dir];
                    ansBoard[bluePos.X][bluePos.Y] = 'B';
                } else if (nextSymbol == '#') {
                    break;
                } else if (nextSymbol == 'O') {
                    return "fail";
                }
            }
            while (true) {
                char nextSymbol = ansBoard[redPos.X + dx[dir]][redPos.Y + dy[dir]];
                if (nextSymbol == '.') {
                    ansBoard[redPos.X][redPos.Y] = '.';
                    redPos.X += dx[dir];
                    redPos.Y += dy[dir];
                    ansBoard[redPos.X][redPos.Y] = 'R';
                } else if (nextSymbol == '#') {
                    return "continue";
                } else if (nextSymbol == 'B') {
                    return "continue";
                } else if (nextSymbol == 'O') {
                    return "success";
                }
            }
        }
    } else {
        while (true) {
            char nextSymbol = ansBoard[redPos.X + dx[dir]][redPos.Y + dy[dir]];
            if (nextSymbol == '.') {
                ansBoard[redPos.X][redPos.Y] = '.';
                redPos.X += dx[dir];
                redPos.Y += dy[dir];
                ansBoard[redPos.X][redPos.Y] = 'R';
            } else if (nextSymbol == '#') {
                break;
            } else if (nextSymbol == 'O') {
                return "success";
            }
        }
        while (true) {
            char nextSymbol = ansBoard[bluePos.X + dx[dir]][bluePos.Y + dy[dir]];
            if (nextSymbol == '.') {
                ansBoard[bluePos.X][bluePos.Y] = '.';
                bluePos.X += dx[dir];
                bluePos.Y += dy[dir];
                ansBoard[bluePos.X][bluePos.Y] = 'B';
            } else if (nextSymbol == '#') {
                return "continue";
            } else if (nextSymbol == 'O') {
                return "fail";
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') redPos = {i, j};
            if (board[i][j] == 'B') bluePos = {i, j};
        }
    }

    for (int iter = 0; iter < (1 << 20); iter++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ansBoard[i][j] = board[i][j];
                if (board[i][j] == 'R') redPos = {i, j};
                if (board[i][j] == 'B') bluePos = {i, j};
            }
        }

        int brute = iter;
        for (int step = 1; step <= 10; step++) {
            int dir = brute % 4;
            brute /= 4;

            string result = tilt(dir);
            if (result == "success") {
                ans = min(ans, step);
                break;
            } else if (result == "fail") {
                break;
            }
        }
    }

    if (ans == 11) cout << -1;
    else cout << ans;
}