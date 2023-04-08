#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define IDX first
#define DIST second
int n, m, fuel;
int board[22][22];
int dist[22][22];
int client[22][22];
int taxi_x, taxi_y;
vector<tuple<int, int, int, int>> info;
int passenger;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int a, int b) {
    return a < 1 || a > n || b < 1 || b > n;
}

bool comp_passenger_info(pair<int, int>& a, pair<int, int>& b) {
    int ax = get<0>(info[a.IDX]), ay = get<1>(info[a.IDX]), bx = get<0>(info[b.IDX]), by = get<1>(info[b.IDX]);
    if (ax != bx) return ax < bx;
    else return ay < by;
}

int to_src() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    vector<pair<int, int>> passenger_info;

    dist[taxi_x][taxi_y] = 0;
    q.push({taxi_x, taxi_y});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (client[cur.X][cur.Y] != -1) {
            if (!passenger_info.empty() && passenger_info.back().DIST != dist[cur.X][cur.Y]) break;
            passenger_info.push_back({client[cur.X][cur.Y], dist[cur.X][cur.Y]});
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (OOB(nx, ny) || board[nx][ny] == 1 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    if (passenger_info.empty()) return -1;

    if (passenger_info.size() > 1) sort(passenger_info.begin(), passenger_info.end(), comp_passenger_info);
    int passenger_no = passenger_info[0].IDX;
    int distance = passenger_info[0].DIST;

    fuel -= distance;

    taxi_x = get<0>(info[passenger_no]);
    taxi_y = get<1>(info[passenger_no]);
    client[taxi_x][taxi_y] = -1;

    return passenger_no;
}

int to_dst(int passenger_no) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = -1;
        }
    }

    int dst_x = get<2>(info[passenger_no]);
    int dst_y = get<3>(info[passenger_no]);
    board[dst_x][dst_y] = 2;
    int distance = -1;

    queue<pair<int, int>> q;
    dist[taxi_x][taxi_y] = 0;
    q.push({taxi_x, taxi_y});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (board[cur.X][cur.Y] == 2) {
            distance = dist[cur.X][cur.Y];
            break;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (OOB(nx, ny) || board[nx][ny] == 1 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    if (distance == -1) return -1;

    fuel -= distance;
    board[dst_x][dst_y] = 0;
    taxi_x = dst_x;
    taxi_y = dst_y;
    return distance;
}

int main() {
    cin >> n >> m >> fuel;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            dist[i][j] = -1;
            client[i][j] = -1;
        }
    }

    cin >> taxi_x >> taxi_y;

    for (int i = 0; i < m; i++) {
        int src_x, src_y, dst_x, dst_y;
        cin >> src_x >> src_y >> dst_x >> dst_y;
        client[src_x][src_y] = i;
        info.push_back({src_x, src_y, dst_x, dst_y});
    }

    passenger = info.size();

    while (passenger--) {
        int passenger_no = to_src();

        if (fuel < 0 || passenger_no == -1) {
            cout << -1;
            return 0;
        }

        int distance = to_dst(passenger_no);

        if (fuel < 0 || distance == -1) {
            cout << -1;
            return 0;
        }

        fuel += distance * 2;
    }
    cout << fuel;
}