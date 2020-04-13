#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
struct runner
{
    char name;
    int pos;
};
int main()
{
    int W;
    int H;
    cin >> W >> H; cin.ignore();
    vector <runner> grid;
    string names;
    getline(cin, names);
    for (int i = 0; i < names.size(); i++) {
        if (names[i] != ' ') 
            grid.push_back({ names[i], i });
    }
    for (int i = 1; i < H - 1; i++) {
        string line;
        getline(cin, line);
        for (int i = 0; i < grid.size(); i++) {
            if ((grid[i].pos > 0) and (line[grid[i].pos - 1] == '-'))
                grid[i].pos = grid[i].pos - 3;
            else if ((grid[i].pos < W - 1) and (line[grid[i].pos + 1] == '-'))
                grid[i].pos = grid[i].pos + 3;
        }
    }
    getline(cin, names);
    for (int i = 0; i < grid.size(); i++){
        cout << grid[i].name << names[grid[i].pos] << endl;
    }
}