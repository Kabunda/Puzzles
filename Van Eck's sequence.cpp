#include <iostream>
#include <map>

using namespace std;

int main()
{
    int A1;
    cin >> A1; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    map <int, int> keys;
    for (int n = 1; n < N; n++)
    {
        int* p = &keys[A1];
        A1 = (*p) ? (n - *p) : 0;
        *p = n;
    }
    cout << A1 << endl;
}