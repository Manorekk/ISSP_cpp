#include <iostream>
#include <cmath>

using namespace std;

long double metodaA(int n)
{
    long double ti;
    if (n == 0)
    {
        ti = 1.0L/ sqrt(3.0L);
    }
    else
    {
        auto tmp = metodaA(n-1);
        ti = (sqrt(tmp * tmp  + 1.0L) - 1.0L) / tmp;
    }
    return ti;
}

long double metodaB(int n)
{
    long double ti;
    if (n == 0)
    {
        ti = 1.0L/ sqrt(3.0L);
    }
    else
    {
        auto tmp = metodaB(n-1);
        ti = tmp / (sqrt(tmp * tmp + 1.0) + 1.0);
    }
    return ti;
}

int main()
{
    long double A;
    long double B;
    cout.precision(10);
    for(int i = 0; i <= 40; i++)
    {
        long double tia = metodaA(i);
        long double tib = metodaB(i);
        A = 6 * pow(2, i) * tia;
        B = 6 * pow(2, i) * tib;
        cout << "i: " << i << "\t" << "metoda A: " << A << endl;
        cout << "i: " << i << "\t" << "metoda B: " << B << endl <<endl;
    }

    return 0;
}