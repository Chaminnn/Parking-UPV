#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PLAZAS 101

/* struct */
struct Coches{
    char matricula[7];
    int hora;
    int mins;
    float tarifa;
};

/* Funci�n INICIALIZA */
void inicializa(struct Coches parking[]){
    for(int i=0;i<PLAZAS;i++){
        strcpy(parking[i].matricula,"\0");
        /* printf("Puesto %d: %s\n",i,parking[i].matricula); */
    }
}

/* Funci�n PRIMERALIBRE */
int primeralibre(struct Coches parking[]){
    for(int i=1;i<PLAZAS;i++){

        if(strcmp(parking[i].matricula,"\0")==0){
            printf("\n*La plaza %d esta disponible*\n",i);
            return i;}
    }
        return -1;
}

/* Funci�n BUSCARVEHICULO */
int buscarvehiculo(struct Coches parking[],char matriculaprueba[7]){
    for(int i=1;i<PLAZAS;i++){
        if (strcmp(matriculaprueba,parking[i].matricula) == 0){return 1;}
    }
    return 0;
}

/* Funci�n LEERVEHICULO */
void leervehiculo(struct Coches parking[], int posicion){

    /* MATRICULA */
    char *matriculaprueba[7];
    printf("Introduce la MATRICULA del coche: \n");
    printf("-> ");
    scanf("%s",&matriculaprueba);
    /* printf("\n *%s*\n",matriculaprueba); */

    /* BUSCARVEHICULO */
    if(buscarvehiculo(parking,matriculaprueba)){printf("\n*Un coche con esa misma matricula ya esta en el parking*\n");return 0;}

    while(!validarmatricula(matriculaprueba)){
        printf("\nMatricula invalidad, intentalo de nuevo. La matricula debe tener 7 caracteres en total (solo letras mayus o numeros)\n");
        printf("-> ");
        scanf("%s",&matriculaprueba);}
    strcpy(parking[posicion].matricula,matriculaprueba); /* !!! */

    /* HORA MINS */
    while (1) {
            printf("\nIntroduce la HORA de entrada del coche (en formato HH:MM utlizando un espacio): \n");
            printf("-> ");
            scanf("%d %d",&parking[posicion].hora,&parking[posicion].mins);
            if (validarhora(parking[posicion].hora, parking[posicion].mins)){break;}
            else{printf("La hora no es valida, introduzca de nuevo\n");}
        }

        /* TARIFA */
    while (1){
        printf("\nIntroduce la TARIFA por minuto a pagar: \n");
        printf("-> ");
        scanf("%f",&parking[posicion].tarifa);
        if(parking[posicion].tarifa >= 0){break;}
        else{
            printf("\nTarifa invalida, introduzca un numero real positivo\n");
            printf("-> ");
            scanf("%f",&parking[posicion].tarifa);
            return 1;}
        }
        printf("\n----------------------------------------------------------------------------------------\n");
        printf("----------------------------------------------------------------------------------------\n");
        printf("\n                           *Coche introducido correctamente*\n");
        /* */
        printf("\n----------------------------------------------------------------------------------------\n");
        printf("----------------------------------------------------------------------------------------\n");
        /* printf("\n                                  MATRICULA: %s",parking[posicion].matricula);
        printf("\n                                  HORA ENTRADA: %d",parking[posicion].hora);
        printf("\n                                  MINS ENTRADA: %d",parking[posicion].mins);
        printf("\n                                  TARIFA: %f\n",parking[posicion].tarifa);
        printf("\n----------------------------------------------------------------------------------------\n");
        printf("----------------------------------------------------------------------------------------\n"); */
}

/* Funci�n VALIDARMATRICULA*/
int validarmatricula(char matriculaprueba[7]){
int longitud =  strlen(matriculaprueba);
if(longitud != 7){return 0;}
for(int i=0;i<7;i++){
    if(!((matriculaprueba[i] >= '0' && matriculaprueba[i] <= '9') || (matriculaprueba[i] >= 'A' && matriculaprueba[i] <= 'Z')))
        return 0;
    }
    return 1;
}

/* Funci�n VALIDARHORA */
int validarhora(int hora, int mins, int posicion){
  if (hora >= 0 && hora <= 23 && mins >= 0 && mins <= 59){return 1;}else{return 0;}
}

