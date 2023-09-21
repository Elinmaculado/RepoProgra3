# Capítulo 1
## El libro
En este libro se verán métodos para analizar datos y estructurarlos, para analizar datos el escribir un código no es suficiente, se tiene que buscar la manera más óptima de llegar al resultado deseado, si no se busca la optimización, los procesos se volverán muy lentos mientras más datos busquemos estructurar.
## Matemáticas
Para iniciar hay que ciertas operaciones y conceptos matemáticos con los que tenemos que estar familiarizados, conocer sus teoremas y en general entender cómo funcionan.
### Exponentes
Los exponentes constan de dos partes, una base y la potencia, la base es un número que se va a multiplicar por si mismo y la potencia es cuantas veces se va a multiplicar.
Ejemplo: 4<sup>3</sup> = 4 x 4x 4 =64
### Logaritmos
El logaritmo es el proceso de encontrar a que potencia se elevó un número para llegar al resultado.
Ejemplo log<sub>10</sub> 100 = 2 y podemos comprobarlo: 10<sup>2</sup> = 10 x 10 = 100.
### Series
Una serie es una  expresión de la suma del número infinito de términos de una sucesión.
Por ejemplo: 
a<sub>n</sub> = 1/2<sup>n</sup> = 1 + 1/2 + 1/4 + 1/8 + 1/16 + 1/32....

En esta serie se van realizando sumas parciales, a cada número se le suma su mitad y así sucesivamente hasta el infinito, la suma al final da 2
### Aritmética modular
La aritmética modular es aquella que trabaja con los residuos de una división.
Por ejemplo: 13/5 = 
## Recursividad
Cuando se habla de recursividad se habla de una función que se llama a si misma y tiene un caso base y un caso general.

Un ejemplo muy fácil donde se puede ver la recursividad es a la hora de sacar el factorial de un número,.
Ejemplo:

```
#include <iostream>

int factorial (int n);

int main()
{
    std::cout << factorial(5);
    return 0;
}

int factorial (int n)
{
    if (n == 0)     //caso base
        n = 1;
        
    else            //caso general
    n = n * factorial(n-1);
    
    return n;
}
```

Si prestamos atención a la función factorial, el caso en el que n es igual a 0, es el caso base, y el otro es el caso general. El caso general es el que llevará a cabo la operación cómo tal (en este caso es multiplicar al numero por su predecesor) y el caso base funciona para detener la recursividad y que se devuelva correctamente el valor, ya que si no lo tomáramos en cuenta, al final todo se multiplicaría por 0.
## Clases en C++
Una clase podría definirse cómo un tipo de variable que nosotros creamos, las clases contienen atributos que nosotros podemos determinar cómo públicos o privados , cuando son públicos, cualquier método fuera de la clase puede acceder a ellos, cuando son privados sólo los métodods dentro de la misma clase pueden acceder a ellos. Estos atributos pueden consistir en datos o funciones, a estas funciones dentro de una clase se les conoce cómo métodos.

### Constructores
Los constructores son un tipo de método que se utiliza para inicializar las variables que se encuentran dentro de una clase, si no utilizamos un constructor para inicializar los valores, las variables recibirá el último valor que se almacenó en la dirección de memoria en la que están. Los constructores pueden recibir parámetros (constructor explicito) o tener un valor que nosotros demos por default.( constructor implicito) 
Ejemplo:
```
#include <iostream>
using namespace std;

class Position
{
    public:
        float X, Y;
        
        Position()      //constructor sin parametro o implicito
        {
            X = 1;
            Y = 1;
        }
        
        Position(float a, float b)   //constructor con parametros o explicito
        {
            X = a;
            Y = b;
        }
};

int main()
{
    Position p1;
    Position p2(3,7);
    //imprimimos los valores del constructor sin parametros
    cout << p1.X << "," << p1.Y << endl;
    //imprimimos los valores del constructor que recibe parametros
    cout << p2.X << "," << p2.Y << endl;
    return 0;
}
```
La variable p1 accede a los valores del constructor sin parámetros, en cambio la variable p2 accede al constructor con parámetros.
### Destructores
Un destructor es una función que elimina los datos almacenados gracias al constructor, usualmente se declara después del constructor y se manda a llamar cuando es necesario, si tomamos cómo ejemplo el código anterior sería declarado así
```
class Position
{
    public:
        float X, Y;
        Position()      //constructor sin parametro o implicito
        {
            X = 1;
            Y = 1;
        }
        Position(float a, float b)   //constructor con parametros o explicito
        {
            X = a;
            Y = b;
        }
        ~Position();
};
```
### Vectores y Strings
#### Vectores
Los vectores se encuentran en C++ cómo una alternativa para sustituir a los arreglos que pueden llegar a tener varios inconvenientes.
Un vector se puede declarar de la siguiente manera
```
vector<int> NumerosPrimos(10) = {1,2,3,5,7,11,13,17,19,23}
```
Tenemos un vector que contiene números primos, el numero entre ( ) indica la extensión del vector(dato al que se puede acceder con el método .size) y dentro de las { } se encuentran lso elementos del vector. 
Y para acceder a un elemento del vector se utilizan [ ] y se escribe el número de posición del dato que se desea, recordando que los vectores inician en la posición 0, por lo que en este caso al tener 10 elementos, los números de posición van del 0 al 9.

