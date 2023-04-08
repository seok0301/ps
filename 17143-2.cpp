#include <bits/stdc++.h>
using namespace std;
int R, C, M;
vector<tuple<int, int, int>> sharks[102][102];
vector<tuple<int, int, int>> tempSharks[102][102];
int ans = 0;

bool shark_exist(int x, int y) {
    return !sharks[x][y].empty();
}

int catch_shark(int x, int y) {
    int s, d, z;
    tie(s, d, z) = sharks[x][y][0];
    sharks[x][y].pop_back();
    return z;
}

void move_fisherman(int fisherman_pos) {
    for (int i = 1; i <= R; i++) {
        if (shark_exist(i, fisherman_pos)) {
            ans += catch_shark(i, fisherman_pos);
            return;
        }
    }
}

void move_shark(int x, int y) {
    int s, d, z;
    tie(s, d, z) = sharks[x][y][0];
    if (d <= 2) {
        int calc = s;
        d == 1 ? calc += R - x: calc += x - 1;
        int a = calc / (R - 1);
        int b = calc % (R - 1);
        if (a % 2) d == 1 ? d = 2 : d = 1;
        if (d == 1) x = R - b;
        else x = 1 + b;
        tempSharks[x][y].push_back({s, d, z});
    } else {
        int calc = s;
        d == 3 ? calc += y - 1: calc += C - y;
        int a = calc / (C - 1);
        int b = calc % (C - 1);
        if (a % 2) d == 3 ? d = 4 : d = 3;
        if (d == 3) y = 1 + b;
        else y = C - b;
        tempSharks[x][y].push_back({s, d, z});
    }
}

bool compSize(tuple<int, int, int>& a, tuple<int, int, int>& b) {
    return get<2>(a) > get<2>(b);
}

void eat_shark(int x, int y) {
    sort(sharks[x][y].begin(), sharks[x][y].end(), compSize);
    while (sharks[x][y].size() > 1) sharks[x][y].pop_back();
}

void move_sharks() {
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (shark_exist(i, j)) move_shark(i, j);
    
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++) {
            sharks[i][j] = tempSharks[i][j];
            tempSharks[i][j].clear();
        }
    
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (sharks[i][j].size() > 1) eat_shark(i, j);
}

int main() {
    cin >> R >> C >> M;
    while (M--) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        sharks[r][c].push_back({s, d, z});
    }

    for (int fisherman_pos = 1; fisherman_pos <= C; fisherman_pos++) {
        move_fisherman(fisherman_pos);
        move_sharks();
    }
    cout << ans;
}