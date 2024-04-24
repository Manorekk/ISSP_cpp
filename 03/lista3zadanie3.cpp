#include <iostream>

// Struktura reprezentująca pojedynczy element listy
struct Link
{
    int value;              // Wartość elementu
    Link* next = nullptr;   // Wskaźnik na następny element, inicjalizowany na nullptr

    Link(int val) : value(val), next(nullptr) {}
};

// Funkcja odwracająca kolejność elementów na liście
void reverse(Link** phead)
{
    // Inicjalizacja zmiennych
    Link* prev = nullptr;  // Poprzedni element, na początku nullptr
    Link* current = *phead; // Bieżący element to głowa listy

    // Iteracja przez listę
    while (current != nullptr) {
        Link* next = current->next; // Zapamiętujemy następny element

        // Odwracamy kierunek wskaźnika bieżącego elementu
        current->next = prev;

        // Przesuwamy wskaźniki
        prev = current;
        current = next;
    }

    // Po zakończeniu pętli poprzedni element staje się nową głową listy
    *phead = prev;
}

// Funkcja wyświetlająca elementy listy
void displayList(Link* head)
{
    Link* current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Funkcja testująca
void test()
{
    // Tworzymy listę
    Link* head = new Link(1);
    head->next = new Link(2);
    head->next->next = new Link(5);
    head->next->next->next = new Link(9);

    std::cout << "Lista: ";
    displayList(head);

    // Odwracamy listę
    reverse(&head);

    std::cout << "Lista odwrocona: ";
    displayList(head);
}

int main()
{
    test();
    return 0;
}