#### Strings
La ventaja de la clase strings comparado con los strings que vienen por defecto en C++ es que primero, se pueden realizar comparaciones lógicas, cómo por ejemplo string1 == string2. También tiene el método .length para obtener el dato de la extensión del string.
## Punteros
Un puntero es un tipo de variable que apunta a la dirección de memoria de otra variable. Se declara de la siguiente manera:
```
int num = 10;
int *puntero = &num;
```
al delclarar un puntero necesita dos cosas, primero necesitamos poner un * antes del nombre de la variable para que se aun puntero, y lo segundo es que al igualarlo a una variable, tenemos que poner el & antes de la variable, para hacer referencia a la dirección de memoria de esta.

A la hora de utilizar el puntero, tenemos dos opciones, utilizar la dirección de memoria o el dato que esta almacena.
Véase el siguiente ejemplo
```
int num = 10;
int *puntero = &num;

std:: cout << *puntero;
std:: cout << puntero;
```
Cuando escribimos el nombre del puntero con un * antes, imprimiremos el valor que está en la dirección de memoria, que en este caso sería 10. En cambio si sólo escribimos el nombre de la variable sin el * imprimiremos la dirección de memoria.
Una vez se deja de referenciar un objeto, es importante utilizar la palabra reservada *delet* para eliminar el objeto, de no hacerlo esto producirá perdida de memoria.

Es importante tener en cuenta que si dos punteros apuntan a un mismo objeto, estos punteros son iguales, pero si apuntan a objetos diferentes no serán iguales, incluso si ambos objetos tienen le mismo valor.

Otro detalle importante a tomar en cuenta es cuando un puntero está trabajando con una clase. Cuando queremos acceder al elemento de una clase usualmente lo hacemos con un punto, pero en el caos de los punteros se tiene que realizar con una ->
Ejemplo:
```
IntCell *m; 
m = new IntCell{ 0 }; 
6 m->write( 5 );             //puntero accediento a write 
```
## Rvalues, Lvalues y referencias
lvalue y rvalue significan left-value y right-value respectivamente, o bien valores de izquierda y valores de derecha; los valores de izquierda son aquellos que no son temporales, y los valores de derecha son aquellos que si son temporales. Visto de manera más simple, si nos fijamos en una igualación por ejemplo, los valores a la izquierda del igual son Lvalues y los valores a la derecha del igual son Rvalues.
```
vector arr( 3 ); 
const int x = 2; 
int y; 
... 
int z = x + y; 
string str = "foo";
vector *ptr = &arr;
```
En este caso, podemos ver los Lvalues y sus Rvalues correspondientes

