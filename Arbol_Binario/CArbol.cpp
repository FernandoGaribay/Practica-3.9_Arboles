#include "CArbol.h"

CArbol::CArbol() {
    arbol = NULL;
}

void CArbol::insertarNodo(CNodo*& arbol, int n, CNodo* padre) {
    if (arbol == NULL) {
        CNodo* nuevoNodo = new CNodo(n, padre);
        arbol = nuevoNodo;
    }
    else {
        int valorRaiz = arbol->getValor();

        if (n < valorRaiz) 
            insertarNodo(arbol->getIzquierda(), n, arbol);
        else
            insertarNodo(arbol->getDerecha(), n, arbol);
    }
}

void CArbol::mostarArbol(CNodo* arbol, int contador) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostarArbol(arbol->getDerecha(), contador + 1);
        for (int i = 0; i < contador; i++) 
            cout << "  ";
        
        cout << arbol->getValor() << endl;
        mostarArbol(arbol->getIzquierda(), contador + 1);
    }
}

bool CArbol::busqueda(CNodo* arbol, int n) {
    if (arbol == NULL) 
        return false;
    else if (arbol->getValor() == n) 
        return true;
    else if (n < arbol->getValor()) 
        return busqueda(arbol->getIzquierda(), n);
    else
        return busqueda(arbol->getDerecha(), n);
}

void CArbol::preOrden(CNodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->getValor() << " - ";
        preOrden(arbol->getIzquierda());
        preOrden(arbol->getDerecha());
    }
}

int CArbol::contarNodos(CNodo* arbol) {
    if (arbol == NULL)
        return 0;
    else
        return (1 + contarNodos(arbol->getDerecha()) + contarNodos(arbol->getIzquierda()));
}

int CArbol::contarNodosHoja(CNodo* arbol) {
    if (arbol == NULL)
        return 0;
    if (arbol->getIzquierda() == NULL && arbol->getDerecha() == NULL)
        return 1;
    else
        return contarNodosHoja(arbol->getIzquierda()) + contarNodosHoja(arbol->getDerecha());
}

int CArbol::alturaArbol(CNodo* nodo){
    if (nodo == NULL) 
        return 0;
    if (alturaArbol(nodo->getDerecha()) > alturaArbol(nodo->getIzquierda()))
        return alturaArbol(nodo->getDerecha()) + 1;
    else
        return alturaArbol(nodo->getIzquierda()) + 1;
}


void CArbol::eliminar(CNodo* arbol, int n) {
    if (arbol == NULL) 
        return;
    else if (n < arbol->getValor()) 
        eliminar(arbol->getIzquierda(), n);
    else if (n > arbol->getValor()) 
        eliminar(arbol->getDerecha(), n);
    else 
        eliminar_Nodo(arbol);
}

void CArbol::eliminar_Nodo(CNodo* aux) {
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
        borrarNodoHoja(aux, arbol);
    }

}

void CArbol::borrarNodoHoja(CNodo*& suprimido, CNodo*& raiz) {

    if (suprimido->getPadre() != NULL) {
        if (EsHijoDerecho(suprimido)) 
            suprimido->getPadre()->setDerecha(NULL);
        else
            suprimido->getPadre()->setIzquierda(NULL);
    }
    else if (raiz == suprimido)
        raiz = NULL;
   
    destruirNodo(suprimido);
}

bool CArbol::EsHijoDerecho(CNodo*& hijo) {
    if (hijo->getPadre()->getDerecha() == hijo)
        return true;
 
    return false;
}

CNodo* CArbol::minimo(CNodo* aux) {
    if (aux == NULL) 
        return NULL;
    if (aux->getIzquierda()) 
        return minimo(aux->getIzquierda());
    else 
        return aux;
}

CNodo* CArbol::maximo(CNodo* aux) {
    if (aux == NULL)
        return NULL;
    if (aux->getDerecha())
        return maximo(aux->getDerecha());
    else
        return aux;
}

void CArbol::remplazar(CNodo* arbol, CNodo* nuevoNodo) {
    if (arbol->getPadre()) {
        if (arbol->getValor() == arbol->getPadre()->getIzquierda()->getValor()) 
            arbol->getPadre()->setIzquierda(nuevoNodo);
        else if (arbol->getValor() == arbol->getPadre()->getDerecha()->getValor()) 
            arbol->getPadre()->setDerecha(nuevoNodo);
    }
    if (nuevoNodo) 
        nuevoNodo->setPadre(arbol->getPadre());
}

void CArbol::destruirNodo(CNodo* nodo) {
    nodo->setIzquierda(NULL);
    nodo->setDerecha(NULL);

    delete nodo;
    nodo = NULL;
}