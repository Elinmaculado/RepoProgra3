# Documentación de la clase FloatCell

## FloatCell.h

### Constructores y destructor
```
 explicit FloatCell(float newvalue = 0);
    //constructor explicito por copia
    FloatCell(const FloatCell &rhs);
    //constructor explicito por referencia
    FloatCell(FloatCell &&rhs) noexcept;
    //Destructor, se activa cuando se usa free
    ~FloatCell() = default;
```
Constructores de la clase, el primer constructor es el constructor por default para cuando no se proporciona un valor, después está el constructor por copia y por referencia, estos se utilizan cuando se nos proporciona un valor a la hora de inicializar una variable.
Y finalmente está el destructor, este se activa cuando ya no se utiliza la variable y se borra.

### Operadores
```
FloatCell &operator = (const FloatCell &rhs);
FloatCell &operator = (FloatCell &&rhs) noexcept;
FloatCell &operator=(float rhs);

FloatCell &operator + (const FloatCell &rhs);
```
Las primeras dos lineas le dicen a la clase que tiene que recibir cunando se quiera utilizar el operador de =, mientras que la tercera linea le está diciendo a la clase que también puede utilizar ese operador cuando le dan un valor tipo float.
Y la cuarta linea le dice que va a recibir cuando vaya a utilizar el operador +.

### Getter/Setter

```
  float getValue() const;
  void setValue(float newValue);
```
La primera linea es la declaración del getter, para acceder al valor de una variable, y la segunda es el setter, para asignarle un valor a una variable.

### Variable
```
protected:
    //Variable que utilizamos para que se puedan asignar los valores
    float storedValue;
```
Por último está cómo protegida la variable para que no se acceda a ella fuera de la clase, esta es la que se utilizará para los métodoes getValue y setValue.
## FloatCell.cpp
Esta es la implementación de los elementos de FloatCell.h

### Constructores

```
FloatCell::FloatCell(float newValue) : storedValue(newValue){}
FloatCell::FloatCell(const FloatCell &rhs) : storedValue(rhs.storedValue){}

FloatCell::FloatCell(FloatCell &&rhs) noexcept : storedValue(rhs.storedValue) {
    rhs.storedValue = 0;
}
```
Todos los constructores harán pondrán un valor dentro de stored value. La primera linea es el constructor implícito el cual ya se declaró que será 0
La segunda línea es el constructor por copia, en donde se toma un rvalor y se le agrega el mismo valor a la variable inicializada.
Y en la tercera línea tenemos el constructor por movimiento, en este caso nuestra variable toma el rvalor y regresa el valor 0.

### Operadores
```
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

FloatCell &FloatCell::operator=(float rhs)
{
    storedValue = rhs;
    return *this;
}
```
Aquí se le explicar cómo utilizar el signo = para asignar un valor, primero se le dice cómo asignar un valor de su propia clase, y la segunda le dice cómo asignar un valor de tipo float.

```
FloatCell &FloatCell::operator+(const FloatCell &rhs) {
    storedValue = storedValue + rhs.storedValue;
    return *this;
}
```
Aquí se le explica cómo utilizar el operador +. Sumando su valor a otro de tipo FloatCell.

### Getter/Setter
```
void FloatCell::setValue(float newValue)
{
    storedValue = newValue;
}

//Método para recuperar el valor
float FloatCell::getValue() const
{
    return storedValue;
}
```
Finalmente se le dice cómo utilizar el getter y el setter.  Y en el caso del getter el tipo de valor que tiene que retornar.