#include <iostream>

double down(int n)
{
    double suma = 0;
    for(int i = 1; i <= n; i++ )
    {
        suma += 1.0/i;
    }
    return suma;
}

double up(int n)
{
    double suma = 0;
    for(int i = n; i > 0; i-- )
    {
        suma += 1.0/i;
    }
    return suma;
}

float down_float(int n)
{
    float suma = 0;
    for(int i = 1; i <= n; i++ )
    {
        suma += 1.0f/i;
    }
    return suma;
}

float up_float(int n)
{
    float suma = 0;
    for(int i = n; i > 0; i-- )
    {
        suma += 1.0f/i;
    }
    return suma;
}

int main()
{
    std::cout << "Double" << std::endl;
    std::cout << "N: 100\t \t Roznica (up - down):\t" << up(100) - down(100) << std::endl;
    std::cout << "N: 100'000\t Roznica (up - down):\t" << up(100'000) - down(100'000) << std::endl;
    std::cout << "N: 100'000'000\t Roznica (up - down):\t" << up(100'000'000) - down(100'000'000) << std::endl;
    std::cout << "\nFloat" << std::endl;
    std::cout << "N: 100\t \t Roznica (up - down):\t" << up_float(100) - down_float(100) << std::endl;
    std::cout << "N: 100'000\t Roznica (up - down):\t" << up_float(100'000) - down_float(100'000) << std::endl;
    std::cout << "N: 100'000'000\t Roznica (up - down):\t" << up_float(100'000'000) - down_float(100'000'000) << std::endl;

    return 0;
}
