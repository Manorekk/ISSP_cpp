#include <iostream>
#include <cstdlib>

int sortowanie(const void* a, const void* b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x % 2 == 0 && y % 2 == 0)
    {
        return x - y;
    }
    else if (x % 2 != 0 && y % 2 != 0)
    {
        return y - x;
    }
    else if (x % 2 == 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int tab[] = {1, 4, 7, 2, 5, 9, 2, 8};
    std::cout << "Tablica:" << std::endl;
    for (int element : tab) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    unsigned rozmiar = sizeof(tab)/sizeof(tab[0]);
    qsort(tab, rozmiar, sizeof(int), sortowanie);
    std::cout << std::endl << "Posortowana Tablica:" << std::endl;
    for(int i = 0; i < rozmiar; i++)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}