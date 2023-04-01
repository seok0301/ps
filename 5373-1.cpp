#include <bits/stdc++.h>
using namespace std;
char cube[6][9];

int main() {
    int t; cin >> t;
    while (t--) {
        for (int i = 0; i < 9; i++) cube[0][i] = 'w';
        for (int i = 0; i < 9; i++) cube[1][i] = 'y';
        for (int i = 0; i < 9; i++) cube[2][i] = 'r';
        for (int i = 0; i < 9; i++) cube[3][i] = 'o';
        for (int i = 0; i < 9; i++) cube[4][i] = 'g';
        for (int i = 0; i < 9; i++) cube[5][i] = 'b';
        int n; cin >> n;
        while (n--) {
            string method; cin >> method;
            char tmpCube[6][9];
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 9; j++)
                    tmpCube[i][j] = cube[i][j];

            if (method == "U-") {
                cube[3][2] = tmpCube[5][2];
                cube[3][1] = tmpCube[5][1];
                cube[3][0] = tmpCube[5][0];

                cube[4][2] = tmpCube[3][2];
                cube[4][1] = tmpCube[3][1];
                cube[4][0] = tmpCube[3][0];

                cube[2][2] = tmpCube[4][2];
                cube[2][1] = tmpCube[4][1];
                cube[2][0] = tmpCube[4][0];

                cube[5][2] = tmpCube[2][2];
                cube[5][1] = tmpCube[2][1];
                cube[5][0] = tmpCube[2][0];

                cube[0][0] = tmpCube[0][2];
                cube[0][1] = tmpCube[0][5];
                cube[0][2] = tmpCube[0][8];
                cube[0][3] = tmpCube[0][1];
                cube[0][5] = tmpCube[0][7];
                cube[0][6] = tmpCube[0][0];
                cube[0][7] = tmpCube[0][3];
                cube[0][8] = tmpCube[0][6];
            }
            else if (method == "U+") {
                cube[3][2] = tmpCube[4][2];
                cube[3][1] = tmpCube[4][1];
                cube[3][0] = tmpCube[4][0];

                cube[4][2] = tmpCube[2][2];
                cube[4][1] = tmpCube[2][1];
                cube[4][0] = tmpCube[2][0];

                cube[2][2] = tmpCube[5][2];
                cube[2][1] = tmpCube[5][1];
                cube[2][0] = tmpCube[5][0];

                cube[5][2] = tmpCube[3][2];
                cube[5][1] = tmpCube[3][1];
                cube[5][0] = tmpCube[3][0];

                cube[0][0] = tmpCube[0][6];
                cube[0][1] = tmpCube[0][3];
                cube[0][2] = tmpCube[0][0];
                cube[0][3] = tmpCube[0][7];
                cube[0][5] = tmpCube[0][1];
                cube[0][6] = tmpCube[0][8];
                cube[0][7] = tmpCube[0][5];
                cube[0][8] = tmpCube[0][2];
            }
            else if (method == "D-") {
                cube[2][6] = tmpCube[5][6];
                cube[2][7] = tmpCube[5][7];
                cube[2][8] = tmpCube[5][8];

                cube[4][6] = tmpCube[2][6];
                cube[4][7] = tmpCube[2][7];
                cube[4][8] = tmpCube[2][8];

                cube[3][8] = tmpCube[4][8];
                cube[3][7] = tmpCube[4][7];
                cube[3][6] = tmpCube[4][6];

                cube[5][6] = tmpCube[3][6];
                cube[5][7] = tmpCube[3][7];
                cube[5][8] = tmpCube[3][8];

                cube[1][6] = tmpCube[1][8];
                cube[1][7] = tmpCube[1][5];
                cube[1][8] = tmpCube[1][2];
                cube[1][5] = tmpCube[1][1];
                cube[1][2] = tmpCube[1][0];
                cube[1][1] = tmpCube[1][3];
                cube[1][0] = tmpCube[1][6];
                cube[1][3] = tmpCube[1][7];
            }
            else if (method == "D+") {
                cube[2][6] = tmpCube[4][6];
                cube[2][7] = tmpCube[4][7];
                cube[2][8] = tmpCube[4][8];

                cube[4][6] = tmpCube[3][6];
                cube[4][7] = tmpCube[3][7];
                cube[4][8] = tmpCube[3][8];

                cube[3][8] = tmpCube[5][8];
                cube[3][7] = tmpCube[5][7];
                cube[3][6] = tmpCube[5][6];

                cube[5][6] = tmpCube[2][6];
                cube[5][7] = tmpCube[2][7];
                cube[5][8] = tmpCube[2][8];

                cube[1][6] = tmpCube[1][0];
                cube[1][7] = tmpCube[1][3];
                cube[1][8] = tmpCube[1][6];
                cube[1][5] = tmpCube[1][7];
                cube[1][2] = tmpCube[1][8];
                cube[1][1] = tmpCube[1][5];
                cube[1][0] = tmpCube[1][2];
                cube[1][3] = tmpCube[1][1];
            }
            else if (method == "F-") {
                cube[0][6] = tmpCube[5][0];
                cube[0][7] = tmpCube[5][3];
                cube[0][8] = tmpCube[5][6];

                cube[4][2] = tmpCube[0][8];
                cube[4][5] = tmpCube[0][7];
                cube[4][8] = tmpCube[0][6];

                cube[1][6] = tmpCube[4][2];
                cube[1][7] = tmpCube[4][5];
                cube[1][8] = tmpCube[4][8];

                cube[5][0] = tmpCube[1][8];
                cube[5][3] = tmpCube[1][7];
                cube[5][6] = tmpCube[1][6];

                cube[2][0] = tmpCube[2][2];
                cube[2][1] = tmpCube[2][5];
                cube[2][2] = tmpCube[2][8];
                cube[2][3] = tmpCube[2][1];
                cube[2][5] = tmpCube[2][7];
                cube[2][6] = tmpCube[2][0];
                cube[2][7] = tmpCube[2][3];
                cube[2][8] = tmpCube[2][6];
            }
            else if (method == "F+") {
                cube[0][6] = tmpCube[4][8];
                cube[0][7] = tmpCube[4][5];
                cube[0][8] = tmpCube[4][2];

                cube[4][2] = tmpCube[1][6];
                cube[4][5] = tmpCube[1][7];
                cube[4][8] = tmpCube[1][8];

                cube[1][6] = tmpCube[5][6];
                cube[1][7] = tmpCube[5][3];
                cube[1][8] = tmpCube[5][0];

                cube[5][0] = tmpCube[0][6];
                cube[5][3] = tmpCube[0][7];
                cube[5][6] = tmpCube[0][8];

                cube[2][0] = tmpCube[2][6];
                cube[2][1] = tmpCube[2][3];
                cube[2][2] = tmpCube[2][0];
                cube[2][3] = tmpCube[2][7];
                cube[2][5] = tmpCube[2][1];
                cube[2][6] = tmpCube[2][8];
                cube[2][7] = tmpCube[2][5];
                cube[2][8] = tmpCube[2][2];
            }
            else if (method == "B-") {
                cube[0][2] = tmpCube[4][0];
                cube[0][1] = tmpCube[4][3];
                cube[0][0] = tmpCube[4][6];

                cube[5][2] = tmpCube[0][0];
                cube[5][5] = tmpCube[0][1];
                cube[5][8] = tmpCube[0][2];

                cube[1][0] = tmpCube[5][8];
                cube[1][1] = tmpCube[5][5];
                cube[1][2] = tmpCube[5][2];

                cube[4][0] = tmpCube[1][0];
                cube[4][3] = tmpCube[1][1];
                cube[4][6] = tmpCube[1][2];

                cube[3][0] = tmpCube[3][2];
                cube[3][1] = tmpCube[3][5];
                cube[3][2] = tmpCube[3][8];
                cube[3][3] = tmpCube[3][1];
                cube[3][5] = tmpCube[3][7];
                cube[3][6] = tmpCube[3][0];
                cube[3][7] = tmpCube[3][3];
                cube[3][8] = tmpCube[3][6];
            }
            else if (method == "B+") {
                cube[0][2] = tmpCube[5][8];
                cube[0][1] = tmpCube[5][5];
                cube[0][0] = tmpCube[5][2];

                cube[5][2] = tmpCube[1][2];
                cube[5][5] = tmpCube[1][1];
                cube[5][8] = tmpCube[1][0];

                cube[1][0] = tmpCube[4][0];
                cube[1][1] = tmpCube[4][3];
                cube[1][2] = tmpCube[4][6];

                cube[4][0] = tmpCube[0][2];
                cube[4][3] = tmpCube[0][1];
                cube[4][6] = tmpCube[0][0];

                cube[3][0] = tmpCube[3][6];
                cube[3][1] = tmpCube[3][3];
                cube[3][2] = tmpCube[3][0];
                cube[3][3] = tmpCube[3][7];
                cube[3][5] = tmpCube[3][1];
                cube[3][6] = tmpCube[3][8];
                cube[3][7] = tmpCube[3][5];
                cube[3][8] = tmpCube[3][2];
            }
            else if (method == "L-") {
                cube[0][0] = tmpCube[2][0];
                cube[0][3] = tmpCube[2][3];
                cube[0][6] = tmpCube[2][6];

                cube[3][2] = tmpCube[0][6];
                cube[3][5] = tmpCube[0][3];
                cube[3][8] = tmpCube[0][0];

                cube[1][6] = tmpCube[3][8];
                cube[1][3] = tmpCube[3][5];
                cube[1][0] = tmpCube[3][2];

                cube[2][0] = tmpCube[1][6];
                cube[2][3] = tmpCube[1][3];
                cube[2][6] = tmpCube[1][0];

                cube[4][0] = tmpCube[4][2];
                cube[4][1] = tmpCube[4][5];
                cube[4][2] = tmpCube[4][8];
                cube[4][3] = tmpCube[4][1];
                cube[4][5] = tmpCube[4][7];
                cube[4][6] = tmpCube[4][0];
                cube[4][7] = tmpCube[4][3];
                cube[4][8] = tmpCube[4][6];
            }
            else if (method == "L+") {
                cube[0][0] = tmpCube[3][8];
                cube[0][3] = tmpCube[3][5];
                cube[0][6] = tmpCube[3][2];

                cube[3][2] = tmpCube[1][0];
                cube[3][5] = tmpCube[1][3];
                cube[3][8] = tmpCube[1][6];

                cube[1][6] = tmpCube[2][0];
                cube[1][3] = tmpCube[2][3];
                cube[1][0] = tmpCube[2][6];

                cube[2][0] = tmpCube[0][0];
                cube[2][3] = tmpCube[0][3];
                cube[2][6] = tmpCube[0][6];

                cube[4][0] = tmpCube[4][6];
                cube[4][1] = tmpCube[4][3];
                cube[4][2] = tmpCube[4][0];
                cube[4][3] = tmpCube[4][7];
                cube[4][5] = tmpCube[4][1];
                cube[4][6] = tmpCube[4][8];
                cube[4][7] = tmpCube[4][5];
                cube[4][8] = tmpCube[4][2];
            }
            else if (method == "R-") {
                cube[0][8] = tmpCube[3][0];
                cube[0][5] = tmpCube[3][3];
                cube[0][2] = tmpCube[3][6];

                cube[2][2] = tmpCube[0][2];
                cube[2][5] = tmpCube[0][5];
                cube[2][8] = tmpCube[0][8];

                cube[1][2] = tmpCube[2][8];
                cube[1][5] = tmpCube[2][5];
                cube[1][8] = tmpCube[2][2];

                cube[3][0] = tmpCube[1][2];
                cube[3][3] = tmpCube[1][5];
                cube[3][6] = tmpCube[1][8];

                cube[5][0] = tmpCube[5][2];
                cube[5][1] = tmpCube[5][5];
                cube[5][2] = tmpCube[5][8];
                cube[5][3] = tmpCube[5][1];
                cube[5][5] = tmpCube[5][7];
                cube[5][6] = tmpCube[5][0];
                cube[5][7] = tmpCube[5][3];
                cube[5][8] = tmpCube[5][6];
            }
            else if (method == "R+") {
                cube[0][8] = tmpCube[2][8];
                cube[0][5] = tmpCube[2][5];
                cube[0][2] = tmpCube[2][2];

                cube[2][2] = tmpCube[1][8];
                cube[2][5] = tmpCube[1][5];
                cube[2][8] = tmpCube[1][2];

                cube[1][2] = tmpCube[3][0];
                cube[1][5] = tmpCube[3][3];
                cube[1][8] = tmpCube[3][6];

                cube[3][0] = tmpCube[0][8];
                cube[3][3] = tmpCube[0][5];
                cube[3][6] = tmpCube[0][2];

                cube[5][0] = tmpCube[5][6];
                cube[5][1] = tmpCube[5][3];
                cube[5][2] = tmpCube[5][0];
                cube[5][3] = tmpCube[5][7];
                cube[5][5] = tmpCube[5][1];
                cube[5][6] = tmpCube[5][8];
                cube[5][7] = tmpCube[5][5];
                cube[5][8] = tmpCube[5][2];
            }
        }
        for (int i = 0; i < 9; i++) {
            cout << cube[0][i];
            if (i % 3 == 2) cout << '\n';
        }
    }
}