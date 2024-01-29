#include <iostream>
#include "mylib.h"
#include <math.h>
using namespace std;

int main()
{
    char bc[20][20];
    int N = 20;
    khoiTaoBanCo(bc,N);
    char luotDi = 'X';

    do
    {
        int x=1, y=1;
        inBanCo(bc,N,x,y);
        char currentKey;
        
        do
        {
            cout << "Moi ben "<< luotDi << " di:\n";
            cout << "\tNhap toa do muon di: ";
            // cin >> x >> y;
            // if (bc[x-1][y-1] == '-') break;

            cin >> currentKey;
            // cout << "current x, y is: " << x << " " << y << "\n";
            switch (currentKey)
            {
            case 'a':
                y = max(1, --y);
                break;
            case 's':
                x = min(20, ++x);
                break;
            case 'd':
                y = min(20, ++y);
                break;
            case 'w':
                x = max(1, --x);
                break;
            case 'c':
                if (bc[x-1][y-1] == '-') break;
                break;
            default :
                break;
            }

            if (bc[x-1][y-1] == '-' && currentKey=='c') break;

            system("cls");
            inBanCo(bc,N, x, y);
        } while (true);

        bc[x-1][y-1] = luotDi;
        if (logic(bc, luotDi, x, y) == true)
        {
            system("cls");
            inBanCo(bc,N,x+1,y);
            cout << luotDi << " win\n";
            break;
        }
        if (luotDi == 'X')
            luotDi = 'O';
        else
            luotDi = 'X';
        system("cls");

    } while (true);
    return 0;
}
