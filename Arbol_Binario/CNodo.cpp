#include "CNodo.h"

CNodo::CNodo(int valor, CNodo* padre) {
    this->valor = valor;
    this->derecha = NULL;
    this->izquierda = NULL;
    this->padre = padre;
}

int CNodo::getValor() {
    return valor;
}
void CNodo::setValor(int valor) {
    this->valor = valor;
}

CNodo*& CNodo::getIzquierda() {
    return izquierda;
}
void CNodo::setIzquierda(CNodo* izquierda) {
    this->izquierda = izquierda;
}

CNodo*& CNodo::getDerecha() {
    return derecha;
}
void CNodo::setDerecha(CNodo* derecha) {
    this->derecha = derecha;
}

CNodo*& CNodo::getPadre() {
    return padre;
}
void CNodo::setPadre(CNodo* padre) {
    this->padre = padre;
}