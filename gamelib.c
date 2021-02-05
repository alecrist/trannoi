//LIBRERIE UTILIZZATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "gamelib.h"

//DICIARAZIONI DELLE VARIABILI GLOBALI
Giocatore* giocatori;
unsigned short quest_da_finire,quest_fatte;
struct Stanza* stanza_attuale;
struct Stanza* pFirst;
struct Stanza* stanza_iniziale;
struct Stanza* lista_stanze;
int numeroGiocatori=0, numeroMorti=0, numeroDefenestrati=0,numeroAstronauti=0,numeroImpostori=0;
int c=0;
const char* nomeGiocatore[] = {"Rosa", "Giallo", "Rosso", "Marrone", "Blu", "Arancione", "Viola", "Verde", "Nero", "Bianco"};
const char* statoGiocatore[] = {"Astronauta", "Impostore", "Assassinato", "Defenestrato"};
const char* tipoStanza[] = {"Vuota", "Quest Semplice", "Quest Complicata", "Botola"};

//FUNZIONE CHE PERMETTE DI STAMPARE UN ELENCO DEI GIOCATORI
static void stampa_giocatori()
{
  //CICLO CHE PERMETTE DI STAMPARE IL NOME DEL GIOCATORE E IL SUO TIPO
  for(int w=0;w<numeroGiocatori;w++)
  {
    printf("\nGIOCATORE %d -> %s -> %s",w+1,nomeGiocatore[giocatori[w].nome],statoGiocatore[giocatori[w].stato]);
  }
}

//FUNZIONE CHE PERMETTE AL GIOCATORE DI MUOVERSI TRA LE VARIE STANZE
static void avanza()
{
  int movimento;
  do{
    printf("\n---DOVE VUOI ANDARE?---\npremere...\n1 -> Avanti\n2 -> Sinistra\n3 -> Destra\nScegli cosa vuoi fare: ");
    scanf("%d",&movimento);
    switch (movimento)
    {
      //IL GIOCATORE VA AVANTI
      case 1:

        //SE LA STANZA NON ESISTE NE CREA UNA NUOVA
        if(giocatori[c].posizione->avanti==NULL)
        {
          stanza_attuale=giocatori[c].posizione;
          giocatori[c].posizione->avanti=(struct Stanza*) malloc(sizeof(struct Stanza));
          giocatori[c].posizione=giocatori[c].posizione->avanti;
          giocatori[c].posizione->stanza_precedente=stanza_attuale;

          int random;
          giocatori[c].posizione->avanti=NULL;
          giocatori[c].posizione->destra=NULL;
          giocatori[c].posizione->sinistra=NULL;
          giocatori[c].posizione->emergenza_chiamata=false;
          random=rand () %100;

          if(random>=0 && random<=25)
            giocatori[c].posizione->tipo=3;
          if(random>=26 && random<=40)
            giocatori[c].posizione->tipo=2;
          if(random>=41 && random<=70)
            giocatori[c].posizione->tipo=1;
          if(random>=71 && random<=100)
            giocatori[c].posizione->tipo=0;

          struct Stanza* lista_stanze=(struct Stanza*) malloc(sizeof(struct Stanza));
          lista_stanze=giocatori[c].posizione;
          lista_stanze->pNext=NULL;
          if(pFirst==NULL)
          {
            pFirst=lista_stanze;
          }
          else
          {
            lista_stanze->pNext=pFirst;
            pFirst=lista_stanze;
          }
        }

        //SE LA STANZA GIÀ ESISTE AGGIORNA LA POSIZIONE DEL GIOCATORE
        else
        {
          stanza_attuale=giocatori[c].posizione;
          giocatori[c].posizione=giocatori[c].posizione->avanti;
          giocatori[c].posizione->stanza_precedente=stanza_attuale;
        }
        break;

      //IL GIOCATORE VA A SINISTRA
      case 2:

        //SE LA STANZA NON ESISTE NE CREA UNA NUOVA
        if(giocatori[c].posizione->sinistra==NULL)
        {
          stanza_attuale=giocatori[c].posizione;
          giocatori[c].posizione->sinistra=(struct Stanza*) malloc(sizeof(struct Stanza));
          giocatori[c].posizione=giocatori[c].posizione->avanti;
          giocatori[c].posizione->stanza_precedente=stanza_attuale;

          int random;
          giocatori[c].posizione->avanti=NULL;
          giocatori[c].posizione->destra=NULL;
          giocatori[c].posizione->sinistra=NULL;
          giocatori[c].posizione->emergenza_chiamata=false;
          random=rand () %100;

          if(random>=0 && random<=25)
            giocatori[c].posizione->tipo=3;
          if(random>=26 && random<=40)
            giocatori[c].posizione->tipo=2;
          if(random>=41 && random<=70)
            giocatori[c].posizione->tipo=1;
          if(random>=71 && random<=100)
            giocatori[c].posizione->tipo=0;

          struct Stanza* lista_stanze=(struct Stanza*) malloc(sizeof(struct Stanza));
          lista_stanze=giocatori[c].posizione;
          lista_stanze->pNext=NULL;
          if(pFirst==NULL)
          {
            pFirst=lista_stanze;
          }
          else
          {
            lista_stanze->pNext=pFirst;
            pFirst=lista_stanze;
          }
        }

        //SE LA STANZA GIÀ ESISTE AGGIORNA LA POSIZIONE DEL GIOCATORE
        else
        {
          stanza_attuale=giocatori[c].posizione;
          giocatori[c].posizione=giocatori[c].posizione->sinistra;
          giocatori[c].posizione->stanza_precedente=stanza_attuale;
        }
        break;

      //IL GIOCATORE VA A DESTRA
      case 3:

        //SE LA STANZA NON ESISTE NE CREA UNA NUOVA
        if(giocatori[c].posizione->destra==NULL)
        {
          stanza_attuale=giocatori[c].posizione;
          giocatori[c].posizione->destra=(struct Stanza*) malloc(sizeof(struct Stanza));
          giocatori[c].posizione=giocatori[c].posizione->destra;
          giocatori[c].posizione->stanza_precedente=stanza_attuale;

          int random;
          giocatori[c].posizione->avanti=NULL;
          giocatori[c].posizione->destra=NULL;
          giocatori[c].posizione->sinistra=NULL;
          giocatori[c].posizione->emergenza_chiamata=false;
          random=rand () %100;

          if(random>=0 && random<=25)
            giocatori[c].posizione->tipo=3;
          if(random>=26 && random<=40)
            giocatori[c].posizione->tipo=2;
          if(random>=41 && random<=70)
            giocatori[c].posizione->tipo=1;
          if(random>=71 && random<=100)
            giocatori[c].posizione->tipo=0;

          struct Stanza* lista_stanze=(struct Stanza*) malloc(sizeof(struct Stanza));
          lista_stanze=giocatori[c].posizione;
          lista_stanze->pNext=NULL;
          if(pFirst==NULL)
          {
            pFirst=lista_stanze;
          }
          else
          {
            lista_stanze->pNext=pFirst;
            pFirst=lista_stanze;
          }
        }

        //SE LA STANZA GIÀ ESISTE AGGIORNA LA POSIZIONE DEL GIOCATORE
        else
        {
          stanza_attuale=giocatori[c].posizione;
          giocatori[c].posizione=giocatori[c].posizione->destra;
          giocatori[c].posizione->stanza_precedente=stanza_attuale;
        }
        break;

      default:
        printf("\nATTENZIONE! COMANDO NON RICONOSCIUTO!\n");
        break;
    }

  }while(movimento!=1 && movimento!=2 && movimento!=3 && movimento!=4);
}

