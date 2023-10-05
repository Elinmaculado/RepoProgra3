#ifndef SLLLIST_H
#define SLLLIST_H

#include <iostream>
#include <utility>

template <typename Object>
class SLList {
private:
    //Cada Cuadrito
    struct Node  {
        Object data;
        Node *next;//Anya
		
		//Constructor de copia
        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {}
		
		//Constructor de referncia
        Node(Object &&d, Node *n = nullptr)
            : data{std::move(d)}, next{n} {}
    };

public:
    class iterator {
    public:
        //constructor implicito, se hace nulo el puntero
		iterator() : current{nullptr} {}

		//Operador * para que se compporte como puntero
        Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

		//Movimiento
		//Operador hace que pueda moverse por la lista. 
        iterator &operator++() {
            if(current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

		//Posicion
		//lee la posicion en la que va
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

    private:
    	//apunta al nodo al que estoy trabajando en ese momento
        Node *current;
        iterator(Node *p) : current{p} {}
        //la clase amigo de acceso a los atributos privados
        friend class SLList<Object>;
    };

public:
	//Define la dimension de la lista
	//Cuando se llame al constructor, ya tiene que estar una cabeza y una cola
    SLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }

	//Destructor de la lista
	//Primero borra el contenido y despues la cola y la cabeza
    ~SLList() {
        clear();
        delete head;
        delete tail;
    }

	//Sirve para meter el iterador al principio o al final
    iterator begin() { return {head->next}; }
    iterator end() { return {tail}; }

	//el tamaño de la lista, para que un iterador sepa cuanto debe recorrer
    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

	//Mientras no este vacia borra el objeto de en frente
    void clear() { while (!empty()) pop_front(); }

	//Si la lista esta vacia da un error, si no retorna el inicio
    Object &front() {
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }

	//funcion de push por copia
    void push_front(const Object &x) { insert(begin(), x); }
    //funcion de push por referencia
    void push_front(Object &&x) { insert(begin(), std::move(x)); }

	//elimina el valo de en frente
    void pop_front() {
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }

	//Recibe un iterador, lee esa posicion e inserta un código en la posicion que le demos
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

	//Getter para toda la lista
    void printList() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

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

#endif