| Lvalues | Rvalues |
|-|-|
|arr()| |
|x | 2 |
| y | | 
| z | x + y |
| str | "foo" |
| \*ptr | &arr|
## Parámetros
Hay tres maneras de pasar un parámetro a un campo que lo requiere.
### Por copia
Un parámetro por copia entra directamente en le espacio que se está pidiendo el parametro
```
void swap( double a, double b );
```
En esta función se está creando una copia de la variable *a* y una copia de la variable *b*, y con esas copias se ejecuta la función.
### Por referencia
Cuando se pasa un parámetro por referencia si pone un & para saber que se está hablando de la dirección de memoria de la variable y se trabaje directamente con el dato original, no con una copia.
```
void swap( double &a, double &b );
```
Cómo se está trabajando con los datos originales, cualquier cambio que sufran *a* y *b* dentro de la función también se verá reflejado fuera de esta.
### Por referencia constante
Este tipo de referencia se utiliza cuando queremos pasar el valor de una clase y además no queremos que este sea alterado.
```
string randomItem( const vector & arr );
```
### Referencia a valor de derecha
Los valores a la derecha son valores temporales que eventualmente van a ser destruidos, este tipo de referencia lo que hace es que mueve un valor en lugar de copiarlo.
```
string randomItem( const vector & arr ); // returns random item in lvalue arr 
string randomItem( vector && arr ); // returns random item in rvalue arr 

vector v { "hello", "world" }; cout << randomItem( v ) << endl; // invokes lvalue method cout << randomItem( { "hello", "world" } ) << endl; // invokes rvalue method
```
### Las 4 formas
Así que para recapitular
- **Por copia:** Cuando trabajamos con valores pequeños y no queremos que se alteren
- **Por referencia:** Cuando trabajamos con cualquier valor que queremos que sea cambiado por la función
- **Por referencia constante:** Cuando trabajamos con valores muy grandes cómo para copiar pero no queremos que el valor cambie por la función
- **Referencia a valor a la derecha:** 
## Return
La palabra return es una palabra reservada que se utiliza para que una función regrese el tipo de valor que le corresponde. 
## Swap y Move
swap y move cumplen funciones similares, se utilizan para evitar realizar copias de Rvalues y así no gastar memoria innecesariamente.
### Swap
La función swap intercambia los valores de dos variables con la ayuda de una tercera que funciona cómo auxiliar.
Ejemplo:
```
int swap (int a, int b)
{
//variable temporal 
int aux;

//aqui se hace el swap
aux = a;
a = b;
b = aux;
}
```
### Move
Move se utiliza cuando quieres mover un objeto a otro objeto existente.
Ejemplo:
```
class Entity
{
public:
	Entity(const string&& name)
		:m_Name(std::move(name))    
		
	void PrintName()
	{
	m_Name.Print();
	}
	
private:
	strinf m_Name;
}

int main ()
{
	Entity entity("Cherno");
	entity.PrintName();
}
```
se utiliza std::move para que el valor que demos se mueva a m_Name que está en privado.
## Los 5 grandes
### Destructor
[[#Destructores]]
### Constructor por copia
Un constructor por copia  es saca su información directamente de otro constructor.
```
TextFile a, b; 
a.Open( "FILE1.DAT" ); 
b.Open( "FILE2.DAT" ); 
b = a;
```

### Constructor por movimiento
Similar a la copia, mueve la información de un constructor ya existente a uno nuevo
### Copia con operador=
El operador = se utiliza con dos objetos que ya fueron construidos previamente, el Lvalue adquiere el mismo Rvalue que la variable a la que se está igualando.

### Movimiento con operador=
Similar a la copia pero ahora el Rvalue de la variable original, deja a esa variable y se vuelve el Rvalue de la nueva variable.

## Plantillas
Una plantilla de es una pieza de código cuya lógica no cambia aunque se utilice en código diferente, así que se puede implementar en diferentes códigos.
### Plantillas de funciones
```
template <typename Comparable>
const Comparable & findMax (const vector <Comparable> &a)
{
int maxIndex = 0;

for (int i = 1; i <a.size(); i++)
	{
	if (a[maxIndex] < a[i])
		maxIndex = i;
	}
	return a[maxIndex]
}
```
 Por ejemplo esta función devuelve el número más grande en un arreglo, y no importa donde queramos usarlo, mientras que le entregues un arreglo que contenga números (enteros o )


### Plantillas de clases
En resumen es lo mismo que las funciones pero con clases, sirve para poder pasar tus clases a otros proyectos.
### Objetos de función
Un objeto de función, o functor, es cualquier tipo que implementa operator(). Este operador se conoce como el operador de llamada_ o a veces el operador de la aplicación. La biblioteca estándar de C++ usa objetos de función principalmente como criterios de ordenación para los contenedores y en algoritmos.
Ejemplo:
```
class Functor 
{ 
	public: 
	int operator()(int a, int b) 
	{ return a < b; } }; int main() { Functor f; int a = 5; int b = 7; int ans = f(a, b); }
```

## Matrices
Una matriz es en esencia y arreglo de dos dimensiones o un vector de vectores, de esta manera se nos pueden representar los datos mediante filas y columnas.
A continuación una clase para generar matrices:
```
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

template <typename Object>
class matrix
{
public:
    matrix(int rows, int cols) : array(rows)
    {
        for (auto &thisRow : array)
            thisRow.resize(cols);
    }

    matrix(vector<vector<Object>> v) : array{v}
    { }

    matrix(vector<vector<Object>> &&v) : array{std::move(v)}
    { }

    const vector<Object> &operator[](int row) const
    {
        return array[row];
    }

    vector<Object> &operator[](int row)
    {
        return array[row];
    }

    int numrows() const
    {
        return array.size();
    }

    int numcols() const
    {
        return numrows() ? array[0].size() : 0;
    }

private:
    vector<vector<Object>> array;
};

#endif

```

## Opinión crítica
Los temas abarcados por el libro me parecieron muy interesantes y sobre todo, es fácil ver la importancia que van a tener para la materia, sobre todo una vez que se empiecen a aplicar temas en conjunto, desafortunadamente en unos momentos sentí que no estaban explicados de la mejor manera, siento que el libro habla muy bien sobre el tema de la estructura de datos, pero al momento de hablar sobre cosas cómo tal de C++ a veces no está explicado de la mejor manera o incluso en el mejor orden.
Por ejemplo, cuando habla de las clases vector y string, te menciona que c++ tiene integrados los arreglos y los strings (cómo tipo de dato), y procede a explicarlos cómo clases, pero hasta unos cuantos puntos después empieza a hablar de los arreglos y strings integrados cuando ya habló de las clases, y siento que debería de ser al revés porque los que vienen integrados son una versión más simple y con menos funciones que sus contrapartes en arreglos.
También por ejemplo dentro de los "Big five" hay otros tipos de constructores, y siento que sería mejor que esos se hubieran explicado cómo tal dentro del apartado de constructores para ver de una manera más ligada la información sobre esos temas.

Dicho eso me pareció mucho más efectivo cuando complemente tanto información del libro cómo información de otras fuentes, en momentos el libro por si sólo era difícil de entender pero con ayuda externa se volvió mucho más claro, además sus ejemplo de código creo que son buenos aunque algunos tuve que analizarlos más de una vez para realmente ver que estaban haciendo. 
Se que será pesado, muy pesado, pero también se que es necesario y valdrá la pena dominar todo esto.

No puedo decir que me sentí igual de bien en todos los temas, algunos me costó entenderles incluso con ayudas de fuentes externas, si está la posibilidad me gustaría en clase tener una aclaración de los siguientes temas:
- Constructores (por copia, por movimiento)
- std::move
- Parámetros: referencia por valor a la derecha
- Objetos de función
- defaults
## Conclusión
Todos los temas son parte de lo que será el manejo de datos, algunos nos ayudaran a modificarlos, a organizarlos, a moverlos, a visualizarlos, etc.
Entender uno sólo de los temas no es suficiente y tampoco será suficiente entenderlo por si mismo (aunque naturalmente este es el primer paso), lo realmente importante será ver cómo todos estos elementos se combinan y complementan para poder hacer códigos lo más eficientes posibles.
## Fuentes
|   |   |
|---|---|
|M. A. Weiss, _Data Structures and Algorithm Analysis in C++_, 4a ed. Upper Saddle River, NJ, Estados Unidos de América: Pearson, 2013.|
|“Laboratorio de Programación 2”, _Uma.es_. [En línea]. Disponible en: http://www.lcc.uma.es/~lopez/lp2/. [Consultado: 20-sep-2023].|
|Wikipedia contributors, “Logaritmo”, _Wikipedia, The Free Encyclopedia_. [En línea]. Disponible en: https://es.wikipedia.org/w/index.php?title=Logaritmo&oldid=152307901.|
|A. Mate, “Definición de series”, 29-nov-2018. [En línea]. Disponible en: https://www.youtube.com/watch?v=7pWuaK5zP4E. [Consultado: 20-sep-2023].|
|“¿Qué es la aritmética modular?”, _Khan Academy_. [En línea]. Disponible en: https://es.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/what-is-modular-arithmetic. [Consultado: 20-sep-2023].|
|The Cherno, “std::move and the Move Assignment Operator in C++”, 19-jun-2020. [En línea]. Disponible en: https://www.youtube.com/watch?v=OWNeCTd7yQE. [Consultado: 20-sep-2023].|
|TylerMSFT, “Constructores de copia y operadores de asignación de copia (C++)”, _Microsoft.com_. [En línea]. Disponible en: https://learn.microsoft.com/es-es/cpp/cpp/copy-constructors-and-copy-assignment-operators-cpp?view=msvc-170. [Consultado: 20-sep-2023].|
|TylerMSFT, “Objetos de función en la biblioteca estándar de C++”, _Microsoft.com_. [En línea]. Disponible en: https://learn.microsoft.com/es-es/cpp/standard-library/function-objects-in-the-stl?view=msvc-170. [Consultado: 21-sep-2023].|

