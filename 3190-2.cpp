#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define TIME first
#define DIR second
int n, k, l, second, dir;
int board[102][102];
queue<pair<int, char>> direction;
deque<pair<int, int>> snake;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) {
    return x < 1 || x > n || y < 1 || y > n;
}

int main() {
    cin >> n;
    cin >> k;

    while (k--) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }

    cin >> l;
    while (l--) {
        int x;
        char c;
        cin >> x >> c;
        direction.push({x, c});
    }

    board[1][1] = -1;
    snake.push_front({1, 1});
    
    while (true) {
        second++;

        auto head = snake.front();
        auto tail = snake.back();

        int nx = head.X + dx[dir];
        int ny = head.Y + dy[dir]; 

        if (OOB(nx, ny) || board[nx][ny] == -1) {
            cout << second;
            return 0;
        }

        if (board[nx][ny] == 0) {
            board[tail.X][tail.Y] = 0;
            snake.pop_back();
        }

        board[nx][ny] = -1;
        snake.push_front({nx, ny});

        if (direction.front().TIME == second) {
            char curDir = direction.front().DIR; direction.pop();

            curDir == 'L' ? dir += 1 : dir += 3;
            dir %= 4;
        }
    }
}