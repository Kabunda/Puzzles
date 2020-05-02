#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    multimap<int,int> posElev;
    posElev.insert({ exitFloor, exitPos });
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        posElev.insert({ elevatorFloor, elevatorPos });
    }
    // game loop
    for (auto i : posElev)
        cerr << '#' << i.first << '\t' << i.second << endl;
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        cerr << "f^" << nbFloors << ' '
            << 'w' << width << ' '
            << 'r' << nbRounds << ' '
            << "exit>" << exitFloor << ':' << exitPos << ' '
            << 't' << nbTotalClones << ' '
            << 'a' << nbAdditionalElevators << ' '
            << 'e' << nbElevators << endl;
        cerr << cloneFloor << '\t' << clonePos << '\t' << direction << endl;

        string ans = "WAIT";
        int c = posElev.count(cloneFloor);
        if (c == 0 and cloneFloor != -1) {
            ans = "ELEVATOR";
            posElev.insert({ cloneFloor, clonePos });
        }
        else {
            int nearElev;
            if (c == 1) {
                nearElev = (*posElev.find(cloneFloor)).second;
            }
            else {
                int min = width;
                auto it = posElev.equal_range(cloneFloor);
                for (auto i = it.first; i != it.second;i++) {
                    if (abs(i->second - clonePos) <= min) {
                        min = abs(i->second - clonePos);
                        nearElev = i->second;
                    }
                }
            }
            if (clonePos > nearElev and direction == "RIGHT")
                ans = "BLOCK";
            if (clonePos < nearElev and direction == "LEFT")
                ans = "BLOCK";
        }
        cout << ans << endl; // action: WAIT or BLOCK
    }
}