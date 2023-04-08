#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second
int n, m;
int board[52][52];
int vis[52][52];
vector<pair<int, int>> virus;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans =  0x7f7f7f7f;

bool OOB(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= n;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) virus.push_back({i, j});
        }
    
    int virusSize = virus.size();
    vector<int> c(virusSize, 0);
    fill(c.end() - m, c.end(), 1);

    do {
        vector<pair<int, int>> v;
        queue<pair<int, int>> q;
        vector<pair<int, int>> tempV[2500];
        for (int i = 0; i < virusSize; i++)
            if (c[i]) v.push_back(virus[i]);
        
        for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, -1);

        for (auto vi : v) {
            vis[vi.X][vi.Y] = 0;
            q.push({vi.X, vi.Y});
        }

        int step = 0;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            step = vis[cur.X][cur.Y];
            tempV[step].push_back({cur.X, cur.Y});
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (OOB(nx, ny) || board[nx][ny] == 1 || vis[nx][ny] >= 0) continue;
                vis[nx][ny] = step + 1;
                q.push({nx, ny});
            }
        }

        bool isImpossible = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == -1 && board[i][j] == 0) {
                    isImpossible = true;
                    break;
                }
            }
        }
        if (isImpossible) continue;

        for (int i = step; i > 0; i--) {
            bool last_virus = true;
            for (auto vi : tempV[i]) {
                if (board[vi.X][vi.Y] != 2) {
                    last_virus = false;
                    break;
                }
            }
            if (last_virus) {
                step--;
            } else break;
        }
        
        ans = min(step, ans);
    } while (next_permutation(c.begin(), c.end()));
    if (ans == 0x7f7f7f7f) cout << -1;
    else cout << ans;
}