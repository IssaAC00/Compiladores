#include "pila.h"
#include <ctype.h>
#include <math.h>

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

    if(Pot()){
        tipoToken tokenT = getToken();
        if(tokenT.token == potencia){
            if(Factor()){
                printf("%s ",tokenT.lexema);
                double v1 = pop();
                double v2 = pop();
                push(pow(v1,v2));

                return 1;               
            }
        }
        retToken(tokenT);
        return 1;
    }
    return 0;

}

int Pot(void){
    tipoToken tokenT = getToken(); 

    if(tokenT.token == seno){
        if(Expr()){
            printf("%s ",tokenT.lexema);
            double v1 = pop();
            push(sin(v1));
            return 1;

        }
    }
    if(tokenT.token == coseno){
        if(Expr()){
            printf("%s ",tokenT.lexema);
            double v1 = pop();
            push(cos(v1));
            return 1;

        }
    }

    if(tokenT.token == logaritmo){
        if(Expr()){
            printf("%s ",tokenT.lexema);
            double v1 = pop();
            push(log10(v1));
            return 1;

        }
    }

    if(tokenT.token == expo){
        if(Expr()){
            printf("%s ",tokenT.lexema);
            double v1 = pop();
            push(exp(v1));
            return 1;

        }
    }

    if(tokenT.token == resta){
        if(Factor()){ //Deriva en factor?
          printf("%s ",tokenT.lexema);
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

    if(tokenT.token == pi){
        printf("3.14 ");
        push(3.1416);
        return 1;
    }
    if(tokenT.token == e){
        printf("2.71828 ");
        push(2.71828);
        return 1;
    }
    return 0;
}