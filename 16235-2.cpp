#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[12][12];
int y[12][12];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> tree[12][12];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            y[i][j] = 5;
        }
    }
        
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    while (k--) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (!tree[i][j].size()) continue;
                int idx = tree[i][j].size() - 1;
                while (idx >= 0) {
                    if (tree[i][j][idx] > y[i][j]) {
                        for (int k = 0; k <= idx; k++)
                            y[i][j] += tree[i][j][k] / 2;
                        tree[i][j].erase(tree[i][j].begin(), tree[i][j].begin() + idx + 1);
                        break;
                    }
                    y[i][j] -= tree[i][j][idx];
                    tree[i][j][idx]++;
                    idx--;
                }
            }
            
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 0; k < tree[i][j].size(); k++)
                    if (tree[i][j][k] % 5 == 0)
                        for (int dir = 0; dir < 8; dir++)
                            tree[i + dx[dir]][j + dy[dir]].push_back(1);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                y[i][j] += a[i][j];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans += tree[i][j].size();
    cout << ans;
}