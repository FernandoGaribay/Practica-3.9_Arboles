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
void mostarArbol(nodo* arbol, int contador);
bool busqueda(nodo* arbol, int n);

void eliminar(nodo* arbol, int n);
void eliminar_Nodo(nodo* aux);
struct nodo* minimo(nodo *aux);

nodo* arbol = NULL; 

int main(){
    menu();
}

void menu() {
    int dato=0, opcion=0, contador = 0;

    do {
        cout << "\tMenu.\n" << endl;
        cout << "1. Insertar nuevo nodo." << endl;
        cout << "2. Mostrar arbol." << endl;
        cout << "3. Buscar nodo." << endl;
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

void mostarArbol(nodo* arbol, int contador) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostarArbol(arbol->derecha, contador + 1);
        for (int i = 0; i < contador; i++) {
            cout << "  "; 
        }
        cout << arbol->valor << endl;
        mostarArbol(arbol->izquierda, contador + 1);
    }
}

bool busqueda(nodo* arbol, int n) {
    if (arbol == NULL) {
        return false;
    }
    else if(arbol->valor == n) {
        return true;
    }
    else if(n < arbol->valor) {
        return busqueda(arbol->izquierda, n);
    }
    else {
        return busqueda(arbol->derecha, n);
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