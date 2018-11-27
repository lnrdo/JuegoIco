#include<stdio.h>
#include<conio.h>
#include "gato.h"
#include "numerocien.h"


int main (void) {
	
	int opcion;
	
   

    do{
	

        printf("\n\n\n     Selecciona el juego que deseas iniciar:\t\t\t\n\n\n");

        
    
        printf("\n\t   1.    Gato\t\n\n\n");
        printf("\n\t    2.    Numero 100\t\n");



        printf("\n\n\n\t 3.     Salir\t\t\n\n");


       
        do
        {
            printf("\n\tSelecciona el juego que deseas iniciar:\t\n");
            scanf( "%i", &opcion );

        } while ( opcion < 1 || opcion > 5 );
      

        switch ( opcion )
        {
            
          
    
			case 1: gato();
			break;
			case 2:numerocien();
			break;

       }
   } while (opcion !=3);
       
         
return 0;

    }

   




