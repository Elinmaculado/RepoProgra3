# Stack

```
#ifndef DLLIST_STACK_H  
#define DLLIST_STACK_H  
  
  
template <typename Iterator>  
class Stack : private DLList<Iterator> {  
public:  
	//Construct default
    Stack() {  
    }  
	//Destructor
    ~Stack(){  
        clear();  
        delete DLList<Iterator>::head;  
        delete DLList<Iterator>::tail;  
    }  
	
```
Aqui tenemos la declaración de la clase y el constructor y su destructor

```
//Metodo para agregar dato al frente
    void push(Iterator &data){  
        DLList<Iterator>::push_front(data);  
    }  
    void push(Iterator &&data){  
        DLList<Iterator>::push_front(data);  
    }  
	//metodo para quitar dato del fente
    void pop(){  
        DLList<Iterator>::pop_front();  
    }  
    Iterator top(){  
        return DLList<Iterator>::head->next->data;  
    }  
```
Aqui tenemos tres metodos que nos hacen ver que trabajamos con un stack, ya que push agrega un dato y pop lo quitan. pero ambos sólo trabajan con el dato de hasta en frente, ya que estamos tratando con una lista.

y el método top nos da el último elemento que se agregó.

```
    void clear(){  
        DLList<Iterator>::clear();  
    }  
  
    void print(){  
        DLList<Iterator>::print();  
    }  
  
    
};  
#endif //DLLIST_STACK_H
```
clear es un método para borrar todo el stack y print para imprimir todos los datos
# Queue

```
#ifndef DLLIST_QUEUE_H  
#define DLLIST_QUEUE_H  
#include "DLList.h"  
  
template<typename XD>  
class Queue : private DLList<XD>{  
public:  
    Queue(){  
    }  
  
    ~Queue(){  
        clear();  
        delete DLList<XD>::head;  
        delete DLList<XD>::tail;  
    }  
```
Declaramos la clase y le damos su constructor implícito y destructor

```
    void enqueue(XD &data){  
        DLList<XD>::push_back(data);  
    }  
  
    void enqueue(XD &&data){  
        DLList<XD>::push_back(data);  
    }  
  
    void dequeue(){  
        DLList<XD>::pop_front();  
    }  
  
```
Estos métodos hacen referencia a la naturaleza de la fila, enque le da un nuevo dato a la fila pero solo hasta el final. Y deque quita un dato que sólo puede ser el del principio.

```
    void print(){  
        DLList<XD>::print();  
    }  
  
    void clear(){  
        DLList<XD>::clear();  
    }  
  
    XD front(){  
        return DLList<XD>::head->next->data;  
    }  
};  
  
#endif //DLLIST_QUEUE_H
```
clear es un método para borrar toda la fila y print para imprimir todos los datos. El front nos dice que dato se encuentra en frente de la fila.
# SLList
Aquí se explicará el funcionamiento de cada parte del código de la clase SLList. Para esto tenemos que entender lo que es una lista de enlace simple, y es un tipo de lista en el que cada dato está ligado al siguiente dato, así que el dato 1 está ligado al dato 2, el 2 al 3, el 3 al 4 y así sucesivamente hasta que se acabe la lista. También tenemos que saber que es un nodo, un nodo es el espacio de la lista en donde se almacenan dos cosas, el dato que queremos que esté ahí, y el puntero que apunta al siguiente nodo. Con eso vemos el primer segmento de código.

```
template <typename Object>
class SLList {
private:
    struct Node  {
        Object data;
        Node *next;//Anya
		
        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {}
		
        Node(Object &&d, Node *n = nullptr)
            : data{std::move(d)}, next{n} {}
    };
```
Lo primero es ver que el código empieza con la línea que dice ```template <typename Object>``` esto es importante porque esta linea le dice a la clase que va a trabajar igual con cualquier tipo de dato, y así no hay que hacer ajustes y declarar cómo se utiliza cada tipo de dato

Después de eso tenemos el código para el nodo, donde vemos que se inicializa el puntero *next* que es el que en cada nodo apuntará al siguiente, y después de eso tenemos los dos constructores del nodo, el primero es por copia y el segundo es por referencia.

```
public:
    class iterator {
    public:
        //constructor implicito, se hace nulo el puntero
		iterator() : current{nullptr} {}
```
Aquí de manera breve tenemos la inicialización del iterador y tenemos su constructor implícito, es importante que un iterador se inicia cómo nulo, para que no apunte a una dirección de memoria aleatoria.

