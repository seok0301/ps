#include <bits/stdc++.h>
using namespace std;
int R, C, M;
vector<tuple<int, int, int, int ,int>> sharks;

int main() {
    cin >> R >> C >> M;
    while (M--) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        sharks.push_back({r, c, s, d, z});
    }

    int ans = 0;
    for (int fishing = 1; fishing <= C; fishing++) {
        int min = 100001, minIdx = -1, sharkSize;
        for (int i = 0; i < sharks.size(); i++) {
            int r, c, s, d, z;
            tie(r, c, s, d, z) = sharks[i];
            if (c == fishing) {
                if (r < min) {
                    min = r;
                    minIdx = i;
                    sharkSize = z;
                }
            }
        }
        if (minIdx != -1) {
            ans += sharkSize;
            sharks.erase(sharks.begin() + minIdx);
        }

        int sharkMap[102][102];
        for (int i = 1; i <= R; i++) fill(sharkMap[i] + 1, sharkMap[i] + C + 1, 0);
        for (int i = 0; i < sharks.size(); i++) {
            int r, c, s, d, z;
            tie(r, c, s, d, z) = sharks[i];
            if (d <= 2) {
                int calc = s;
                d == 1 ? calc += R - r: calc += r - 1;
                int a = calc / (R - 1);
                int b = calc % (R - 1);
                if (a % 2) d == 1 ? d = 2 : d = 1;
                if (d == 1) r = R - b;
                else r = 1 + b;
                sharks[i] = {r, c, s, d, z};
            } else {
                int calc = s;
                d == 3 ? calc += c - 1: calc += C - c;
                int a = calc / (C - 1);
                int b = calc % (C - 1);
                if (a % 2) d == 3 ? d = 4 : d = 3;
                if (d == 3) c = 1 + b;
                else c = C - b;
                sharks[i] = {r, c, s, d, z};
            }

            if (sharkMap[r][c] != 0) {
                for (int j = 0; j < i; j++) {
                    if (get<0>(sharks[i]) == get<0>(sharks[j]) && get<1>(sharks[i]) == get<1>(sharks[j])) {
                        if (get<4>(sharks[i]) > get<4>(sharks[j])) sharks.erase(sharks.begin() + j);
                        else sharks.erase(sharks.begin() + i);
                        i--;
                        break;
                    }
                }
            }
            sharkMap[r][c] = 1;
        }
    }
    cout << ans;
}