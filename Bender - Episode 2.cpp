#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
struct rooms
{
    //int num;
    int cash;
    int f_exit;
    int s_exit;
    bool visit;
};
pair <int,rooms> Construktor(string s) 
{
    rooms r;
    int t1 = s.find(' ', 0);
    int num = stoi(s.substr(0, t1));
    int t2 = s.find(' ', t1 + 1);
    r.cash = stoi(s.substr(t1, t2-t1));
    int t3 = s.find(' ', t2 + 1);
    string e = s.substr(t2+1, t3-t2-1);
    if (e == "E")
        r.f_exit = -1;
    else
        r.f_exit = stoi(e);
    e = s.substr(t3+1);
    if (e == "E")
        r.s_exit = -1;
    else
        r.s_exit = stoi(e);
    r.visit = false;
    return make_pair(num,r);
}
map <int,rooms> m;
int search_max(int n)
{
    if (m[n].visit == true)
        return 0;
    m[n].visit = true;
    int a, b;
    if (m[n].f_exit == -1) {
        m[n].visit = false;
        return m[n].cash;
    }
    else
        a = search_max(m[n].f_exit);
    if (m[n].s_exit == -1) {
        m[n].visit = false;
        return m[n].cash;
    }
    else
        b = search_max(m[n].s_exit);
    if (a > b)
        b = a;
    m[n].visit = false;
    return b + m[n].cash;
}
int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string room;
        getline(cin, room);
        m.insert(Construktor(room));
    }
    cout << search_max(0) << endl;
}