#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Svetofor
{
public:
    int dist;// ��������� �� ���������
    int light;// �������� ������������
    bool ColorGreen(int speed)
    {// �������� �������� � ��������� � ��/�
        double s = (double)speed * .277777;// ������� �������� � �/�
        double t = (double)dist / s;// ����� �������
        int in = (int)t % (2 * light);// ������� �� ������� �� ��������
        if (in < light) return true;    // ���� � ������ ��������� �� �������
        else            return false;   // ���� �� ������ �� �������
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
    // ������, ���� ���� ������� ���������
    while (VseSvetofori(speed) == false)
        speed--;

    cout << speed << endl;
}