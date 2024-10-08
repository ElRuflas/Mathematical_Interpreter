
#include "errores.h"
#include <stdio.h>


void ERROR_ABRIR_ARCHIVO(){
    printf("Error al abrir el archivo\n");
}
void ERROR_LEXEMA_EN_BUFFER(){
    printf("Error con el lexema en el buffer\n");
}

void ERROR_CARACTER_NO_RECONOCIDO(int linea){
    printf("Linea %d \tCaracter no reconocido por el analziador lexico\n",linea);
}

void ERROR_NUMERO_BINARIO(int linea){
    printf("Linea %d \tError lexico: numero binario\n",linea);
}

void ERROR_NUMERO_OCTAL(int linea){
    printf("Linea %d \tError lexico: numero octal\n",linea);
}

void ERROR_NUMERO_HEXADECIMAL(int linea){
    printf("Linea %d \tError lexico: numero hexadecimal\n",linea);
}
void ERROR_NUMERO_FLOTANTE(int linea){
    printf("Linea %d \tError lexico: numero flotante\n",linea);
}

void ERROR_VARIABLE_NO_ASIGNADA(char* lexema){
    printf("ERROR SINTACTICO: variable %s no asignada\n",lexema);
}

void ERROR_FUNCION_INCORRECTA(char* lexema){
    printf("ERROR SINTACTICO: expresion incorrecta con la funcion %s\n",lexema);
}