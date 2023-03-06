#include <stdio.h>
#include <stdlib.h>
#include "lexer.c"
#include "parser.c"
#include "pila.c"

// en terminal: echo 5+6|main.exe
/*Con ayuda del lexer analiza la cadena que entra por cosola */

extern int Expr(void);

int calc(void){
    // tipoToken tokenT;
    // while ((tokenT = getToken()).token != fin_de_archivo){
    //     switch (tokenT.token)
    //     {
    //     case numero:
    //        printf("numero %s\n",tokenT.lexema);
    //         break;

    //     case suma:
    //         printf("suma\n");
    //         break;
        
    //     case resta:
    //         printf("resta\n");
    //         break;
        
    //     case multiplicacion:
    //         printf("multi\n");
    //         break;
        
    //     case parentesis_izq:
    //         printf("(\n");
    //         break;

    //     case parentesis_der:
    //         printf(")\n");
    //         break;

    //     case division:
    //         printf("div\n");
    //         break;
    //     case potencia:
    //         printf("potencia\n");
    //         break;
    //     case error:
    //         printf("error\n");
    //         break;
    //     case e:
    //         printf("e\n");
    //     case fin_de_linea:
    //         printf("Fin linea\n");
    //         exit (-1);
    //         break;
    //     case pi:
    //         printf("pi\n");
    //         break;

    //     case fin_de_archivo:
    //         printf("Fin archivo\n");
    //         break;
    //     }

        
    // }

    if(Expr()){
        printf("\nResultado: %lf\n",pop());

    }
    else{
        printf("no salio bien");
    }
   // printf("Se leyeron %ld caracteres\n",caracteres_leidos);
}

int main(void){
    //printf("Ingrese una expresion: ");
    calc();
    return 0;
}
