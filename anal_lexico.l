%{
#include <string.h>
#include "tabla_simbolos.h"
#include "errores.h"
#include "y.tab.h"
%}


/*DEFINICIONES BASICAS*/
LETRA [a-zA-Z]
DIGIT [0-9]



/*ESPACIOS*/
ESPACIOS [ \t\n]+


/*IDENTIFICADORES*/
IDENTIFICADOR ({LETRA}|\_)(({LETRA}|{DIGIT}|\_)*)

INTEGER {DIGIT}+
FLOAT {DIGIT}*\.{INTEGER}

NUM {INTEGER}|{FLOAT}



%%

{ESPACIOS} { /* Ignorar espacios en blanco y saltos de línea */ }
[-+=\*\/;\(\),]                 {return yytext[0];}
{NUM} {yylval.num = atof(yytext);return NUMERO;}
{IDENTIFICADOR} {yylval.id=strdup(yytext); return consultarTabla(yytext);}
%%

int yywrap (void) {
    yyin = stdin;
    return 0;
}


//abrir archivo
void abrirArchivo(char *archivo){
    FILE *fp;
    fp = fopen(archivo, "r");
    if(fp != NULL){
        yyin = fp;   
    }else{
        ERROR_ABRIR_ARCHIVO();
    }
}


//cerrar archivo
void destruirFlex(){
    fclose(yyin);
    yylex_destroy();
}
