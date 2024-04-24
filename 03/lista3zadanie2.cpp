#include <iostream>

struct Link
{
    int data;
    Link* next;

    Link(int val) : data(val), next(nullptr) {}
};

void release(Link** phead)
{
    if (*phead == nullptr)
        return;

    Link* tmp = *phead;
    *phead = (*phead)->next;
    delete tmp;
    release(phead);
}

int main()
{
    // Tworzenie listy przykładowych elementów
    Link* head = new Link(1);
    head->next = new Link(2);
    head->next->next = new Link(3);
    head->next->next->next = new Link(4);
    head->next->next->next->next = new Link(5);

    // Zwolnienie pamięci listy przy użyciu funkcji release
    release(&head);

    // Sprawdzenie, czy lista została poprawnie zwolniona
    if (head == nullptr)
        std::cout << "Lista została zwolniona poprawnie.\n";
    else
        std::cout << "Błąd! Lista nie została zwolniona poprawnie.\n";

    return 0;
}
