//
// Created by david on 10/04/24.
//

#include "comandos.h"
#include <stdio.h>
#include "tabla_simbolos.h"
#include "lex.yy.h"
#include <stdlib.h>
#include "y.tab.h"
#define MAX_FILE_LEN 50
int echo_control = 1;
double help(){
    printf("\n\nINTERPRETE MATEMATICO\n--------------------------\n\n");
    printf("Comportamiento:\n-Cada sentecia debe acabar en ';'. ej: 4*3;\n-Los comandos no usan parentesis. ej: echo;\n");
    printf("\nFunciones del sistema :\n");
    printf("quit     : sale.\n");
    printf("help     : ayuda sobre el sistema en general.\n");
    printf("workspace: muestra todas las variables y su contenido.\n");
    printf("clear    : destruye el espacio de trabajo.\n");
    printf("echo     : variable de estado que hace que se impriman las cosas o no.\n");
    printf("load     : carga script guardado en un fichero.\n");
    printf("\nFunciones matemáticas:\n");
    mostrarFunciones();
    return 0;
}

double salir(){
    destruirFlex();
    mostrarTabla();
    destruirTS();
    exit(EXIT_SUCCESS);
}

double workspace(){
    printf("\n\n--------VARIABLES ACTUALES:--------\n\n");
    printf("\tNOMBRE\t|\tVALOR\n\n-----------------------------------\n\n");
    mostrarWorkplace();
    printf("\n-----------------------------------\n\n");
    return 0;
}

double clear(){
    destruirTS();
    crearTS();
    printf("\n---------WORKSPACE BORRADO---------\n");
    return 0;
}

double load(){
    char fp[MAX_FILE_LEN];
    printf("Introduce Nombre archivo: ");
    scanf(" %s",fp);
    abrirArchivo(fp);
    return 0;
}


double echo(){
    if(echo_control){
        echo_control = 0;
        printf("ECHO DESACTIVADO\n");
    }else{
        echo_control = 1;
        printf("ECHO ACTIVADO\n");
    }
    return 0;
}

int getecho(){
    return echo_control;
}