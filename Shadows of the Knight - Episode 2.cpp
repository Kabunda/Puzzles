#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Xmin;
int Xmax;
int Ymin;
int Ymax;
string Jump(string Detect, int& x, int& y, int& xold, int& yold, bool** A)
{
    int xnew = 0;
    int ynew = 0;
    if (Detect == "UNKNOWN") {
        if (x < (Xmax + Xmin) / 2) {
            xnew = (Xmax + x) / 2;
        }
        else {
            xnew = (x + Xmin) / 2;
        }
        if (y < (Ymax + Ymin) / 2) {
            ynew = (Ymax + y) / 2;
        }
        else {
            ynew = (y + Ymin) / 2;
        }
    }
    if (Detect == "WARMER") {

    }

    xold = x; yold = y; x = xnew; y = ynew;
    return to_string(xnew) + " " + to_string(ynew);
}
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
            // динамический массив 2D
    bool** A = new bool* [H];
    A[0] = new bool[H * W];
    for (int i = 0; i < H; i++) {
        A[i] = A[0] + i * W;
        for (int j = 0; j < W; j++)
            A[i][j] = false; // инициализация
    }
    
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    Xmin = 0;
    Xmax = W - 1;
    Ymin = 0;
    Ymax = H - 1;
    int x1 = X0;
    int y1 = Y0;
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();
        cout << Jump(bombDir, X0, Y0, x1, y1, A) << endl;
        //cerr << x1 << ':' << y1 << '>' << X0 << ':' << Y0 << endl;
    }
    delete[] A[0];
    delete[] A;
}