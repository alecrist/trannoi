#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "gamelib.h"

int main()
{
  int scelta=0;
  bool flag=false;
  bool giocato=false;
  do
  {
    system("clear");

    printf(" ___________  ___   _   _  _   _ _____ _____ \n");
    printf("|_   _| ___ ]/ _ ] | ] | || [ | |  _  |_   _|\n");
    printf("  | | | |_/ / /_] ]|  ]| ||  [| | | | | | |  \n");
    printf("  | | |    /|  _  || . ` || . ` | | | | | |  \n");
    printf("  | | | |[ [| | | || |[  || |[  [ [_/ /_| |_ \n");
    printf("  [_/ [_| [_[_| |_/[_| [_/[_| [_/[___/ [___/ \n\n\n");

    printf("+-----------------------------------------------------------------------------------------------------+\n");
    printf("| Un gruppo di astronauti si trova in viaggio sull'astronave Skelt, e il loro obiettivo è riuscire a  |\n");
    printf("| completare tutte le attività previste per il mantenimento della nave, arrivando così a destinazione |\n");
    printf("| Tra di loro si celano però anche gli impostori, il cui scopo è eliminare gli astronauti senza farsi |\n");
    printf("| scoprire. Riusciranno ad arrivare a destinazione prima di essere decimati dagli impostori? Trannoi  |\n");
    printf("| è liberamente ispirato ad un gioco esistente. Spero tu ti possa divertire! Ora iniziamo a giocare!  |\n");
    printf("+-----------------------------------------------------------------------------------------------------+\n\n");

    printf("+-----------------------+\n");
    printf("|    MENÙ PRINCIPALE    |\n");
    printf("|                       |\n");
    printf("|   Scegli cosa fare:   |\n");
    printf("| 1. Imposta gioco      |\n");
    printf("| 2. Gioca a Trannoi    |\n");
    printf("| 3. Esci da Trannoi    |\n");
    printf("|                       |\n");
    printf("+-----------------------+\n\n");
    printf("Inserisci qui la tua scelta: ");
    scanf("%d",&scelta);

    switch(scelta)
    {
      case 1:
        if(giocato==true)
          terminagioco();
        impostagioco();
        flag=true;
        break;

      case 2:
        if(flag==true)
        {
          gioca();
          giocato=true;
        }
        else
        {
          printf("\nDEVI PRIMA IMPOSTARE IL GIOCO\n");
        }
        break;

      case 3:
        if(giocato==true)
          terminagioco();
        printf("\n\n+------------------------------------------+\n");
        printf("| SPERO TU TI SIA DIVERTITO! ALLA PROSSIMA |\n");
        printf("| Alessandro Cristofani Matricola->333563  |\n");
        printf("+------------------------------------------+\n\n");
        break;

      default:
        printf("\n ATTENZIONE! COMANDO NON RICONOSCIUTO!\n");
    }
  } while(scelta!=3);
}
