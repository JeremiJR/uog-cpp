#include "numbers/complex_numbers.hpp" // Path relative to this file
#include <iostream>

int main() {
    // (h) Re-implementing the logic from the original task
    ComplexNumber* z_array = new ComplexNumber[5];

    for (int i = 0; i < 5; ++i) {
        z_array[i] = ComplexNumber(static_cast<double>(i + 1), static_cast<double>(i + 2));
    }

    ComplexNumber s(0, 0);
    for (int i = 0; i < 5; ++i) {
        s = s + z_array[i];
    }

    std::cout << "Sum of array: " << s << std::endl;

    // Lambda calculation: 1 + z + z^2 + z^3 + z^4 + z^5
    ComplexNumber z(1, 2);
    ComplexNumber lambda(0, 0);
    for (int i = 0; i <= 5; ++i) {
        lambda = lambda + z.pow(i);
    }

    std::cout << "Lambda (1+z+...+z^5): " << lambda << std::endl;

    delete[] z_array;
    return 0;
}