#include <bits/stdc++.h>
using namespace std;
int n, arr[13], op[4], mx = -100000001, mn = 1000000001;

void bt(int sum, int k) {
    if (k == n) {
        mx = max(sum, mx);
        mn = min(sum, mn);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] == 0) continue;
        op[i]--;
        if (i == 0) bt(sum + arr[k], k + 1);
        else if (i == 1) bt(sum - arr[k], k + 1);
        else if (i == 2) bt(sum * arr[k], k + 1);
        else bt(sum / arr[k], k + 1);
        op[i]++;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < 4; i++) cin >> op[i];
    bt(arr[0], 1);
    cout << mx << '\n' << mn;
}