#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "giocatore.h"
#include "giocatori.h"
#include "squadra.h"
#include "squadre.h"
#include "campionato.h"
#include "campionati.h"


int crea_campionati(campionati* campionati_lista){
	*campionati_lista = NULL;
	return 0;
}

int inserisci_campionato(campionati* campionati_lista, char nome[]){
	campionati nuovo_campionato;
	nuovo_campionato = (campionati)malloc(sizeof(struct campionati));
	if(nuovo_campionato == NULL) return 1;
	int result = crea_campionato(&(nuovo_campionato->c), nome); 
	if(result == 1){
		free(nuovo_campionato);
		return 1;
	}
	nuovo_campionato->next = *campionati_lista;
	*campionati_lista = nuovo_campionato;
	return 0;
}

campionato cerca_campionato(campionati campionati_lista, char nome_chiave[]){
	while(campionati_lista != NULL){
		char nome[20];
		get_nome_campionato(campionati_lista->c, nome);
		if(strcmp(nome_chiave, nome) == 0)
			return campionati_lista->c;
		campionati_lista = campionati_lista->next;
	}
}

int cancella_campionati(campionati* campionati_lista, char nome_chiave[]){
	campionati r = *campionati_lista;
	campionati q = *campionati_lista;
	char nome[20];
	get_nome_campionato(q->c, nome);
	while ((q != NULL) && (strcmp(nome, nome_chiave) !=0)){
			r = q;
			q = q->next;
			get_nome_campionato(q->c, nome);
	}
	if (q == NULL)
			return 1;
	if (q == *campionati_lista)
			(*campionati_lista) = (*campionati_lista)->next;
	else
			r->next = q->next;
	cancella_campionato(&(q->c));
	free(q);
	return 0;
}

void stampa_campionati(campionati campionati_lista){
	while(campionati_lista != NULL){
		stampa_campionato(campionati_lista->c);
		campionati_lista = campionati_lista->next;
	}
}

