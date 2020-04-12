#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int refer(string);
class Stroka
{
public:
    string oper;
    string a1;
    string a2;
    int rezultat;
    bool r = false;// флаг подсчитанного результата
    int rez()
    {
        if (r == true) return rezultat;// если уже считали, то повторно не считать
        int rezult = 0;
        if (oper == "VALUE") rezult = refer(a1);
        else if (oper == "ADD") rezult = refer(a1) + refer(a2);
        else if (oper == "SUB") rezult = refer(a1) - refer(a2);
        else if (oper == "MULT") rezult = refer(a1) * refer(a2);
        r = true;
        rezultat = rezult;
        return rezultat;
    }
};
vector<Stroka> sh1;
int refer(string st)
{
    if (st == "_") return 0;
    if (st[0] != '$') return stoi(st);
    int n = stoi(st.substr(1));
    return sh1[n].rez();
}
int main()
{
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        Stroka x;
        cin >> x.oper >> x.a1 >> x.a2; cin.ignore();
        sh1.push_back(x);
    }
    for (int i = 0; i < N; i++) {
        cout << sh1[i].rez() << endl;
    }
}