```
 Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        iterator &operator++() {
            if(current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }

		//Operadores para realizar comparaciones
        bool operator==(const iterator &rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }
```
Ahora lo que tenemos es la parte en la que le decimso al iterador cómo utilizar distintos operadores. Primero el * que cómo sabemos es el operador que ponemos para que el puntero acceda al dato que tiene, por eso si cuando se utiliza el * el puntero es nulo, mandará un error, pero si tiene un dato, este dato es el que se retorna

Después tenemos dos acciones que realiza el operador ++. La primera indicación es para que el puntero cambie de posición en la lista a la siguiente, por eso tenemos la igualación de la posición actual a la siguiente y un error en caso de que el puntero esté en la última posición.
Y la segunda indicación para el operador ++ es para que el iterador pueda leer la posición en la que va. Podría decirse que la primera indicación hace referencia al movimiento, y la segunda a la posición.

Después están los operadores == y !=, que sirven para comparar, por eso se comparan al valor del lado derecho que nosotros demos.

```
 private:
        Node *current;
        iterator(Node *p) : current{p} {}
        friend class SLList<Object>;
    };
```
Ayuda a que el nodo y el iterador se inicialicen.

```
public:
    SLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }

    ~SLList() {
        clear();
        delete head;
        delete tail;
    }
```
Aquí lo primero que tenemos es el constructor de una lista vacía, una lista a fuerzas tiene que tener una cabeza y una cola, cómo son los únicos dos elementos, inmediatamente después de la cabeza sigue la cola, y vemos eso en la primera parte.
Después tenemos el destructor, la primera indicación de *clear* elimina todo entre la cola y la cabeza, una vez eliminados esos datos ya se eliminan la cabeza y la cola.

```
iterator begin() { return {head->next}; }
    iterator end() { return {tail}; }

    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

    void clear() { while (!empty()) pop_front(); }

    Object &front() {
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }
```
Aquí tenemos distintos métodos, el begin hace referencia al principio de la lista y end al final. Después tanto size cómo empty hacen referencia al tamaño de la lista, size devuelve el tamaño y empty es un booleano que devuelve verdadero si la lista está vacía.
clear borra todos los objetos hasta que la lista esté vacía, y finalmente front retorna el objeto que esté en el frente de la lista, a menos de que esta esté vacía.

```
    void push_front(const Object &x) { insert(begin(), x); }
    //funcion de push por referencia
    void push_front(Object &&x) { insert(begin(), std::move(x)); }

    void pop_front() {
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }
```
Aquí tenemos el método push front que inserta un valor al frente de la lista, y lo tenemos tanto por copia cómo por referencia. después tenemos la función pop front que ahora lo que hace es quitar el valor que esté en el frente.

```
    iterator insert(iterator itr, const Object &x) {
        Node *p = itr.current;
        head->next = new Node{x, head->next};
        theSize++;
        return iterator(head->next);
    }

    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        head->next = new Node{std::move(x), head->next};
        theSize++;
        return iterator(head->next);
    }
```
Aquí tenemos la función insert que funciona con un iterador, esta función inserta un dato en la posición que le indiquemos al iterador, tenemos esta función tanto por copia y por referencia.

```
 iterator erase(iterator itr) {
        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node *p = head;
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current;
        theSize--;
        return iterator(p->next);
    }
```
De manera similar la función erase también accede al punto que le digamos al iterador pero en este caso es para borrar el dato que se encuentra en la posición.

```
void printList() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }
```
Y la última función que tenemos es printlist, que utiliza un iterador para recorrer toda la lista e ir imprimiendo dato por dato hasta llegar al final, lo cual resulta en que se imprime toda la lista.

```
private:
    Node *head;
    Node *tail;
    int theSize;
    //init necesita acceso a los datos privados para inicializar una lista vacia
    void init() {
        theSize = 0;
        head->next = tail;
    }
};
```
Y por último están los parametros privados, donde tenemos la cola y cabeza de la lista, así cómo el tamaño de esta. El init está aquí para acceder a los datos privados e inicializar una lista vacía.


