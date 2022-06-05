#pragma once
#include <iostream>
#include "CNodo.h"

using namespace std;

class CArbol
{
protected:
	CNodo* arbol;
public:
	CArbol();

	void insertarNodo(CNodo*&, int, CNodo*);
	void mostarArbol(CNodo*, int);
	bool busqueda(CNodo*, int n);
	void preOrden(CNodo*);
	int contarNodos(CNodo*);
	int contarNodosHoja(CNodo*);
	int alturaArbol(CNodo* nodo);

	void eliminar(CNodo*, int);
	void eliminar_Nodo(CNodo*);
	CNodo* minimo(CNodo*);
	CNodo* maximo(CNodo*);
	void remplazar(CNodo*, CNodo*);
	void destruirNodo(CNodo* nodo);

	void borrarNodoHoja(CNodo*& suprimido, CNodo*& raiz);
	bool EsHijoDerecho(CNodo*& hijo);
};

