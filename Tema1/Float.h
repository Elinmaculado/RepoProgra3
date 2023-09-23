#ifndef TEMA1_FLOAT_H
#define TEMA1_FLOAT_H

class FloatCell {
public:
    //Constructor implícito
    explicit FloatCell(float newvalue = 0);

    //constructor explicito por copia
    FloatCell(const FloatCell &rhs);

    //constructor explicito por referencia
    FloatCell(FloatCell &&rhs) noexcept;

    //Destructor, se activa cuando se usa free
    ~FloatCell() = default;

    //Asignación por copia, para r-valores
    FloatCell &operator = (const FloatCell &rhs);
    FloatCell &operator = (FloatCell &&rhs) noexcept;

    //Se le dice con que tipo de datos va a trabajar en este caso "float"
    //Porque sin esto solo puede trabajar con datos de su propia clase
    FloatCell &operator=(float rhs);

    //Función para ver que valor está asignado
    float getValue() const;

    //funcion para asignar valor
    //Es void porque solo recibe un valor pero no necesitar regresar nada
    void setValue(float newValue);

private:
    //Variable que utilizamos para que se puedan asignar los valores
    float storedValue;
};


#endif //TEMA1_FLOAT_H
