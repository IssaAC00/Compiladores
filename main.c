#include <stdio.h>
#include <stdlib.h>
#include "lexer.c"

// en terminal: echo 5+6|main.exe
int main(void){
    lexer();
    printf("Se leyeron %ld caracteres\n",caracteres_leidos);
    return 0;
}
