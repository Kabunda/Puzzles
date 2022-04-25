#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 struct position     //Создаем структуру позиций робота
{                  
    int row;        //строка
    int col;        //колонка
    string dim;     //направление
    bool invert;    //инвертирование
    bool breaker;   // брейкер
};   

int main()
{
    int L;
    int C;

    vector<string> board;
    vector<position> history;
    cin >> L >> C; cin.ignore();
    for (int i = 0; i < L; i++) {
        string row;
        getline(cin, row);
        board.push_back(row);
    }
    for (int i=0;i<L;i++){
    cout << board[i] << endl;
    }
}



