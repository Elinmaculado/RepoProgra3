# Árboles

Un árbol es una colección de nodos que salen a partir de un nodo llamado el nodo raíz, al que denominaremos el nodo *r*, a este nodo se conectan los nodos del siguiente nivel, podría decirse que son sub nodos de *r* y nos referiremos a ellos cómo *T1, T2... Tk*. Cuando un nodo está conectado otro nodo, se dice que el nodo del que sale la conexión es el padre y el otro es el hijo.

![[Pasted image 20231028161554.png]]
En esta imagen tenemos a A cómo nodo raíz. E tiene a A cómo su padre y a I y J cómo hijos, nodos con el mismo padre justo cómo a I y J se les llama hermanos. Y a los nodos sin hijos cómo B y C se les llama hojas o *leaves*.

Hay que entender algunas características que se describen al utilizar árboles
- *Length* o distancia hace referncia a cuantos pasos hay que tomas para llegar de un nodo a otro. por ejemplo la distancia entre E y Q es de 2, ya que a partir de E vamos a J (1) y después a Q(2).
- *Depth* o profundidad es la distancia entre la raíz y un nodo. Regresando a Q su profundidad es de 3, ya que el camino desde la raíz es E(1), J(2), Q(3).
- *Height* o altura se refiere a la distancia que hay entre la hoja más lejana y un nodo que sea su ancestro. Por ejemplo la altura de E es 2, ya que al empezar de P o Q pasamos a J(1) y después a E(2).

## Implementación de árboles

Una manera de implementar un árbol es crear un enlace con cada nodo hijo. Sin embargo esto puede no ser lo mejor ya que el número de hijos de cada nodo puede variar. Una solución para este problema puede ser la siguiente
```
struct TreeNode
{ 
Object element; 
TreeNode *firstChild; 
TreeNode *nextSibling; 
};
```
De esta manera cada  nodo apunta al hermano siguiente y a su primer hijo, con esta implementación, la imagen anterior se vería de esta manera.
![[Pasted image 20231028164028.png]]
Los nodos conectados por una flecha horizontal son hermanos, mientras que los que están conectados por una flecha vertical son el primer hijo.
## Desplazamiento en el árbol

Un ejemplo muy común para un árbol es un directorio, cómo lo podemos ver en varios sistemas operativos. A continuación un ejemplo

![[Pasted image 20231028165313.png]]
Este es un directorio de unix, una forma fácil de verlo es cómo si los elementos con \* son carpetas y los que no lo tienen son archivos. Aquí se accede a la carpeta o archivo que deseemos conociendo la ruta, por ejemplo */usr/mark/book/ch1.r* 

# Árboles binarios

Un árbol binario es un árbol en el que cada nodo puede tener un máximo de 2 hijos. 
## Implementación

En los árboles binarios la declaración de los nodos es un poco similar a la lista doblemente enlazada en el aspecto de que ambos tienen dos punteros, pero en este caso en lugar de apuntar adelante y atrás, apunta hacía la derecha y la izquierda.
## Ejemplo: árbol de expresiones

Un árbol de expresiones es un tipo de árbol que representa funciones matemáticas, sus hojas son los números o variables en los que se realizará la operación, y los otros nodos contienen los operadores.

![[Pasted image 20231029105328.png]]
Para poder evaluar estas operaciones, nos fijamos en los subárboles y los evaluamos de izquierda a derecha, por lo que la operación sería $(a + b * c) + ((d * e+f) * g)$ 

### Construcción de un árbol de expresiones



# Árbol de búsqueda ADT - árboles de busqueda binaria

Para que un ábol binario pueda ser un árbol de busqueda binaria, se necesita que para cada nodo X, todos los elementos de la izquierda sean menores que el elemento X. Por ejemplo:
![[Pasted image 20231029132210.png]]
En este caso tenemos dos árboles muy parecidos, pero sólo el de la izquierda es un árbol de búsqueda binaria. ya que todos los elementos a su izquierda son menores que el 6. En el árbol de la derecha no se cumple la condición ya que el 7 es mayor que el 6.

