#include "pila.h"
#include <ctype.h>

int Expr(void);
int Term(void);
int Factor(void);
int Pot(void);


int Expr(void){
    if(Term()){ //Deriva en termino
        tipoToken tokenT = getToken();
        if(tokenT.token == suma || tokenT.token == resta){ 
            if(Expr()){ //Si el token es suma o resta, preguntamos si se puede producir una expresion otra vez    
                printf("%s ",tokenT.lexema);
                double v1 = pop();
                double v2 = pop();
                switch (tokenT.token)
                {
                case suma:
                    push(v1+v2);
                    break;
                case resta:
                    push(v2-v1);
                    break;
                }

                return 1;
            }
        }

        retToken(tokenT);
        return 1;
        
    }
    return 0;
}

int Term(void){
    if(Factor()){ //Deriva en factor
        tipoToken tokenT = getToken();
        if(tokenT.token == multiplicacion || tokenT.token == division){
            if(Term()){
                printf("%s ",tokenT.lexema);
                double v1 = pop();
                double v2 = pop();
                switch (tokenT.token)
                {
                case multiplicacion:
                    push(v1*v2);
                    break;
                case division:
                    push(v2/v1);
                    break;
                }

                return 1;
            }
        }
        retToken(tokenT);
        return 1;
    }
    return 0;
}

int Factor(void){
    tipoToken tokenT = getToken();
    if(tokenT.token == resta){
        if(Factor()){ //Deriva en factor?
          printf("%s ",tokenT.lexema);
          printf("pop: %lf",-pop());
          push(-pop()); //Simplemente cambiamos el signo y lo volvemos a meter a la pila
          return 1;
        }
    }
    if(tokenT.token == parentesis_izq){
        if(Expr()){ //Leemos otra expresion
            tipoToken tokenT = getToken();
            if(tokenT.token==parentesis_der){
               // printf("%s ",tokenT.lexema);
                return 1;
            }

        }
    }
    if(tokenT.token == numero){
        printf("%s ",tokenT.lexema);
        push(atof(tokenT.lexema));
        return 1;
    }
    return 0;
}