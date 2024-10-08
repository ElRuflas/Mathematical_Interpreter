#include "BR_abin.h"
#ifndef ANAL_LEXICO_TABLA_SIMBOLOS_H
#define ANAL_LEXICO_TABLA_SIMBOLOS_H


void crearTS();

int consultarTabla(char* lexema);

void asignarValor(char* variable,double valor);

union u extraerValor(char* variable);

void mostrarTabla();

void mostrarWorkplace();

void mostrarFunciones();

void destruirTS();

#endif //ANAL_LEXICO_TABLA_SIMBOLOS_H