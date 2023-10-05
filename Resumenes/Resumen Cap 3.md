# Listas pilas y colas
A continuación se va a hablar de los las maneras más básicas de estructurar datos, prácticamente cualquier programa utilizará al menos uno de estos métodos, y las pilas están integradas de manera implícita en cualquier programa.
También veremos la implementación de dos librerías: Vector y List.

## Tipos de datos abstractos
Los datos abstractos son abstracciones matemáticas, por ejemplo las listas y las gráficas podrían verse cómo datos abstractos, de la misma manera en la que valores cómo los enteros o los booleanos, también son datos.
Así cómo los datos enteros y booleanos tienen operaciones, también los datos abstractos tienen operaciones, por ejemplo para el tipo de dato abstracto *set* tenemos las operaciones: *add, remove, size* y *contains*.

Las clases en C++ nos permiten implementar datos abstractos, también nos permite realizar operaciones con estos datos incluso fuera de la clase, si implementamos un método para esto.

Distintas operaciones pueden funcionar con distintos datos abstractos, no hay una regla sobre cual usar con cual, suele ser decisión del diseñador.
## La lista
Una lista es una secuencia de elementos que se encuentran ordenandos de manera encadenada, a comparación de los vectores estas son más rápidas a la hora de insertar o borrar datos
Para acceder a la librería que nos permite crear una liste tenemos que escribir: 
\#inlcude \<list>
Algunos métodos que podemos utilizar en una lista son los siguientes
- printlist
- makeEmpty
- find
- insert
- remove
- findkth

Un pequeño código cómo ejemplo de una lista muy simple es el siguiente:
```
#include <iostream>
#include <list>
using namespace std;

int main()
{
    list <int> lista;
    int numero;
    
    cout << "introduzca 5 numeros: ";
    
    for (int i = 0; i < 5; i++)
    {
        cin >> numero;
    lista.push_back(numero);
    }
    
    cout << "aqui está su lista" << endl;
    
    list<int>::iterator it = lista.begin();
    while( it != lista.end())
    {
      cout << *it++ << endl;
    }
}
```
Este código crea una lista y después permite al usuario ingresar cinco valores y finalmente visualizarlos.

### Listas enlazadas simples
Una lista enlazada es una lista en la que cada elemento está ligado al que tiene antes y al que tiene después de manera lineal cómo se ve en las siguientes imagenes.
Esta es una lista enlazada
![[Pasted image 20231002104456.png]]
Y esta es una lista enlazada doble
![[Pasted image 20231002105312.png]]

