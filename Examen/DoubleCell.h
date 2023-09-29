#ifndef DOUBLE_CELL_H
#define DOUBLE_CELL_H

class DoubleCell {
public:

    // Default constructor
    // Constructor default se inicializa
    DoubleCell();

    //Constructor que es capaz de recibir un valor
    explicit DoubleCell(double value);

    // Copy constructor
    // Constructor que realiza una copia del valor que le damos
    DoubleCell(const DoubleCell& other);

    //Reference constructor
    //Constructor capaz de leer el valor dentro de una referencia que le pasemos
    DoubleCell(DoubleCell &&other);

    // Destructor
    // destruye la variable que ya no se use
    ~DoubleCell() = default;

    // Assignment operator by copy
    // Asignacion que realiza una copia de lo que le demos
    DoubleCell& operator=(const DoubleCell &other);

    // Assignment operator by reference
    // Asignacion que se realiza cuando recibe una referencia
    DoubleCell &operator=(DoubleCell&& other) noexcept ;

    // Assignment operator for double
    // se le dice al operador de asignacion que puede recibir valores tipo double
    DoubleCell& operator=(double value);

    // Arithmetic operators
    //Se da una indicacion de como funciona cada operador aritmético
    //Tanto para que trabaje con valores DoubleCell y double.
    DoubleCell operator +(const DoubleCell& other) const;
    DoubleCell operator +(const double other) const;
    DoubleCell operator -(const DoubleCell& other) const;
    DoubleCell operator -(const double other) const;
    DoubleCell operator *(const DoubleCell& other) const;
    DoubleCell operator *(const double other) const;
    DoubleCell operator /(const DoubleCell& other) const;
    DoubleCell operator /(const double other) const;

    // Setters
    // Para que la variable reciba un valor
    void SetValue(double newValue);

    // Getters
    // Para acceder al valor de la variable
    double GetValue() const;


private:
    double Storedvalue;
};

#endif  // DOUBLE_CELL_H