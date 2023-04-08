#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
int n, m;
int board[52][52];
int dist[52][52];
vector<pair<int, int>> virus;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans =  0x7f7f7f7f;
int emptySpace = 0;

bool OOB(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= n;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) virus.push_back({i, j});
            if (board[i][j] == 0) emptySpace++;
        }
    
    int virusSize = virus.size();
    vector<int> c(virusSize, 0);
    fill(c.end() - m, c.end(), 1);

    do {
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
        for (int i = 0; i < virusSize; i++) {
            if (!c[i]) continue;
            dist[virus[i].X][virus[i].Y] = 0;
            q.push({virus[i].X, virus[i].Y});
        }

        int step = 0, cnt = 0;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (OOB(nx, ny) || board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
                if (board[nx][ny] != 2) {
                    step = dist[nx][ny];
                    cnt++;
                }
            }
        }
        
        if (cnt != emptySpace) continue;
        ans = min(step, ans);
    } while (next_permutation(c.begin(), c.end()));
    ans == 0x7f7f7f7f? cout << -1 : cout << ans;
}