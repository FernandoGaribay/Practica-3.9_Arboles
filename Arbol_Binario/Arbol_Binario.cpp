#include <iostream>
#include "CNodo.h"
#include "CArbol.h"

using namespace std;


void menu();
void insertarArbol();
void eliminarElemento(int& dato);
void buscarNodo(int& dato);
void cantidadNodos();
void cantidadNodosHoja();
void alturaArbol();
void mostrarArbol();
void preOrden();
void nodoValorMayor();
void borrarNodoValorMenor();

void insertarNodo(int& dato);

CNodo* arbol = NULL;
CArbol objArbol;

int main(void){
    insertarArbol();
    menu();
    
    return 0;
}

void menu() {
    int dato=0, opcion=0;

    do {
        cout << "\tMenu.\n" << endl;
        cout << "1. Insertar nuevo nodo." << endl;
        cout << "2. Eliminar un nodo." << endl;
        cout << "3. Buscar nodo." << endl;
        cout << "4. Cantidad de nodos." << endl;
        cout << "5. Cantidad de nodos hoja." << endl;
        cout << "6. Altura del arbol." << endl;
        cout << "7. Mostrar arbol." << endl;
        cout << "8. Imprimir los valores (pre-orden)." << endl;
        cout << "9. Imprimir mayor valor del arbol." << endl;
        cout << "10. Borrar el nodo menor del arbol." << endl;
        cout << "11. Salir." << endl;

        cout << "\nDijite una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: 
            insertarNodo(dato);
            break;
        case 2:
            eliminarElemento(dato); 
            break;
        case 3:
            buscarNodo(dato);
            break;
        case 4:
            cantidadNodos(); 
            break;
        case 5:
            cantidadNodosHoja();
            break;
        case 6:
            alturaArbol();
            break;
        case 7:
            mostrarArbol();
            break;
        case 8:
            preOrden();
            break;
        case 9:
            nodoValorMayor();
            break;
        case 10:
            borrarNodoValorMenor();
            break;
        default:
            cout << "Opcion no encontrada." << endl;
            break;
        }
        system("cls");
    } while (opcion != 11);
}

void insertarNodo(int& dato) {
    cout << "\nINSERTAR NUEVO NODO -----\n\n ";

    cout << "Dijite un numero: ";
    cin >> dato;

    objArbol.insertarNodo(arbol, dato, NULL);
    cout << "\nNodo insertado." << endl;

    cout << endl;
    system("pause");
}

void eliminarElemento(int& dato) {
    cout << "\nELIMINAR UN ELEMENTO -----\n\n ";

    cout << "Dijite el elemento a eliminar: ";
    cin >> dato;

    objArbol.eliminar(arbol, dato);

    cout << endl;
    system("pause");
}

void buscarNodo(int& dato) {
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

void cantidadNodos() {
    cout << "\nCANTIDAD DE NODOS EN EL ARBOL -----\n\n ";
    cout << "La cantidad de nodos es: " << objArbol.contarNodos(arbol) << endl;

    cout << endl;
    system("pause");
}

void cantidadNodosHoja() {
    cout << "\nCANTIDAD DE NODOS HOJA EN EL ARBOL -----\n\n ";
    cout << "La cantidad de nodos hoja es: " << objArbol.contarNodosHoja(arbol) << endl;

    cout << endl;
    system("pause");
}

void alturaArbol() {
    cout << "\nLA ALTURA DEL ARBOL -----\n\n ";
    cout << "La altura del arbol es: " << objArbol.alturaArbol(arbol) << endl;

    cout << endl;
    system("pause");
}

void mostrarArbol() {
    int contador = 0;

    cout << "\nMOSTRAR ARBOL -----\n\n ";

    objArbol.mostarArbol(arbol, contador);

    cout << endl;
    system("pause");
}

void preOrden() {
    cout << "\nIMPRIMIR VALORES (PRE-ORDEN) -----\n\n ";

    objArbol.preOrden(arbol);

    cout << "\n" << endl;
    system("pause");
}

void nodoValorMayor() {
    cout << "\nIMPRIMIR MAYOR VALOR DEL ARBOL -----\n\n";
    cout << "El valor mayor del arbol es: " << objArbol.maximo(arbol)->getValor() << endl;

    cout << endl;
    system("pause");
}

void borrarNodoValorMenor(){
    cout << "\nBORRAR EL NODO MENOR DEL ARBOL -----\n\n";
    cout << "El nodo con el valor \"" << objArbol.minimo(arbol)->getValor() << "\" ah sido borrado." << endl;

    objArbol.eliminar(arbol, objArbol.minimo(arbol)->getValor());

    cout << endl;
    system("pause");
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