#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Svetofor
{
public:
    int dist;// дистанция до светофора
    int light;// интервал переключения
    bool ColorGreen(int speed)
    {// скорость движения к светофору в км/ч
        double s = (double)speed * .277777;// перевод скорости в м/с
        double t = (double)dist / s;// время приезда
        int in = (int)t % (2 * light);// остаток от деления на интервал
        if (in < light) return true;    // если в первой половинке то зеленый
        else            return false;   // если во второй то красный
    }
};
vector<Svetofor> way;
bool VseSvetofori(int speed)
{
    for (int i = 0; i < way.size(); i++)
        if (way[i].ColorGreen(speed) == false)
            return false;
    return true;
}
int main()
{
    int speed;
    cin >> speed; cin.ignore();
    int lightCount;
    cin >> lightCount; cin.ignore();
    for (int i = 0; i < lightCount; i++) {
        Svetofor n;
        cin >> n.dist >> n.light; cin.ignore();
        way.push_back(n);
    }
    // крутим, пока есть красные светофоры
    while (VseSvetofori(speed) == false)
        speed--;

    cout << speed << endl;
}