## Vector y lista en STL
STL significa biblioteca de plantillas estándar, por lo que vamos a ver cómo utilizar las librerías de C++ de vector y *list*, esto también no ayudará a entender mejor elementos del código anterior en [[#La lista]].

Podría decirse que el vector también es un tipo de lista, así que tanto la librería vector cómo la librería *list* sirven para hacer listas pero también tienen sus diferencias. Por ejemplo los vectores son muy útiles ya que son flexibles y su tamaño puede crecer si es necesario, pero es complicado añadir o borrar datos en medio de la lista, es más sencillo si se realiza esto al final de la lista, por otro lado cuando usamos la librería *list*, las listas son de doble enlace y es más fácil añadir o remover elementos del medio de la lista (pero es necesario conocer la posición que deseamos dentro de la lista), aunque tanto *list* cómo vector no son muy eficientes para realizar búsquedas.

A continuación habrá un listado de métodos útiles y sus descripciones, estos métodos funcionan tanto con vector cómo con *list*.

- int size( ) const: retorna el número de elementos en la lista.
- void clear( ): vacía la lista.
- bool empty( ) const: Si la lista está vacía, retorna true.
- void push_back( const Object & x ): Agrega x al final de la lista.
- void pop_back( ): Borra el elemento al final de la lista,
- const Object & back( ) const: Retorna el último elemento de la lista. 
- const Object & front( ) const: Retorna el primer elemento de la lista. 

Después tenemos un par de métodos que sólo funcionan en *list* ya que es necesario que al lista esé doblemente enlazada.
- void push_front( const Object & x ): agrega elemento al frente de la lista. 
- void pop_front( ): Borra el primer elemento de la lista.

Y finalmente tenemos algunos métodos que sólo funcionan con vectores.
- Object & operator[] ( int idx ): Retorna el índice del objeto de una lista. 
- int capacity( ) const: Retorna la capacidad del vector.
- void reserve( int newCapacity ): Da una nueva capacidad al vector, puede ser útil para evitar que el vector se expanda innecesariamente por si sólo.
### Iteradores
Un iterador es un objeto que puede recorrere una lista y acceder de manera individual a cada uno de los elementos en esta.

Para ser más claro en cómo se declara y se puede utilizar, se usará un fragmento del código en [[#La lista]].
```
 list<int>::iterator it = lista.begin();
    while( it != lista.end())
    {
      cout << *it++ << endl;
    }
```
Este iterador se utiliza para recorrer la lista completa, vemos que lo primero que se hace es declarar el iterador llamado *it* dentro de la lista llamada lista, y muy importante se iguala al método .begin de la lista. Así nos aseguramos de que el iterador es igual al primer elemento de la lista y desde ahí pueda recorrerla de principio a fin.  

Para recorrer la lista utilizamos un ciclo *while*, mientras el iterador sea diferente al método .end de la lista, osea mientras sea diferente del último elemento, el ciclo seguirá. Y por último imprimimos el iterador (utilizando el \* para acceder al valor de la posición en la que se encuentra el iterador)  y utilizamos el ++ para que el iterador vaya a la siguiente posición.
Este ciclo nos imprimirá todos los elementos dentro de la lista.

A continuación hay tres métodos que se pueden utilizar para modificar una lista y que hacen uso de un iterador.
- iterator insert( iterator pos, const Object & x ): agrega x a la lista, una posición antes del valor que le demos, el método retorna un iterador indicando la posición en la que se introdujo x.
- iterator erase( iterator pos ): Elimina el dato en la posición que le demos.
- iterator erase( iterator start, iterator end ): Elimina todos los elementos entre la primera y la última posición que le demos.
### const_iterators
Cuando utilizamos los iteradores es importante tener en cuenta que estamos accediendo directamente al valor dentro de una lista, no sólo a su posición. por lo que si le dijeramos a nuestro iterador que hiciera algún cambio, el cambio se realiziazría a la lista original directamente. Para cuidarnos de esto podemos usar un const_iterator que es un iterador constante, este no permitirá ningún cambio al valor de la posición a la que se está accediendo.

Por ejemplo
```
void function1(vector<int> &V)
{
vector<int>::iterator begin = V.begin()
for (; begin != V.end(); ++begin)
	{
	*begin += 10;
	cout << *begin << " ";
	}
	cout << endl;
}

void function2(vector<int> &V)
{
vector<int>::const_iterator begin = V.begin()
for (; begin != V.end(); ++begin)
	{
	cout << *begin << " ";
	}
	cout << endl;
}
```
Aquí tenemos dos códigos que reciben un vector tipo entero, la primera función lo que hace es sumarle 10 a cada elemento del vector gracias a la linea que dice \*begin +=10, por lo que por ejemplo si recibimos un vector con los numeros del 1 al 5, terminarían siendo los numeros del 11 al 15.

Por otra parte la segunda función con el iterador constant no pued modificar el vector, de hecho si le pusieramos misma linea \*begin +=10 nos daría un error y no compilaría.

Si mandaramos a llamar a ambas funciones con vectores iguales, el resultado sería
11 12 13 14 15
1 2 3 4 5
## Implementación de vector
Aunque los vectores puedan parecerse a los arreglos de C++. Hay que tener en claro algunas diferencias y porque optamos por usar mejor vectores. La principal diferencia es que los arreglos son estáticos, osea que no pueden cambiar su tamaño cómo un vector.

a continuación veremos partes del código de la clase vector e ir diciendo que hace cada parte.

```
Vector( const Vector & rhs ) : theSize{ rhs.theSize }, 
theCapacity{ rhs.theCapacity }, objects{ nullptr } 
{ 
objects = new Object[ theCapacity ]; 
for( int k = 0; k < theSize; ++k ) 
objects[ k ] = rhs.objects[ k ]; 
}
```
Este es el constructor por copia, este se puede realizar fácilmente por el operador =. El cual también tiene que ser inicializado dentro de la clase, se ve a continuación:

```
Vector( Vector && rhs ) : theSize{ rhs.theSize }, 
theCapacity{ rhs.theCapacity }, objects{ rhs.objects } 
{ 
rhs.objects = nullptr; 
rhs.theSize = 0; 
rhs.theCapacity = 0; 
} 

Vector & operator= ( Vector && rhs ) 
{ 
std::swap( theSize, rhs.theSize ); 
std::swap( theCapacity, rhs.theCapacity );
std::swap( objects, rhs.objects ); 

return *this; 
}
```


Además de esas secciones, tenemos otras que también trabajan métodos muy importantes. cómo por el ejemplo el método de resize, que es lo que le da al vector su importante característica  de cambiar de tamaño. Se ve a continuación:

```
void resize( int newSize ) 
{ 
if( newSize > theCapacity ) 
reserve( newSize * 2 ); 
theSize = newSize; 
}
```
cómo podemos ver se ajusta *theSize*, expandir la capacidad de un vector puede ser algo muy costoso, por lo que lo mejor es que no se realice mucho, por ejemplo si en algún momento cambiamos el tamaño del vector, podemos hacerlo de tal manera que nos sobren algunos espacios, así prevenir un poco y tratar de no realizar más cambios de tamaño.

A continuación tenemos el método reserve
```
void reserve( int newCapacity ) 
{ 
if( newCapacity < theSize ) 
return; 

Object *newArray = new Object[ newCapacity ]; 
for( int k = 0; k < theSize; ++k ) 
newArray[ k ] = std::move( objects[ k ] ); 

theCapacity = newCapacity; 
std::swap( objects, newArray ); 
delete [ ] newArray; 
}
```
Esta acción consiste en crear un nuevo vector con la nueva capacidad que se necesita y pasando los elementos a ese nuevo vector. Si el nuevo vector no tiene el tamaño para guardar el vector original, reserve será ignorado.

Después está cómo utilizar el operador\[]
```
Object & operator[]( int index ) 
{ return objects[ index ]; } 
const Object & operator[]( int index ) const 
{ return objects[ index ]; }
```
Recordemos que al declarar un vector utilizamos \[] para declarar el tamaño, y más adelante se utiliza para acceder a la posición del vector que deseamos acceder.

Después veremos varios métodos que se pueden utilizar dentro de un vector
```
bool empty( ) const 
{ return size( ) == 0; } 
int size( ) const 
{ return theSize; } 
int capacity( ) const 
{ return theCapacity; } 

void push_back( const Object & x ) 
{ 
if( theSize == theCapacity ) 
reserve( 2 * theCapacity + 1 ); 8
bjects[ theSize++ ] = x; 
} 

void push_back( Object && x ) 
{ 
if( theSize == theCapacity ) 
reserve( 2 * theCapacity + 1 ); 
objects[ theSize++ ] = std::move( x ); 
}

void pop_back( ) 
{ 
--theSize; 
} 

const Object & back ( ) const 
{ 
return objects[ theSize - 1 ]; 
}
```
A continuación qu ehace cada método:
- Empty: Devuelve True si el vector está vacio, sino devuelve falso
- push back: Agrega un elemento al final del vector
- pop back: Elimina el último elemento del final del vector


Finalmente veremos la declaración del iterador:
```
typedef Object * iterator; 
typedef const Object * const_iterator; 

iterator begin( ) 
{ return &objects[ 0 ]; } 
const_iterator begin( ) const 
{ return &objects[ 0 ]; }
iterator end( ) 
{ return &objects[ size( ) ]; } 
const_iterator end( ) const
{ return &objects[ size( ) ]; }
```
Lo importante es que el iterador tenga claro donde empieza y donde termina, naturalmente esto es el primer y el último elemento del vector, así podrá recorrer sin problema todo lo que hay en medio.
## Implementación de lista
Vamos a hablar de la implementación de la clase *list*, para esto tenemos que tener en cuenta algunas características de esta clase. Lo primero es que esta clase crea listas doblemente enlazada, por lo que cada elemento tiene un puntero apuntando tanto al siguiente elemento cómo al anterior (excepto el primer y el último elemento).

Al igual que con la implementación del vector, veremos códigos dentro de la declaración de *list* y veremos que hacen estos códigos

```
struct Node 
{ 
Object data; 
Node *prev; 
Node *next; 

Node( const Object & d = Object{ }, Node * p = nullptr, 
Node * n = nullptr ) 
: data{ d }, prev{ p }, next{ n}{} 
 
Node( Object && d, Node * p = nullptr, Node * n = nullptr ) 
: data{ std::move( d ) }, prev{ p }, next{ n}{} 13 };
```
Aquí vemos que se define lo que es un nodo, lo primero es fijarnos en que está declareado cómo struct y no cómo class. Un struct es cómo una clase pero en la que todos sus elementos por default son públicos.
Podemos ver que se declara el dato que va a recibir y que también se declaran los dos punteros que va a utilizar, el del dato anterior y el del siguiente dato.

A continuación vamos a ver la declaración de const iterator y de iterator.
Const iterator:
```
class const_iterator 
2 {
3 public: 
4 const_iterator( ) : current{ nullptr } 
5 { } 
6 
7 const Object & operator* ( ) const 
8 { return retrieve( ); } 
9 
10 const_iterator & operator++ ( ) 
11 { 
12 current = current->next; 
13 return *this; 
14 } 
15 
16 const_iterator operator++ ( int ) 
17 { 
18 const_iterator old = *this; 
19 ++( *this ); 
20 return old; 
21 } 
22 
23 bool operator== ( const const_iterator & rhs ) const 
24 { return current == rhs.current; } 
25 bool operator!= ( const const_iterator & rhs ) const 
26 { return !( *this == rhs ); } 
27 
28 protected: 
29 Node *current; 
30 
31 Object & retrieve( ) const 
32 { return current->data; } 
33 
34 const_iterator( Node *p ) : current{ p } 
35 { } 
36 
37 friend class List; 
38 };
```

Iterator:
```
class iterator : public const_iterator 
{ 
public: 
iterator( ) 
{ } 

Object & operator* ( ) 
{ return const_iterator::retrieve( ); } 
const Object & operator* ( ) const 
{ return const_iterator::operator*( ); } 

iterator & operator++ ( ) 
{ 
this->current = this->current->next; 
return *this; 
} 
 
iterator operator++ ( int ) 
{ 
iterator old = *this; 
++( *this ); 
return old; 
} 

protected: 
iterator( Node *p ) : const_iterator{ p } 
{ } 

friend class List; 
};
```
De entrada algo interesante que notaremos aquí es que se está utilizando la herencia. se puede ver en la declaración de la clase iterator, ```iterator : public const_iterator``` está diciendo que iterador hereda todos los datos y métodos de const_iterator. Iterator puede agregar cosas nuevas e incluso reempalzar elementos heredados de const_iterator, pero lo importante es que hasta que se haga eso, tiene exactamente lo mismo que const_iterator.

A continuación veremos los constructores y destructores.
```
List( ) 
{ init( ); } 

~List( ) 
{ 
clear( ); 
delete head; 
delete tail; 
} 

List( const List & rhs ) 
{ 
init( ); 
for( auto & x : rhs ) 
push_back( x ); 
} 

List & operator= ( const List & rhs ) 
{ 
List copy = rhs; 
std::swap( *this, copy ); 
return *this; 23 }
 

List( List && rhs ) 
: theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail } 
{ 
rhs.theSize = 0; 
rhs.head = nullptr; 
rhs.tail = nullptr; 
} 

List & operator= ( List && rhs ) 
{ 
std::swap( theSize, rhs.theSize ); 
std::swap( head, rhs.head ); 
std::swap( tail, rhs.tail ); 

return *this; 
} 

void init( ) 
{ 
theSize = 0; 
head = new Node; 
tail = new Node; 
head->next = tail; 
tail->prev = head; 
}
```
En esta ocasión utilizamos la rutina init, este nos ayuda para el constructor de una lista vacía y para el constructor por copia, ya que init lo que hace es crear una lista vacía.

La siguiente imagen será una representación gráfica  que nos perimitirá ver cómo funciona la inserción de un nuevo nodo en medio de una lista de doble enlace.
![[Pasted image 20231005111020.png]]
Podemos ver cómo los punteros de los tres nodos, se acoplan y apuntan al nuevo nodo correspondiente, la lógica de esto se ve en el siguiente código:
```
// Insert x before itr. 
iterator insert( iterator itr, const Object & x ) 
{ 
Node *p = itr.current; 
theSize++; 
return { p->prev = p->prev->next = new Node{ x, p->prev, p } };
} 
 
// Insert x before itr. 
iterator insert( iterator itr, Object && x ) 
{ 
Node *p = itr.current; 
theSize++; 
return { p->prev = p->prev->next 
= new Node{ std::move( x ), p->prev, p } }; 
}
```


De igual manera, ahora veremos una imagen que muestra la lógica de quitar un nodo de la lista y su respectivo código:
![[Pasted image 20231005111752.png]]
```
// Erase item at itr. 
iterator erase( iterator itr ) 
{ 
Node *p = itr.current; 
iterator retVal{ p->next }; 
p->prev->next = p->next; 
p->next->prev = p->prev; 
delete p; 
theSize--; 

return retVal; 
} 

iterator erase( iterator from, iterator to ) 
{ 
for( iterator itr = from; itr != to; ) 
itr = erase( itr ); 

return to; 
}
```
Vemos que básicamente lo que se hace es ignorar el nodo, ya que si verdaderamente se borrara, se tendría un mayor costo de tiempo y en la memoria ya que habría que reordenar toda la lista. También algo importante que hay que fijarse tanto cuando quitamos o agregamos un nodo es que el tamaño del vector se actualiza.
## Opinión crítica
Creo que sería muy buena idea repasar para tener en claro cuales son los métodos que estaremos usando más con las listas y vectores, así cómo también dejar muy bien en claro cuando usar cual o al menos en que fijarnos a la hora de elegir. 
También me gustaría dar un repaso a los códigos de vector y lista, para dejar en claro cualquier posible duda.
También hay que tener claro lo que es un nodo, un nodo es el espacio donde se va a almacenar el dato de una lista y es donde se encuentran los punteros para la anterior y siguiente posición.

## Conclusiones
Con esto ya comenzamos adentrarnos en la estructura de datos, ya que al empezar con las listas, estamos viendo una forma de acomodar y trabajar con un conjunto de datos. Es importante ir conociendo las distintas maneras en las que seremos capaces de acomodar nuestros datos e igual de importante es saber cómo podemos trabajar con ellos dependiendo de cómo elijamos acomodarlos, y que herramientas adicionales (cómo iteradores por ejemplo) nos ayudarán a trabajar y cumplir nuestros objetivos.
## Referencias
|   |   |
|---|---|
|[1]|M. A. Weiss, _Data Structures and Algorithm Analysis in C++_, 4a ed. Upper Saddle River, NJ, Estados Unidos de América: Pearson, 2013.|
|[2]|_Wikibooks.org_. [En línea]. Disponible en: https://es.wikibooks.org/wiki/Programación_en_C%2B%2B/Librería_Estándar_de_Plantillas/Listas#:~:text=Las%20listas%20(Lists)%20de%20C%2B%2B,menor%20velocidad%20de%20acceso%20aleatorio. [Consultado: 02-oct-2023].|
|[3]|“List in C++ standard template library (STL)”, _GeeksforGeeks_, 07-dic-2015. [En línea]. Disponible en: https://www.geeksforgeeks.org/list-cpp-stl/. [Consultado: 02-oct-2023].|
|[4]|TylerMSFT, “Iterators”, _Microsoft.com_. [En línea]. Disponible en: https://learn.microsoft.com/es-es/cpp/standard-library/iterators?view=msvc-170. [Consultado: 02-oct-2023].|
|[5]|ByteBites, “const iterator vs regular iterator C++ STL”, 08-sep-2021. [En línea]. Disponible en: https://www.youtube.com/watch?v=SFn1JV5uUrQ. [Consultado: 02-oct-2023].|




