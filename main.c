#include "tabla_simbolos.h"
#include "y.tab.h"
int main() {

    crearTS();
    mostrarTabla();
    yyparse();
}
