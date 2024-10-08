//
// Created by david on 29/03/24.
//


#ifndef FLEX_LEXICO_LEX_YY_H
#define FLEX_LEXICO_LEX_YY_H

int yylex();
int yylex_destroy ( void );
void abrirArchivo(char *nombreArchivo);
void destruirFlex();

#endif //FLEX_LEXICO_LEX_YY_H
