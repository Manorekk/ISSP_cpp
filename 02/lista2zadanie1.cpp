#include <iostream>

using namespace std;

int suma(const int tab[], unsigned size)
{
    int wynik = 0;
    for (unsigned i = 0; i < size; i++)
    {
        wynik += tab[i];
    }
    return wynik;
}

void suma2(const int tab[], unsigned size, int* result)
{
    *result = 0;
    for (unsigned i = 0; i < size; i++)
    {
        *result += tab[i];
    }
}

void pisz(const int* tab, size_t size, ostream * out)
{
    for (size_t i = 0; i < size; i++)
    {
        *out << tab[i] << " ";
    }
    *out << endl;
}

void iota(int tab[], size_t size)
{
    for (unsigned i = 0; i < size; i++)
    {
        tab[i] = i;
    }
}

void revers(int* tab, size_t size)
{
    for (size_t i = 0; i < size / 2; ++i)
    {
        swap(tab[i], tab[size - i - 1]);
    }
}

int dot_product(const int* tab1 , const int* tab2, size_t size)
{
    int wynik = 0;
    for (size_t i = 0; i < size; i++)
    {
        wynik += tab1[i] * tab2[i];
    }
    return wynik;
}

int main()
{
    int tab[] = {1, 2, 3, 4, 5};
    unsigned size = sizeof(tab)/sizeof(tab[0]);

    cout << "a) suma:\t" << suma(tab, size) << endl;


    int wynik;
    suma2(tab, size, &wynik);
    cout << "b) suma:\t" << wynik << endl;


    cout << "c) tablica:\t";
    pisz(tab, size, &cout);


    int tabd[5];
    unsigned sized = sizeof(tabd)/sizeof(tabd[0]);
    cout << "d) tablica:\t";
    iota(tabd, sized);
    pisz(tabd, sized, &cout);


    int tabe[] = {1, 2, 3, 4, 5};
    unsigned sizee = sizeof(tabe)/sizeof(tabe[0]);
    cout << "e) tablica:\t";
    revers(tabe, sizee);
    pisz(tabe, sizee, &cout);


    int tab1[] = {1, 2, 3, 4, 5};
    int tab2[] = {5, 4, 3, 2, 1};
    unsigned sizef = sizeof(tab1)/sizeof(tab1[0]);
    cout << "f) iloczyn:\t" << dot_product(tab1, tab2, sizef) << endl;

    return 0;
}