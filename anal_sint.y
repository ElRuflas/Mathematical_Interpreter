%{
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.h"
#include "tabla_simbolos.h"
#include "comandos.h"
void yyerror (char *s);
union u uni;
%}

%union {
    double num;
    char* id;
}
%token<num> NUMERO
%token<id> ID COMMAND FUNC FUNC2 CONST;

%type<num> line exp term cmmd fnc;

%start line


%left '+' '-'
%left '*' '/'
%precedence NEG
%right '='

%% /* A continuación las reglas gramaticales y las acciones */

line:   asign ';'           {;}
|       exp ';'		        {if(getecho())printf("%.2lf\n",$1);}
|	    cmmd ';'	        {;}
|       fnc  ';'            {if(getecho())printf("%.2lf\n",$1);}
|	    line exp ';'	    {if(getecho())printf("%.2lf\n",$2);}
|       line asign ';'	    {;}
|       line cmmd ';'	    {;}
|       line fnc ';'        {if(getecho())printf("%.2lf\n",$2);}
	    ;

asign: ID '=' exp           {asignarValor($1,$3);free($1);}
|       ID '=' fnc           {asignarValor($1,$3);free($1);}
        ;

exp: term { $$ = $1; }

|	exp '+' exp {$$ = $1 + $3;} 
|	exp '-' exp {$$ = $1 - $3;} 
|	exp '*' exp {$$ = $1 * $3;} 
|	exp '/' exp {$$ = $1 / $3;}
|   '-' exp  %prec NEG { $$ = -$2;}
|	'(' exp ')' {$$ = $2;}
    ;

term:   NUMERO  { $$ = $1;}
|       CONST      { $$ = extraerValor($1).val; free(yylval.id);}
|       ID      { $$ = extraerValor($1).val; free(yylval.id);}
        ;


cmmd:   COMMAND {uni = extraerValor($1); (*uni.cmd)();free(yylval.id);}
        ;

fnc:    FUNC '(' exp ')' {uni=extraerValor($1); $$=(*uni.func)($3); free($1);}
|       FUNC '(' fnc ')' {uni=extraerValor($1); $$=(*uni.func)($3); free($1);}
|       FUNC2 '(' exp ',' exp ')' {uni=extraerValor($1); $$=(*uni.func2)($3,$5); free($1);}
        ;

%%

void yyerror(char *s) {
    fprintf(stderr,"%s\n",s);
}