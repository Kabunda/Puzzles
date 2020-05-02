#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Line
{
    string line;
    string expre;
    string types;
public:
    Line(string s,string e,string t)
    {
        line = s;
        expre = e;
        types = t;
    }
    int compare(Line a, Line b)
    {

    }
    void Print()
    {
        cerr << line << endl;
    }
};
vector <Line> base;
int main()
{
    string expression;
    getline(cin, expression);
    string types;
    getline(cin, types);
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string ROW;
        getline(cin, ROW);
        Line t(ROW, expression, types);
        base.push_back(t);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for (Line i : base)
        i.Print();
    cout << "answer" << endl;
}