/* Funci�n CHATOINT */

/* Funci�n VER PARKING */
void imprimirocupacion(struct Coches parking[]){
    printf("\n----------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("\n");
    for(int i=1;i<=10;i++){printf("%d. %s ",i,parking[i].matricula);}
    printf("\n");
    for(int i=11;i<=20;i++){printf("%d. %s ",i,parking[i].matricula);}
    printf("\n");
    for(int i=21;i<=30;i++){printf("%d. %s ",i,parking[i].matricula);}
    printf("\n");
    for(int i=31;i<=40;i++){printf("%d. %s ",i,parking[i].matricula);}
    printf("\n");
    for(int i=41;i<=50;i++){printf("%d. %s ",i,parking[i].matricula);}
    printf("\n");
    for(int i=51;i<=60;i++){printf("%d. %s ",i,parking[i].matricula);}
    printf("\n");
    for(int i=61;i<=70;i++){printf("%d. %s ",i,parking[i].matricula);}
    printf("\n");
    for(int i=71;i<=80;i++){printf("%d. %s ",i,parking[i].matricula);}
    printf("\n");
    for(int i=81;i<=90;i++){printf("%d. %s ",i,parking[i].matricula);}
    printf("\n");
    for(int i=91;i<=100;i++){printf("%d. %s ",i,parking[i].matricula);}
    printf("\n");
    printf("\n----------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------\n");
}

/* Funci�n MAIN */
int main(){

    struct Coches parking[PLAZAS];
    inicializa(parking);

    /* MEN� */
    printf("\nBIENVENIDO AL PARKING UPV\n");
    int menu;
    do{

        printf("\nSelecciona una opcion:\n");
        printf("\t1. Introducir un coche\n");
        printf("\t2. Revisar informacion de un coche\n");
        printf("\t3. Retirar un coche\n");
        printf("\t4. Ver parking completo\n");
        printf("\t0. Salir de programa :c\n");
        printf("-> ");
        scanf("%d",&menu);

        switch(menu){
            case 1:
                printf("\nHaz selecionado INTRODUCIR...\n");
                int posicion = primeralibre(parking);
                if (posicion == -1){
                    printf("\nNo hay plazas libres, lo sentimos :c\n");
                    break;}
                leervehiculo(parking,posicion); /* !!! */
                break;
            case 2:

                printf("\nHaz seleccionado REVISAR...\n");
                char *matricularevisar[7];
                printf("Introduce la matricula del coche\n");
                printf("-> ");
                scanf("%s",&matricularevisar);

                while(!validarmatricula(matricularevisar)) {
                    printf("\nMatricula invalida, intentalo de nuevo. La matricula debe tener 7 caracteres en total (solo letras mayus o numeros)\n");
                    printf("-> ");
                    scanf("%s",&matricularevisar);
                }

                int i=1;
                for (i; i < PLAZAS; i++) {
                    if (strcmp(matricularevisar, parking[i].matricula) == 0) { break; }
                }

                if(buscarvehiculo(parking,matricularevisar) == 1) {
                        printf("\n----------------------------------------------------------------------------------------\n");
                        printf("----------------------------------------------------------------------------------------\n");
                        printf("\n                                  Datos del coche:");
                        printf("\n                                  MATRICULA: %s\n",parking[i].matricula);
                        printf("                                  HORA DE ENTRADA: %2d:%2d\n",parking[i].hora,parking[i].mins);
                        printf("                                  TARIFA: %f\n",parking[i].tarifa);
                        printf("\n----------------------------------------------------------------------------------------\n");
                        printf("----------------------------------------------------------------------------------------\n");
                }
                if(buscarvehiculo(parking,matricularevisar)!=1){printf("\nNo hay ningun coche con esa matricula en el parking\n");}
                break;

            case 3:
                printf("\nHaz seleccionado RETIRAR...\n");
                break;
            case 4:
                printf("\nHaz seleccionado VER EL PARKING...\n");
                imprimirocupacion(parking);
                break;
            case 0:
                break;
            default:
                printf("\nValor invalido, intentalo de nuevo...\n");
                break;
        }

    } while(menu!=0);

    /* MEN� */
    return 0;
}
