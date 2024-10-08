
#ifndef ANAL_LEXICO_BR_ABIN_H
#define ANAL_LEXICO_BR_ABIN_H

#define VARIABLE_NO_ASIGNADA 404

typedef double(*func_ptr)(double);
typedef double(*cmd_ptr)();
typedef double (*func_ptr2)(double,double);

union u{
  double val;
  func_ptr func;
  cmd_ptr cmd;
  func_ptr2 func2;
};

typedef struct{
    char* lexema; 
    int comp_lexico;
    union u valor;
} TIPOELEMENTOABB;


typedef struct TreeNode* nodo;


void crearArbol(nodo* root);

void buscarElemento(nodo root,char* lexema,int* identificador);

nodo insertarFunciones(nodo* root,TIPOELEMENTOABB info,nodo padre);

nodo guardarValor(nodo* root,char* lexema,double v,nodo padre);

void obtenerValor(nodo root,char* lexema,union u* valorObtenido);

void inorden(nodo root);

void print2D(nodo root);

void printVariables(nodo root);

void printFuncines(nodo root);

void destruirArbol(nodo* root);

#endif //ANAL_LEXICO_BR_ABIN_H
