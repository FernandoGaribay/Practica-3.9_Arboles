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

	void eliminar(CNodo*, int);
	void eliminar_Nodo(CNodo*);
	CNodo* minimo(CNodo*);
	void remplazar(CNodo*, CNodo*);
	void destruirNodo(CNodo* nodo);

	void Borrado_SinHijos(CNodo*& suprimido, CNodo*& raiz);
	bool EsHijoDerecho(CNodo*& hijo);
};

