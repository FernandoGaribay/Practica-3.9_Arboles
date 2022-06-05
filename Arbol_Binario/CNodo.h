#pragma once
#include <iostream>

using namespace std;

class CNodo
{
private:
    int valor;
    CNodo* izquierda;
    CNodo* derecha;
    CNodo* padre;

    friend class CArbol;
public:
    CNodo(int n, CNodo* padre);
    ~CNodo();

    int getValor();
    void setValor(int);

    CNodo*& getIzquierda();
    void setIzquierda(CNodo*);

    CNodo*& getDerecha();
    void setDerecha(CNodo*);

    CNodo*& getPadre();
    void setPadre(CNodo*);
};