//FUNZIONE CHE PERMETTE DI ESEGUIRE LA QUEST CONTENUTA NELLA STANZA
static void esegui_quest()
{
  //CONTROLLO DEL TIPO DI STANZA E AUMENTO DEL CONTATORE DI CONSEGUENZA
  if(giocatori[c].posizione->tipo==1)
  {
    quest_fatte++;
  }
  else
  {
    quest_fatte+=2;
  }
}

//FUNZIONE CHE PERMETTE DI EFFETTUARE UNA CHIAMATA D'EMERGENZA
static void chiamata_emergenza()
{
  time_t t;
  srand((unsigned) time(&t));
  //DICHIARAZIONE VARIABILI LOCALI
  int nAstronauti=0,nImpostori=0,percentuale_astronauta=0,percentuale_impostore=0,random=0;
  bool flag=false;

  //CICLO PER CONTARE IL NUMERO DI IMPOSTORI E ASTRONAUTI NELLA STESSA STANZA DEL GIOCATORE
  for(int i=0;i<numeroGiocatori;i++)
  {
    //AUMENTO CONTATORE AUSTRONAUTI
    if(giocatori[c].posizione==giocatori[i].posizione && giocatori[i].stato==0)
      nAstronauti++;
    //AUMENTO CONTATORE IMPOSTORI
    if(giocatori[c].posizione==giocatori[i].posizione && giocatori[i].stato==1)
      nImpostori++;
  }

  //CALCOLO DELLA PERCENTUALE DI DEFENESTRAGGIO
  percentuale_impostore=30+(nAstronauti*20)-(nImpostori*30);
  percentuale_astronauta=30+(nImpostori*20)-(nAstronauti*30);
  random=rand()%101;

  //CICLO PER VERIFICARE SE C'È UN GIOCATORE DEFENESTRATO
  for(int i=0;i<numeroGiocatori;i++)
  {
    //CONTROLLO SU ASTRONAUTI
    if(giocatori[c].posizione==giocatori[i].posizione && giocatori[i].stato==0 && flag==false)
    {
      if(random<=percentuale_astronauta)
      {
        giocatori[i].stato=3;
        printf("\nIl giocatore %s e' stato defenestrato ed era un ASTRONAUTA\n", nomeGiocatore[giocatori[i].nome]);
        numeroMorti++;
        flag=true; //FLAG IL QUALE PERMETTE CHE UN SOLO GIOCATORE SIA DEFENSTRATO
      }
    }

    //CONTROLLO SU IMPOSTORI
    if(giocatori[c].posizione==giocatori[i].posizione && giocatori[i].stato==1 && flag==false)
    {
      if(random>=(random-percentuale_impostore))
      {
        giocatori[i].stato=3;
        printf("\nIl giocatore %s e' stato defenestrato ed era un IMPOSTORE\n", nomeGiocatore[giocatori[i].nome]);
        numeroDefenestrati++;
        flag=true; //FLAG IL QUALE PERMETTE CHE UN SOLO GIOCATORE SIA DEFENSTRATO
      }
    }
  }

  //COMUNICAZIONE IN TAL CASO NESSUN GIOCATORE È STATO DEFENESTRATO
  if(flag==false)
    printf("\nNon e' stato defenestrato nessuno\n");

  //CAMBIO VALORE DEL PARAMETRO CHIAMATA EMERGENZA NELLA STANZA ATTUALE (IN QUESTO MODO NON POTRÀ ESSERCI NUOVAMENTE UN'ALTRA CHIAMATA D'EMERGENZA)
  giocatori[c].posizione->emergenza_chiamata=true;
}

