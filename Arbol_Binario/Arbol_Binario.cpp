#include <iostream>

using namespace std;

struct nodo {
    int valor;
    nodo* izquierda;
    nodo* derecha;
    nodo* padre;
};

void menu();
nodo *crearNodo(int, nodo*);
void insertarNodo(nodo*& arbol, int n, nodo*);
void mostarArbol(nodo* arbol, int contador);
bool busqueda(nodo* arbol, int n);
void preOrden(nodo* arbol);

void eliminar(nodo* arbol, int n);
void eliminar_Nodo(nodo* aux);
nodo* minimo(nodo *aux);
void remplazar(nodo*, nodo* );
void destruirNodo(nodo* nodo);

nodo* arbol = NULL; 

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

nodo *crearNodo(int n, nodo* padre) {
    nodo* nuevoNodo = new nodo();
    
    nuevoNodo->valor = n;
    nuevoNodo->derecha = NULL;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->padre = padre;

    return nuevoNodo;
}

void insertarNodo(nodo*& arbol, int n, nodo* padre) {
    if (arbol == NULL) {
        nodo* nuevoNodo = crearNodo(n, padre);
        arbol = nuevoNodo;
    }
    else {
        int valorRaiz = arbol->valor;
        if (n < valorRaiz) {
            insertarNodo(arbol->izquierda, n, arbol);
        }
        else {
            insertarNodo(arbol->derecha, n, arbol);
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

void preOrden(nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->valor << " - ";
        preOrden(arbol->izquierda);
        preOrden(arbol->derecha);
    }
}





void eliminar(nodo *arbol, int n) {
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

void eliminar_Nodo(nodo* aux) {
    if (aux->izquierda && aux->derecha) {
        nodo* menor = minimo(aux->derecha);
        aux->valor = menor->valor;
        eliminar_Nodo(menor);
    }
    else if (aux->izquierda) {
        remplazar(aux, aux->izquierda);
        destruirNodo(aux);
    }
    else if (aux->derecha) {
        remplazar(aux, aux->derecha);
        destruirNodo(aux);
    }
    else {
        remplazar(aux, NULL);
        destruirNodo(aux);
    }
}

struct nodo* minimo(nodo* aux) {
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

void remplazar(nodo* arbol, nodo* nuevoNodo) {
    if (arbol->padre) {
        if (arbol->valor == arbol->padre->izquierda->valor) {
            arbol->padre->izquierda = nuevoNodo;
        }
        else if (arbol->valor == arbol->padre->derecha->valor) {
            arbol->padre->derecha = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        nuevoNodo->padre = arbol->padre;
    }
}

void destruirNodo(nodo* nodo) {
    nodo->izquierda = NULL;
    nodo->derecha = NULL;

    delete nodo;
    nodo = NULL;
}