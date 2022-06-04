#include <iostream>
#include "CNodo.h"
#include "CArbol.h"

using namespace std;


void menu();
void insertarArbol();
void eliminarElemento(int& dato);
void preOrden();
void buscarNodo(int& dato);
void mostrarArbol(int contador);
void insertarNodo(int& dato);

CNodo* arbol = NULL;
CArbol objArbol;

int main(void){
    insertarArbol();
    menu();
    
    return 0;
}

void insertarArbol()
{
    objArbol.insertarNodo(arbol, 10, NULL);
    objArbol.insertarNodo(arbol, 5, NULL);
    objArbol.insertarNodo(arbol, 3, NULL);
    objArbol.insertarNodo(arbol, 8, NULL);
    objArbol.insertarNodo(arbol, 6, NULL);
    objArbol.insertarNodo(arbol, 9, NULL);
    objArbol.insertarNodo(arbol, 7, NULL);
    objArbol.insertarNodo(arbol, 15, NULL);
    objArbol.insertarNodo(arbol, 12, NULL);
    objArbol.insertarNodo(arbol, 20, NULL);
    objArbol.insertarNodo(arbol, 30, NULL);
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
            insertarNodo(dato);
            break;
        case 2:
            mostrarArbol(contador);
            break;
        case 3:
            buscarNodo(dato);
            break;
        case 4:
            preOrden();
            break;
        case 5:
            eliminarElemento(dato);
            break;
        case 6:

            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 9);
}

void eliminarElemento(int& dato)
{
    cout << "\nELIMINAR UN ELEMENTO -----\n\n ";

    cout << "Dijite el elemento a eliminar: ";
    cin >> dato;

    objArbol.eliminar(arbol, dato);

    cout << endl;
    system("pause");
}

void preOrden()
{
    cout << "\nIMPRIMIR VALORES (PRE-ORDEN) -----\n\n ";

    objArbol.preOrden(arbol);

    cout << "\n" << endl;
    system("pause");
}

void buscarNodo(int& dato)
{
    cout << "\nBUSCAR NODO -----\n\n ";

    cout << "Dijite el elemento a buscar: ";
    cin >> dato;

    if (objArbol.busqueda(arbol, dato))
        cout << "\nElemento " << dato << " ah sido encontrado en el arbol" << endl;
    else
        cout << "\nElemento no encontrado" << endl;

    cout << endl;
    system("pause");
}

void mostrarArbol(int contador)
{
    cout << "\nMOSTRAR ARBOL -----\n\n ";

    objArbol.mostarArbol(arbol, contador);

    cout << endl;
    system("pause");
}

void insertarNodo(int& dato){
    cout << "\nINSERTAR NUEVO NODO -----\n\n ";

    cout << "Dijite un numero: ";
    cin >> dato;

    objArbol.insertarNodo(arbol, dato, NULL);
    cout << "\nNodo insertado." << endl;

    cout << endl;
    system("pause");
}
