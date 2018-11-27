#include<stdio.h>
#include<conio.h>
#include "hockey.h"
#include "gato.h"
#include "numerocien.h"
#include "adivinanum.h"


int main (void) {
	
	int opcion;
	
   

    do{
	

        printf("\n\n\n     Selecciona el juego que deseas iniciar:\t\t\t\n");

        printf("\n\t 1.    Hockey\t\n");
        printf("\n\t  2.    Adivina el numero que estas pensando\t\n");
        printf("\n\t   3.    Gato\t\n");
        printf("\n\t    4.    Numero 100\t\n");



        printf("\n\n\n\t 5.     Salir\t\t\n\n");


       
        do
        {
            printf("\n\tSelecciona el juego que deseas iniciar:\t\n");
            scanf( "%i", &opcion );

        } while ( opcion < 1 || opcion > 5 );
      

        switch ( opcion )
        {
            
            case 1: hockey();
			break;
    
			case 2: adivinanum();
			break;

            case 3:gato();
			break;
			case 4:numerocien();
			break;

       }
   } while (opcion !=5);
       
         
return 0;

    }

   




