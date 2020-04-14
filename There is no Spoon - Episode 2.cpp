#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int width; // the number of cells on the X axis
int height; // the number of cells on the Y axis
/**
 * The machines are gaining ground. Time to show them what we're really made of...
 **/

class Point
{
public:
	Point()
	{
	}
	Point(char s)
	{
		if (s == '.') {
			value = 0;
			paint = 0;
		}
		else {
			value = s - 48;
			paint = 55;
		}
		remain = value;
		if (value == 1) {
			up = 1; down = 1; left = 1; right = 1;
		}
		else {
			up = 2; down = 2; left = 2; right = 2;
		}
	}
	~Point()
	{

	}
	bool Cell()
	{
		if (paint == 55)
			return true;
		else
			return false;
	}
	string PrintP()
	{
		return to_string(remain);
	}
	bool gorizont()
	{
		if (paint == 33 or paint == 44)
			return true;
		return false;
	}
	bool vertikal()
	{
		if (paint == 11 or paint == 22)
			return true;
		return false;
	}
	void PaintCell(string naprav)
	{
		if (naprav == "gor") paint = 33;
		if (naprav == "ver") paint = 11;
	}
	void Connect(string ns, int nl)
	{
		if (ns == "up") up = up - nl;
		if (ns == "down") down = down - nl;
		if (ns == "left") left = left - nl;
		if (ns == "right") right = right - nl;
		remain = remain - nl;
		if (remain == 0) {
			up = 0; down = 0; left = 0; right = 0;
		}
	}
	int up;
	int down;
	int left;
	int right;
	int remain; // остаток неиспользованных связей
	char value;  // ячейка со значением
	int paint; // преграда для расчетов (false пусто, true занято)
				// paint -  11 - вертикальная
				//          22 - две вертикальные
				//          33 - горизонтальная
				//          44 - две горизонтальные
				//          55 - узел
				//          0 - чистая
};
Point grid[30][30];
class Begunok
{
	int x;
	int y;
	int up;
	int down;
	int left;
	int right;
	int remain;
public:
	Begunok(int xx, int yy)
	{
		x = xx;
		y = yy;
		up = grid[x][y].up;
		down = grid[x][y].down;
		left = grid[x][y].left;
		right = grid[x][y].right;
		remain = grid[x][y].remain;
	}

	bool Run()
	{
		// 1 обновляем коннекторы
		if (up > 0) up = goUp();
		if (down > 0) down = goDown();
		if (left > 0) left = goLeft();
		if (right > 0) right = goRight();
		cerr << '[' << x << ':' << y << ']' << '\t';
		cerr << '(' << remain << ')' << 't';
		cerr << 'U' << up << 'D' << down << 'L' << left << 'R' << right << endl;
		// 2 проверяем однозначность хода
		if (remain == (up + down + left + right)) {
			DrawAll(1);
			return true;
		}
		if ((remain == 1) and (numWays() == 1)) {
			DrawAll(1);
			return true;
		}
		if ((remain == 2) and (numWays() == 1)) {
			DrawAll(2);
			return true;
		}
		if ((remain == 3) and (numWays() == 2)) {
			DrawAll(1);
			return true;
		}
		if ((remain == 4) and (numWays() == 2)) {
			DrawAll(2);
			return true;
		}
		if ((remain == 5) and (numWays() == 3)) {
			DrawAll(1);
			return true;
		}
		if ((remain == 6) and (numWays() == 3)) {
			DrawAll(2);
			return true;
		}
		return false;
	}
	int numWays()
	{
		int n=0;
		if (up > 0) n++;
		if (down > 0) n++;
		if (left > 0) n++;
		if (right > 0) n++;
		return n;
	}
	void PrintAnswer(int x2, int y2, int NumberOfLinks)
	{
		cout << x << ' ' << y << ' ' << x2 << ' ' << y2 << ' ' << NumberOfLinks << '\n';
	}
	void DrawAll(int NumberOfLinks)
	{
		if (up > 0) drawUp(NumberOfLinks);
		if (down > 0) drawDown(NumberOfLinks);
		if (left > 0) drawLeft(NumberOfLinks);
		if (right > 0) drawRight(NumberOfLinks);
	}
private:
	int goUp()
	{
		for (int i = y - 1; i >= 0; i--) {
			if (grid[x][i].gorizont() == true) return 0;
			if (grid[x][i].Cell() == true) return grid[x][i].down;
		}
		return 0;
	}
	int goDown()
	{
		for (int i = y + 1; i < height ; i++) {
			if (grid[x][i].gorizont() == true) return 0;
			if (grid[x][i].Cell() == true) return grid[x][i].up;
		}
		return 0;
	}
	int goLeft()
	{
		for (int i = x - 1; i >= 0; i--) {
			if (grid[i][y].vertikal() == true) return 0;
			if (grid[i][y].Cell() == true) return grid[i][y].right;
		}
		return 0;
	}
	int goRight()
	{
		for (int i = x + 1; i < width; i++) {
			if (grid[i][y].vertikal() == true) return 0;
			if (grid[i][y].Cell() == true) return grid[i][y].left;
		}
		return 0;
	}
	void drawUp(int NumberOfLinks)
	{
		grid[x][y].Connect("up", NumberOfLinks);
		for (int i = y - 1; i >= 0; i--) {
			if (grid[x][i].Cell() == true) {
				grid[x][i].Connect("down", NumberOfLinks);
				PrintAnswer(x, i, NumberOfLinks);
				return;
			}
			else {
				grid[x][i].PaintCell("ver");
			}
		}
	}
	void drawDown(int NumberOfLinks)
	{
		grid[x][y].Connect("down", NumberOfLinks);
		for (int i = y + 1; i < height; i++) {
			if (grid[x][i].Cell() == true) {
				grid[x][i].Connect("up", NumberOfLinks);
				PrintAnswer(x, i, NumberOfLinks);
				return;
			}
			else {
				grid[x][i].PaintCell("ver");
			}
		}
	}
	void drawLeft(int NumberOfLinks)
	{
		grid[x][y].Connect("left", NumberOfLinks);
		for (int i = x - 1; i >= 0; i--) {
			if (grid[i][y].Cell() == true) {
				grid[i][y].Connect("right", NumberOfLinks);
				PrintAnswer(i, y, NumberOfLinks);
				return;
			}
			else {
				grid[i][y].PaintCell("gor");
			}
		}
	}
	void drawRight(int NumberOfLinks)
	{
		grid[x][y].Connect("right", NumberOfLinks);
		for (int i = x + 1; i < width; i++) {
			if (grid[i][y].Cell() == true) {
				grid[i][y].Connect("left", NumberOfLinks);
				PrintAnswer(i, y, NumberOfLinks);
				return;
			}
			else {
				grid[i][y].PaintCell("gor");
			}
		}
	}
};
int main()
{
	cin >> width; cin.ignore();
	cin >> height; cin.ignore();
	for (int i = 0; i < height; i++) {
		string line;
		getline(cin, line); // width characters, each either a number or a '.'
		for (int j = 0; j < width; j++) {
				grid[j][i] = { line[j] };
		}
	}
	/* тестовый вывод карты поля
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cerr << grid[j][i].PrintP() << ' ';
		}
		cerr << '\n';
	}
	*/
	bool changes;
	int count = 0;
	do
	{
		count++;
		changes = false;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (grid[j][i].Cell() ==true) {
					Begunok t(j, i);
					if (t.Run()==true) changes = true;
				}
			}
		}
		cerr << "Count " << count<<endl;
	} while (changes == true);
	cout << "Options are finished" << endl;
	// работы по отрисовке ненадежных связей
}