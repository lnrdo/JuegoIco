#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char palabra_s[80][20] = {{"hardware"},{"software"},{"antonio"},{"programacion"},{"ahorcado"}};

int ahorcado(){

    int a;
    printf("\t\t\t<---BIENVENIDO AL AHORCADO--->\n");
    printf("\t\t\t__\n\t\t\t| |\n\t\t\t| 0\n\t\t\t|/|\\ \n\t\t\t|/ \\ ");
    printf("\n\tMenu :");
    printf("\n\t\t1) Iniciar \n");
    printf("\n\t\t2) Ahorcado Aleatorio \n");
    scanf("%d",&a);
    switch(a){
case 1:
    system("cls");
    iniciar();
    break;
case 2:
    system("cls");
    aleatorio();
default:
    break;

    }

}
void dibujar_ahorcado(int i,char *b,char *c){
switch(i){
    case 1:
    printf("\n\t\t\t| \n\t\t\t|\n\n\n");
     break;
    case 2:
     printf("\n\t\t\t|\n\t\t\t| \n\t\t\t|\n\n");
      break;
    case 3:
    printf("\n\t\t\t|\n\t\t\t|\n\t\t\t| \n\t\t\t|\n");
     break;
    case 4:
    printf("\t\t\t_\n\t\t\t|\n\t\t\t|\n\t\t\t| \n\t\t\t|");
     break;
    case 5:
    printf("\t\t\t__\n\t\t\t|\n\t\t\t|\n\t\t\t| \n\t\t\t|");
     break;
    case 6:
    printf("\t\t\t__\n\t\t\t|\n\t\t\t|\n\t\t\t| \n\t\t\t|");
     break;
    case 7:
    printf("\t\t\t__\n\t\t\t| |\n\t\t\t|\n\t\t\t| \n\t\t\t|");
     break;
    case 8:
    printf("\t\t\t__\n\t\t\t| |\n\t\t\t| 0\n\t\t\t| \n\t\t\t|");
     break;
    case 9:
    printf("\t\t\t__\n\t\t\t| |\n\t\t\t| 0\n\t\t\t|/|\\ \n\t\t\t|");
     break;
    case 10:
    printf("\t\t\t__\n\t\t\t| |\n\t\t\t| 0\n\t\t\t|/|\\ \n\t\t\t|/ \\ ");
     break;
    default:
    break;
}
  printf("\n\n\n\n\t\t\t%s\t\t\t Numero de intentos -> %d\n\n\n\n\t\tLETRAS INTRODUCIDAS >>> %s ",b,i,c);

}
void iniciar(){
    char  palabra_s[20]="SUSPENSO",palabra_s2[20]="________",introducidos[15]=" ",palabra_intro;
    int intentos=0,salir=1,hubo=0,x,r;
    while (1){
        hubo=0;
        printf("\n\n\n\n\t\tIntroduce una letra >>> \n\n");
        scanf(" %c",&palabra_intro);
        system("cls");
        for(x=0;palabra_s[x]!='\0';x++){
            if(palabra_s[x]==palabra_intro){
                palabra_s2[x]=palabra_intro;
                hubo=1;
            }
        }
        if(hubo==0){ intentos++;introducidos[intentos]=palabra_intro;}
        if(intentos==10){
            system("cls");
            printf("\n\n\n\t\tLo siento has fallado :( \n\n\n\n\n");
            printf("\t\t¿Quieres volver a jugar (1/0)?\n\n\t\t");
            scanf("%d",&r);
            if(r!=0){intermedio2();break;}else{printf("\n\t\tEsta bien, pero dejeme sus dies no mas . \n\n\n\n\n\n\n\n");break;}
        }
        if(strcmp(palabra_s,palabra_s2)==0){
            system("cls");
            printf("\n\n\n\t\tEnhorabuena has acertado la palabra .\n\n\n\n\n");
            printf("\t\t¿Quieres volver a jugar (1/0)?\n\n\t\t");
            scanf("%d",&r);
            if(r!=0){intermedio2();break;}else{printf("\n\t\tEsta bien, pero dejeme sus dies no mas . \n\n\n\n\n\n");break;}

        }
        palabra_s2[x]='\0';
        dibujar_ahorcado(intentos,palabra_s2,introducidos);

}

}

void aleatorio(){
    char introducidos[15]=" ";
    char arr[20][20];
    strcpy(arr[0], "Hola");
    strcpy(arr[1], "Hardware");
    strcpy(arr[2], "Software");
    strcpy(arr[3], "Antonio");
    strcpy(arr[4], "Programacion");
    strcpy(arr[5], "Ahorcado");
    char *str=NULL;
    int r;
    char palabra_intro;
    int semilla,hubo=0,x,salir=1,intentos=0,alea;
    semilla=time(0);
	srand(semilla);
    alea=rand() % 6;
    str = (char *)malloc(sizeof(char) * (strlen(arr[alea])+1));

    for(x=0;x<strlen(arr[alea]);x++){
        *(str + x)='_';
    }
    str[x]='\0';
  //COMPLETO EL ARRAY QUE CONTIENE LAS BARRABAJAS CON LA NUEVA PALABRA , LO BUENO SERIA CON MEMALLOC

    //BUCLE PRINCIPAL
    while (1){
        hubo=0;
        //LECTURA DE LETRA
        printf("\n\n\n\n\t\tIntroduce una letra >>> ");
        scanf(" %c",&palabra_intro);
        system("cls");
        //RECORRO LA PALABRA CORRECTA PARA COMPARARLA CON LA INTRODUCIDA POR EL USUARIO
        for(x=0;x<strlen(arr[alea]);x++){

            if(arr[alea][x]==palabra_intro){
                //SI ES LA MISMA LETRA PONGO EN EL ARRAY DE BARRABAJA LA LETRA Y INDICO QUE HUBO COINCIDENCIAS
                  *(str + x)  = palabra_intro;
                    hubo=1;
                }
        }

        if(intentos>=10){

         system("cls");
            printf("\n\n\n\t\tLo siento has fallado :( \n\n\n\n\n");
            printf("\t\t¿Quieres volver a jugar (1/0)?\n\n\t\t");
            scanf("%d",&r);
            if(r!=0){intermedio();break;}else{printf("\n\t\tEsta bien, pero dejeme sus dies no mas . \n\n\n\n\n\n");break;}
        }
        printf("%d,%d,%s,%s",strlen(str),strlen(arr[alea]),str,arr[alea]);
        if(strcmp(arr[alea],str)==0){
            system("cls");
            printf("\n\n\n\t\tEnhorabuena has acertado la palabra .\n\n\n\n\n");
            printf("\t\t¿Quieres volver a jugar (1/0)?\n\n\t\t");
            scanf("%d",&r);
            if(r!=0){intermedio();break;}else{printf("\n\t\tEsta bien, pero dejeme sus dies no mas .\n\n\n\n\n\n ");break;}
            }
        if(hubo==0){ intentos++;introducidos[intentos]=palabra_intro;}
            dibujar_ahorcado(intentos,str,introducidos);
    }
    free(str);
}
void intermedio(){
system("cls");
aleatorio();
}
void intermedio2(){
system("cls");
iniciar();
}
