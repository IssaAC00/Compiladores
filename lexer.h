#ifndef _LEXER_
#define _LEXER_
#include <stdio.h>
#define LenCadena 60

enum token {numero, suma, resta, multiplicacion,division,potencia,pi,e,logaritmo,seno,coseno,
exp,parentesis_izq,parentesis_der,fin_de_archivo,error, fin_de_linea};

//Nos sirve para ver como está estructurado el token
struct tokenStruct{
    char lexema[LenCadena];
    size_t lexemaLen;
    enum token token;
};


typedef struct tokenStruct tipoToken;
typedef enum token token_t;


extern tipoToken getToken(void);
extern void retToken(tipoToken tokenT);


#endif