//FUNZIONE CHE PERMETTE ALL'IMPOSTORE DI UCCIDERE UN ASTRONAUTA
static void uccidi_astronauta()
{
  time_t t;
  srand((unsigned) time(&t));
  //DICHIARAZIONE DELLE VARIABILI LOCALI
  int ucciso=0,scelta=0,nAstronautiQui=0,nAstronautiPrima=0,Defenestraggio=0,random=0;

  //CICLO PER CONTARE GLI ASTRONAUTI PRESENTI NELLA STANZA ATTUALE E IN QUELLA PRECEDENTE
  for(int i=0;i<numeroGiocatori;i++)
  {
    //STANZA ATTUALE
    if(giocatori[i].posizione==giocatori[c].posizione && giocatori[i].stato==0)
      nAstronautiQui++;
    //STANZA PRECEDENTE
    if(giocatori[i].posizione==giocatori[c].posizione->stanza_precedente && giocatori[i].stato==0)
      nAstronautiPrima++;
  }

  //UCCISIONE DELL'UNICO ASTRONAUTA PRESENTE
  if(nAstronautiQui==1)
  {
    for(int i=0;i<numeroGiocatori && ucciso==0;i++)
    {
      if(giocatori[i].posizione==giocatori[c].posizione && giocatori[i].stato==0)
      {
        printf("Hai ucciso il giocatore %s", nomeGiocatore[giocatori[i].nome]);
        giocatori[i].stato=2;
      }
    }
  }

  //SCELTA DELL'ASTRONAUTA DA UCCIDERE
  if(nAstronautiQui>1)
  {
    do
    {
      for(int i=0;i<numeroGiocatori && ucciso==0;i++)
      {
        if(giocatori[i].posizione==giocatori[c].posizione && giocatori[i].stato==0)
        {
          do
          {
            printf("\nVuoi uccidere %s?\n1) Uccidi\n2) Scegli un altro astronauta da uccidere\nFai una scelta: ", nomeGiocatore[giocatori[i].nome]);
            scanf("%d", &scelta);
            if(scelta==1)
            {
              ucciso=1;
              giocatori[i].stato=2;
              printf("Hai ucciso il giocatore %s...", nomeGiocatore[giocatori[i].nome]);
              numeroMorti++;
            }
          }while (scelta!=1 && scelta!=2);
        }
      }
    }while(ucciso==0);
  }

  //CALCOLO DELLA PROBABILITÀ PER DETERMINARE SE L'IMPOSTORE VERRÀ DEFENESTRATO O MENO
  nAstronautiQui--;
  random=rand()%101;
  Defenestraggio=(nAstronautiQui*50)+(nAstronautiPrima*20);

  //DEFENESTRAGGIO E AUMENTO CONTATORE
  if(random<Defenestraggio)
  {
    giocatori[c].stato=3;
    printf("ma sei stato defenestrato perche' ti hanno scoperto!\n");
    numeroDefenestrati++;
  }
  else
  {
    printf("e sei salvo perche' non ti hanno scoperto!\n");
  }
}

