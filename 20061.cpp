#include <iostream>
using namespace std;
#define KIND first
#define POS second
int n, score;

void store_block(int box[6][4], pair<int, int> block) {
    int kind = block.KIND, pos = block.POS;
    if (kind == 1) {
        for (int i = 0; i < 6; i++) {
            if (box[i][pos] != 0) {
                box[i - 1][pos] = 1;
                return;
            }
        }
        box[5][pos] = 1;
    } else if (kind == 2) {
        for (int i = 0; i < 6; i++) {
            if (box[i][pos] != 0 || box[i][pos + 1] != 0) {
                box[i - 1][pos] = 1;
                box[i - 1][pos + 1] = 1;
                return;
            }
        }
        box[5][pos] = 1;
        box[5][pos + 1] = 1;
    } else {
        for (int i = 0; i < 6; i++) {
            if (box[i][pos] != 0) {
                box[i - 2][pos] = 1;
                box[i - 1][pos] = 1;
                return;
            }
        }
        box[4][pos] = 1;
        box[5][pos] = 1;
    }
}

void score_block(int box[6][4]) {
    for (int i = 0; i < 6; i++) {
        int isFull = 0;
        for (int j = 0; j < 4; j++) isFull += box[i][j];
        if (isFull == 4) {
            for (int k = i; k > 0; k--)
                for (int jj = 0; jj < 4; jj++)
                    box[k][jj] = box[k - 1][jj];
            score++;
        }
    }
}

void check_special(int box[6][4]) {
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        int isExist = 0;
        for (int j = 0; j < 4; j++)
            isExist += box[i][j];
        if (isExist) cnt++;
    }

    if (cnt == 0) return;
    for (int i = 5 - cnt; i >= 0; i--)
        for (int j = 0; j < 4; j++)
            box[i + cnt][j] = box[i][j];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++)
            box[i][j] = 0;
    }
}

int main() {
    int green[6][4], blue[6][4];
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++) {
            green[i][j] = 0;
            blue[i][j] = 0;
        }
    cin >> n;
    while (n--) {
        int t, x, y; cin >> t >> x >> y;
        pair<int, int> green_block = {t, y};
        if (t == 2) t = 3;
        else if (t == 3) {
            t = 2;
            x++;
        }
        pair<int, int> blue_block = {t, 3 - x};

        store_block(green, green_block);
        store_block(blue, blue_block);

        score_block(green);
        score_block(blue);

        check_special(green);
        check_special(blue);
    }
    int cnt = 0;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            cnt += green[i][j] + blue[i][j];
    cout << score << '\n' << cnt;
}