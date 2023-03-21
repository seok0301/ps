#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool vis[9];
int n, m;

void bt(int k) {
    if (k == m) {
        for (int item : v) cout << item << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            v.push_back(i);
            vis[i] = true;
            bt(k + 1);
            v.pop_back();
            vis[i] = false;
        }    
    }
}

int main() {
    cin >> n >> m;
    bt(0);
}