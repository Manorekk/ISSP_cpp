#include <iostream>
#include <cmath>

double root(double (*f)(double), double a, double b, double tolerance = 1e-10) {
    double fa = f(a);
    double fb = f(b);

    if (fa * fb > 0) {
        std::cerr << "Error: The function has the same sign at both endpoints of the interval\n";
        return NAN; // Not-a-Number, to oznacza błąd
    }

    while (b - a > tolerance) {
        double mid = (a + b) / 2.0;
        double fmid = f(mid);

        if (fmid == 0.0) // Dokładne dopasowanie
            return mid;
        else if (fa * fmid < 0)
            b = mid;
        else
            a = mid;
    }

    return (a + b) / 2.0;
}

double equation1(double x) {
    return cos(x) - x;
}

double equation2(double x) {
    return cos(x) - 0.5;
}

int main() {
    double tolerance = 1e-6;

    // Pierwsze równanie: cos(x) = x w przedziale [0, 2]
    double result1 = root(equation1, 0, 2, tolerance);
    std::cout << "Pierwiastek pierwszego rownania: " << result1 << std::endl;

    // Drugie równanie: cos(x) = 1/2 w przedziale [0, 1.5]
    double result2 = root(equation2, 0, 1.5, tolerance);
    std::cout << "Pierwiastek drugiego rownania: " << result2 << std::endl;

    return 0;
}

