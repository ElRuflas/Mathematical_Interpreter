# Makefile para compilar y ejecutar el programa

# Nombre del ejecutable
TARGET = ejecutable

# Compilador
CC = gcc

# Opciones del compilador
CFLAGS = -Wall

# Archivos fuente
SRCS = main.c BR_abin.c tabla_simbolos.c errores.c comandos.c lex.yy.c y.tab.c

# Archivos de encabezado
HEADERS = BR_abin.h tabla_simbolos.h errores.h comandos.h lex.yy.h y.tab.c

# Archivos generados por flex
FLEX_SRC = lex.yy.c

# Objetivo por defecto
all: bison_compile flex_compile compile

bison_compile:
	bison -yd anal_sint.y
# Compilar lex.yy.c usando flex
flex_compile:
	flex anal_lexico.l

# Compilar los archivos fuente y generar el ejecutable
compile: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) -lm


# Limpiar los archivos generados por la compilación
clean:
	rm -f $(TARGET)
