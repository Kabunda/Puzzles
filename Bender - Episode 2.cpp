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
    int n;
    vector <string> map;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string room;
        getline(cin, room);
        map.push_back(room);
    }
    for (int i=0;i<n;i++){
        cout << map[i] << endl;
    }
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "answer" << endl;
}