#include <bits/stdc++.h>
using namespace std;
int n, arr[13], ops[4], op[13], mx = -100000001, mn = 1000000001;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> ops[i];
    }
    int idx = ops[0];
    for (int i = 1; i < 4; i++) {
        fill(op + idx, op + idx + ops[i], i);
        idx += ops[i];
    }
    
    do {
        int val = arr[0];
        for (int i = 0; i < n - 1; i++) {
            if (op[i] == 0) {
                val += arr[i + 1];
            } else if (op[i] == 1) {
                val -= arr[i + 1];
            } else if (op[i] == 2) {
                val *= arr[i + 1];
            } else {
                val /= arr[i + 1];
            }
        }
        mx = max(val, mx);
        mn = min(val, mn);
    } while (next_permutation(op, op + n - 1));
    cout << mx << '\n' << mn;
}