#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int L, N;
void TurnOnTheLight(int x, int y, bool** A)
{
    for (int i = x - L+1; i < x + L; i++) {
        for (int j = y - L+1; j < y + L; j++) {
            if (i >= 0 and i < N and j >= 0 and j < N)
                A[i][j]=true;
        }
    }
}
int main()
{
    std::cin >> N; std::cin.ignore();
    std::cin >> L; std::cin.ignore();
    bool** A = new bool * [N];
    A[0] = new bool[N * N];
    for (int i = 0; i < N; i++) {
        A[i] = A[0] + i * N;
        for (int j = 0; j < N; j++)
            A[i][j] = false;
    }
    for (int i = 0; i < N; i++) {
        std::string LINE;
        std::getline(std::cin, LINE);
        for (int j = 0; j < N; j++) {
            if (LINE[j*2] == 'C') TurnOnTheLight(i, j, A);
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j]==false) count++;
        }
    }
    std::cout << count << std::endl;
    delete[]A[0];
    delete[]A;
}