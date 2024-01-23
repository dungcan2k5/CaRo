#include <iostream>
using namespace std;

int main()
{
    int n; cout<<"Enter a number n: "; cin>>n;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans*=2;
        cout<<"2 ^ "<<i<<" = "<< ans << endl;
    }
    
}