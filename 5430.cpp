#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        deque<int> dq;
        bool isReverse = false;

        string s;
        for (char c : arr) {
            if (c == '[') continue;
            if (c == ',' || c == ']') {
                if (s.length() != 0) dq.push_back(stoi(s));
                s.clear();
            } else {
                s.push_back(c);
            }
        }

        bool isError = false;
        for (char c : p) {
            if (c == 'R') isReverse = !isReverse;
            else {
                if (dq.empty()) {
                    isError = true;
                    break;
                }
                if (isReverse) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (isError) cout << "error" << '\n';
        else {
            cout << '[';
            while (!dq.empty()) {
                if (isReverse) {
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty()) cout << ',';
                } else {
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty()) cout << ',';
                }
            }
            cout << ']' << '\n';
        }
    }
}