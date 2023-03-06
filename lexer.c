#include <stdio.h>
#include "lexer.h"

/*Automata con todos los estados permitidos y sus respectivos estados de aceptación*/
																															
																															
																															
																															
	int automata [][30]={																														
		{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	3,	8,	9,	10,	11,	14,	12,	13,	6,	7,	15,	0,	0,	16,	17,	18,	19,	20,	21,	22},
		{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	2,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4},
		{2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4,	4},
		{2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	7,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	20,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	21,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	19,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	7,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	6,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
		{22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22,	22},
	};																														
															

int alfabeto [] = {'0', '1', '2', '3', '4', '5', '6','7','8','9','.','(',')','+','-','*','/','^','p','i','e',' ', '\t' , '\n','c', 'o', 's', 'n', 'x'};

const size_t cantCaracteres = 30;
const size_t cantEstados = 23;
size_t estadoAnterior = 0;

/*Busca el caracter en el alfabeto para  posteriormente relacionarlo con el automata*/
size_t columna(char c){
    size_t i;
    for (int i=0; i<cantCaracteres; i++){
        if (c ==alfabeto[i]){
            return i;
        }
    }

}


/* Funcion que hace la lectura e identificación de los tokens que entran por consola*/

tipoToken getToken(void){
    char c;
    size_t estado = 0;
    size_t estadotem = 0;
    tipoToken tokenT;
    tokenT.lexemaLen = 0;
    while ((c = getc(stdin))!=EOF)
    {
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
            estadoAnterior = 15;
            return tokenT;
        case 6: //p
            if (estadoAnterior==21){
                estadoAnterior = 0;
                tokenT.token = exp;
                return tokenT;
            }
            estadoAnterior = 6;
            break;
        case 7: // i de pi
            if(estadoAnterior==6){
                estadoAnterior = 0;
                tokenT.token = pi;
                return tokenT;
            }
            if (estadoAnterior==19){ // i de seno
                estadoAnterior = 19;
                break;
            }
            else{// i de logaritmo
                estadoAnterior = 7;
                break;
            }
        case 17: //c
            estadoAnterior = 17;
            break;
        case 18://o
            if (estadoAnterior==17){
                estadoAnterior = 18;
                printf("se tomada\n");
                break;
            }
            else {
                ungetc(c,stdin);
                printf("error despues de la c\n");
                tokenT.token = error;
                return tokenT;
            }
        case 19: //s
           if(estadoAnterior==18){
                estadoAnterior = 0;
                tokenT.token = coseno;
                printf("se toma el s bien\n");
                return tokenT;
            }
            else{ //s de seno 
                estadoAnterior = 19;
                printf("S de seno\n");
                break;
            }
        case 20://n de seno
            if (estadoAnterior==19){
                estadoAnterior = 0;
                tokenT.token = seno;
                return tokenT;
            }
            if(estadoAnterior==7){ // n de logaritmo
                estadoAnterior = 0;
                tokenT.token = logaritmo;
                return tokenT;
            }
            else{ 
                ungetc(c,stdin);
                printf("error despues de la c\n");
                tokenT.token = error;
                return tokenT;
            }
        case 16:
           tokenT.token = fin_de_linea;
           return tokenT;
        case 21:
            if(estadoAnterior==15){ 
                estadoAnterior = 21;
                break;
            }
            else {
                ungetc(c,stdin);
                printf("error despues de la c\n");
                tokenT.token = error;
                return tokenT;
            }

        case 22:
            tokenT.token = error;
            return tokenT;
       
        }
    }

    tokenT.token = fin_de_archivo;
    tokenT.lexema[tokenT.lexemaLen] = '\0';
    return tokenT;
    
}

//Devuelve el token al teclado
void retToken(tipoToken tokenT){
    //printf("Tam lexema: %ld\n",tokenT.lexemaLen);
    //printf("Lexema: %s\n",tokenT.lexema);
    for(long i = tokenT.lexemaLen-1;i>=0;i--){
        ungetc(tokenT.lexema[i],stdin);
    }
}