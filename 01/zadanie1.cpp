#include <iostream>
#include <cmath>

int N = 1'000'000;

int main()
{
    double A = 0;
    double B = 1;
    double C = 0;
    for (int i = 1; i <= N; i++)
    {
        A += (pow(-1, i + 1)) / (2.0 * i - 1.0);
        B *= (4.0 * i * i) / ((4.0 * i * i) - 1.0);
        C += 1 / pow((2.0 * i - 1.0), 2);
    }
    double wynikA = 4 * A;
    double wynikB = 2 * B;
    double wynikC = sqrt(8.0 * C);

    std::cout << "a) pi: " << M_PI << "\t"
              << "wyliczone: " << wynikA << "\t"
              << "roznica: " << M_PI - wynikA << std::endl;
    std::cout << "b) pi: " << M_PI << "\t"
              << "wyliczone: " << wynikB << "\t"
              << "roznica: " << M_PI - wynikB << std::endl;
    std::cout << "c) pi: " << M_PI << "\t"
              << "wyliczone: " << wynikC << "\t"
              << "roznica: " << M_PI - wynikC << std::endl;

    return 0;
}
