#include <stdio.h>
#include <stdlib.h>
#include "lexer.c"

// en terminal: echo 5+6|main.exe

int calc(void){
    token_t token;
    while ((token = lexer()) != fin_de_archivo){
        switch (token)
        {
        case numero:
            printf("numero\n");
            break;

        case suma:
            printf("suma\n");
            break;
        
        case resta:
            printf("resta\n");
            break;
        
        case multiplicacion:
            printf("multi\n");
            break;
        
        case parentesis_izq:
            printf("(\n");
            break;

        case parentesis_der:
            printf(")\n");
            break;

        case division:
            printf("div\n");
            break;
        case potencia:
            printf("potencia\n");
            break;
        case error:
            printf("error\n");
            break;
        case e:
            printf("e\n");
        case fin_de_linea:
            printf("Fin linea\n");
            break;
        case pi:
            printf("pi\n");
            break;

        case fin_de_archivo:
            printf("Fin archivo\n");
            break;
        }

        
    }
   // printf("Se leyeron %ld caracteres\n",caracteres_leidos);
}

int main(void){
    calc();
    return 0;
}
