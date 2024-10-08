#include "tabla_simbolos.h"
#include "comandos.h"
#include "y.tab.h"
#include <stdlib.h>
#include<stdio.h>
#include <math.h> /* Para funciones matemáticas, cos(), sin(), etc*/
#include "errores.h"

#define PI 3.1415
#define E 2.71828
struct tabla{
    nodo root;
};

struct tabla* TABLA;


void crearTS(){
    TABLA = (struct tabla*)malloc(sizeof(struct tabla));
    if(TABLA == NULL){
        printf("Error en la reserva de memoria de la tabla de simbolos\n");
        exit(EXIT_FAILURE);
    }
    crearArbol(&TABLA->root);

    TIPOELEMENTOABB funciones[] = {
            {"PI", CONST, {.val = PI}},
            {"E", CONST, {.val = E}},
        {"cos", FUNC, {.func=cos}},
        {"sin", FUNC, {.func=sin}},
        {"log", FUNC, {.func=log}},
        {"sqrt", FUNC, {.func=sqrt}},
        {"log10", FUNC, {.func=log10}},
        {"floor", FUNC, {.func=floor}},
        {"ceil", FUNC, {.func=ceil}},
        {"fabs", FUNC, {.func=fabs}},
        {"tan", FUNC, {.func=tan}},
        {"pow", FUNC2, {.func2=pow}},
        {"fmod", FUNC2, {.func2=fmod}},
        {"help", COMMAND, {.cmd=help}},
        {"quit", COMMAND, {.cmd=salir}},
        {"workspace", COMMAND, {.cmd=workspace}},
        {"clear", COMMAND, {.cmd=clear}},
        {"load", COMMAND, {.cmd=load}},
        {"echo", COMMAND, {.cmd=echo}}
    };
    //añadimos las keywords a la Tabla de Simbolos
    int n = sizeof(funciones)/ sizeof(funciones[0]);
    for (int i = 0; i < n; ++i) {
        TABLA->root = insertarFunciones(&TABLA->root, funciones[i], NULL);
    }
}

void asignarValor(char* variable,double valor){
    TABLA->root = guardarValor(&TABLA->root,variable,valor,NULL);
}

union u extraerValor(char* variable){
    union u ans;
    obtenerValor(TABLA->root,variable,&ans);
    if(ans.val == VARIABLE_NO_ASIGNADA){
        ERROR_VARIABLE_NO_ASIGNADA(variable);
    }
    return ans;
}

int consultarTabla(char* lexema){
    int cmp_lexico=ID;
    buscarElemento(TABLA->root,lexema,&cmp_lexico);
    return cmp_lexico;
}

void mostrarWorkplace(){
    printVariables(TABLA->root);
}

void mostrarFunciones(){
    printFuncines(TABLA->root);
}

//muestra la tabla de 2 formas diferentes
void mostrarTabla(){
    printf("\n------------INORDEN------------------\n");
    inorden(TABLA->root);
    printf("\n------------------------------\n");
    printf("\n--------------ARBOL2D----------------\n");
    print2D(TABLA->root);
    printf("\n------------------------------\n");
}

//liberar memoria
void destruirTS(){
    destruirArbol(&(TABLA->root));
    free(TABLA);
    TABLA = NULL;
}