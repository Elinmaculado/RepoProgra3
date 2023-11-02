# Árbol AVL
Un árbol AVL es un tipo especial de árbol binario cuya característica más importante es que es auto-balanceable.

El balance consiste en mantener la profundidad de un árbol relativamente pareja, evitando que haya nodos que lleguen mucho más profundo que los que tienen a su lado. Esto se realiza mediante las rotaciones
## Documentación

```
//  
// Created by miky_ on 26/10/2023.  
//  
  
#ifndef BINARYTREE_AVL_TREE_H_H  
#define BINARYTREE_AVL_TREE_H_H  
//Librerias  
#include<iostream>  
#include<iomanip>  
#include<algorithm>  
#include<memory>  
  
//Se utiliza template para trabajar con todo tipo de dato primitivo  
template <typename T>  
class Node {  
public:  
    // Aqui se guarda el dato que contiene el nodo  
    T data;  
    //Nivel del arbol  
    int height;  
    //Declaración de los punteros para nodo izquierdo y derecho  
    std::shared_ptr<Node<T>> left;  
    std::shared_ptr<Node<T>> right;  
  
    //Definición del nodo  
    Node(T data) : data(data), height(1), left(nullptr), right(nullptr) {}  
};  
  
template <typename T>  
class AVLTree {  
public:  
    //Se declara el nodo raiz  
    std::shared_ptr <Node<T>> root;  
  
    //el árbol hereda el nodo raíz  
    AVLTree() : root(nullptr) {}  
  
    //Funcion para añadir un dato al nodo raíz  
    void add(T data) {  
        root = insert(root, data);  
    }  
  
    //Funcion para borrar informacion dentro del nodo raíz  
    void remove(T data) {  
        root = deleteNode(root, data);  
    }  
  
    void print() {  
        if (root != nullptr) {  
            //Si la Raiz no esta vacia, se devuelve esta misma  
            print(root, 0);  
        } else {  
            //De otra forma marca error ya que el árbol está vacío  
            std::cout << "The tree is empty." << std::endl;  
        }  
    }  
  
private:  
    //función para imprimir el árbol  
    void print(std::shared_ptr <Node<T>> node, int indent) {  
        if (node) {  
            //Revisa que haya nodo a la derecha y se mueve a el  
            if (node->right) {  
                //Imprime el nodo a la derecha del nodo actual  
                print(node->right, indent + 8);  
            }  
            //Si indent tiene valor, Este valor se le asigna a width  
            if (indent) {  
                //setw = setwidth  
                std::cout << std::setw(indent) << ' ';  
            }  
            //Revisa que haya nodo a la derecha y se mueve a el  
            if (node->right) {  
                //Imprime el valor derecho del nodo actual  
                std::cout << " / (Right of " << node->data << ")\n" << std::setw(indent) << ' ';  
            }  
            std::cout << node->data << "\n";  
            if (node->left) {  
                //imprime el lado izquierdo  
                std::cout << std::setw(indent) << ' ' << " \\ (Left of " << node->data << ")\n";  
                print(node->left, indent + 8);  
            }  
        }  
    }  
  
    //Se crea un nuevo nodo  
    std::shared_ptr <Node<T>> newNode(T data) {  
        return std::make_shared<Node<T>>(data);  
    }  
  
    //Rotaciones  
    //Rotacion a la derecha    std::shared_ptr<Node<T>> rightRotate(std::shared_ptr<Node<T>> y) {  
        std::shared_ptr<Node<T>> x = y->left;  
        std::shared_ptr<Node<T>> T2 = x->right;  
  
        x->right = y;  
        y->left = T2;  
  
        y->height = max(height(y->left), height(y->right))+1;  
        x->height = max(height(x->left), height(x->right))+1;  
  
        return x;  
    }  
  
    //Rotación a la derecha  
    std::shared_ptr<Node<T>> leftRotate(std::shared_ptr<Node<T>> x) {  
        std::shared_ptr<Node<T>> y = x->right;  
        std::shared_ptr<Node<T>> T2 = y->left;  
  
        y->left = x;  
        x->right = T2;  
  
        x->height = max(height(x->left),height(x->right))+1;  
        y->height = max(height(y->left),height(y->right))+1;  
  
        return y;  
    }  
  
    int getBalance(std::shared_ptr<Node<T>> N) {  
        if (N == nullptr)  
            return 0;  
        return height(N->left) - height(N->right);  
    }  
  
    //Se inserta un nodo cuidando mantener el balance  
    std::shared_ptr<Node<T>> insert(std::shared_ptr<Node<T>> node, T data) {  
        if (node == nullptr)  
            return (newNode(data));  
  
        if (data < node->data)  
            node->left = insert(node->left, data);  
        else if (data > node->data)  
            node->right = insert(node->right, data);  
        else  
            return node;  
  
        node->height = 1 + max(height(node->left), height(node->right));  
  
        int balance = getBalance(node);  
  
        if (balance > 1 && data < node->left->data)  
            return rightRotate(node);  
  
        if (balance < -1 && data > node->right->data)  
            return leftRotate(node);  
  
        if (balance > 1 && data > node->left->data) {  
            node->left = leftRotate(node->left);  
            return rightRotate(node);  
        }  
  
        if (balance < -1 && data < node->right->data) {  
            node->right = rightRotate(node->right);  
            return leftRotate(node);  
        }  
  
        return node;  
    }  
  
    //Funcion para calular el minvalue  
    std::shared_ptr<Node<T>> minValueNode(std::shared_ptr<Node<T>> node) {  
        std::shared_ptr<Node<T>> current = node;  
  
        while (current->left != nullptr)  
            current = current->left;  
  
        return current;  
    }  
  
    //Funcion para eliminar un nodo  
    std::shared_ptr<Node<T>> deleteNode(std::shared_ptr<Node<T>> root, T data) {  
        if (!root)  
            return root;  
  
        if (data < root->data) {  
            root->left = deleteNode(root->left, data);  
        }  
        else if(data > root->data) {  
            root->right = deleteNode(root->right, data);  
        }  
        else {  
            if(!root->left || !root->right) {  
                root = (root->left) ? root->left : root->right;  
            }  
            else {  
                std::shared_ptr<Node<T>> temp = minValueNode(root->right);  
                root->data = temp->data;  
                root->right = deleteNode(root->right, temp->data);  
                temp.reset();  
            }  
        }  
  
        if(!root)  
            return root;  
  
        root->height = 1 + max(height(root->left), height(root->right));  
  
        int balance = getBalance(root);  
  
        if (balance > 1 && getBalance(root->left) >= 0)  
            return rightRotate(root);  
  
        if (balance < -1 && getBalance(root->right) <= 0)  
            return leftRotate(root);  
  
        if (balance > 1 && getBalance(root->left) < 0) {  
            root->left = leftRotate(root->left);  
            return rightRotate(root);  
        }  
  
        if (balance < -1 && getBalance(root->right) > 0) {  
            root->right = rightRotate(root->right);  
            return leftRotate(root);  
        }  
  
        return root;  
    }  
    //Funcion para obtener la altura  
    int height(std::shared_ptr<Node<T>> N) {  
        if (N == nullptr)  
            return 0;  
        return N->height;  
    }  
  
    int max(int a, int b) {  
        return (a > b)? a : b;  
    }  
};  
  
#endif //BINARYTREE_AVL_TREE_H_H
```