//FUNZIONE CHE PERMETTE AD UN IMPOSTORE DI CAMBIARE STANZA USANDO UNA BOTOLA ---DA MODIFICARE---
static void usa_botola()
{
  //DICHIARAZIONE DELLE VARIABILI LOCALI
  time_t t;
  srand((unsigned) time(&t));
  int numeroBotole=0,random=0,numeroStanze=0,contantore=0,flag=0,flag_giocatoriIesieme=0,stanzaNum=0,scelta;

  //CONTROLLO SE ESISTONO DELLE STANZE
  if(pFirst==NULL)
  {
    printf("Lista stanze vuota!");
  }
  else
  {

    //VARIABILI NECESSARIE PER LE OPERAZIONI SUCCESSIVE
    struct Stanza* pScan = pFirst;
    int trovata_stanza=0;

    //CALCOLO DEL NUMERO DI STANZE CHE HANNO UNA BOTOLA
    do
    {
      if(pScan->tipo==3)
        numeroBotole++;

      pScan=pScan->pNext;
    }while(pScan!=NULL);

    //SWITCH PER DIVERSIFICARE LE AZIONI IN BASE AL CONTATORE PRECEDENTEMENTE CALCOLATO
    switch(numeroBotole)
    {
      case 1: //1 SOLA STANZA CON BOTOLA
        do
        {
          numeroStanze++;
          pScan=pScan->pNext;
        }while(pScan!=NULL);

        do
        {
          contantore=0;
          random=rand()%numeroStanze+1;
          struct Stanza* pScan=pFirst;
          do
          {
            contantore++;
            if(contantore==random && giocatori[c].posizione!=pScan)
            {
              giocatori[c].posizione=pScan;
              for(int i=0;i<numeroGiocatori;i++)
              {
                if(giocatori[i].posizione==pScan && giocatori[i].nome!=giocatori[c].nome && giocatori[i].stato!=2 && giocatori[i].stato!=3)
                  flag_giocatoriIesieme++;
              }
              if(flag_giocatoriIesieme==0)
              {
                printf("Nessun giocatore si trova nella stanza in cui sei andato\n");
              }
              else
              {
                printf("Giocatori nella tua nuova stanza:\n");
                for(int i=0;i<numeroGiocatori;i++)
                {
                  if(giocatori[i].posizione==pScan && giocatori[i].nome!=giocatori[c].nome && giocatori[i].stato!=2 && giocatori[i].stato!=3)
                    printf("\t- %s (%s)\n", nomeGiocatore[giocatori[i].nome],statoGiocatore[giocatori[i].stato]);
                }
              }
              flag=1;
            }

            pScan = pScan->pNext;
          }while(pScan!= NULL && flag!=1);
        }while(flag!=1);

      case 2: //2 STANZE CON BOTOLA
        do
        {
          flag_giocatoriIesieme=0;
          if(pScan->tipo==3 && giocatori[c].posizione!=pScan)
          {
            for(int i=0;i<numeroGiocatori;i++)
            {
              if(giocatori[i].posizione==pScan && giocatori[i].nome!=giocatori[c].nome && giocatori[i].stato!=2 && giocatori[i].stato!=3)
                flag_giocatoriIesieme++;
            }
            if(flag_giocatoriIesieme==0)
            {
              giocatori[c].posizione=pScan;
              trovata_stanza=1;
              printf("Sei entrato nell'unica altra stanza con una botola e sei solo all'interno di essa\n");
            }
            else
            {
              giocatori[c].posizione=pScan;
              trovata_stanza=1;
              printf("Sei entrato nell'unica altra stanza con una botola\n");
              printf("Giocatori nella tua nuova stanza:\n");
              for(int i=0;i<numeroGiocatori;i++)
              {
                if(giocatori[i].posizione==pScan && giocatori[i].nome!=giocatori[c].nome && giocatori[i].stato!=2 && giocatori[i].stato!=3)
                  printf("\t- %s (%s)\n", nomeGiocatore[giocatori[i].nome],statoGiocatore[giocatori[i].stato]);
              }
            }
          }
          pScan = pScan->pNext;
        }while(pScan!=NULL && trovata_stanza==0);
      }

      if(numeroBotole>2) //PIÙ DI 2 STANZE CON BOTOLA
      {
        do
        {
          stanzaNum=0;

          do
          {
            flag_giocatoriIesieme=0;
            if(pScan->tipo==3 && giocatori[c].posizione!=pScan)
            {
              stanzaNum++;
              for(int i=0;i<numeroGiocatori;i++)
              {
                if(giocatori[i].posizione==pScan && giocatori[i].nome!=giocatori[c].nome && giocatori[i].stato!=2 && giocatori[i].stato!=3)
                {
                  flag_giocatoriIesieme++;
                }
              }
              if(flag_giocatoriIesieme==0)
              {
                printf("\n\nNessun giocatore si trova in questa stanza\n");
                do
                {
                  printf("Vuoi entrare nella stanza %s con botola?\n1) Entra\n2) Scorri stanze con botola\nFai una scelta: ", stanzaNum);
                  scanf("%d", &scelta);
                }while(scelta!=1 && scelta!=2);

                if(scelta==1)
                  giocatori[c].posizione=pScan;
              }
              else
              {
                printf("\n\nGiocatori nella stanza: \n");
                for(int i=0;i<numeroGiocatori;i++){
                  if(giocatori[i].posizione==pScan && giocatori[i].nome!=giocatori[c].nome && giocatori[i].stato!=2 && giocatori[i].stato!=3)
                    printf("\t- %s (%s)\n", nomeGiocatore[giocatori[i].nome],statoGiocatore[giocatori[i].stato]);
                }
                do
                {
                  printf("Vuoi entrare nella stanza %d con botola?\n1) Entra\n2) Scorri stanze con botola\nFai una scelta: ", stanzaNum);
                  scanf("%d", &scelta);
                }while(scelta!=1 && scelta!=2);
                if(scelta==1)
                  giocatori[c].posizione=pScan;
              }
            }
            pScan = pScan->pNext;
          }while(pScan!= NULL && scelta!=1);
      }while(scelta!=1);
    }
  }
  return;
}

