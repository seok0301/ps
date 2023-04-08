#include<iostream>
#include<algorithm>
using namespace std;
int d, w, k;
int board[15][22];
int tmpBoard[15][22];

bool test() {
    for (int i = 0; i < w; i++) {
        int cur = tmpBoard[0][i];
        int mx = 0;
        int cur_len = 1;
        for (int j = 1; j < d; j++) {
            if (tmpBoard[j][i] != cur) {
                mx = max(mx, cur_len);
                cur_len = 1;
            } else cur_len++;
            cur = tmpBoard[j][i];
        }
        mx = max(mx, cur_len);
        if (mx < k) return false;
    }
    return true;
}

int main(int argc, char** argv) {
	int test_case, T; cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
        cin >> d >> w >> k;
        for (int i = 0; i < d; i++)
            for (int j = 0; j < w; j++)
                cin >> board[i][j];

        for (int yak = 0; yak <= d; yak++) {
            vector<int> brute(d, 0);
            fill(brute.end() - yak, brute.end(), 1);

            bool flag = false;
            do {
                vector<int> idx;
                for (int i = 0; i < d; i++)
                    if (brute[i]) idx.push_back(i);
                
                for (int iter = 0; iter < (1 << yak); iter++) {

                    for (int i = 0; i < d; i++)
                        for (int j = 0; j < w; j++)
                            tmpBoard[i][j] = board[i][j];

                    int tmp = iter;
                    for (int i = 0; i < yak; i++) {
                        int yak_kind = tmp % 2;
                        tmp /= 2;
                        for (int x = 0; x < w; x++) tmpBoard[idx[i]][x] = yak_kind;
                    }

                    if (test()) {
                        cout << "#" << test_case << ' ' << yak << '\n';
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            } while (next_permutation(brute.begin(), brute.end()));
            if (flag) break;
        }
	}
	return 0;
}