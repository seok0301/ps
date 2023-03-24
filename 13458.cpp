#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, b, c;
    long long cnt = 0;
    int arr[1000001];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> b >> c;

    for (int i = 0; i < n; i++) {
        cnt++;
        arr[i] -= b;
        if (arr[i] > 0) {
            cnt += arr[i] / c;
            if (arr[i] % c != 0) cnt++;
        }
    }

    cout << cnt;
}