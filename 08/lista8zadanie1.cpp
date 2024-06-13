#include <iostream>
#include <vector>
#include <complex>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int main() {
    std::vector<int> wektorInt = {1, 2, 3, 4, 5};
    std::vector<double> wektorDouble = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<std::complex<double>> wektorComplex = {{1.0, 1.1}, {2.0, 2.2}, {3.0, 3.3}};

    std::cout << "Wektor int: " << wektorInt << std::endl;
    std::cout << "Wektor double: " << wektorDouble << std::endl;
    std::cout << "Wektor liczb zespolonych: " << wektorComplex << std::endl;

    return 0;
}