# DLList
Aquí vamos a explicar el funcionamiento de la clase DLList, que se refiere a *double linked list* o una lista de doble enlace. Lo primero es entender que es una lista de doble enlace, y es una lista en la que cada nodo está apuntando al nodo siguiente y al nodo anterior a la vez, excepto la cabeza (que sólo apunta al siguiente) y la cola (que sólo apunta al anterior). así que por ejemplo el nodo 3 apunta al nodo 2 y al nodo 4. Este tipo de lista tiene la ventaja de que podemos recorrerla en ambas direcciones, no sólo de principio a fin cómo la de enlace simple. 

A continuación se irá explicando el funcionamiento del código de la clase.
```
template <typename Object>  
class DLList{  
private:  
    struct Node  {  
        Object data;  
        Node *next;  
        Node *prev;  
        
        Node(const Object &d = Object{}, Node *n = nullptr)  
                : data{d}, next{n}, prev{n} {}  
                
        Node(Object &&d, Node *n = nullptr)  
                : data{std::move(d)}, next{n}, prev{n} {}  
    };
```
Aquí tenemos la estructura del nodo, se le dice lo que va contener que es un objeto, y dos punteros, uno para el siguiente nodo y otro para el anterior, y después tenemos los constructores por copia y por referencia.

```
public:  
    class iterator{  
    public:  
        //constructor implicito, se hace nulo el puntero  
        iterator() : current{nullptr} {}  
  

```
Aquí de manera breve tenemos la inicialización del iterador y tenemos su constructor implícito, es importante que un iterador se inicia cómo nulo, para que no apunte a una dirección de memoria aleatoria.


```
Object &operator*() {  
	if(current == nullptr)  
	    throw std::logic_error("Trying to dereference a null pointer.");  
	return current->data;  
    }
     
iterator &operator++() {  
    if(current)  
        current = current->next;  
    else  
        throw std::logic_error("Trying to increment past the end.");  
    return *this;  
}  
  
iterator operator++(int) {  
    iterator old = *this;  
    ++(*this);  
    return old;  
}  
  
iterator &operator--() {  
    if(current)  
        current = current->prev;  
    else  
        throw std::logic_error("Trying to decrease past the beginning.");  
    return *this;  
}  
  
iterator operator--(int) {  
    iterator old = *this;  
    --(*this);  
    return old;  
}
```
Ahora lo que tenemos es la parte en la que le decimso al iterador cómo utilizar distintos operadores. Primero el * que cómo sabemos es el operador que ponemos para que el puntero acceda al dato que tiene, por eso si cuando se utiliza el * el puntero es nulo, mandará un error, pero si tiene un dato, este dato es el que se retorna

Después tenemos dos acciones que realiza el operador ++. La primera indicación es para que el puntero cambie de posición en la lista a la siguiente, por eso tenemos la igualación de la posición actual a la siguiente y un error en caso de que el puntero esté en la última posición.
Y la segunda indicación para el operador ++ es para que el iterador pueda leer la posición en la que va. Podría decirse que la primera indicación hace referencia al movimiento, y la segunda a la posición.

Similar al operador ++ tenemos al operador -- que hace lo exactamente lo contrario, esto es posible gracias a los dos punteros que tiene el nodo.
Este operador hace que el iterador se mueva hacía atrás en la lista, y sus dos declaraciones funcionan igual que las de ++, la primera hace referencia al movimiento del iterador y la segunda a su posición


```
//Operadores para realizar comparaciones  
bool operator==(const iterator &rhs) const {  
    return current == rhs.current;  
}  
  
bool operator!=(const iterator &rhs) const {  
    return !(*this == rhs);  
}
```
Después están los operadores de comparación == y !=, que sirven para comparar dos valores distintos, por eso se comparan al valor del lado derecho que nosotros demos. 

```
private:  
    Node *current;  
    iterator(Node *p) : current{p} {}  
    friend class DLList<Object>;  
};
```
Ayuda a que el nodo y el iterador se inicialicen. También declaramos a DLList cómo clase amiga de la clase iterador, para que DLList pueda acceder a los datos privados de iterador.

```
public:  
   DLList() : head(new Node()), tail(new Node()), theSize(0) {  
        head->next = tail;  
    }  
	
	~DLList() {  
        clear();  
        delete head;  
        delete tail;  
    }
```
Aquí lo primero que tenemos es el constructor de una lista vacía, una lista a fuerzas tiene que tener una cabeza y una cola, cómo son los únicos dos elementos, inmediatamente después de la cabeza sigue la cola, y vemos eso en la primera parte.
Después tenemos el destructor, la primera indicación de *clear* elimina todo entre la cola y la cabeza, una vez eliminados esos datos ya se eliminan la cabeza y la cola.

