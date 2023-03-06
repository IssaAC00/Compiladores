//HEADER que crea la estructura de una pila

#ifndef _PILA_
#define _PILA_

#include <stdlib.h>
#include "lexer.h"

struct nodo{
    double valor;
    struct nodo *siguiente;
};

typedef struct nodo tipoNodo;

extern tipoNodo *pila;
extern void push(double valor);
extern double pop(void);


#endif