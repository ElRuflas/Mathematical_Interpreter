## Requisitos

- Flex (para generar el analizador léxico)
- GCC (para compilar el código)
- Bison

## Compilación y Ejecución

1. Clona o descarga este repositorio en tu máquina.

2. Abre una terminal y navega hasta el directorio donde se encuentra el código fuente.

3. Para compilar el programa el programa, simplemente ejecuta el comando (da permisos si es necesario con chmod):

make

4.Para ejecutar:

./ejecutable

5. Para limpiar los archivos generados por la compilación, utiliza el comando:

make clean


FUNCIONAMIENTO:
El codigo es un interprete matemático capaz de calcular expresiones matemáticas, además puede utilizar funciones matemáticas de la librería math.h de c.
Para ejecutar expresiones, comandos o funciones es importante que la línea acabe en ';' para que no de error de sintaxis.
El código cuenta con una serie de comandos que afectan al comportamiento del interprete, para saber mas ejecutar el programa y teclear: help; . Con esto saldrá toda la información del intérprete.
El interprete muestra en cada linea el resultado del cálculo, es decir, si se pone 4+2; se mostrará 6, sin embargo en las asignaciones no se muestra el valor. Es decir x = 4; no muestra nada.
Para ver el valor de una variable escribir el nombre de la variable seguido de ';'. Ejemplo:  x;

Nota: 
Para la función load (carga un archivo), primero escribir el comanado con ';' -> load;
Luego pedirá un archivo. Escribir el nombre del archivo sin ';'.
Ejemplo:
load;
archivo.txt

