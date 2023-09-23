#include <iostream>
#include "Float.h"

int main() {
    FloatCell Cell;
    float n;
    std::cout << "intrduzca un numero" << std::endl;
    std::cin >> n;

    Cell.setValue(n);

    std::cout << "el valor es: " << Cell.getValue() << std::endl;

    std::cout << "Tu clase si funciona :D";

}
