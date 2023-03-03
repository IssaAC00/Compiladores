#include <stdio.h>
#include "lexer.h"

size_t caracteres_leidos = 0;

int automata [][25] ={																									
	{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	3,	8,	9,	10,	11,	14,	12,	13,	6,	7,	15,	0,	0,	16,	17},
	{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	2,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4},
	{2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4},
	{2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	7,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{17,17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17},
};																									

int alfabeto [] = {'0', '1', '2', '3', '4', '5', '6','7','8','9','.','(',')','+','-','*','/','^','p','i','e',' ', '\t' , '\n'};

const size_t cantCaracteres = 25;
const size_t cantEstados = 18;
size_t estadoAnterior = 0;

size_t columna(char c){
    size_t i;
    for (int i=0; i<cantCaracteres; i++){
        if (c ==alfabeto[i]){
            return i;
        }
    }

}


/* Funcion que hace la lectura e identificación de los tokens que entran por consola*/

tipoToken lexer(void){
    char c;
    char p;
    size_t estado = 0;
    size_t estadotem = 0;
    tipoToken tokenT;
    tokenT.lexemaLen = 0;
    while ((c = getc(stdin))!=EOF)
    {
        caracteres_leidos++;
        tokenT.lexema[tokenT.lexemaLen++] = c;
        tokenT.lexema[tokenT.lexemaLen] = '\0';
        estado = automata[estado][columna(c)];
       // printf("C: %ld \n",c);
       // printf("Estado: %ld \n",estado);
        switch (estado)
        {
        case 4:
            ungetc(c,stdin);
            tokenT.token = numero;
            tokenT.lexema[--tokenT.lexemaLen] = '\0';
            return tokenT;
         case 5:
            ungetc(c,stdin);
            tokenT.token = error;
            tokenT.lexema[--tokenT.lexemaLen] = '\0';
            return tokenT;
         case 8:
            tokenT.token = parentesis_izq;
            return tokenT;
            
        case 9:
            tokenT.token = parentesis_der;
            return tokenT;
        case 10:
            tokenT.token = suma;
            return tokenT;
        case 11:           
            tokenT.token = resta;
            return tokenT;
        case 12:
            tokenT.token = division;
            return tokenT;
        case 13:
            tokenT.token = potencia;
            return tokenT;
        case 14:
            tokenT.token = multiplicacion;
            return tokenT;
        case 15:
            tokenT.token = e;
            return tokenT;
        case 6: //p
            estadoAnterior = 6;
            break;
        case 7:
            if(estadoAnterior==6){
                estadoAnterior = 0;
                tokenT.token = pi;
                return tokenT;
            }
            else{
                ungetc(c,stdin);
                tokenT.token = error;
                return tokenT;
            }

        case 16:
           tokenT.token = fin_de_linea;
           return tokenT;
        case 17:
            tokenT.token = error;
            return tokenT;
       
        }
    }

    tokenT.token = fin_de_archivo;
    tokenT.lexema[tokenT.lexemaLen] = '\0';
    return tokenT;
    
}