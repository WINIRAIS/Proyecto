#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Map.c"
#include  <stdbool.h>
#include "list_answer.c"

typedef struct 
{
    char valor;
    char simbolo;
    int ass;
    char pinta;
}valores;

typedef struct 
{
    char *nombre;
    int dinero;
    List *cartas;
}datosJugadores;

int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}

int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}

void chomp(char *s) {
    while(*s && *s != '\n' && *s != '\r') s++;
    *s = 0;
}

void nombre_y_dinero(Map *mapa, datosJugadores *new){
    new = (datosJugadores*)malloc(sizeof(datosJugadores));
    new->nombre = (char*)calloc(100,sizeof(char));

    fflush(stdin);
    fgets(new->nombre, 100, stdin);
    chomp(new->nombre);

    printf("\nIngrese Dinero Disponible\n\n>> ");
    scanf("%d", &new->dinero);

    insertMap(mapa,new->nombre, new);
    free(new);  
    return;
}

void llenarDatos (Map * mapa){
    datosJugadores *datos;
    int opc,i;
    printf("\nIngrese Cantidad de Jugadores\n>> ");
    scanf("%d", &opc);
    printf("\n\nIngrese Nombre de Jugadores\n\n");
    for(i = 0 ; i < opc ; i++){
        printf("JUGADOR %d >> ", i+1);
        nombre_y_dinero(mapa,datos);
        printf("\n");
    }

    return;
}
void mostrarDatos(datosJugadores* dato){
    printf("Nombre: %s\nDinero: %s\n\n", dato->nombre,dato->dinero);
}
void mostrarJugadores(Map *mapa){
    datosJugadores * aux = firstMap(mapa);// esta ordenado asi que deberia de darme el primer dato en relacion a la key
    if(aux == NULL) printf("hola");
    while(aux != NULL){

        mostrarDatos(aux);
        aux = nextMap(mapa);
    }
}
void menu(Map *mapa){
    int opc;
    printf("*********************");
    printf(" BLACK JACK 21 ");
    printf("*********************\n\n");
    printf("1. JUGAR\n");
    printf("2. ABANDONAR JUEGO\n\n");
    printf(">> ");
    scanf ("%d", &opc);

    switch(opc){
        case 1 : 
            llenarDatos(mapa);
            
            break;
        case 2 : 
            return;
    }
}
int main (){
    Map * mapa = createMap(is_equal_string);
    setSortFunction(mapa,lower_than_string);

    menu(mapa);

    printf("Gracias por usar nuestro programa!\n > ");
    fflush(stdin);
    getchar();

    return 0;
}