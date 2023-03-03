#include "lexer.h"

int Expr(void);
int Term(void);
int Factor(void);
int Pot(void);


int Expr(void){
    if(Term()){ //Deriva en termino
        tipoToken tokenT = getToken();
        if(tokenT.token == suma || tokenT.token == resta){ 
            if(Expr()){ //Si el token es suma o resta, preguntamos si se puede producir una expresion otra vez
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
    if(tokenT.token == potencia){
        if(Factor()){ //Deriva en factor?
            return 1;
        }
    }
    if(tokenT.token == parentesis_izq){
        if(Expr()){ //Leemos otra expresion
            tipoToken tokenT = getToken();
            if(tokenT.token==parentesis_der){
                return 1;
            }

        }
    }
    if(tokenT.token == numero){
        return 1;
    }
    return 0;
}