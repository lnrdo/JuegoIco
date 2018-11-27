#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
 
void numerocien() {
    srand(time(NULL));  //debes poner esta linea antes de llamar a rand para que no se repita los numeros
    bool turnoJugador = true;
    bool gameOver = false;
    int acumulado = 0;
    int tempValor = 0;
    srand ( 9 );
    
    while ( !gameOver ) {
        
        if ( turnoJugador ) {
            do {
                tempValor = printf ( "Introduzca un numero entre 1 y 10:\n" );
                scanf ( "%i", &tempValor );
            } while ( ( tempValor > 10 || tempValor <= 0 ) );
            
            
        } else {
            if ( acumulado >= 90 ) {
                acumulado = 100;
            } 
            else {
                tempValor = (1 + rand() % 10);  //Eso garantiza numeros entre 1 y 10 sino puede pasarse de rosca
                printf ( "La maquina ha escogido:\n%i\n", tempValor );
            }
        }
        
        acumulado += tempValor;
        
        if ( acumulado >= 100 ) {
            if ( turnoJugador ) {
                printf ( "Acumulado: %d\n", acumulado ); //Esta linea la puede borrar si quieres    
                printf ( "Gana jugador!" );
            } 
            else {
                printf ( "Acumulado: %d\n", acumulado ); //Esta linea la puede borrar si quieres
                printf ( "Gana la maquina!" );
            }
            
            gameOver = true;
        } 
        else {
            printf ( "Acumulado: %d\n", acumulado );
        }
        
        turnoJugador = !turnoJugador;
        
    }
    
}
