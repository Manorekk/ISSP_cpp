#include <iostream>

// Struktura reprezentująca pojedynczy element listy
struct Link
{
    int value;              // Wartość elementu
    Link* next = nullptr;   // Wskaźnik na następny element, inicjalizowany na nullptr
};

// Funkcja zwracająca liczbę elementów na liście
size_t size(const Link* head) {
    size_t count = 0;               // Inicjalizujemy licznik na 0
    const Link* current = head;     // Ustawiamy wskaźnik na początek listy
    while (current != nullptr) {
        count++;                    // Zwiększamy licznik za każdym razem, gdy mamy kolejny element
        current = current->next;    // Przechodzimy do następnego elementu listy
    }
    return count;                   // Zwracamy liczbę elementów
}

// Funkcja zwracająca sumę wartości wszystkich elementów na liście
size_t sum(const Link* head) {
    size_t total = 0;               // Inicjalizujemy sumę na 0
    const Link* current = head;     // Ustawiamy wskaźnik na początek listy
    while (current != nullptr) {
        total += current->value;    // Dodajemy wartość bieżącego elementu do sumy
        current = current->next;    // Przechodzimy do następnego elementu listy
    }
    return total;                   // Zwracamy sumę wartości
}

// Funkcja testująca
void test() {
    // Tworzymy listę o pięciu elementach
    Link* head = new Link{1};                   // Pierwszy element z wartością 1
    head->next = new Link{2};                   // Drugi element z wartością 2
    head->next->next = new Link{3};             // Trzeci element z wartością 3
    head->next->next->next = new Link{4};       // Czwarty element z wartością 4
    head->next->next->next->next = new Link{5}; // Piąty element z wartością 5

    // Wyświetlamy liczbę elementów i sumę wartości na liście
    std::cout << "Dlugosc listy: " << size(head) << std::endl;
    std::cout << "Suma wartosci elementow listy: " << sum(head) << std::endl;

    // Zwolnienie zaalokowanej pamięci dla każdego elementu listy
    while (head != nullptr) {
        Link* temp = head;  // Zapamiętujemy wskaźnik na bieżący element
        head = head->next;  // Przesuwamy wskaźnik na następny element
        delete temp;        // Usuwamy bieżący element
    }
}

int main() {
    test();
    return 0;
}
