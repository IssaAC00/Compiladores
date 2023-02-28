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
            printf("numero");
            break;
        }
    }
    printf("Se leyeron %ld caracteres\n",caracteres_leidos);
}

int main(void){
    calc();
    return 0;
}
