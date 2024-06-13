#include <iostream>
#include "timer.h"

unsigned int silnia(int n)
{
    if (n == 0)
        return 1;
    return n * silnia(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    Timer timer; // Tworze obiekt timer do pomiaru czasu
    timer.start(); // Rozpoczynam pomiar czasu

    for (int i = 30; i >= 0; i--)
        std::cout << i << "! = " << silnia(i) << "\n";

    for (unsigned int i = 0; i <= 35; i++)
        std::cout << "fibonacci(" << i << ") = " << fibonacci(i) << std::endl;

    std::cout << "Koniec programu\n";

    std::cout << "Czas wykonania programu: " << timer.get_elapsed_seconds() << " sekundy" << std::endl; // Wyświetlam czas wykonania programu
}
