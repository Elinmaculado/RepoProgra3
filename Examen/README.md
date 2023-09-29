# Parte 1

i. **¿Qué es un Rvalor y un Lvalor?**
Un Rvalor es el que se encuentra del lado derecho de una igualación, y el Lvalor es el que se encuentra del lado izquierdo.

ii. **¿Porqué es necesario que una clase tenga constructores y operadores por
copia y por referencia?**
Porque tienen usos diferentes, el de copia nos ayuda copiar un objeto y crear uno nuevo igual, y no tener que  crear desde 0 otro objeto con exactamente la misma información
En cambio los de referencia utilizan la información original así que nos ayudan a prevenir gastos de memoria innecesarios.

iii. **¿Qué función desarrollan los :: en la implementación de la clase?**
Me ayudan a acceder a un elemento dentro de la clase

iv. **¿Cómo se le denomina a cuando una clase posee un operador puede
tener múltiples implementaciones dependiendo de los argumentos que
este reciba?**

v. **¿Cuál es la función del archivo .h ?**
Se utiliza para realizar todas las declaraciones de lo que va a haber dentro de una clase


# Parte 2

```
#include <iostream>
int algoritmo1(int n) {
int resultado = 0;
for (int i = 0; i < n; i++) {
	resultado += i; // Operación simple O(1)
}

for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	resultado += i * j; // Operación simple O(1)
}

}
return resultado;
}
int main() {
int n;
std::cout << "Ingrese el valor de n: ";
std::cin >> n;
Parte 2

Complejidad Temporal

int resultado = algoritmo1(n);
std::cout << "Resultado: " << resultado << std::endl;
return 0;
}
```

La complejidad del código es cuadrática.  $O(n^2)$

El código cuenta con tres ciclos for, todos dentro de la función algoritmo1. El primero es una operación simple, pero el problema está en el segundo for, ya que tiene un segundo for anidado dentro, lo que sería lo mismo que $O(n * n) = O(n^2)$ .



# Documentación

## DoubleCell.h
En el archivo header vamos a declarar todo lo que va a utilizar nuestra clase
### Constructores y destructor
```
DoubleCell();  

explicit DoubleCell(double value);  

DoubleCell(const DoubleCell& other);  
  
DoubleCell(DoubleCell &&other);  

~DoubleCell() = default;
```
La primera fila inicializa el constructor default.
Después de este se inicializan un constructor que es capaz de recibir un valor double, después el constructor por copia y el constructor por referencia, estos recibirían valores tipo DoubleCell. Y finalmente tenemos declarado el destructor, este se iguala a default para que se borren los valores una vez que ya no se utilicen, a diferencia de los constructores, cómo delcaramos el destructor con el default aquí, ya no es necesario desarrollarlo en el .cpp.

### Operadores de asignación
```
DoubleCell& operator=(const DoubleCell &other);  

DoubleCell &operator=(DoubleCell&& other) noexcept ;  

DoubleCell& operator=(double value);
```
Aquí le diremos las distintas formas de utilizar el operador de asignación (=).
La primera linea es para asignar por copia y la segunda para asignar por referencia.
La tercera es para que nuestra clase pueda trrabajar con valores tipo double además de los DoubleCell.

### Operadores aritméticos
```
DoubleCell operator +(const DoubleCell& other) const;  
DoubleCell operator +(const double other) const;  
DoubleCell operator -(const DoubleCell& other) const;  
DoubleCell operator -(const double other) const;  
DoubleCell operator *(const DoubleCell& other) const;  
DoubleCell operator *(const double other) const;  
DoubleCell operator /(const DoubleCell& other) const;  
DoubleCell operator /(const double other) const;
```
Aquí se le dice los operadores con los que va a trabajar y también se le dice que puede utilizar cada uno tanto con valores DoubleCell y con valores double. En cada operador, la primera declaración es para valores DoubleCell y la segunda declaración corresponde a los valores double.

### Getter y setter

```
void SetValue(double newValue);  
  
double GetValue() const;
```
Finalmente se declaran las funciones SetValue y GetValue, estas las utilizaremos  para asignar y revisar valores respectivamente.

### Variable
```
private:  
    double Storedvalue;
```
Esta variable es privada para que no se pueda acceder a ella fuera de la clase, y es de tipo double ya que son el tipo de valores que queremos que se guarden dentro de nuestras variables. Esta variable nos ayudará para todo lo que involucre modificar o asignar un valor a nuestras variables tipo DoubleCell.

## DoubleCell.cpp

### Constructores
```
DoubleCell::DoubleCell()  
        :Storedvalue(0){}  
  
DoubleCell::DoubleCell(double value)  
        : Storedvalue(value){}  
  
DoubleCell::DoubleCell(const DoubleCell& other)  
        : Storedvalue(other.Storedvalue){}  
    
DoubleCell::DoubleCell(DoubleCell&&  other)  
        : Storedvalue(other.Storedvalue){}  
  
}
```
El primer constructor es por default, por lo tanto su valor asignado es igual a 0. después de ese está el que recibe un valor tipo double.

La tercera línea recibe un valor DoubleCell y realiza una copia del valor. El siguiente es por referencia y también recibe un valor DoubleCell

### Operador de asignación
```
DoubleCell& DoubleCell::operator=(const DoubleCell& other){  
    if (this != &other){  
        Storedvalue = other.Storedvalue;  
    }  
    return *this;  
}  
  
DoubleCell &DoubleCell::operator=(DoubleCell &&other) noexcept{  
    if(this != &other){  
        Storedvalue = other.Storedvalue;  
        other.Storedvalue = 0;  
    }  
    return *this;  
}  
  
DoubleCell& DoubleCell::operator=(double value){  
    Storedvalue = value;  
    return *this;  
}
```

Aquí le decimos las distintas maneras de utilizar el operador de asignación (=). 
Primero le decimos cómo realizar una copia de otra variable tipo DoubleCell.
Después le decimos cómo asignar por referencia, es importante igualar el StoredValue de la referencia a 0, si no sería lo mismo que hacerlo por copia.
Finalmente es el caso para que podamos usar la asignación entre valores DoubleCell y doube.

### Operadores aritméticos
```
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
```
A continuación se le dice a la clase cómo trabajar cada operador, tanto con valores de su mismo tipo cómo con valores double. Es importante tomar en cuenta que en las divisiones se tiene que prevenir el caso de la división entre 0.

### Getter y setter
```
void DoubleCell::SetValue(double value){  
    Storedvalue = value;  
}  
  
// Getters  
// Para acceder al valor de la variable  
double DoubleCell::GetValue() const {  
    return Storedvalue;  
}
```
El setter y el getter llaman a la variable para realizar su respectiva función, el setter para darle un valor a una variable, y el getter para acceder a ese valor