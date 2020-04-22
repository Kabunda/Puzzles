#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string mapCoding(string s,int key)
{
    for (char& c : s)
    {
        int n = c + key++;
        n = (n - 'A') % 26 + 'A';
        c = (char)n;
    }
    return s;
}
string rotorCoding(string s, string* rotor)
{
    for (int i = 0; i < 3; i++)
    {
        for (char& c : s)
        {
            c = rotor[i][c - 'A'];
        }
    }
    return s;
}
string rotorDecod(string s, string* rotor)
{
    for (int i = 2; i >= 0; i--)
    {
        for (char& c : s)
        {
            int n = rotor[i].find(c);
            c = (char)n + 'A';
        }
    }
    return s;
}
string mapDecod(string s, int key)
{
    for (char& c : s)
    {
        int n = c - key++;
        while (n < 'A')
        {
            n = n + 26;
        }
        c = (char)n;
    }
    return s;
}
int main()
{
    string Operation;
    getline(cin, Operation);
    int pseudoRandomNumber;
    cin >> pseudoRandomNumber; cin.ignore();
    string* rotor = new string[3];
    for (int i = 0; i < 3; i++) {
        getline(cin, rotor[i]);
    }
    string message;
    getline(cin, message);
    if (Operation == "ENCODE")
        cout << rotorCoding(mapCoding(message, pseudoRandomNumber), rotor) << endl;
    else
        cout << mapDecod(rotorDecod(message, rotor), pseudoRandomNumber) << endl;
    delete[]rotor;
}