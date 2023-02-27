#include <stdio.h>
#include "lexer.h"

size_t caracteres_leidos = 0;


const size_t cantCaracteres = 25;
const size_t cantEstados = 18;
size_t estado = 0;

enum token lexer(void){
    char c;
    while ((c = getc(stdin))!=EOF)
    {
        caracteres_leidos++;
        putc(c,stdout);
    }
    return fin_de_archivo;
    
}