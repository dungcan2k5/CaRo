#include <iostream>
using namespace std;

void khoiTaoBanCo (char a[20][20], int N)
{
    for (int d = 1; d <= N; d++)
    for (int c = 1; c <= N; c++)
        a[d-1][c-1] = '-'; 
}

void inBanCo(char a[20][20], int N)
{
    cout << "   ";
    for (int c = 1; c <= N; c++)
    {
        if (c<10)
            cout << c << "  ";
        else 
            cout << c << " ";
    }
    cout << endl;

    for (int d = 1; d <= N; d++)
    {
        if (d < 10)
            cout << d << "  ";
        else
            cout << d << " ";
        for (int c = 1; c <= N; c++)
            cout << a[d-1][c-1] << "  ";
        cout << endl;
    }
}

bool logic(char a[20][20], char luotDi, int x, int y)
{
    int count;

    // Ngang
    count = 0;
    for (int i = x-4; i <= x+4; i++)
    {
        if (i<=0) continue;
        else if (a[i-1][y-1] == luotDi) count++;
        else if (a[i-1][y-1] != luotDi) count=0;
        else break;
    }

    if (count==5)
    {
        return true;
    }
    
    
    return false;
}