#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *data;
    int *p;
    data = (int*)malloc(100*sizeof(int));
    for(int i=0; i<100; i++){
        data[20]=*p;
    }
    free(data);
    for(int i=0; i<100; i++){
        printf(" %d", data[i]);
    }
    return 0;
}