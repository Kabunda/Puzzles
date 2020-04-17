#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int width; // the number of cells on the X axis
int height; // the number of cells on the Y axis

class Point
{
public:
	Point()
	{
		Point('.');
	}
	Point(char s)
	{
		if (s == '.') {		
			remain = 0; paint = 0;
		}
		else {
			remain = s - 48; paint = 3;
		}
		if (remain >= 2){
			up = 2; down = 2; left = 2; right = 2;
		}
		else{
			up = remain; down = remain; left = remain; right = remain; 
		}
	}
	bool getCell()
	{
		if (paint == 3)
			return true;
		else
			return false;
	}
	string PrintP()
	{
		return to_string(remain);
	}
	bool getGoriz()
	{
		if (paint == 2)
			return true;
		return false;
	}
	bool getVert()
	{
		if (paint == 1)
			return true;
		return false;
	}
	void setGoriz()
	{
		paint = 2;
	}
	void setVert()
	{
		paint = 1;
	}
	void setConnectUp(int NumberOfLinks)
	{
		up = up - NumberOfLinks;
		CalculNRem(NumberOfLinks);
	}
	void setConnectDown(int NumberOfLinks)
	{
		down = down - NumberOfLinks;
		CalculNRem(NumberOfLinks);
	}
	void setConnectLeft(int NumberOfLinks)
	{
		left = left - NumberOfLinks;
		CalculNRem(NumberOfLinks);
	}
	void setConnectRight(int NumberOfLinks)
	{
		right = right - NumberOfLinks;
		CalculNRem(NumberOfLinks);
	}
	int connecterUp()
	{
		return up;
	}
	int connecterDown()
	{
		return down;
	}
	int connecterLeft()
	{
		return left;
	}
	int connecterRight()
	{
		return right;
	}
	int getRemain()
	{
		return remain;
	}
private:
	int up;
	int down;
	int left;
	int right;
	int remain; // остаток неиспользованных связей
	int paint; // 
				// paint -  1 - вертикальная
				//          2 - горизонтальная 
				//          3 - узел
				//          0 - чистая
	void CalculNRem(int NumberOfLinks = 0)
	{
		remain = remain - NumberOfLinks;
		if (remain == 0) {
			up = 0; down = 0; left = 0; right = 0;
		}
		if (remain == 1) {
			if (up > 1) up = 1;
			if (down > 1) down = 1;
			if (left > 1) left = 1;
			if (right > 1) right = 1;
		}
	}
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
		up = grid[x][y].connecterUp();
		down = grid[x][y].connecterDown();
		left = grid[x][y].connecterLeft();
		right = grid[x][y].connecterRight();
		remain = grid[x][y].getRemain();
	}

	bool Run(int exp)
	{
	// 1 обновляем коннекторы
		if (up > 0) up = goUp();
		if (down > 0) down = goDown();
		if (left > 0) left = goLeft();
		if (right > 0) right = goRight();
	/*	cerr << '[' << x << ':' << y << ']' << '\t';
		cerr << '(' << remain << ')' << 't';
		cerr << 'U' << up << 'D' << down << 'L' << left << 'R' << right << endl;
	*/
	// распеределенную ячейку не трогаем
		if (remain == 0) return false;
	// 2 проверяем однозначность хода	

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
		if (remain == (up + down + left + right)) {
			DrawAll(1);
			return true;
		}
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
			if (grid[x][i].getGoriz() == true) return 0;
			if (grid[x][i].getCell() == true) return grid[x][i].connecterDown();
		}
		return 0;
	}
	int goDown()
	{
		for (int i = y + 1; i < height ; i++) {
			if (grid[x][i].getGoriz() == true) return 0;
			if (grid[x][i].getCell() == true) return grid[x][i].connecterUp();
		}
		return 0;
	}
	int goLeft()
	{
		for (int i = x - 1; i >= 0; i--) {
			if (grid[i][y].getVert() == true) return 0;
			if (grid[i][y].getCell() == true) return grid[i][y].connecterRight();
		}
		return 0;
	}
	int goRight()
	{
		for (int i = x + 1; i < width; i++) {
			if (grid[i][y].getVert() == true) return 0;
			if (grid[i][y].getCell() == true) return grid[i][y].connecterLeft();
		}
		return 0;
	}
	void drawUp(int NumberOfLinks)
	{
		grid[x][y].setConnectUp(NumberOfLinks);
		for (int i = y - 1; i >= 0; i--) {
			if (grid[x][i].getCell() == true) {
				grid[x][i].setConnectDown(NumberOfLinks);
				PrintAnswer(x, i, NumberOfLinks);
				return;
			}
			else {
				grid[x][i].setVert();
			}
		}
	}
	void drawDown(int NumberOfLinks)
	{
		grid[x][y].setConnectDown(NumberOfLinks);
		for (int i = y + 1; i < height; i++) {
			if (grid[x][i].getCell() == true) {
				grid[x][i].setConnectUp(NumberOfLinks);
				PrintAnswer(x, i, NumberOfLinks);
				return;
			}
			else {
				grid[x][i].setVert();
			}
		}
	}
	void drawLeft(int NumberOfLinks)
	{
		grid[x][y].setConnectLeft(NumberOfLinks);
		for (int i = x - 1; i >= 0; i--) {
			if (grid[i][y].getCell() == true) {
				grid[i][y].setConnectRight(NumberOfLinks);
				PrintAnswer(i, y, NumberOfLinks);
				return;
			}
			else {
				grid[i][y].setGoriz();
			}
		}
	}
	void drawRight(int NumberOfLinks)
	{
		grid[x][y].setConnectRight(NumberOfLinks);
		for (int i = x + 1; i < width; i++) {
			if (grid[i][y].getCell() == true) {
				grid[i][y].setConnectLeft(NumberOfLinks);
				PrintAnswer(i, y, NumberOfLinks);
				return;
			}
			else {
				grid[i][y].setGoriz();
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
	for (int exp = 0; exp < 2; exp++) {
		bool changes;
		do
		{
			changes = false;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (grid[j][i].getCell() == true) {
						Begunok t(j, i);
						if (t.Run(exp) == true) changes = true;
					}
				}
			}
		} while (changes == true);
	}
	// работы по отрисовке ненадежных связей
}