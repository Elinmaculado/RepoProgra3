#ifndef TEMA1_FLOAT_H
#define TEMA1_FLOAT_H

class FloatCell {
public:
    //Constructor implícito
    explicit FloatCell(float newvalue = 0);

    //constructor explicito por copia
    FloatCell(const FloatCell &rhs);

    //construcor explicot por referencia
    FloatCell(FloatCell &&rhs) noexcept;

    //Destructor, se activa cuando se usa free
    ~FloatCell() = default;

    //Asignacion por copia, para rvalores
    FloatCell &operator = (const FloatCell &rhs);
    FloatCell &operator = (FloatCell &&rhs) noexcept;

    //Se le dice con que tipo de datos va a trabajar en este caso "float"
    //Porque solo puede trabjar con datos de su propia clase
    FloatCell &operator=(float rhs);

    //Funcion para ver que valor está asignado
    float getValue() const;

    //funcion para asignar valor
    void setValue(float newValue);

private:
    //Variable que utilizamos para
    float storedValue;
};


#endif //TEMA1_FLOAT_H
