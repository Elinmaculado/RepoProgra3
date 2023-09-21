#include "Float.h"

//Constructor implicito
FloatCell::FloatCell(float newValue) : storedValue(newValue){}

//Copy constructor
FloatCell::FloatCell(const FloatCell &rhs) : storedValue(rhs.storedValue){}

//Move constructor
FloatCell::FloatCell(FloatCell &&rhs) noexcept : storedValue(rhs.storedValue) {
    rhs.storedValue = 0;
}


FloatCell &FloatCell::operator=(const FloatCell &rhs) {
    if(this != &rhs)
        storedValue = rhs.storedValue;

    return * this;
}

FloatCell &FloatCell::operator=(FloatCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }

    return *this;
}

void FloatCell::setValue(float newValue)
{
    storedValue = newValue;
}
float FloatCell::getValue() const
{
    return storedValue;
}