```
template 
class BinarySearchTree 
{ 
public: 
BinarySearchTree( ); 
BinarySearchTree( const BinarySearchTree & rhs ); 
BinarySearchTree( BinarySearchTree && rhs ); 
~BinarySearchTree( ); 

const Comparable & findMin( ) const; 
const Comparable & findMax( ) const; 
bool contains( const Comparable & x ) const; 
bool isEmpty( ) const; 
void printTree( ostream & out = cout ) const; 

void makeEmpty( ); 
void insert( const Comparable & x ); 
void insert( Comparable && x ); 
void remove( const Comparable & x ); 

BinarySearchTree & operator=( const BinarySearchTree & rhs ); 
BinarySearchTree & operator=( BinarySearchTree && rhs ); 

private: 
struct BinaryNode 
{ 
Comparable element; 
BinaryNode *left; 
BinaryNode *right; 
 
BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt ) 
: element{ theElement }, left{ lt }, right{ rt } { } 

BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt ) 
: element{ std::move( theElement ) }, left{ lt }, right{ rt } { } 
}; 

BinaryNode *root; 

void insert( const Comparable & x, BinaryNode * & t ); 
void insert( Comparable && x, BinaryNode * & t ); 
void remove( const Comparable & x, BinaryNode * & t ); 
BinaryNode * findMin( BinaryNode *t ) const; 
BinaryNode * findMax( BinaryNode *t ) const; 
bool contains( const Comparable & x, BinaryNode *t ) const; 
void makeEmpty( BinaryNode * & t ); 
void printTree( BinaryNode *t, ostream & out ) const; 
BinaryNode * clone( BinaryNode *t ) const; 
};
```
Esta es la clase del árbol de busqueda binario

```
/** 
* Returns true if x is found in the tree. 
*/ 
bool contains( const Comparable & x ) const 
{ 
return contains( x, root ); 
} 

/** 
* Insert x into the tree; duplicates are ignored. 
*/ 
void insert( const Comparable & x ) 
{ 
insert( x, root ); 
} 

/** 
* Remove x from the tree. Nothing is done if x is not found. 
*/ 
void remove( const Comparable & x ) 
{ 
remove( x, root ); 
}
```
Y esto que tenemos aquí es para ver cómo un miembro público manda llamar a un miembro privado para utilizar recursividad.

A continuación vamos a explicar algunos métodos de la clas.
## Contains
El método contains es un booleano que retorna *true* si el elemento que le digamos se encuentra en el árbol, de lo contrario retorna *false*.

```
/** 
* Internal method to test if an item is in a subtree. 
* x is item to search for. 
* t is the node that roots the subtree. 
*/ 
bool contains( const Comparable & x, BinaryNode *t ) const 
{ 
if( t == nullptr ) 
return false; 
else if( x < t->element ) 
return contains( x, t->left ); 
else if( t->element < x ) 
return contains( x, t->right ); 
else 
return true; // Match 
}
```

## FindMin y FindMax

Este método retorna un puntero cada una, *findMin* retorna un puntero con el valor más bajo en el árbol y *findMax* el valor más alto.

```
/** 
* Internal method to find the smallest item in a subtree t. 
* Return node containing the smallest item. 
*/ 
BinaryNode * findMin( BinaryNode *t ) const 
{ 
if( t == nullptr ) 
return nullptr; 
if( t->left == nullptr ) 
return t; 
return findMin( t->left ); 
}

/** 
* Internal method to find the largest item in a subtree t.
3 * Return node containing the largest item. 
4 */ 
5 BinaryNode * findMax( BinaryNode *t ) const 
{ 
if( t != nullptr ) 
while( t->right != nullptr ) 
t = t->right; 
return t; 
}
```

## Insert

En concepto la función insert es simple, le damos un elemento X, si el elemento X ya se encuentra en el árbol no hace nada, en cambio si no se encuentra, coloca X en el último espacio del camino o *path* recorrido.
Si se quiere tener duplicados, podemos añadir un parámetro extra al nodo, que indique cuantos elementos de ese objeto tenemos.

```
/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void insert( const Comparable & x, BinaryNode *&t)
{
    if( t == nullptr )
        t = new BinaryNode{ x, nullptr, nullptr };
    else if( x < t->element )
        insert( x, t->left );
    else if( t->element < x )
        insert( x, t->right );
    else
        ; // Duplicate; do nothing
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert by moving.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void insert( Comparable && x, BinaryNode *&t)
{
    if( t == nullptr )
        t = new BinaryNode{ std::move( x ), nullptr, nullptr };
    else if( x < t->element )
        insert( std::move( x ), t->left );
    else if( t->element < x )
        insert( std::move( x ), t->right );
    else
        ; // Duplicate; do nothing
}

```

## Remove

