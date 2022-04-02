#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct compu{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
} typedef compu;

compu ingresar();
compu ingresarAleatorio();
void mostrar(compu computadora);
void masVieja(compu *computadora, int cantidad);
void masRapida(compu *computadora, int cantidad);

int main(){
    compu *PC = malloc(5 * sizeof(compu));
    int opcion;

    puts("Ingresar 1 para aleatorio, 2 para usuario");
    scanf("%d", &opcion);
    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        if(opcion == 2){
            printf("\nPC n%cmero %d\n", 163, i + 1);
            *(PC + i) = ingresar();
        }
        if(opcion == 1){
            *(PC + i) = ingresarAleatorio();
        }
    }

    printf("\nMostrando todas las PC:\n");
    for(int i = 0; i < 5; i++){
        printf("PC n%cmero %d\n", 163, i + 1);
        mostrar(*(PC + i));
        printf("\n");
    }

    printf("\nMostrando la PC m%cs vieja:\n", 160);
    masVieja(PC, 5);

    printf("\nMostrando la PC m%cs r%cpida:\n", 160, 160);
    masRapida(PC, 5);

    return 0;
}

compu ingresar(){
    compu computadora;

    puts("Ingrese la velocidad de procesamiento en GHz:");
    scanf("%d", &computadora.velocidad);

    printf("Ingrese el a%co de fabricaci%cn:\n", 164, 162);
    scanf("%d", &computadora.anio);
    
    printf("Ingrese la cantidad de n%ccleos:\n", 163);
    scanf("%d", &computadora.cantidad);

    puts("Ingrese el tipo de procesador:");
    computadora.tipo_cpu = malloc(20 * sizeof(char));
    scanf("%s", computadora.tipo_cpu);

    return computadora;
}

compu ingresarAleatorio(){
    compu computadora;
    int numAleatorio;
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    computadora.velocidad = 2 + rand() % 2;
    computadora.anio = 2000 + rand() % 17;
    computadora.cantidad = 1 + rand() % 4;
    numAleatorio = rand() % 6;
    computadora.tipo_cpu = malloc(strlen(tipos[numAleatorio]));
    strcpy(computadora.tipo_cpu, tipos[numAleatorio]);

    return computadora;
}

void mostrar(compu computadora){

    printf("Velocidad del procesador en GHz: %d\n", computadora.velocidad);
    printf("A%co de fabricaci%cn: %d\n", 164, 162, computadora.anio);
    printf("Cantidad de n%ccleos: %d\n", 163, computadora.cantidad);
    printf("Tipo de procesador: %s\n", computadora.tipo_cpu);

    return;
}

void masVieja(compu *computadora, int cantidad){
    int anio, indice = 0;

    anio = computadora->anio;

    for(int i = 1; i < cantidad; i++){
        if((computadora + i)->anio < anio){
            indice = i;
        }
    }

    mostrar(*(computadora + indice));

}

void masRapida(compu *computadora, int cantidad){
    int velocidad, indice = 0;

    velocidad = computadora->velocidad;

    for(int i = 1; i < cantidad; i++){
        if((computadora + i)->velocidad > velocidad){
            indice = i;
        }
    }

    mostrar(*(computadora + indice));

}