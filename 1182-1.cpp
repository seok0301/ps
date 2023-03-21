#include <bits/stdc++.h>
using namespace std;
int arr[21];
int cnt, n, s;

void bt(int k, int sum, int len) {
    bool flag = false;
    if (sum == s && len > 0) {
        flag = true;
        cnt++;
    }
    if (k == n) return;
    bt(k + 1, sum + arr[k], len + 1);
    if (flag) cnt--;
    bt(k + 1, sum, len);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];
    bt(0, 0, 0);
    cout << cnt;
}