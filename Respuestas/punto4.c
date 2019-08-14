
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int memory = atoi(argv[1]) * 1E6;
    int time = atoi(argv[2]);
    printf("Memoria separada = %p Megas\n", argv[1]);
    char *p = malloc(memory);

    clock_t time_t;
    time_t = clock();
    while ((clock() - time_t) / CLOCKS_PER_SEC < time)
    {
        for (int i = 0; i < memory; i++)
        {
            p[i] = 0;
        }
    }
    return 0;
}