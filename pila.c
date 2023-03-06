//Funcionalidad de la pila

#include "pila.h"

tipoNodo *pila = NULL;

void push(double valor){
    tipoNodo *nuevo = malloc(sizeof(tipoNodo));
    nuevo->valor = valor;
    nuevo->siguiente = pila; 
    pila = nuevo;
}

double pop(void){
    tipoNodo *nodo = pila;
    if(nodo){
        pila = nodo->siguiente;
        double valor = nodo->valor;
        free(nodo);
        return valor;
    }

    return 0; 
}

