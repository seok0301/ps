#include <bits/stdc++.h>
using namespace std;
#define T first
#define P second
int n, sum, mx;
vector<pair<int, int>> consult = {{0, 0}};

void bt(int day) {
    if (day == n + 1) {
        mx = max(mx, sum);
        return;
    }
    if (day > n + 1) return;

    sum += consult[day].P;
    bt(day + consult[day].T);
    sum -= consult[day].P;
    bt(day + 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t, p;
        cin >> t >> p;
        consult.push_back({t, p});
    }
    bt(1);
    cout << mx;
}