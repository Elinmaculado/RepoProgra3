#include <iostream>
#include "Float.h"

int main() {
    FloatCell variable;
    float n;
    std::cout << "intrduzca un numero" << std::endl;
    std::cin >> n;

    variable.setValue(n);

    std::cout << "el valor es: " << variable.getValue();

}
