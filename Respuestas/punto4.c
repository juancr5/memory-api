#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
* main -  programa que use cierta cantidad de memoria, llamado memory-user.c.
* Este programa debe tomar un argumento por linea de comandos: el número de megabytes
* de memoria que usted usará. Cuando lo ejecute, el programa debe separar memoria para
* un arreglo (vector) y recorrer el arreglo, accediendo consecutivamente a cada entrada
* (por ejemplo, escribiendo un valor inicial a cada posición). El programa deberá hacer
* esto indefinidamente o, por lo menos, por una cierta cantidad de tiempo especificada
* también por línea de comandos
* @argc: contador de argumentos
* @argv: vector de argumentos
* Return: 0 éxito -1 si falla
*/
int main(int argc, char *argv[])
{
        int tiempo;
        int cantidadMem;  /* stack */
        char *vector;

        if(argc < 4 && argc > 1)
        {

                cantidadMem = (atoi(argv[1]))*1e6;  /* cantidad de memoria en Mb */
                char *vector = malloc(cantidadMem);  /* disposición dinámica en el heap */
                if(vector == NULL)
                {
                        printf("Fallo en memoria\n");
                        return (-1);
                }
                else
                {
                        if(argc == 2)
                        {
                                while(1==1) /* Infitnito */
                                {
                                        for(long i = 0; i < cantidadMem; i++)
                                        {
                                                vector[i] = i;
                                        }
                                }
                        }
                        else if(argc == 3)
                        {
                                time_t inicio = time(0);
                                tiempo = (atoi(argv[2]));
                                while(time(0)-inicio < tiempo)
                                {
                                        for(long i = 0; i<cantidadMem; i++)
                                        {
                                                vector[i] = i;
                                        }
                                }
                        }
                }
        }
        else
        {
                printf("Parametros inadecuados, ingreso 2 ó 3 parametros \n");
        }

        return 0;
}
