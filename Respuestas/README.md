## Realizado por: Andres Alvarez & Juan Camilo Rojas ## 

# Memory API # 

En este laboratorio ganará algún grado de familiaridad con la asignación de memoria (memory allocation). Para el caso, ustedd escribirá algunos programas con bugs. Luego, usará algunas herramientas para localizar los bugs que usted ha insertado. De este modo se familiarizará con algunas de estas herramientas para un uso futuro. Estas herramientas son: el debuger (**gdb**) y el memory-bug detector (**valgrind**).

## Questions ##

1. Escriba un programa simple llamado ```null.c``` que cree un puntero a un entero, llevelo a null y entonces intente desreferenciarlo (esto es, asignarle un valor). Compile este programa llamado ```null```. ¿Qué pasa cuando usted ejecuta este programa?.

- El codigo es el siguiente: [null.c](https://github.com/juancr5/memory-api/blob/master/Respuestas/null.c)
- Al ejecutar null.c la salida presentada fue:

![alt tag](https://github.com/juancr5/memory-api/blob/master/Respuestas/Imagenes/01%20null.c.png)


2. Compile el programa del ejercicio anterior usando información de simbolos (con la flag -g). Al hacer esto se esta poniendo mas informacion en el ejecutable para permitir al debugger acceder a informacion util sobre los nombres de las variables y cosas similares. Ejecute el programa bajo el debugger digitando en consola (para el caso) ```gdb null``` y entonces una vez el ```gdb``` este corriendo ejecute ```run```. ¿Qué muestra gdb?

- El programa recibió una señal SIGSEGV, es decir una Violación de Segmento.
- La linea que hace referencia esta en la 10

![alt tag](https://github.com/juancr5/memory-api/blob/master/Respuestas/Imagenes/02%20gdb%20run.png)

3. Haga uso de la herramienta ```valgrind``` en el programa empleado en los puntos anteriores. Se usará la herramienta ```memcheck``` que es parte de ```valgrind``` para analizar lo que pasa: ``` valgrind --leak-check=yes null```. ¿Qué pasa cuando corre esto?, Â¿Puede usted interpretar la salida de la herramienta anterior?

- En este caso podemos observar la herramienta memcheck detectó una escritura inválida de tamaño 4 bytes en la línea 8 del archivo 

![alt tag](https://github.com/juancr5/memory-api/blob/master/Respuestas/Imagenes/03%20valgrind%20memcheck.png)

4. Escriba un programa sencillo que asigne memoria usando ```malloc()``` pero olvide liberarla antes de que el programa termina. ¿Qué pasa cuando este programa se ejecuta?, ¿Puede usted usar gdb para encontrar problemas como este?, ¿Que dice acerca de Valgrind (de nuevo use este con la bandera ```--leak check=yes```)?

-El codigo es el siguiente: [punto4.c](https://github.com/juancr5/memory-api/blob/master/Respuestas/punto4.c)
-Al ejecutar punto4.c la salida presentada con vagrind fue:

![alt tag](https://github.com/juancr5/memory-api/blob/master/Respuestas/Imagenes/04%20valgrind.png)

-Donde se muestra que se hicieron 2 allocs y 1 Free es decir que falto desasignar el espacio de memoria asignada por la llamada a malloc.

-Al usar el GDB la salida fue la siguiente:

![alt tag](https://github.com/juancr5/memory-api/blob/master/Respuestas/Imagenes/04%20gdb.png)

-Al usar la bandera ```--leak check=yes``` se presenta lo siguiente: 

![alt tag](https://github.com/juancr5/memory-api/blob/master/Respuestas/Imagenes/04%20tool.png)

5. Escriba un programa que cree un array de enteros llamado data de un tamaño de 100 usando ```malloc```; entonces, lleve el ```data[100]``` a ```0```. ¿Qué pasa cuando este programa se ejecuta?, ¿Qué pasa cuando se corre el programa usando ```valgrind```?, ¿El programa es correcto?

-El codigo planteado para resolver el ejercicio es: [punto5.c](https://github.com/juancr5/memory-api/blob/master/Respuestas/punto5.c).

-En el momento de llevar el arreglo a 0 se presento esto.

6. Codifique un programa que asigne un array de enteros (como arriba), luego lo libere, y entonces intente imprimir el valor de un elemento del array. ¿El programa corre?, ¿Que pasa cuando hace uso de ```valgrind```?

-El codigo planteado para este ejemplo: [punto6.c](https://github.com/juancr5/memory-api/blob/master/Respuestas/punto6.c).
-Al ejecutar punto5.c liberando la memoria asignada por malloc; la salida presentada haciendo uso del Valgrind fue la siguiente:

![alt tag](https://github.com/juancr5/memory-api/blob/master/Respuestas/Imagenes/06%20Free.png)

-Donde no se presento ningun error.

-Despues se libero la memoria haciendo uso de free al llevar el vector a 0, la salida presentada muestra el siguiente error:
-ERROR SUMMARY: 100 errors from 1 contexts (suppressed: 0 from 0).

![alt tag](https://github.com/juancr5/memory-api/blob/master/Respuestas/Imagenes/06%20No%20Free.png

7. Ahora pase un **funny value** para liberar (e.g. un puntero en la mitad del array que usted ha asignado) ¿Qué pasa?, ¿Ústed necesita herramientas para encontrar este tipo de problemas?

-Al pasar un funny value en el codigo: [punto7.c]((https://github.com/juancr5/memory-api/blob/master/Respuestas/punto7.c).

- Al ejecutar el codigo normalmente se presento un error de violacion de segmento y con la herramienta valgrind se mostraron mas errores de lo habitual. pero si necesitaramos usar otra herramienta para encontrar problemas usariamos el PurifyPlus que es otra herramienta para hacer debugger 

![alt tag](https://github.com/juancr5/memory-api/blob/master/Respuestas/Imagenes/07%20Tools.png)

9. Gaste mas tiempo y lea sobre el uso de gdb y valgrind. Conocer estas herramientas es critico; gaste el tiempo y aprenda como volverse un experto debugger en UNIX y C enviroment.

## Eso Es Justamente Lo Que Haremos ## 
