#include <iostream>
#include "mylib.h"
#include <math.h>
#include <conio.h>
using namespace std;

int main()
{
    system("cls");
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
            cout << "\nMoi ben "<< luotDi << " di:\n";
            cout << "\tDung phim WASD de di chuyen\n\tBam phim Space de xac nhan chon: ";

            currentKey = getch();

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
            case ' ':
                if (bc[x-1][y-1] == '-') break;
                break;
            default :
                break;
            }

            if (bc[x-1][y-1] == '-' && currentKey==' ') break;

            system("cls");
            inBanCo(bc,N, x, y);
        } while (true);

        bc[x-1][y-1] = luotDi;
        if (logic(bc, luotDi, x, y) == true)
        {
            system("cls");
            inBanCo(bc,N,x+1,y);
            cout <<"\n\tCHUC MUNG "<< luotDi << " DA CHIEN THANG!!\n";
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
