#include "Float.h"
//Los :: es par que la función o método sólo se pueda usar en esa parte

//Constructor implicito
FloatCell::FloatCell(float newValue) : storedValue(newValue){}

//Copy constructor
FloatCell::FloatCell(const FloatCell &rhs) : storedValue(rhs.storedValue){}

//Move constructor
FloatCell::FloatCell(FloatCell &&rhs) noexcept : storedValue(rhs.storedValue) {
    rhs.storedValue = 0;
}

//Esta diciendo cómo hacer la asignación de un rvalor cuando se iguala a otra variable
FloatCell &FloatCell::operator=(const FloatCell &rhs) {
    if(this != &rhs)
        storedValue = rhs.storedValue;

    return * this;
}

FloatCell &FloatCell::operator+(const FloatCell &rhs) {
    storedValue = storedValue + rhs.storedValue;
    return *this;
}

//Esta diciendo cómo hacer la asignación de un rvalor cuando se iguala a un valor constante
FloatCell &FloatCell::operator=(FloatCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }

    return *this;
}

FloatCell &FloatCell::operator=(float rhs)
{
    storedValue = rhs;
    return *this;
}

//Método para asignar un valor
void FloatCell::setValue(float newValue)
{
    storedValue = newValue;
}

//Método para recuperar el valor
float FloatCell::getValue() const
{
    return storedValue;
}