//FUNZIONE CHE PERMETTE DI CANCELLARE LA QUEST PRESENTE NELLA STANZA
static void sabotaggio()
{
  //RENDE LA STANZA NELLA QUALE SI TROVA L'ASTRONAUTA DI TIPO VUOTA
  giocatori[c].posizione->tipo=0;
  printf("\nLA QUEST È STATA SABOTATA\n");
}

//FUNZIONE CHE CONTROLLA ALLA FINE DI OGNI TURNO SE LA PARTITA SI È CONCLUSA
static bool controlla_fine()
{
  bool b=false;
  if(quest_fatte==quest_da_finire)
  {
    b=true;
    printf("\nTUTTE LE QUEST SONO STATE COMPLETATE! GLI ASTRONAUTI HANNO VINTO!\n");
  }
  if(numeroMorti==numeroAstronauti)
  {
    b=true;
    printf("\nTUTTI GLI ASTRONAUTI SONO STATU UCCISI! GLI IMPOSTORI HANNO VINTO!\n");
  }
  if(numeroDefenestrati==numeroImpostori)
  {
    b=true;
    printf("\nTUTTI GLI IMPOSTORI SONO STATI DEFENESTRATI! GLI ASTRONAUTI HANNO VINTO!\n");
  }
  return b;
}

