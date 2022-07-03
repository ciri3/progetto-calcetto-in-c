#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "giocatore.h"
#include "giocatori.h"
#include "squadra.h"
#include "squadre.h"

int crea_squadre(squadre* squadre_lista){
	*squadre_lista = NULL;
	return 0;
}

int inserisci_squadra(squadre* squadre_lista, char nome[]){
	squadre nuova_squadra;
	nuova_squadra = (squadre)malloc(sizeof(struct squadre));
	if(nuova_squadra == NULL) return 1;
	int result = crea_squadra(&(nuova_squadra->s), nome);
	if (result == 1){
		free(nuova_squadra);
		return 1;
	}
	nuova_squadra->next = *squadre_lista;
	*squadre_lista = nuova_squadra;
	return 0;
}

squadra cerca_squadra(squadre squadra_lista, char nome_chiave[]){
	while(squadra_lista != NULL){
		char nome_squadra[20];
		get_nome_squadra(squadra_lista->s, nome_squadra);
		if(strcmp(nome_chiave, nome_squadra) == 0)
			return squadra_lista->s;
		squadra_lista = squadra_lista->next;
	}
}

int elimina_squadre(squadre* squadre_lista){
	while(*squadre_lista != NULL){
		squadre p = *squadre_lista;
		cancella_squadra(&(p->s));
		*squadre_lista = (*squadre_lista)->next;
		free(p);
	}
}

void stampa_squadre(squadre squadre_lista){
	while(squadre_lista != NULL){
		stampa_nome_squadra(squadre_lista->s);
		squadre_lista = squadre_lista->next;
	}
}


