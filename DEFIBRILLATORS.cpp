#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string zamena(string s, char a = ',', char b = '.')
{// заменяет в строке s запятую на точку
    int n = s.find(a);
    if (n != -1) s.replace(n, n + 1, 1, b);
    return s;
}
string izvlech(string s, int n = 4,char c=';')
{// извлекает из строки запись номер int n. Разделитель char c
    int x = -1;
    for (int i = 0; i < n; i++) {
        x = s.find(c, x + 1);
    }
    int y = s.find(c, x + 1);
    return s.substr(x + 1, y - x - 1);
}
double rad(double grad)
{// перевод градусов в радианы
    return grad * 3.1415 / 180.;
}
double dist(double lon1, double lat1, double lon2, double lat2)
{
    double x = ((lon2) - (lon1)) * cos((rad(lat1) + rad(lat2)) / 2.);
    double y = (lat2) - (lat1);
    double d = sqrt(pow(x, 2.) + pow(y, 2.)) * 6371.;
    return d;
}
int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();

    double lon = stof(zamena(LON));
    double lat = stof(zamena(LAT));

    double min = -1;
    string st = "nofing";

    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        double longitude = stof(zamena(izvlech(DEFIB, 4)));
        double latitude = stof(zamena(izvlech(DEFIB, 5)));
        double d = dist(longitude, latitude, lon, lat);
        if ((izvlech(DEFIB, 0) == "107") or (izvlech(DEFIB, 0) == "108")) {
            cerr << zamena(izvlech(DEFIB, 5)) << '\t' << zamena(izvlech(DEFIB, 4));
            cerr << "\td= " << d << '\t' << izvlech(DEFIB, 1) << '\n';
            
        }
        if ((d < min) or (min == -1)) {
            min = d;
            st = izvlech(DEFIB, 1);
            cerr << zamena(izvlech(DEFIB, 5)) << '\t' << zamena(izvlech(DEFIB, 4));
            cerr << "\td= " << d << '\t' << izvlech(DEFIB, 1) << '\n';
        }
    }

    std::cout << st << endl;
}