//FUNZIONE LA QUALE HA IL COMPITO DI IMPOSTARE TUTTI I VALORI NECESSARI PER AVVIARE LA PARTITA
void impostagioco()
{
  //DICHIARAZIONI DELLE VARIABILI LOCALI
  time_t t;
  srand((unsigned) time(&t));
  int x,contaImpostori=0;

  //CICLO PER L'INSERIMENTO DEL NUMERO DI GIOCATORI (ESSO CONTINUA IN LOOP FINO A QUANDO L'UTENTE NON INSERISCE UN VALORE ACCETTABILE)
  do
  {
    printf("---IMPOSTAZIONE GIOCO---\nTrannoi può essere giocato da un minimo di 4 ad un massimo di 10 giocatori...\nQUANTI SIETE A GIOCARE?\n");
    scanf("%d",&numeroGiocatori);
    if(numeroGiocatori<4 || numeroGiocatori>10)
      printf("---ATTENZIONE---\nNon è possibile giocare a Trannoi con il numero di giocatori inserito!\n");
  } while(numeroGiocatori<4 || numeroGiocatori>10);

  //CREAZIONE ARRAY GIOCATORI
  giocatori=malloc(numeroGiocatori*sizeof(Giocatore));

  //ASSEGNAZIONE NOMI AI GIOCATORI
  for (x=0;x<numeroGiocatori;x++)
  {
    giocatori[x].nome=rand()%10;
    for(int q=0;q<numeroGiocatori;q++)
    {
      if(giocatori[x].nome==giocatori[q].nome)
      {
        giocatori[x].nome=rand()%10;
      }
    }

  }

  //ASSEGNAZIONE NUMERO IMPOSTORI IN BASE AL NUMERO DI GIOCATORI TOTALI
  if(numeroGiocatori>=4 && numeroGiocatori<=6)
    contaImpostori=1;
  if(numeroGiocatori>=7 && numeroGiocatori<=8)
    contaImpostori=2;
  if(numeroGiocatori>=9 && numeroGiocatori<=10)
    contaImpostori=3;

  //ASSEGNAZIONE A CIASCUN GIOCATORE SE ESSO SARA' UN IMPOSTORE O UN ASTRONAUTA
  switch(contaImpostori)
  {
    //1 IMPOSTORE
    case 1:
      for(x=0;x<contaImpostori;x++)
      {
        if(rand()%100<25)
        {
          giocatori[x].stato=1;
          numeroImpostori++;
        }
        else
        {
          giocatori[x].stato=0;
          numeroAstronauti++;
        }
      }

    //2 IMPOSTORI
    case 2:
      for(x=0;x<contaImpostori;x++)
      {
        if(rand()%100<35)
        {
          giocatori[x].stato=1;
          numeroImpostori++;
        }
        else
        {
          giocatori[x].stato=0;
          numeroAstronauti++;
        }
      }

    //3 IMPOSTORI
    case 3:
      for(x=0;x<contaImpostori;x++)
      {
        if(rand()%100<45)
        {
          giocatori[x].stato=1;
          numeroImpostori++;
        }
        else
        {
          giocatori[x].stato=0;
          numeroGiocatori++;
        }
      }
  }

  //ASSEGNAZIONE VALORI ALLA STANZA DI PARTENZA
  stanza_iniziale=(struct Stanza*) malloc(sizeof(struct Stanza));
  stanza_iniziale->avanti=NULL;
  stanza_iniziale->destra=NULL;
  stanza_iniziale->sinistra=NULL;
  stanza_iniziale->stanza_precedente=NULL;
  stanza_iniziale->emergenza_chiamata=false;

  //GENERAZIONE RANDOMICA DEL TIPO DELLA STANZA
  int probabilita_stanza=rand () %100;
  if(probabilita_stanza<=25)
      stanza_iniziale->tipo=3;
  if(probabilita_stanza>=26 && probabilita_stanza<=40)
      stanza_iniziale->tipo=2;
  if(probabilita_stanza>=41 && probabilita_stanza<=70)
      stanza_iniziale->tipo=1;
  if(probabilita_stanza>=71 && probabilita_stanza<=100)
      stanza_iniziale->tipo=0;

  //ASSEGNAZIONE POSIZIONE DEI GIOCATORI NELLA STANZA INIZIALE
  for(x=0;x<numeroGiocatori;x++)
  {
    giocatori[x].posizione=stanza_iniziale;
  }

  //INSERIMENTO DEL NUMERO DI QUEST DA FINIRE DA PARTE DEGLI ASTRONAUTI PER POTER VINCERE LA PARTITA
  do
  {
    printf("\nQUANTE QUEST DOVRANNO COMPIERE GLI ASTRONAUTI PER POTER VINCERE?\nil numero di quest deve essere maggiore del numero dei giocatori\n");
    scanf("%hu",&quest_da_finire);
    if(quest_da_finire<numeroGiocatori)
      printf("\nATTENZIONE! NUMERO QUEST TROPPO BASSO! TI RICORDO CHE DEVE ESSERE ALMENO IL DOPPIO DEL NUMERO DI GIOCATORI!");
  } while(quest_da_finire<numeroGiocatori);

  //INSERIMENTO DELLA STANZA APPENA CREATA ALL'INTERNO DELLA LISTA DI STANZE
  lista_stanze=(struct Stanza*)malloc(sizeof(struct Stanza));
  lista_stanze=stanza_iniziale;
  lista_stanze->pNext=NULL;
  pFirst = lista_stanze;

  //FUNZIONE CHE PERMETTE DI STAMPARE TUTTE LE INFORMAZIONI RELATIVE AI GIOCATORI
  stampa_giocatori();
}

