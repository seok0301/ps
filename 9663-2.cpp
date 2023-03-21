#include <bits/stdc++.h>
using namespace std;

int cnt, n;
bool vis1[15];
bool vis2[31];
bool vis3[31];

void bt(int k) {
    if (k == n) {
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if (!vis1[i] && !vis2[k + i] && !vis3[n + k - i]) {
            vis1[i] = true;
            vis2[k + i] = true;
            vis3[n + k - i] = true;
            bt(k + 1);
            vis1[i] = false;
            vis2[k + i] = false;
            vis3[n + k - i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    bt(0);
    cout << cnt;
}