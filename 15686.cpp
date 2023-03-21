#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, cnt;
int board[60][60];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int chickenSize;
int houseSize;
int chickenUsed[20];

int calcHouse(int houseNum) {
    int dist = 1000000;
    int houseX = house[houseNum].X;
    int houseY = house[houseNum].Y;
    for (int chickenNum = 0; chickenNum < chickenSize; chickenNum++) {
        if (chickenUsed[chickenNum]) {
            int chickenX = chicken[chickenNum].X;
            int chickenY = chicken[chickenNum].Y;
            int tempDist = abs(chickenX - houseX) + abs(chickenY - houseY);
            dist = min(dist, tempDist);
        }
    }
    return dist;
}

int calcChicken() {
    int dist = 0;
    for (int houseNum = 0; houseNum < houseSize; houseNum++) {
        dist += calcHouse(houseNum);
        }
    return dist;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (num == 2) chicken.push_back({i, j});
            if (num == 1) house.push_back({i, j});
        }
    }
    chickenSize = chicken.size();
    houseSize = house.size();
    for (int i = chickenSize - m; i < chickenSize; i++) chickenUsed[i] = 1;

    int ans = 1000000;
    do {
        int dist = calcChicken();
        ans = min(ans, dist);
    } while (next_permutation(chickenUsed, chickenUsed + chickenSize));

    cout << ans;
}