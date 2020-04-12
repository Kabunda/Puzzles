#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
struct Player
{
    int name;
    string action;
    string story;
};
bool battle(const Player &playerA,const Player &playerB)
{
    if (playerA.action == "R") {
        if (playerB.action == "C") return true;
        if (playerB.action == "S") return false;
        if (playerB.action == "L") return true;
        if (playerB.action == "P") return false;
        if (playerA.name < playerB.name) return true;
        return false;
    }
    if (playerA.action == "C") {
        if (playerB.action == "R") return false;
        if (playerB.action == "S") return false;
        if (playerB.action == "L") return true;
        if (playerB.action == "P") return true;
        if (playerA.name < playerB.name) return true;
        return false;
    }
    if (playerA.action == "S") {
        if (playerB.action == "C") return true;
        if (playerB.action == "R") return true;
        if (playerB.action == "L") return false;
        if (playerB.action == "P") return false;
        if (playerA.name < playerB.name) return true;
        return false;
    }
    if (playerA.action == "L") {
        if (playerB.action == "C") return false;
        if (playerB.action == "S") return true;
        if (playerB.action == "R") return false;
        if (playerB.action == "P") return true;
        if (playerA.name < playerB.name) return true;
        return false;
    }
    if (playerA.action == "P") {
        if (playerB.action == "C") return false;
        if (playerB.action == "S") return true;
        if (playerB.action == "L") return false;
        if (playerB.action == "R") return true;
        if (playerA.name < playerB.name) return true;
        return false;
    }
}
int main()
{
    vector<Player> grid;
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        Player temp;
        cin >> temp.name >> temp.action; cin.ignore();
        temp.story = "";
        grid.push_back(temp);
    }

    while (grid.size()>1)
    {
        for (int i = 0; i < grid.size(); i++) {
            if (battle(grid[i], grid[i + 1]))
                swap(grid[i], grid[i + 1]);
            grid[i + 1].story = grid[i + 1].story + " " + to_string(grid[i].name);
            grid.erase(grid.begin() + i);
        }
    }
    cout << grid[0].name << endl;
    cout << grid[0].story.substr(1) << endl;
}