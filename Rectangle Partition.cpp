#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w;
    int h;
    int countX;
    int countY;
    cin >> w >> h >> countX >> countY; cin.ignore();
    int* x1 = new int[(countX + 2) + (countY + 2)];
    int* y1 = x1 + countX + 2;
    int* segX = new int[((countX + 1) * (countX + 2)) / 2];
    x1[0] = 0;
    y1[0] = 0;
    x1[countX + 1] = w;
    y1[countY + 1] = h;
    int itX = 0;
    for (int i = 1; i <= countX; i++) {
        int x;
        cin >> x; cin.ignore();      
        x1[i] = x;
        for (int j = 0; j < i; j++)
            segX[itX++] = x1[i] - x1[j];
    }
    for (int j = 0; j <= countX; j++)
        segX[itX++] = x1[countX+1] - x1[j];

    int count = 0;
    for (int i = 1; i <= countY; i++) {
        int y;
        cin >> y; cin.ignore();
        y1[i] = y;
        for (int j = 0; j < i; j++)
            for (int k = 0; k < itX; k++)
                if (segX[k] == y1[i] - y1[j]) count++;
    }
    for (int j = 0; j <= countY; j++)
        for (int k = 0; k < itX; k++)
            if (segX[k] == y1[countY+1] - y1[j]) count++;

    cout << count << endl;
    delete[]segX;
    delete[]x1;
}