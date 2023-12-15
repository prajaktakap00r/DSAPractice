#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int fact;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    cout << fact;
}