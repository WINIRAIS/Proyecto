#include <stdio.h>
#include "Map.c"

int main(*Map mapa){
    printf("Jugador >>  \n");

    char *ptr = 0;
    int ptrSize = 0;

    while(1){
        ptr = (char*) realloc (ptr , ptrSize + 1);
        int c = getchar();
        if(c == EOF ){
            ptr[ptrSize] = 0;
            break;
        }
        ptr[ptrSize] = (char)c;
        ptrSize++;
    }
    insertMap(mapa);
    printf("Cadena introducida: \n%s", ptr);
    
    return 0;
}