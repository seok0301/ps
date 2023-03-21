#include <bits/stdc++.h>
using namespace std;

int main() {
    // int a[5] = {0, 0, 0, 1, 1};
    // do {
    //     for (int i = 0; i < 5; i++) {
    //         if (a[i] == 0) cout << (i + 1);
    //     }
    //     cout << '\n';
    // } while (next_permutation(a, a + 5));
    int n = 3;
    int dir = 4;

    for(int i = 0; i < (1 << (2 * n)); i++){
        int tmp = i;
        for(int j = 0; j < n; j++) {
            cout << tmp % dir;
            tmp /= dir;
        }
        cout << '\n';
    }
}