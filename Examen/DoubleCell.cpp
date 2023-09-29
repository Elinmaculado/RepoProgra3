#include "DoubleCell.h"
#include <stdexcept>

// Default constructor
// Constructor cuando no recibe ningun dato
DoubleCell::DoubleCell()
        :Storedvalue(0){}

// Constructor with value
// Constructor que recibe un valor
DoubleCell::DoubleCell(double value)
        : Storedvalue(value){}

// Copy constructor
// Constructor que realiza una copia del valor que le damos
DoubleCell::DoubleCell(const DoubleCell& other)
        : Storedvalue(other.Storedvalue){}

//Reference  constructor
//Constructor capaz de leer el valor dentro de una referencia que le pasemos
DoubleCell::DoubleCell(DoubleCell&&  other)
        : Storedvalue(other.Storedvalue){}

// Assignment operator by copy
// Asignacion que realiza una copia de lo que le demos
DoubleCell& DoubleCell::operator=(const DoubleCell& other){
    if (this != &other){
        Storedvalue = other.Storedvalue;
    }
    return *this;
}

// Assignment operator by reference
// Asignacion que se realiza cuando recibe una referencia
DoubleCell &DoubleCell::operator=(DoubleCell &&other) noexcept{
    if(this != &other){
        Storedvalue = other.Storedvalue;
        other.Storedvalue = 0;
    }
    return *this;
}

// Assignment operator for double
// se le dice al operador de asignacion que puede recibir valores tipo double
DoubleCell& DoubleCell::operator=(double value){
    Storedvalue = value;
    return *this;
}

// Arithmetic operators
//Se da una indicacion de como funciona cada operador aritmético
//Tanto para que trabaje con valores DoubleCell y double.
//DoubleCell adding
DoubleCell DoubleCell::operator +(const DoubleCell& other) const{
    return DoubleCell(Storedvalue + other.Storedvalue);
}

//primitive double adding
DoubleCell DoubleCell::operator  +(double value) const{
    return DoubleCell(Storedvalue + value);
}

//DoubleCell substracting
DoubleCell DoubleCell::operator-(const DoubleCell &other) const {
    return DoubleCell(Storedvalue - other.Storedvalue);
}

//primitive double substracting
DoubleCell DoubleCell::operator -(double value) const{
    return DoubleCell(Storedvalue - value);
}

//DoubleCell multiplication
DoubleCell DoubleCell::operator *(const DoubleCell& other) const{
    return DoubleCell(Storedvalue * other.Storedvalue);
}
//primitive double multiplication
DoubleCell DoubleCell::operator *(double value) const{
    return DoubleCell(Storedvalue * value);
}

//DoubleCell division
DoubleCell DoubleCell::operator /(const DoubleCell& other) const{
    if(other.Storedvalue == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / other.Storedvalue);
}

//Primitive double division
DoubleCell DoubleCell::operator /(double value) const{
    if(value == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(Storedvalue / value);
}

// Setters
// Para que la variable reciba un valor
void DoubleCell::SetValue(double value){
    Storedvalue = value;
}

// Getters
// Para acceder al valor de la variable
double DoubleCell::GetValue() const {
    return Storedvalue;
}