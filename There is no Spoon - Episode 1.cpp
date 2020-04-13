#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int width; // the number of cells on the X axis
int height; // the number of cells on the Y axis

bool a[30][30];

void PrintR(int x, int y) {
    for (int i = x+1; i < width; i++) {
        if (a[i][y] == true) {
            cout << i << ' ' << y << ' ';
            return;
        }
    }
    cout << "-1 -1 ";
    return;
}
void PrintD(int x, int y) {
    for (int i = y+1; i < height; i++) {
        if (a[x][i] == true) {
            cout << x << ' ' << i;
            return;
        }
    }
    cout << "-1 -1";
    return;
}
int main()
{
    cin >> width; cin.ignore();
    cin >> height; cin.ignore();
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .
        for (int j = 0; j < width; j++) {
            if (line[j] == '.') 
                a[j][i] = false;
            else 
                a[j][i] = true;
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (a[j][i] == true) {
                cout << j << ' ' << i << ' ';
                PrintR(j, i);
                PrintD(j, i);
                cout << endl;
            }
        }
    }
}