#include <bits/stdc++.h>
using namespace std;
int n, board[21][21], ans = 0x7f7f7f7f;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    vector<int> v(n, 1);
    fill(v.begin(), v.begin() + n / 2, 0);

    do {
        vector<int> arr0, arr1;
        int sum0 = 0, sum1 = 0;
        for (int i = 0; i < n; i++) v[i] ? arr1.push_back(i) : arr0.push_back(i);

        for (auto i : arr0)
            for (auto j : arr0)
                sum0 += board[i][j];
        for (auto i : arr1)
            for (auto j : arr1)
                sum1 += board[i][j];
                
        ans = min(ans, abs(sum0 - sum1));
    } while (next_permutation(v.begin(), v.end()));

    cout << ans;
}