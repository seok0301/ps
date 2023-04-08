#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[12][12];
int y[12][12];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<vector<vector<int>>> tree(12, vector<vector<int>>(12, vector<int>()));

bool OOB(int a, int b) {
    return a < 1 || a > n || b < 1 || b > n;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    for (int i = 1; i <= n; i++) fill(y[i] + 1, y[i] + n + 1, 5);

    while (k--) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (!tree[i][j].size()) continue;
                sort(tree[i][j].begin(), tree[i][j].end());
                for (int k = 0; k < tree[i][j].size(); k++) {
                    if (tree[i][j][k] > y[i][j]) {
                        while (tree[i][j].size() > k) {
                            y[i][j] += tree[i][j].back() / 2;
                            tree[i][j].pop_back();
                        }
                        break;
                    }
                    y[i][j] -= tree[i][j][k];
                    tree[i][j][k]++;
                }
            }
            
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (!tree[i][j].size()) continue;
                for (int k = 0; k < tree[i][j].size(); k++) {
                    if (tree[i][j][k] % 5 == 0) {
                        for (int dir = 0; dir < 8; dir++) {
                            int ni = i + dx[dir];
                            int nj = j + dy[dir];
                            if (OOB(ni, nj)) continue;
                            tree[ni][nj].push_back(1);
                        }
                    }
                }
            }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                y[i][j] += a[i][j];
            }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans += tree[i][j].size();
    cout << ans;
}