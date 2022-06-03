#include <iostream>

using namespace std;

struct nodo {
    int valor;
    nodo* izquierda;
    nodo* derecha;
};

void menu();
nodo *crearNodo(int);
void insertarNodo(nodo*& arbol, int n);

void eliminar(nodo* arbol, int n);
void eliminar_Nodo(nodo* aux);
struct nodo* minimo(nodo *aux);

nodo* arbol = NULL; 

int main(){
    menu();
}

void menu() {
    int dato=0, opcion=0;

    do {
        cout << "\tMenu.\n" << endl;
        cout << "1. Insertar nuevo nodo." << endl;
        cout << "9. Salir." << endl;

        cout << "\nDijite una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: 
            cout << "\nDijite un numero: ";
            cin >> dato;
            insertarNodo(arbol, dato);
            cout << "\nNodo insertado." << endl;
            system("pause");
            break;


        }
        system("cls");
    } while (opcion != 9);
}

nodo *crearNodo(int n) {
    nodo* nuevoNodo = new nodo();
    
    nuevoNodo->valor = n;
    nuevoNodo->derecha = NULL;
    nuevoNodo->izquierda = NULL;

    return nuevoNodo;
}

void insertarNodo(nodo*& arbol, int n) {
    if (arbol == NULL) {
        nodo* nuevoNodo = crearNodo(n);
        arbol = nuevoNodo;
    }
    else {
        int valorRaiz = arbol->valor;
        if (n < valorRaiz) {
            insertarNodo(arbol->izquierda, n);
        }
        else {
            insertarNodo(arbol->derecha, n);
        }
    }
}

void eliminar(struct nodo *arbol, int n) {
    if (arbol == NULL) {
        return;
    }
    else if (n < arbol->valor) {
        eliminar(arbol->izquierda, n);
    }
    else if (n > arbol->valor) {
        eliminar(arbol->derecha, n);
    }
    else {
        eliminar_Nodo(arbol);
    }
}

void eliminar_Nodo(struct nodo* aux) {
    if (aux->izquierda && aux->derecha) {
        struct nodo* menor = minimo(aux->derecha);
        aux->valor = menor->valor;
        eliminar_Nodo(menor);
    }
}

struct nodo* minimo(struct nodo* aux) {
    if (aux == NULL) {
        return NULL;
    }
    if (aux->izquierda) {
        return minimo(aux->izquierda);
    }
    else {
        return aux;
    }
}