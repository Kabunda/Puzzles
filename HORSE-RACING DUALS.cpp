#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    set <int> m;
    set <int>::iterator it;

    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        m.insert(Pi);
    }
    it = m.begin();
    int min = -1;
    for (int i = 1; i < N; i++) {// число сравнений на 1 меньше (N-1)
        int x1 = *it;
        it++;
        int x2 = *it;
        int z = abs(x1 - x2);
        if ((min == -1) or (z<=min)) {
            min = z;
        }
    }
    cout << min << endl;
}
