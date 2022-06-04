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
        if (n < valorRaiz) {
            insertarNodo(arbol->getIzquierda(), n, arbol);
        }
        else {
            insertarNodo(arbol->getDerecha(), n, arbol);
        }
    }
}

void CArbol::mostarArbol(CNodo* arbol, int contador) {
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

bool CArbol::busqueda(CNodo* arbol, int n) {
    if (arbol == NULL) {
        return false;
    }
    else if (arbol->getValor() == n) {
        return true;
    }
    else if (n < arbol->getValor()) {
        return busqueda(arbol->getIzquierda(), n);
    }
    else {
        return busqueda(arbol->getDerecha(), n);
    }
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





void CArbol::eliminar(CNodo* arbol, int n) {
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
        Borrado_SinHijos(aux, arbol);
    }
}

void CArbol::Borrado_SinHijos(CNodo*& suprimido, CNodo*& raiz) {

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

bool CArbol::EsHijoDerecho(CNodo*& hijo) {
    if (hijo->getPadre()->getDerecha() == hijo) {
        return true;
    }
    return false;

}

CNodo* CArbol::minimo(CNodo* aux) {
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

void CArbol::remplazar(CNodo* arbol, CNodo* nuevoNodo) {
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

void CArbol::destruirNodo(CNodo* nodo) {
    nodo->setIzquierda(NULL);
    nodo->setDerecha(NULL);

    delete nodo;
    nodo = NULL;
}