```
iterator begin() { return {head->next}; }  
iterator end() { return {tail}; }
 
int size() const { return theSize; }  
bool empty() const { return size() == 0; }

void clear() { while (!empty()) pop_front(); }

Object &front() {  
    if(empty())  
        throw std::logic_error("List is empty.");  
    return *begin();  
}
```
Aquí tenemos distintos métodos, el begin hace referencia al principio de la lista y end al final. Después tanto size cómo empty hacen referencia al tamaño de la lista, size devuelve el tamaño y empty es un booleano que devuelve verdadero si la lista está vacía.
clear borra todos los objetos hasta que la lista esté vacía, y finalmente front retorna el objeto que esté en el frente de la lista, a menos de que esta esté vacía.

```
void push_front(const Object &x) { insert(begin(), x); }  
void push_front(Object &&x) { insert(begin(), std::move(x)); }  
  
void push_back(const Object &x) { insert(end(), x); }  
void push_back(Object &&x) { insert(end(), std::move(x)); }

void pop_front() {  
    if(empty())  
        throw std::logic_error("List is empty.");  
    erase(begin());  
}
```
Aquí tenemos el método push front que inserta un valor al frente de la lista, y lo tenemos tanto por copia cómo por referencia. después tenemos la función pop front que ahora lo que hace es quitar el valor que esté en el frente.


```
//Recibe un iterador, lee esa posicion e inserta un cÃ³digo en la posicion que le demos  
//este funciona por copia  
iterator insert(iterator itr, const Object &x) {  
    Node *p = itr.current;  
    head->next = new Node{x, head->next};  
    theSize++;  
    return iterator(head->next);  
}  
  
//este funciona por referencia  
iterator insert(iterator itr, Object &&x) {  
    Node *p = itr.current;  
    head->next = new Node{std::move(x), head->next};  
    theSize++;  
    return iterator(head->next);  
}  
  
//esta funcion nos ayuda a recibir un iterador y después volverlo un int  
void insert(int pos, const Object &x) {  
    insert(get_iterator(pos), x);  
}  
  
//Aqui es donde el iterador se vuelve un entero  
iterator get_iterator(int a)  
{  
    iterator it = begin();  
    for(int i = 0; i != a; ++i) {  
        ++it;  
    }  
    return it;  
}
```
Aquí tenemos el método insert, que utilizamos para introducir un elemento en el punto que queramos de la lista. Las primeras dos declaraciones son la función por copia y por referencia, pero en estas declaraciones sólo puede recibir un iterador. pero para arreglar eso, estám los siguientes métodos, el insert que es tipo void recibe un entero cómo posición y el objeto que queremos utilizar en la lista, después manda a llamar a la función original pero dentro dándole cómo parametron la función *get_iterator* que lo que hace es que se encarga de convertir un entero en un iterador.
Todo esto es para que el usuario al indicar la posición, pueda escribir un entero y no un iterador solamente.

```
//recibe un iterador y borra el dato en la posicion que le digamos  
iterator erase(iterator itr) {  
  
    if (itr == end())  
        throw std::logic_error("Cannot erase at end iterator");  
    Node *p = head;  
    while (p->next != itr.current) p = p->next;  
    p->next = itr.current->next;  
    delete itr.current;  
    theSize--;  
    return iterator(p->next);  
}  
  
void erase(int pos)  
{  
    erase(get_iterator(pos));  
}
```
El método *erase* es para borrar el dato en la posición que nos den, pero de manera similar a *insert* la declaración original sólo funcionar con iterador, por lo que se vuelve a declarar otra función tipo void, que utiliza la función *get_iterator* para convertir un entero a un iterador, y que el usuario pueda introducir enteros.

```
//Getter para toda la lista  
void print() {  
    iterator itr = begin();  
    while (itr != end()) {  
        std::cout << *itr << " ";  
        ++itr;  
    }  
    std::cout << std::endl;  
}
```
Aquí tenemos el método *print*, utiliza un iterador para recorrer toda la lista y va imprimiendo cada dato.

```
private:  
    Node *head;  
    Node *tail;  
    int theSize;  
    void init() {  
        theSize = 0;  
        head->next = tail;  
    }  
};
```
Finalmente tenemos los parámetros privados, aquí tenemos los punteros al nodo anterior y siguiente, el tamaño de la lista y el método init, para declarar una lista vacía.