*Remove* sirve para remover un nodo del árbol, pero lo intersante es lo que le sucede a la estructura cuando hacemos esto. ya que si eliminamos un nodo que no sea una hoja, la estructura del árbol se ve alterada.

Obvio el caso más simple es eliminar una hoja, después de esto tenemos el caso en el que se elimine un nodo con un sólo hijo. Donde tampoco hay tanto problema ya que ese hijo toma el lugar del padre y ya.
![[Pasted image 20231030105942.png]]
En este ejemplo se eliminó el nodo 4 y su hijo 3 pasó a ser hijo de 2, que era el padre de 4.

Cuando se pone más complicado es cuando se elimina un nodo con dos hijos, en este caso la estrategia es reemplazar el dato de este nodo con el dato más pequeño a la derecha.
![[Pasted image 20231030110618.png]]
Aquí tenemos el ejemplo. Eliminamos el dato del nodo 2. Así que buscamos a su derecha el dato más pequeño que es 3. el 3 ocupa el lugar  del 2 y ahora el 4 es hijo directo de 5, ya que el 3 ya no se encuentra.
```
/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void remove( const Comparable & x, BinaryNode *&t)
{
    if( t == nullptr )
        return; // Item not found; do nothing
    if( x < t->element )
        remove( x, t->left );
    else if( t->element < x )
        remove( x, t->right );
    else if( t->left != nullptr && t->right != nullptr ) // Two children
    {
        t->element = findMin( t->right )->element;
        remove( t->element, t->right );
    }
    else
    {
        BinaryNode *oldNode = t;
        t = ( t->left != nullptr ) ? t->left : t->right;
        delete oldNode;
    }
}
```

## Destructor y constructor por copia

El destructor se encarga de recorrer nodo por nodo de manera recursiva e ir eliminando los datos. El constructor por copia hace lo de siempre, tomando r valores y asignándolos dentro del árbol.

# Árboles AVL

AVL se refiere a *Adelson-Velskii and Landis*, es un tipo de árbol que debe de tener una condición de balance para asegurar que el nivel de complejidad se mantenga en O(logN). La idea más básica sería asegurarse de que el lado derecho e izquierdo cuenten con la misma profundidad.
![[Pasted image 20231030122142.png]]
Un árbol AVL es idéntico a uno binario, excepto en un detalle y es que el lado izquierdo y el derecho pueden variar su profundidad en máximo 1.
![[Pasted image 20231030125138.png]]
En este ejemplo, el árbol de la izquierda es un AVL porque la profundidad del lado izquierdo es de 3 y el derecho de 2. Pero el árbol de la derecha no puede ser ya que las profundidades son de 3 y 1.

Si queremos insertar un nodo en un árbol AVL corremos el riesgo de alterar y hacer que no se cumpla la condición, esto se puede prevenir con algo llamado rotación

# Opinión crítica
Me gustaría que viéramos los distintos modos de recorrer un árbol de manera recursiva, ya que la verdad no les entendí del todo. El aspecto de las rotaciones la verdad es que tampoco me quedó claro y no le pude entender y por eso la verdad no me sentí con la capacida de explicarlo en el resumen.
# Conclusiones
Los árboles se ve que bien utilizados son una gran manera de organizar nuestros datos

# Referencias

|   |   |
|---|---|
|M. A. Weiss, _Data Structures and Algorithm Analysis in C++_, 4a ed. Upper Saddle River, NJ, Estados Unidos de América: Pearson, 2013.|
|“110. Programación en C++ || Árboles || Concepto de Árboles”, 14-nov-2016. [En línea]. Disponible en: https://www.youtube.com/watch?v=k2kx7hupEy4. [Consultado: 30-oct-2023].|
|“Introduction to binary tree - data structure and algorithm tutorials”, _GeeksforGeeks_, 31-mar-2013. [En línea]. Disponible en: https://www.geeksforgeeks.org/introduction-to-binary-tree-data-structure-and-algorithm-tutorials/. [Consultado: 30-oct-2023].|
|“Introduction to binary tree - data structure and algorithm tutorials”, _GeeksforGeeks_, 31-mar-2013. [En línea]. Disponible en: https://www.geeksforgeeks.org/introduction-to-binary-tree-data-structure-and-algorithm-tutorials/. [Consultado: 30-oct-2023].|
|J. C. Méndez, “Rotación de árboles AVL”, 05-mar-2021. [En línea]. Disponible en: https://www.youtube.com/watch?v=wNhYwaoI1i8. [Consultado: 30-oct-2023].|






