#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Xmin;
int Xmax;
int Ymin;
int Ymax;
string Jump(string Detect, int& x, int& y)
{
    if (Detect == "U" or Detect == "UR" or Detect == "UL") Ymax = y - 1;
    if (Detect == "D" or Detect == "DR" or Detect == "DL") Ymin = y + 1;
    if (Detect == "L" or Detect == "DL" or Detect == "UL") Xmax = x - 1;
    if (Detect == "R" or Detect == "UR" or Detect == "DR") Xmin = x + 1;
    x = (Xmax + Xmin) / 2;
    y = (Ymax + Ymin) / 2;
    return to_string(x) + " " + to_string(y);
}
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    Xmin = 0;
    Xmax = W - 1;
    Ymin = 0;
    Ymax = H - 1;
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();
        cout << Jump(bombDir, X0, Y0) << endl;
    }
}