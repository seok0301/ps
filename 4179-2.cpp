#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
string board[1002];
int jeffBoard[1002][1002];
int fireBoard[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int R, C, ans;
    cin >> R >> C;
    for (int i = 0; i < R; i++) cin >> board[i];

    queue<pair<int, int>> jeffQ;
    queue<pair<int, int>> fireQ;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '#') {
                jeffBoard[i][j] = -1;
                fireBoard[i][j] = -1;
            } else if (board[i][j] == 'J') {
                jeffBoard[i][j] = 1;
                jeffQ.push({i, j});
            } else if (board[i][j] == 'F') {
                fireBoard[i][j] = 1;
                fireQ.push({i, j});
            }
        }
    }

    while (!fireQ.empty()) {
        pair<int, int> cur = fireQ.front(); fireQ.pop();
        int state = fireBoard[cur.X][cur.Y];
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (fireBoard[nx][ny] != 0) continue;
            fireBoard[nx][ny] = state + 1;
            fireQ.push({nx, ny});
        }
    }

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (fireBoard[i][j] == 0) fireBoard[i][j] = INFINITY;

    while (!jeffQ.empty()) {
        pair<int, int> cur = jeffQ.front(); jeffQ.pop();
        ans = jeffBoard[cur.X][cur.Y];
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << ans;
                return 0;
            }
            if (jeffBoard[nx][ny] != 0 || ans + 1 >= fireBoard[nx][ny]) continue;;
            jeffBoard[nx][ny] = ans + 1;
            jeffQ.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}