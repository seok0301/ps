#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, ans, spaceSize;
int board[10][10];
int ansBoard[10][10];
vector<pair<int, int>> virus, space;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= m;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (OOB(nx, ny) || ansBoard[nx][ny] != 0) continue;
            ansBoard[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                virus.push_back({i, j});
            } else if (board[i][j] == 0) {
                space.push_back({i, j});
            }
        }
    }

    spaceSize = space.size();
    vector<int> safe(spaceSize);
    fill(safe.end() - 3, safe.end(), 1);

    do {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ansBoard[i][j] = board[i][j];
            }
        }

        for (int i = 0; i < spaceSize; i++) {
            if (safe[i]) { 
                ansBoard[space[i].X][space[i].Y] = 1;
            }
        }
        
        for (auto v : virus) {
            bfs(v.X, v.Y);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ansBoard[i][j] == 0) {
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);

    } while (next_permutation(safe.begin(), safe.end()));
    cout << ans;
}