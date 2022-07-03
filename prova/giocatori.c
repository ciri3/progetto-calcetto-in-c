#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "giocatore.h"
#include "giocatori.h"


int crea_giocatori(giocatori* giocatori_lista){
	*giocatori_lista = NULL;
	return 0;
}

int inserisci_giocatore(giocatori* giocatori_lista, char nome[], char  cognome[], char numero_maglia[]){
	giocatori nuovo_giocatore;
	nuovo_giocatore = (giocatori)malloc(sizeof(struct giocatori));
	if(nuovo_giocatore == NULL) return 1;
	int result =  crea_giocatore(&(nuovo_giocatore->pn), nome, cognome, numero_maglia);
	if (result == 1) return 1;
	nuovo_giocatore->next = *giocatori_lista;
	*giocatori_lista = nuovo_giocatore;
	return 0;
}

giocatore cerca_giocatore(giocatori giocatori_lista, char numero_maglia_chiave[]){
	while(giocatori_lista != NULL){
		char numero_maglia[3];
		get_numero_maglia(giocatori_lista->pn, numero_maglia);
		if(strcmp(numero_maglia_chiave, numero_maglia) == 0)
			return giocatori_lista->pn;
		giocatori_lista = giocatori_lista->next;
	}
}

int modifica_giocatore(giocatori giocatori_lista, char numero_maglia_chiave[], char nuovo_nome[], char nuovo_cognome[]){
	giocatore giocatore_chiave = cerca_giocatore(giocatori_lista, numero_maglia_chiave);
	if(giocatore_chiave == NULL) return 1;
	int result1 = 0;
	int result2 = 0;
	if(nuovo_nome[0] != '\0')
		result1 = set_nome(giocatore_chiave, nuovo_nome);
	if(nuovo_cognome[0] != '\0')
		result2 = set_cognome(giocatore_chiave,nuovo_cognome);
	if(result1 && result2) return 1;
	return 0;
}

//int aggiungi_gol_giocatore(giocatori giocatori_lista, char numero_maglia_chiave, int gol_aggiuntivi);

int cancella_giocatori(giocatori* giocatori_lista){
	while(*giocatori_lista != NULL){
		giocatori p = *giocatori_lista;
		distruggi_giocatore(&(p->pn));
		*giocatori_lista = (*giocatori_lista)->next;
		free(p);
	}
}

void stampa_giocatori(giocatori giocatori_lista){
	while(giocatori_lista != NULL){
		stampa_giocatore(giocatori_lista->pn);
		giocatori_lista = giocatori_lista->next;
	}
}