//FUNZIONE CONTENENTE TUTTE LE OPERAZIONI CHE POTRANNO ESSERE SVOLTE DURANTE LA PARTITA
void gioca()
{
  //DICHIARAZIONI VARIABILI LOCALI
  bool flag_fine=false;
  int flag_azione=0;
  int menu,chiamata,uccidi;
  //CICLO CHE VIENE RIPETUTO ALL'INFINITO FINCHÈ QUALCUNO NON VINCE
  do {
    //SWITCH CHE DIFFERENZIA LE POSSIBILI AZIONI IN BASE AL TIPO DEL GIOCATORE ATTUALE
    switch (giocatori[c].stato)
    {
      case 0: //ASTRONAUTI
        system("clear");
        printf("\nTOCCA AL GIOCATORE %s\n",nomeGiocatore[giocatori[c].nome]);
        printf("\nLA STANZA ALL'INTERNO DELLA QUALE TI TROVI E' DI TIPO %s\n",tipoStanza[giocatori[c].posizione->tipo]);

        //CICLO PER CONTROLLARE SE C'È UN MORTO NELLA STANZA
        for(int c1=0;c1<numeroGiocatori;c1++)
        {
          if(giocatori[c].posizione==giocatori[c1].posizione && giocatori[c1].stato==2)
          {
            printf("\nC'È UN MORTO ALL'INTERNO DELLA STANZA! VUOI FARE UNA CHIAMATA D'EMERGENZA? (1=SI 2=NO)\n");
            scanf("%d",&chiamata);
            if (chiamata==1)
            {
              chiamata_emergenza();
              flag_azione=1;
            }
            else
            {
              flag_azione=0;
            }
          }
        }
        //SWITCH CHE DIFFERENZIA LE POSSIBILI AZIONI IN BASE AL TIPO DI STANZA
        switch (giocatori[c].posizione->tipo)
        {
          case 0: //STANZA VUOTA
            printf("\nTi trovi all'interno di una stanza vuota\n");

            //CONTROLLO SE IL GIOCATORE HA EFFETTUATO GIÀ UN'ALTRA AZIONE
            if(flag_azione==0)
            {
              //CICLO PER RICHIEDERE QUALE TIPO DI AZIONE VUOLE FARE IL GIOCATORE
              do {
                printf("\nCOSA VUOI FARE?\n1. RESTA FERMO\n2. CAMBIA STANZA\n");
                scanf("%d",&menu);
                if(menu!=1 && menu !=2)
                  printf("\nATTENZIONE! COMANDO NON RICONOSCIUTO\n");
              } while(menu!=1 && menu !=2);

              //RICHIAMA LA FUNZIONE RICHIESTA
              if(menu==2)
                avanza();
            }
            break;


          case 1: //QUEST SEMPLICE
            printf("\nTi trovi all'interno di una stanza contenente una quest semplice\n");

            //CONTROLLO SE IL GIOCATORE HA EFFETTUATO GIÀ UN'ALTRA AZIONE
            if(flag_azione==0)
            {
              //CICLO PER RICHIEDERE QUALE TIPO DI AZIONE VUOLE FARE IL GIOCATORE
              do {
                printf("\nCOSA VUOI FARE?\n1. RESTA FERMO\n2. ESEGUI QUEST\n3. AVANZA\n");
                scanf("%d",&menu);
                if(menu!=1 && menu!=2 && menu!=3)
                  printf("\nATTENZIONE! COMANDO NON RICONOSCIUTO\n");
              } while(menu!=1 && menu!=2 && menu!=3);

              //RICHIAMA LA FUNZIONE RICHIESTA
              if(menu==2)
                esegui_quest();
              if(menu==3)
                avanza();
            }
            break;

          case 2: //QUEST COMPLICATA
            printf("\nTi trovi all'interno di una stanza contenente una quest complicata\n");

            //CONTROLLO SE IL GIOCATORE HA EFFETTUATO GIÀ UN'ALTRA AZIONE
            if(flag_azione==0)
            {
              //CICLO PER RICHIEDERE QUALE TIPO DI AZIONE VUOLE FARE IL GIOCATORE
              do {
                printf("\nCOSA VUOI FARE?\n1. RESTA FERMO\n2. ESEGUI QUEST\n3. AVANZA\n");
                scanf("%d",&menu);
                if(menu!=1 && menu!=2 && menu!=3)
                  printf("\nATTENZIONE! COMANDO NON RICONOSCIUTO\n");
              } while(menu!=1 && menu!=2 && menu!=3);

              //RICHIAMA LA FUNZIONE RICHIESTA
              if(menu==2)
                esegui_quest();
              if(menu==3)
                avanza();
            }
            break;

          case 3: //BOTOLA
            printf("\nTi trovi all'interno di una stanza contenente una botola\nNon puoi fare nulla!");
            break;
        }

      case 1: //IMPOSTORI
        system("clear");
        printf("\nTOCCA AL GIOCATORE %s\n",nomeGiocatore[giocatori[c].nome]);
        printf("\nLA STANZA ALL'INTERNO DELLA QUALE TI TROVI E' DI TIPO %s\n",tipoStanza[giocatori[c].posizione->tipo]);

        //CICLO PER CONTROLLARE SE C'È UN MORTO NELLA STANZA
        for(int c1=0;c1<numeroGiocatori;c1++)
        {
          if(giocatori[c].posizione==giocatori[c1].posizione && giocatori[c1].stato==2)
          {
            printf("\nC'È UN MORTO ALL'INTERNO DELLA STANZA! VUOI FARE UNA CHIAMATA D'EMERGENZA? (1=SI 2=NO)\n");
            scanf("%d",&chiamata);
            if (chiamata==1)
            {
              chiamata_emergenza();
              flag_azione=1;
            }
            else
            {
              flag_azione=0;
            }
          }
          if(giocatori[c].posizione==giocatori[c1].posizione)
          {
            printf("\nC'È UN ALTRO GIOCATORE NELLA TUA STESSA STANZA, VUOI UCCIDERLO? (1=SI 2=NO)\n");
            scanf("%d",&uccidi);
            if (uccidi==1)
            {
              uccidi_astronauta();
              flag_azione=1;
            }
            else
            {
              flag_azione=0;
            }
          }
        }
        //SWITCH CHE DIFFERENZIA LE POSSIBILI AZIONI IN BASE AL TIPO DI STANZA
        switch (giocatori[c].posizione->tipo)
        {
          case 0: //STANZA VUOTA
            printf("\nTi trovi all'interno di una stanza vuota\n");

            //CONTROLLO SE IL GIOCATORE HA EFFETTUATO GIÀ UN'ALTRA AZIONE
            if(flag_azione==0)
            {
              //CICLO PER RICHIEDERE QUALE TIPO DI AZIONE VUOLE FARE IL GIOCATORE
              do {
                printf("\nCOSA VUOI FARE?\n1. RESTA FERMO\n2. AVANZA\n");
                scanf("%d",&menu);
                if(menu!=1 && menu!=2)
                  printf("\nATTENZIONE! COMANDO NON RICONOSCIUTO\n");
              } while(menu!=1 && menu!=2);

              //RICHIAMA LA FUNZIONE RICHIESTA
              if(menu==2)
                avanza();
            }
            break;

          case 1: //QUEST SEMPLICE
            printf("\nTi trovi all'interno di una stanza contenente una quest semplice\n");

            //CONTROLLO SE IL GIOCATORE HA EFFETTUATO GIÀ UN'ALTRA AZIONE
            if(flag_azione==0)
            {
              //CICLO PER RICHIEDERE QUALE TIPO DI AZIONE VUOLE FARE IL GIOCATORE
              do {
                printf("\nCOSA VUOI FARE?\n1. RESTA FERMO\n2. SABOTA QUEST\n3. AVANZA\n");
                scanf("%d",&menu);
                if(menu!=1 && menu!=2 && menu!=3)
                  printf("\nATTENZIONE! COMANDO NON RICONOSCIUTO\n");
              } while(menu!=1 && menu!=2 && menu!=3);

              //RICHIAMA LA FUNZIONE RICHIESTA
              if(menu==2)
                sabotaggio();
              if(menu==3)
                avanza();
            }
            break;

          case 2: //QUEST COMPLICATA
            printf("\nTi trovi all'interno di una stanza contenente una quest complicata\n");

            //CONTROLLO SE IL GIOCATORE HA EFFETTUATO GIÀ UN'ALTRA AZIONE
            if(flag_azione==0)
            {
              //CICLO PER RICHIEDERE QUALE TIPO DI AZIONE VUOLE FARE IL GIOCATORE
              do {
                printf("\nCOSA VUOI FARE?\n1. RESTA FERMO\n2. SABOTA QUEST\n3. AVANZA\n");
                scanf("%d",&menu);
                if(menu!=1 && menu!=2)
                  printf("\nATTENZIONE! COMANDO NON RICONOSCIUTO\n");
              } while(menu!=1 && menu!=2 && menu!=3);

              //RICHIAMA LA FUNZIONE RICHIESTA
              if(menu==2)
                sabotaggio();
              if(menu==3)
                avanza();
            }
            break;

          case 3: //BOTOLA
            printf("\nTi trovi all'interno di una stanza contenente una botola\n");

            //CONTROLLO SE IL GIOCATORE HA EFFETTUATO GIÀ UN'ALTRA AZIONE
            if(flag_azione==0)
            {
              //CICLO PER RICHIEDERE QUALE TIPO DI AZIONE VUOLE FARE IL GIOCATORE
              do {
                printf("\nCOSA VUOI FARE?\n1. RESTA FERMO\n2. USA BOTOLA\n3. AVANZA\n");
                scanf("%d",&menu);
                if(menu!=1 && menu!=2 && menu!=3)
                  printf("\nATTENZIONE! COMANDO NON RICONOSCIUTO\n");
              } while(menu!=1 && menu!=2 && menu!=3);

              //RICHIAMA LA FUNZIONE RICHIESTA
              if(menu==2)
                usa_botola();
              if(menu==3)
                avanza();
            }
            break;
        }
      case 2: //ASSASSINATO
        break;

      case 3: //DEFENESTRATO
        break;
    }
    //AUMENTO DEL CONTATORE PER PERMETTERE AL GIOCATORE SUCCESSIVO DI GIOCARE. SE IL CONTATORE È TROPPO ALTO LO RESETTA PER FAR RICOMINCIARE IL GIRO DEI TURNI
    c++;
    if(c>numeroGiocatori)
      c=0;

    //CONTROLLO SE UNA DELLE CONDIZIONI CHE DECRETA LA FINE DELLA PARTITA È VERA
    flag_fine=controlla_fine();

  } while(flag_fine==false);
}

//FUNZIONE RICHIAMATA AL TERMINE DELLA PARTITA E CHE DEALLOCA TUTTA LA MEMORIA DINAMICA PRECEDENTEMENTE UTILIZZATA
void terminagioco()
{
  //DEALLOCAZIONE MEMORIA IMPIEGATA DALL'ARRAY DEI GIOCATORI E DALLA STANZA INIZIALE
  free(giocatori);
  free(stanza_iniziale);

  //CICLO PER LA DEALLOCAZIONE DELLA MEMORIA IMPIEGATA DALLA LISTA DI STANZE
  do{
    lista_stanze=lista_stanze->pNext;
    free(lista_stanze);
  }while(lista_stanze!=NULL);
}
