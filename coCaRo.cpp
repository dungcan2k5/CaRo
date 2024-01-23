#include <iostream>
#include "mylib.h"
using namespace std;

int main()
{
    char bc[20][20];
    int N = 20;
    khoiTaoBanCo(bc,N);
    char luotDi = 'X';

    do
    {
        inBanCo(bc,N);
        int x, y;
        
        do
        {
            cout << "Moi ben "<< luotDi << " di:\n";
            cout << "\tNhap toa do muon di: ";
            cin >> x >> y;
            if (bc[x-1][y-1] == '-') break;
            cout << "Di nham roi, di lai di\n";
        } while (true);

        bc[x-1][y-1] = luotDi;
        if (logic(bc, luotDi, x, y) == true)
        {
            system("cls");
            inBanCo(bc,N);
            cout << luotDi << " win\n";
            break;
        }
        if (luotDi == 'X')
            luotDi = 'O';
        else
            luotDi = 'X';
        // system("cls");

    } while (true);
    return 0;
}
