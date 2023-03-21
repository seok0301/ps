#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int cnt, n;
vector<pair<int, int>> v;

void bt(int k) {
    if (k == n) {
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++) {
        bool isPossible = true;
        for (auto queen : v) {
            if (queen.x + queen.y == k + i || queen.x - queen.y == k - i || queen.y == i) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            v.push_back({k, i});
            bt(k + 1);
            v.pop_back();
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