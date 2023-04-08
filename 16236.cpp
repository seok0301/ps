#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
int board[22][22];
int vis[22][22];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
pair<int, int> shark;
int sharkSize = 2;
int eatFish = 0;

bool OOB(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= n;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark = {i, j};
                board[i][j] = 0;
            }
        }
    }

    int second = 0;
    while (true) {
        for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
        int step = 0;
        queue<pair<int, int>> q;
        q.push(shark);
        vis[shark.X][shark.Y] = 1;
        vector<pair<int, int>> fish;

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (step != vis[cur.X][cur.Y] && !fish.empty()) {
                sort(fish.begin(), fish.end());
                break;
            }
            step = vis[cur.X][cur.Y];
            if (board[cur.X][cur.Y] != 0 && board[cur.X][cur.Y] < sharkSize) fish.push_back({cur.X, cur.Y});
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (OOB(nx, ny) || vis[nx][ny]) continue;
                if (board[nx][ny] > sharkSize) continue;
                q.push({nx, ny});
                vis[nx][ny] = step + 1;
            }

        }
        if (fish.empty()) {
            cout << second;
            return 0;
        }
        second += step - 1;
        board[fish[0].X][fish[0].Y] = 0;
        shark = {fish[0].X, fish[0].Y};
        eatFish++;
        if (eatFish == sharkSize) {
            sharkSize++;
            eatFish = 0;
        }
    }
}