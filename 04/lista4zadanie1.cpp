#include <iostream>
#include <vector>

// Przedefiniowanie operatora * dla std::vector<double>
double operator*(const std::vector<double>& v, const std::vector<double>& w) {
    // Sprawdzenie, czy wektory mają tę samą liczbę elementów
    if (v.size() != w.size()) {
        std::cerr << "Błąd: Wektory muszą mieć tę samą liczbę elementów." << std::endl;
        return 0.0; // Zwracamy zero, gdy wektory mają różne rozmiary
    }

    // Obliczenie iloczynu skalarnego
    double dotProduct = 0.0;
    for (size_t i = 0; i < v.size(); ++i) {
        dotProduct += v[i] * w[i];
    }

    return dotProduct;
}

int main() {
    std::vector<double> v1 = {2.0, 2.0, 2.0};
    std::vector<double> v2 = {3.0, 5.0, 2.0};

    // Obliczenie iloczynu skalarnego v1 i v2
    double result = v1 * v2;

    std::cout << "Iloczyn skalarny v1 i v2: " << result << std::endl;

    return 0;
}
