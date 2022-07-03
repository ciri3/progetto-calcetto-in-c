#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "giocatore.h"
#include "giocatori.h"
#include "squadra.h"


int crea_squadra(squadra* nuova_squadra, char nome_squadra[]){
    (*nuova_squadra) = (squadra)malloc(sizeof(struct squadra));
	if ((*nuova_squadra) == NULL) return 1;
	set_nome_squadra(*nuova_squadra, nome_squadra);
	//nuova_squadra.punti = 0;
	int result = crea_giocatori(&((*nuova_squadra)->lon));
	if(result == 1){
		free(*nuova_squadra);
		*nuova_squadra = NULL;
		return 1;
	}
	return 0;
}

int get_nome_squadra(squadra la_mia_squadra, char nome_squadra[]){
	if(la_mia_squadra == NULL) return 1;
	strcpy(nome_squadra, la_mia_squadra->nome_squadra);
	return 0;
}

//prova
int get_punti (squadra la_mia_squadra, int punti){
	if(la_mia_squadra == NULL) return 1;
	//strcpy(punti, la_mia_squadra->punti);
	punti = la_mia_squadra->punti;
	return 0;
}

int get_giocatori(squadra la_mia_squadra, giocatori** giocatori){
	if(la_mia_squadra == NULL) return 1;
	*giocatori = &(la_mia_squadra->lon);
	return 0;
}


int aggiugi_punti(squadra la_mia_squadra, int punti_da_agiungere){
	if(la_mia_squadra == NULL) return 1;
	la_mia_squadra -> punti += punti_da_agiungere;
	return 0;
}
//controllare

int set_nome_squadra(squadra la_mia_squadra, char nome[]){
	if(la_mia_squadra == NULL) return 1;
	strcpy(la_mia_squadra->nome_squadra, nome);
	return 0;
}

int cancella_squadra(squadra* la_mia_squadra){
	if(*la_mia_squadra == NULL) return 1;
	int result = cancella_giocatori(&((*la_mia_squadra)->lon));
	if(result == 1)
		return 1;
	free(*la_mia_squadra);
	*la_mia_squadra = NULL;
	return 0;
}

int stampa_squadra(squadra la_mia_squadra){
	if(la_mia_squadra == NULL) return 1;
	printf("%s\n\n\n punti: %d \n\n ", la_mia_squadra->nome_squadra, la_mia_squadra->punti);
	stampa_giocatori(la_mia_squadra->lon);
	return 0;
}

int stampa_nome_squadra(squadra la_mia_squadra){
	if(la_mia_squadra == NULL) return 1; 
	printf("%s \n", la_mia_squadra->nome_squadra);
	return 0;
}


//int set_punti(squadra la_mia_squadra, int punti);
