#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int x1;
    int y1;
    cin >> x1 >> y1; cin.ignore();
    int x2;
    int y2;
    cin >> x2 >> y2; cin.ignore();
    float x3 = ((float)x1 + (float)x2)/2;
    float y3 = ((float)y1 + (float)y2)/2;
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << x3<<' '<<y3 << endl;
}