#include <bits/stdc++.h>
using namespace std;
int n, arr[13], op[13], mx = -100000001, mn = 1000000001;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int idx = 1;
    for (int i = 0; i < 4; i++) {
        int cnt; cin >> cnt;
        while (cnt--) op[idx++] = i;
    }
    
    do {
        int val = 0;
        for (int i = 0; i < n; i++) {
            if (op[i] == 0) val += arr[i];
            else if (op[i] == 1) val -= arr[i];
            else if (op[i] == 2) val *= arr[i];
            else val /= arr[i];
        }
        mx = max(val, mx);
        mn = min(val, mn);
    } while (next_permutation(op + 1, op + n));
    
    cout << mx << '\n' << mn;
}