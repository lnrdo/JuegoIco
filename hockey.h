#include <windows.h>
#include <iostream> 
#include <conio.h> 
#include <stdlib.h>
#include <dos.h>

int x; // posicion de la bola x (2 al 23)
int y; // posicion de la bola y (2 al 78)
int pix; // posicion x del portero izquierdo
int piy; // posicion y del portero izquierdo
int pdx; // posicion x del porterdo derecho
int pdy; // posicion y del portero derecho
int scorei, scored;

void gotoxy(int x, int y) 
{ 
    HANDLE hCon; 
    COORD dwPos; 
    
    dwPos.X = x; 
    dwPos.Y = y; 
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleCursorPosition(hCon,dwPos); 
} 

void marcador(int &si, int &sd)
{
     gotoxy(24,1); printf("Izquierdos %d - %d Derechos", si, sd);
}


void jugar(int &x, int &y)
{
     gotoxy(abs(x),abs(y)); printf("O");
     Sleep(70);
     
     
     
     
     if (y == 23 || y == -3)
     {
        y *= -1;    
     }
     

     if (x == 77 || x == -2)
     {
        x *= -1;    
     }
     
     if (abs(x) == pix && abs(y) == piy)
     {
        x *= -1;
        gotoxy(29,12); printf("ATAJADAAAAAAAAAAAAAA");
        Sleep(600);           
        gotoxy(29,12); printf("                    ");
     }

     if (abs(x) == pdx && abs(y) == pdy)
     {
        x *= -1;
        gotoxy(29,12); printf("ATAJADAAAAAAAAAAAAAA");
        Sleep(600);           
        gotoxy(29,12); printf("                    ");
     }
     
     // Rutina para los goles
     if (abs(x) == 2 && (abs(y) >= 8 && abs(y) <= 16))
     {
        gotoxy(29,12); printf("GOOOOOOOOOOOOOOOOOOL");
        Sleep(600);           
        gotoxy(29,12); printf("                    ");
        scored++;
        marcador(scorei, scored);
     }
     

     // Rutina para los goles
     if (abs(x) == 77 && (abs(y) >= 8 && abs(y) <= 16))
     {
        gotoxy(29,12); printf("GOOOOOOOOOOOOOOOOOOL");
        Sleep(600);           
        gotoxy(29,12); printf("                    ");
        scorei++;
        marcador(scorei, scored);
     }


     gotoxy(abs(x),abs(y)); printf(" ");
     gotoxy(pix,piy);printf(")");
     gotoxy(pdx,pdy);printf("(");
     
     
     // Rutina para mover a los porteros
     if(kbhit()==1)
     {
         unsigned char tecla = getch();
         switch(tecla)
         {
              case 's':
                   if(piy < 23)
                   { 
                     gotoxy(pix,piy);printf(" ");
                     piy++;
                     gotoxy(pix,piy);printf(")");
                   }

                   break;
              case 'w':
                   if(piy > 3)
                   { 
                       gotoxy(pix,piy);printf(" ");
                       piy--;
                       gotoxy(pix,piy);printf(")");
                   }
                   break;
              case char(72):
                   if(pdy > 3)
                   { 
                       gotoxy(pdx,pdy);printf(" ");
                       pdy--;
                       gotoxy(pdx,pdy);printf("(");
                   }
                break;
              case char(80):
                   if(pdy < 23)
                   { 
                     gotoxy(pdx,pdy);printf(" ");
                     pdy++;
                     gotoxy(pdx,pdy);printf("(");
                   }
                break;

          }
    }


     x++;
     y++;
}

void pintar()
{
     int c, d;     
     c=1;
     d=1;
     
     // Lineas de banda
     for(c=1; c < 79; c++)
     {
        gotoxy(c, 2); printf ("%c", 196);         
        gotoxy(c, 24); printf ("%c", 196);         
     }
     
     //Lineas de meta
     for(d=2; d < 24; d++)
     {
        gotoxy(1,d); printf ("%c", 179);         
        gotoxy(78,d); printf ("%c", 179);         
     }
     
     // Esquinas
     gotoxy(1,2); printf ("%c", 218);
     gotoxy(1,24); printf ("%c", 192);
     gotoxy(78,2); printf ("%c", 191);
     gotoxy(78,24); printf ("%c", 217);
     
     // Porterias
     for(d=8; d <= 16; d++)
     {
        gotoxy(78,d); printf (" ");
        gotoxy(1,d); printf (" ");
     }
     
     gotoxy(1,7); printf ("%c", 193);
     gotoxy(78,7); printf ("%c", 193);
     gotoxy(1,17); printf ("%c", 194);
     gotoxy(78,17); printf ("%c", 194);
     
     
}


void hockey(void)
{
	
	system("cls");
     scorei = 0;
     scored = 0;
     x = 2;
     y = 3;
     pdx = 76;
     pdy = 12;

     pix = 3;
     piy = 12;
     
     // Porteros inicial
     gotoxy(pix, piy); printf(")");
     gotoxy(pdx, pdy); printf("(");
     
     pintar();
     
     // Marcador Inicial
     marcador(scorei, scored);
     
     while (scorei < 5 && scored < 5)
     {
           jugar(x,y);      
     }
     
     gotoxy(29,12); printf("JUEGO TERMINADO");
     getch();
     
}
