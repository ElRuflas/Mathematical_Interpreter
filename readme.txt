# Intérprete Matemático

Este proyecto es un intérprete matemático escrito en C, capaz de evaluar expresiones matemáticas, incluidas funciones de la librería estándar `math.h`. Además, el intérprete cuenta con varios comandos que permiten modificar su comportamiento y cargar archivos de expresiones.

## Requisitos

- **Flex** (para generar el analizador léxico)
- **Bison** (para generar el analizador sintáctico)
- **GCC** (para compilar el código)

## Compilación y Ejecución

1. Clona o descarga este repositorio en tu máquina:

   ```bash
   git clone https://github.com/usuario/repo.git
   cd repo
   ```

2. Abre una terminal y navega hasta el directorio donde se encuentra el código fuente.

3. Para compilar el programa, ejecuta el siguiente comando (si es necesario, da permisos con `chmod`):

   ```bash
   make
   ```

4. Para ejecutar el programa:

   ```bash
   ./ejecutable
   ```

5. Para limpiar los archivos generados durante la compilación, utiliza:

   ```bash
   make clean
   ```

## Funcionamiento

El intérprete permite evaluar expresiones matemáticas y utilizar funciones de la librería `math.h` de C. Para ejecutar expresiones, comandos o funciones, es importante que la línea termine con un `;` para evitar errores de sintaxis.

- El intérprete muestra el resultado de los cálculos en cada línea. Por ejemplo, si introduces `4 + 2;`, se mostrará `6`.
- En las asignaciones de variables, no se muestra el valor. Por ejemplo, `x = 4;` no mostrará nada.
- Para ver el valor de una variable, simplemente escribe el nombre de la variable seguido de `;`. Ejemplo:

   ```bash
   x;
   ```

### Comandos

El intérprete cuenta con una serie de comandos que afectan su comportamiento. Para obtener más información sobre los comandos disponibles, puedes ejecutar el programa y escribir:

```bash
help;
```

Esto mostrará toda la información necesaria para utilizar el intérprete correctamente.

### Nota sobre el Comando `load`

El comando `load` permite cargar un archivo que contiene expresiones para ser evaluadas por el intérprete. Para usar este comando:

1. Escribe el comando seguido de `;`:

   ```bash
   load;
   ```

2. Luego, el intérprete te pedirá el nombre del archivo (sin `;` al final):

   ```bash
   archivo.txt
   ```

## Ejemplo de Uso

```bash
> 4 + 2;
6
> x = 10;
> x;
10
```

