#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct nodo {
    struct nodo* padre;
    struct nodo* izquierda;
    struct nodo* derecha;
    int valor;
};

struct nodo* crear_Nodo(struct nodo* padre, int valor);
void agregar_Valor(struct nodo* arbol, int valor);

int main(){
    struct nodo* arbol;
    arbol = crear_Nodo(NULL, 40);
    agregar_Valor(arbol, 10);
    agregar_Valor(arbol, 50);
    agregar_Valor(arbol, 1);
    agregar_Valor(arbol, 4);
    agregar_Valor(arbol, 2);
    agregar_Valor(arbol, 45);
    agregar_Valor(arbol, 30);
}

struct nodo* crear_Nodo(struct nodo* padre, int valor) {
    struct nodo *n = (struct nodo*)calloc(sizeof(struct nodo),1);
    n->padre = padre;
    n->valor = valor;
    return n; 
}

void agregar_Valor(struct nodo* arbol, int valor) {
    struct nodo* temp = NULL, * pivote = NULL;
    int derecho = 0; 

    if (arbol) {
        temp = arbol;
        while (temp != NULL) {
            pivote = temp;
            if (valor > temp->valor) {
                temp = temp->derecha;
                derecho = 1;
            }
            else {
                temp = temp->izquierda;
                derecho = 0;
            }
        }
        temp = crear_Nodo(pivote, valor);
        if (derecho) {
            cout << "Insertando " << valor << " del lado derecho de " << pivote->valor << endl;
            pivote->derecha = temp;
        }
        else {
            cout << "Insertando " << valor << " del lado izquierdo de " << pivote->valor << endl;
            pivote->izquierda = temp;
        }
    }
    else {
        cout << "Arbol vacio" << endl;
    }

}