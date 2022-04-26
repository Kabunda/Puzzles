#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int a,b;
	string s = "15 5 11 22";
	a = stoi(s.substr(0, s.find(' ', 0));
	b = stoi(s.substr(s.find(' ', 0), s.find(' ', s.find(' ', 0)));
	cout << a << endl;
	cout << b << endl;
}