#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int board[21][21];
int vis[21][21];
vector<tuple<int, int, int, vector<pair<int, int>>>> blockgroup;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

bool OOB(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= n;
}

void find_blockgroup(int x, int y) {
    if (vis[x][y] || board[x][y] == 0 || board[x][y] == -1 || board[x][y] == -2) return;
    int color = board[x][y];
    int rainbow = 0;
    vector<pair<int, int>> v;
    queue<pair<int, int>> q;
    vis[x][y] = 1;
    q.push({x, y});
    v.push_back({x, y});

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (board[cur.X][cur.Y] == 0) rainbow++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (OOB(nx, ny) || vis[nx][ny]) continue;
            if (board[nx][ny] != 0 && board[nx][ny] != color) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
            v.push_back({nx, ny});
        }
    }

    if (v.size() < 2) return;
    for (auto block : v)
        if (board[block.X][block.Y] == 0) vis[block.X][block.Y] = 0;
    sort(v.begin(), v.end());
    for (auto block : v)
        if (board[block.X][block.Y] != 0) {
            blockgroup.push_back({rainbow, block.X, block.Y, v});
            return;
        }
}

bool comp_blockgroup(tuple<int, int, int, vector<pair<int, int>>>& a, tuple<int, int, int, vector<pair<int, int>>>& b) {
    int a1, a2, a3, b1, b2, b3;
    vector<pair<int, int>> a4, b4;
    tie(a1, a2, a3, a4) = a;
    tie(b1, b2, b3, b4) = b;
    int a0 = a4.size();
    int b0 = b4.size();
    if (a0 != b0) return a0 > b0;
    else if (a1 != b1) return a1 > b1;
    else if (a2 != b2) return a2 > b2;
    else return a3 > b3;
}

void delete_blockgroup() {
    sort(blockgroup.begin(), blockgroup.end(), comp_blockgroup);
    auto blocks = get<3>(blockgroup[0]);

    ans += blocks.size() * blocks.size();
    for (auto block : blocks) board[block.X][block.Y] = -2;

    blockgroup.clear();
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
}

void velocity() {
    for (int j = 0; j < n; j++) {
        int idx = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (board[i][j] == -1) idx= i - 1;
            else if (board[i][j] == -2) continue;
            else {
                if (idx == i) {
                    idx--;
                    continue;
                }
                board[idx][j] = board[i][j];
                board[i][j] = -2;
                idx--;
            }
        }
    }
}

void rotate() {
    int tmpBoard[21][21];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmpBoard[i][j] = board[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = tmpBoard[j][n - i - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    while (true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) find_blockgroup(i, j);
            }
        }
        if (blockgroup.empty()) break;
        delete_blockgroup();
        velocity();
        rotate();
        velocity();
    }
    cout << ans;
}