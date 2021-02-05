#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

enum Stato_giocatore {Astronauta, Impostore, Assassinato, Defenestrato};
enum Nome_giocatore {Rosa, Giallo, Rosso, Marrone, Blu, Arancione, Viola, Verde, Nero, Bianco};
enum Tipo_stanza {Vuota, Quest_Semplice, Quest_Complicata, Botola};

struct Stanza{
  struct Stanza* avanti;
  struct Stanza* destra;
  struct Stanza* sinistra;
  struct Stanza* stanza_precedente;
  struct Stanza* pNext;
  enum Tipo_stanza tipo;
  bool emergenza_chiamata;
};

typedef struct{
  struct Stanza* posizione;
  enum Stato_giocatore stato;
  enum Nome_giocatore nome;
}Giocatore;

void impostagioco();
void gioca();
void terminagioco();
