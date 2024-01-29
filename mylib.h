#include <iostream>
using namespace std;

void khoiTaoBanCo (char a[20][20], int N)
{
    for (int d = 1; d <= N; d++)
    for (int c = 1; c <= N; c++)
        a[d-1][c-1] = '-'; 
}

void inBanCo(char a[20][20], int N, int currentX, int currentY)
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
        {
            if (d==currentX && c==currentY) cout << (char) 219 << "  ";
            else cout << a[d-1][c-1] << "  ";
        }
        cout << endl;
    }
}

bool logic(char a[20][20], char luotDi, int x, int y)
{
    int count;

    // Ngang
    count = 0;
    for (int i = y-4; i <= y+4; i++)
    {
        if (i<=0) continue;
        else if (a[x-1][i-1] == luotDi) 
        {
            count++;
            if (count==5) return true;
        }
        else if (a[x-1][i-1] != luotDi) count=0;
        else break;
    }
    
    // Dọc
    count = 0;
    for (int i = x-4; i <= x+4; i++)
    {
        if (i<=0) continue;
        else if (a[i-1][y-1] == luotDi) 
        {
            count++;
            if (count==5) return true;
        }
        else if (a[i-1][y-1] != luotDi) count=0;
        else break;
    }

    int col;

    // Chéo phải
    count = 0;
    col = y-4;
    for (int i = x-4; i <= x+4; i++)
    {
        if (i<=0) continue;
        else if (a[i-1][col-1] == luotDi) 
        {
            count++;
            col++;
            if (count==5) return true;
        }
        else if (a[i-1][col-1] != luotDi) 
        {
            count=0;
            col++;
        }
        else break;
    }
        cout << endl;

    // Chéo trái
    count = 0;
    col = y-4;
    for (int i = x+4; i <= x-4; i--)
    {
        if (i>=21) continue;
        else if (a[i-1][col-1] == luotDi) 
        {
            count++;
            col++;
            if (count==5) return true;
        }
        else if (a[i-1][col-1] != luotDi) 
        {
            count=0;
            col++;
        }
        else break;
    }
    return false;
}