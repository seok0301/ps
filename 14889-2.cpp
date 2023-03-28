#include <bits/stdc++.h>
using namespace std;
int n, board[21][21], ans = 0x7f7f7f7f;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    vector<int> team(n, 1);
    fill(team.begin(), team.begin() + n / 2, 0);

    do {
        int diff = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (team[i] != team[j]) continue;
                if (team[i] == 1) diff += board[i][j] + board[j][i];
                else diff -= board[i][j] + board[j][i];
            }
        }

        ans = min(ans, abs(diff));
    } while (next_permutation(team.begin(), team.end()));
    
    cout << ans;
}