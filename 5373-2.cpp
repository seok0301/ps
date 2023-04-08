#include <bits/stdc++.h>
using namespace std;
char cube[6][3][3];
char tmpCube[6][3][3];

char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
const int U = 0;
const int D = 1;
const int F = 2;
const int B = 3;
const int L = 4;
const int R = 5;

void makeTempCube() {
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                tmpCube[i][j][k] = cube[i][j][k];
}

void rot(int side, int r) {
    while (r--) {
        makeTempCube();
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[side][i][j] = tmpCube[side][2 - j][i];
    }
}

void rotate(int side, int clockwise) {
    int r; clockwise ? r = 1 : r = 3;
    rot(side, r);
    while (r--) {
        makeTempCube();
        if (side == U) {
            for (int i = 0; i < 3; i++) {
                cube[B][0][2 - i] = tmpCube[L][0][2 - i];
                cube[R][0][2 - i] = tmpCube[B][0][2 - i];
                cube[F][0][2 - i] = tmpCube[R][0][2 - i];
                cube[L][0][2 - i] = tmpCube[F][0][2 - i];
            }
        } else if (side == D) {
            for (int i = 0; i < 3; i++) {
                cube[F][2][i] = tmpCube[L][2][i];
                cube[R][2][i] = tmpCube[F][2][i];
                cube[B][2][i] = tmpCube[R][2][i];
                cube[L][2][i] = tmpCube[B][2][i];
            }
        } else if (side == F) {
            for (int i = 0; i < 3; i++) {
                cube[U][2][i] = tmpCube[L][2 - i][2];
                cube[R][i][0] = tmpCube[U][2][i];
                cube[D][0][2 - i] = tmpCube[R][i][0];
                cube[L][2 - i][2] = tmpCube[D][0][2 - i];
            }
        } else if (side == B) {
            for (int i = 0; i < 3; i++) {
                cube[U][0][2 - i] = tmpCube[R][2 - i][2];
                cube[L][i][0] = tmpCube[U][0][2 - i];
                cube[D][2][i] = tmpCube[L][i][0];
                cube[R][2 - i][2] = tmpCube[D][2][i];
            }
        } else if (side == L) {
            for (int i = 0; i < 3; i++) {
                cube[U][i][0] = tmpCube[B][2 - i][2];
                cube[F][i][0] = tmpCube[U][i][0];
                cube[D][i][0] = tmpCube[F][i][0];
                cube[B][2 - i][2] = tmpCube[D][i][0];
            }
        } else {
            for (int i = 0; i < 3; i++) {
                cube[U][2 - i][2] = tmpCube[F][2 - i][2];
                cube[B][i][0] = tmpCube[U][2 - i][2];
                cube[D][2 - i][2] = tmpCube[B][i][0];
                cube[F][2 - i][2] = tmpCube[D][2 - i][2];
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    cube[i][j][k] = color[i];

        int n; cin >> n;
        while (n--) {
            string method; cin >> method;
            if (method[0] == 'U') rotate(U, method[1] == '+');
            else if (method[0] == 'D') rotate(D, method[1] == '+');
            else if (method[0] == 'F') rotate(F, method[1] == '+');
            else if (method[0] == 'B') rotate(B, method[1] == '+');
            else if (method[0] == 'L') rotate(L, method[1] == '+');
            else rotate(R, method[1] == '+');
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << cube[U][i][j];
            cout << '\n';
        }
    }
}