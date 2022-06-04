#include <iostream>
#include "CNodo.h"

using namespace std;


void menu();
void insertarNodo(CNodo*&, int, CNodo*);
void mostarArbol(CNodo*, int);
bool busqueda(CNodo*, int n);
void preOrden(CNodo*);

void eliminar(CNodo*, int);
void eliminar_Nodo(CNodo*);
CNodo* minimo(CNodo*);
void remplazar(CNodo*, CNodo*);
void destruirNodo(CNodo* nodo);

void Borrado_SinHijos(CNodo*& suprimido, CNodo*& raiz);
bool EsHijoDerecho(CNodo*& hijo);

CNodo* arbol = NULL;

int main(){
    insertarNodo(arbol, 10, NULL);
    insertarNodo(arbol, 5, NULL);
    insertarNodo(arbol, 3, NULL);
    insertarNodo(arbol, 8, NULL);
    insertarNodo(arbol, 6, NULL);
    insertarNodo(arbol, 9, NULL);
    insertarNodo(arbol, 7, NULL);
    insertarNodo(arbol, 15, NULL);
    insertarNodo(arbol, 12, NULL);
    insertarNodo(arbol, 20, NULL);
    insertarNodo(arbol, 30, NULL);
    menu();
}

void menu() {
    int dato=0, opcion=0, contador = 0;

    do {
        cout << "\tMenu.\n" << endl;
        cout << "1. Insertar nuevo nodo." << endl;
        cout << "2. Mostrar arbol." << endl;
        cout << "3. Buscar nodo." << endl;
        cout << "4. Imprimir los valores (pre-orden)" << endl;
        cout << "5. Eliminar un nodo" << endl;
        cout << "6. Cantidad de nodos" << endl;
        cout << "9. Salir." << endl;

        cout << "\nDijite una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: 
            cout << "\nDijite un numero: ";
            cin >> dato;
            insertarNodo(arbol, dato, NULL);
            cout << "\nNodo insertado." << endl;
            system("pause");
            break;
        case 2:
            cout << "\nMostar arbol.\n\n ";
            mostarArbol(arbol, contador);
            cout << endl;
            system("pause");
            break;
        case 3:
            cout << "\nDijite el elemneto a buscar: ";
            cin >> dato;
            if (busqueda(arbol, dato)) {
                cout << "\nElemento " << dato << " ah sido encontrado en el arbol" << endl;
            }
            else {
                cout << "\nElemento no encontrado" << endl;
            }
            cout << endl;
            system("pause");
            break;
        case 4:
            cout << "\nImprimir los valores (pre-orden).\n\n ";
            preOrden(arbol);
            cout << endl;
            system("pause");
            break;
        case 5:
            cout << "\nDijite el elemento a eliminar: ";
            cin >> dato;
            eliminar(arbol, dato);
            cout << endl;
            system("pause");
            break;
        case 6:

            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 9);
}

void insertarNodo(CNodo*& arbol, int n, CNodo* padre) {
    if (arbol == NULL) {
        CNodo* nuevoNodo = new CNodo(n, padre);
        arbol = nuevoNodo;
    }
    else {
        int valorRaiz = arbol->getValor();
        if (n < valorRaiz) {
            insertarNodo(arbol->getIzquierda(), n, arbol);
        }
        else {
            insertarNodo(arbol->getDerecha(), n, arbol);
        }
    }
}

void mostarArbol(CNodo* arbol, int contador) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostarArbol(arbol->getDerecha(), contador + 1);
        for (int i = 0; i < contador; i++) {
            cout << "  "; 
        }
        cout << arbol->getValor() << endl;
        mostarArbol(arbol->getIzquierda(), contador + 1);
    }
}

bool busqueda(CNodo* arbol, int n) {
    if (arbol == NULL) {
        return false;
    }
    else if(arbol->getValor() == n) {
        return true;
    }
    else if(n < arbol->getValor()) {
        return busqueda(arbol->getIzquierda(), n);
    }
    else {
        return busqueda(arbol->getDerecha(), n);
    }
}

void preOrden(CNodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->getValor() << " - ";
        preOrden(arbol->getIzquierda());
        preOrden(arbol->getDerecha());
    }
}





void eliminar(CNodo* arbol, int n) {
    if (arbol == NULL) {
        return;
    }
    else if (n < arbol->getValor()) {
        eliminar(arbol->getIzquierda(), n);
    }
    else if (n > arbol->getValor()) {
        eliminar(arbol->getDerecha(), n);
    }
    else {
        eliminar_Nodo(arbol);
    }
}

void eliminar_Nodo(CNodo* aux) {
    if (aux->getIzquierda() && aux->getDerecha()) {
        CNodo* menor = minimo(aux->getDerecha());
        aux->setValor(menor->getValor());
        eliminar_Nodo(menor);
    }
    else if (aux->getIzquierda()) {
        remplazar(aux, aux->getIzquierda());
        destruirNodo(aux);
    }
    else if (aux->getDerecha()) {
        remplazar(aux, aux->getDerecha());
        destruirNodo(aux);
    }
    else {
        Borrado_SinHijos(aux, arbol);
    }
}

void Borrado_SinHijos(CNodo*& suprimido, CNodo*& raiz) {

    if (suprimido->getPadre() != NULL) {//si el nodo a borrar tiene padre

        if (EsHijoDerecho(suprimido)) {//si es un hijo derecho
            suprimido->getPadre()->setDerecha(NULL);
        }
        else {//si en cambio es un hijo izquierdo
            suprimido->getPadre()->setIzquierda(NULL);
        }

    }
    else if (raiz == suprimido) {//si el nodo a borrar es la raiz
        raiz = NULL;//anulamos a raiz en el caso de que sea el nodo a borrar
    }

    destruirNodo(suprimido);

}

bool EsHijoDerecho(CNodo*& hijo) {
    if (hijo->getPadre()->getDerecha() == hijo) {
        return true;
    }
    return false;

}

CNodo* minimo(CNodo* aux) {
    if (aux == NULL) {
        return NULL;
    }
    if (aux->getIzquierda()) {
        return minimo(aux->getIzquierda());
    }
    else {
        return aux;
    }
}

void remplazar(CNodo* arbol, CNodo* nuevoNodo) {
    if (arbol->getPadre()) {
        if (arbol->getValor() == arbol->getPadre()->getIzquierda()->getValor()) {
            arbol->getPadre()->setIzquierda(nuevoNodo);
        }
        else if (arbol->getValor() == arbol->getPadre()->getDerecha()->getValor()) {
            arbol->getPadre()->setDerecha(nuevoNodo);
        }
    }
    if (nuevoNodo) {
        nuevoNodo->setPadre(arbol->getPadre());
    }
}

void destruirNodo(CNodo* nodo) {
    nodo->setIzquierda(NULL);
    nodo->setDerecha(NULL);

    delete nodo;
    nodo = NULL;
}