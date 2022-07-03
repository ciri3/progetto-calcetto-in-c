#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "giocatore.h"

int crea_giocatore(giocatore* nuovo_giocatore, char nome[], char  cognome[], char numero_maglia[]){
	  (*nuovo_giocatore) = (giocatore)malloc(sizeof(struct giocatore));
	  if ((*nuovo_giocatore) == NULL) return 1;
    set_nome(*nuovo_giocatore, nome);
	  set_cognome(*nuovo_giocatore, cognome);
	  set_numero_maglia(*nuovo_giocatore, numero_maglia);
	  return 0;
}

int get_nome(giocatore il_mio_giocatore, char nome[]){
    if(il_mio_giocatore == NULL) return 1;
	  strcpy(nome, il_mio_giocatore->nome);
	  return 0;
}

int get_cognome(giocatore il_mio_giocatore, char cognome[]){
    if(il_mio_giocatore == NULL) return 1;
	  strcpy(cognome, il_mio_giocatore->cognome);
	  return 0;
}

int get_numero_maglia(giocatore il_mio_giocatore, char numero_maglia[]){
	  if(il_mio_giocatore == NULL) return 1;
	  strcpy(numero_maglia, il_mio_giocatore->numero_maglia);
	  return 0;
}

//int get_gol_personali(giocatore il_mio_giocatore, int gol_personali){
//	  if(il_mio_giocatore == NULL) return 1;
//	  strcpy(gol_personali, il_mio_giocatore->gol_personali);
//	  return 0;
//}

int set_nome(giocatore il_mio_giocatore, char nome[]){
	  if(il_mio_giocatore == NULL) return 1;
	  strcpy(il_mio_giocatore->nome, nome);
	  return 0;
}

int set_cognome(giocatore il_mio_giocatore, char cognome[]){
	  if(il_mio_giocatore == NULL) return 1;
	  strcpy(il_mio_giocatore->cognome, cognome);
	  return 0;
}

int set_numero_maglia(giocatore il_mio_giocatore, char numero_maglia[]){
	  if(il_mio_giocatore == NULL) return 1;
	  strcpy(il_mio_giocatore->numero_maglia, numero_maglia);
	  return 0;
}

//int set_gol_personali(giocatore il_mio_giocatore, int gol_personali){
//	  if(il_mio_giocatore == NULL) return 1;
//	  strcpy(il_mio_giocatore->gol_personali, gol_personali);
//	  return 0;
//}

//int aggiungi_gol_personali(giocatore il_mio_giocatore, int gol_personali);

int distruggi_giocatore(giocatore* il_mio_giocatore){
	  if(*il_mio_giocatore == NULL) return 1;
	  free(*il_mio_giocatore);
	  *il_mio_giocatore = NULL;
	  return 0;
}

int stampa_giocatore(giocatore il_mio_giocatore){
	  if(il_mio_giocatore == NULL) return 1;
	  else printf("%s %s %s\n", il_mio_giocatore->nome, il_mio_giocatore->cognome, il_mio_giocatore->numero_maglia);
	  return 0;
}

