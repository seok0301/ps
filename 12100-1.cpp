#include <bits/stdc++.h>
using namespace std;
#define num first
#define idx second
int n;
int board[30][30];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int val = 0;
    for (int iter = 0; iter < 1024; iter++) {
        int ans[30][30];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = board[i][j];

        int brute = iter;
        for (int turn = 0; turn < 5; turn++) {
            int dir = brute % 4;
            brute /= 4;

            if (dir == 0) {
                for (int i = 0; i < n; i++) {
                    vector<int> v;
                    for (int j = 0; j < n; j++)
                        v.push_back(ans[j][i]);

                    bool state = false;
                    pair<int, int> store;
                    for (int k = 0; k < v.size(); k++) {
                        if (v[k] == 0) continue;
                        if (v[k] != 0) {
                            if (state) {
                                if (v[store.idx] == v[k]) {
                                    v[store.idx] = store.num * 2;
                                    v[k] = 0;
                                    state = false;
                                } else {
                                    store.num = v[k];
                                    store.idx = k;
                                }
                            } else {
                                store.num = v[k];
                                store.idx = k;
                                state = true;
                            }
                        }
                    }

                    int index = 0;
                    for (int k = 0; k < v.size(); k++) {
                        if (v[k] != 0) {
                            ans[index][i] = v[k];
                            index++;
                        }
                    }

                    for (int k = index; k < n; k++)
                        ans[k][i] = 0;
                }
            } else if (dir == 1) {
                for (int i = 0; i < n; i++) {
                    vector<int> v;
                    for (int j = n - 1; j >= 0; j--)
                        v.push_back(ans[j][i]);

                    bool state = false;
                    pair<int, int> store;
                    for (int k = 0; k < v.size(); k++) {
                        if (v[k] == 0) continue;
                        if (v[k] != 0) {
                            if (state) {
                                if (v[store.idx] == v[k]) {
                                    v[store.idx] = store.num * 2;
                                    v[k] = 0;
                                    state = false;
                                } else {
                                    store.num = v[k];
                                    store.idx = k;
                                }
                            } else {
                                store.num = v[k];
                                store.idx = k;
                                state = true;
                            }
                        }
                    }

                    int index = n - 1;
                    for (int k = 0; k < v.size(); k++) {
                        if (v[k] != 0) {
                            ans[index][i] = v[k];
                            index--;
                        }
                    }

                    for (int k = index; k >= 0; k--)
                        ans[k][i] = 0;
                }
            } else if (dir == 2) {
                for (int i = 0; i < n; i++) {
                    vector<int> v;
                    for (int j = 0; j < n; j++) 
                        v.push_back(ans[i][j]);

                    bool state = false;
                    pair<int, int> store;
                    for (int k = 0; k < v.size(); k++) {
                        if (v[k] == 0) continue;
                        if (v[k] != 0) {
                            if (state) {
                                if (v[store.idx] == v[k]) {
                                    v[store.idx] = store.num * 2;
                                    v[k] = 0;
                                    state = false;
                                } else {
                                    store.num = v[k];
                                    store.idx = k;
                                }
                            } else {
                                store.num = v[k];
                                store.idx = k;
                                state = true;
                            }
                        }
                    }

                    int index = 0;
                    for (int k = 0; k < v.size(); k++) {
                        if (v[k] != 0) {
                            ans[i][index] = v[k];
                            index++;
                        }
                    }

                    for (int k = index; k < n; k++)
                        ans[i][k] = 0;
                }

            } else {
                for (int i = 0; i < n; i++) {
                    vector<int> v;
                    for (int j = n - 1; j >= 0; j--)
                        v.push_back(ans[i][j]);

                    bool state = false;
                    pair<int, int> store;
                    for (int k = 0; k < v.size(); k++) {
                        if (v[k] == 0) continue;
                        if (v[k] != 0) {
                            if (state) {
                                if (v[store.idx] == v[k]) {
                                    v[store.idx] = store.num * 2;
                                    v[k] = 0;
                                    state = false;
                                } else {
                                    store.num = v[k];
                                    store.idx = k;
                                }
                            } else {
                                store.num = v[k];
                                store.idx = k;
                                state = true;
                            }
                        }
                    }

                    int index = n - 1;
                    for (int k = 0; k < v.size(); k++) {
                        if (v[k] != 0) {
                            ans[i][index] = v[k];
                            index--;
                        }
                    }

                    for (int k = index; k >= 0; k--)
                        ans[i][k] = 0;
                }
            }
        }

        int mx = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mx = max(mx, ans[i][j]);
        val = max(val, mx);
    }
    cout << val;
}