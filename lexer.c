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
	{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
	{17,17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17,	17},
};																									

int alfabeto [] = {'0', '1', '2', '3', '4', '5', '6','7','8','9','.','(',')','+','-','*','/','^','p','i','e',' ', '\t' , '\n'};

const size_t cantCaracteres = 25;
const size_t cantEstados = 18;


/* Funcion que hace la lectura e identificación de los tokens que entran por consola*/

enum token lexer(void){
    char c;
    char p;
    size_t estado = 0;
    size_t estadotem = 0;
    while ((c = getc(stdin))!=EOF)
    {
        caracteres_leidos++;
        estado = automata[estado][columna(c)];
        switch (estado)
        {
        case 4:
            ungetc(c,stdin);
            return numero;
         case 5:
            ungetc(c,stdin);
            return error;
         case 8:
            return parentesis_izq;
        case 9:
            return parentesis_der;
        case 10:
            return suma;
        case 11:           
            return resta;
        case 12:
            return division;
        case 13:
            return potencia;
        case 14:
            return multiplicacion;
        case 15:
            return e;
        case 6:
            p = getc(stdin);
            estadotem = automata[estado][columna(p)];
            if (estadotem == 7)
                return pi;
            else:
                ungetc(c,stdin);
                return error;
        case 7:
            ungetc(c,stdin);
            return error;
        case 16:
            return fin_de_linea;
        case 17:
            return error;
       
        }
    }
    return fin_de_archivo;
    
}