#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Plan
{ 
    int N;      // оставшийся огонь
    int L;      // размер леса
    int water;  // оставшаяся вода
    bool m[21][21] = { false };
    int CountFire(int x, int y,int z,bool braise = false)
    {
        if (x + z > L or y + z > L or x < 0 or y < 0) 
            return -1;  // если тушение невозможно
        int count = 0;
        for (int i = y; i < y + z; i++) // строки
            for (int j = x; j < x + z; j++) // столбы
                if (m[i][j] == true) {
                    count++; // считаем количество огня
                    if (braise == true) m[i][j] = false;
                }
        return count;
    }
    void BraiseFire(int x, int y, int z)
    {
        N = N - CountFire(x, y, z,true);
        if (z == 1) water -= 600;
        if (z == 2) water -= 1200;
        if (z == 3) water -= 2100;

    }
    void Answer(int x,int y,char l)
    {
        cout << l << " " << x << " " << y << endl;
    }
public:
    Plan(int size, int wat, int fires = 0)
    {
        L = size;        water = wat;        N = fires;
    }
    void SetFire(int x, int y)
    {
        m[y][x] = true;        N++;
    }
    bool Braise(int x1 = 0, int y1 = 0)
    {
        if (N == 0) return true;
        for (int i = y1; i < L; i++)
            for (int j = x1; j < L; j++) {
                if (CountFire(j, i, 1) == 1 and water >= 600) {
                    Plan t = *this;
                    t.BraiseFire(j, i, 1);
                    if (t.Braise(j, i) == true) {
                        Answer(j, i, 'J');
                        return true;
                    }
                }
                if (CountFire(j, i, 2) >= 3 and water >= 1200) {
                    Plan t = *this;
                    t.BraiseFire(j, i, 2);
                    if (t.Braise(j, i) == true) {
                        Answer(j, i, 'H');
                        return true;
                    }
                }
                if (CountFire(j, i, 3) >= 4 and water >= 2100) {
                    Plan t = *this;
                    t.BraiseFire(j, i, 3);
                    if (t.Braise(j, i) == true) {
                        Answer(j, i, 'C');
                        return true;
                    }
                }
            }
        return false;
    }
};

int main()
{
    int L; // Size of forest map
    cin >> L; cin.ignore();
    int water; // Total amount of water available
    cin >> water; cin.ignore();
    // game loop
    while (1) {
        int N; // Amount of fires
        cin >> N; cin.ignore();
        Plan w(L, water);
        for (int i = 0; i < N; i++) {
            int fireX; // X coordinate of fire
            int fireY; // Y coordinate of fire
            cin >> fireX >> fireY; cin.ignore();
            w.SetFire(fireX,fireY);
        }
        w.Braise();
    }
}