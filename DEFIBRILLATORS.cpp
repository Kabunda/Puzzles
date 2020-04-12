#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

string zamena(string s, char a = ',', char b = '.')
{
    int n = s.find(a);
    if (n != -1) 
        s.replace(n,n+1, 1, b);
    return s;
}
string izvlech(string s, int n = 4,char c=';')
{
    int x = -1;
    for (int i = 0; i < n; i++) {
        x = s.find(c, x + 1);
    }
    int y = s.find(c, x + 1);
    return s.substr(x + 1, y - x - 1);
}
double rad(double grad)
{
    return grad * 3.1415 / 180;
}
int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();

    LON = zamena(LON);
    LAT = zamena(LAT);

    double lon = stof(LON);
    double lat = stof(LAT);

    double min = -1;
    string st = "nofing";

    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        //cerr << izvlech(DEFIB, 1) << '\n';
        //cerr << izvlech(DEFIB, 4) << '\t' << izvlech(DEFIB, 5) << '\n';
        double longitude = stof(zamena(izvlech(DEFIB, 4)));
        double latitude = stof(zamena(izvlech(DEFIB, 5)));
        double x = (rad(longitude) - rad(lon)) * cos((rad(latitude) + rad(lat)) / 2);
        double y = rad(latitude) - rad(lat);
        double d = sqrt(x * x + y * y) * 6371;
        if ((izvlech(DEFIB, 0) == "107") or (izvlech(DEFIB, 0) == "108")) {
            cerr << izvlech(DEFIB, 4) << '\t' << izvlech(DEFIB, 5) << '\n';
            cerr << "\td=\t" << d << '\t' << izvlech(DEFIB, 1) << '\n';
            
        }
        if ((d < min) or (min == -1)) {
            min = d;
            st = izvlech(DEFIB, 1);
            cerr << izvlech(DEFIB, 4) << '\t' << izvlech(DEFIB, 5) << '\n';
            cerr << "\td=\t" << d << '\t' << izvlech(DEFIB, 1) << '\n';
        }
    }


    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    //cerr << "lon =\t" << LON << '\t' << lon << '\n';
    //cerr << "lot =\t" << LAT << '\t' << lat << '\n';
    cerr << "\td=\t" << min<<'\n';
    std::cout << st << endl;
}