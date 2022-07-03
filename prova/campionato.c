#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "giocatore.h"
#include "giocatori.h"
#include "squadra.h"
#include "squadre.h"
#include "campionato.h"

int crea_campionato(campionato* nuovo_campionato, char nome[]){
	(*nuovo_campionato) = (campionato)malloc(sizeof(struct campionato));
	if((*nuovo_campionato) == NULL) return 1;
	set_nome_campionato(*nuovo_campionato, nome);
	int result = crea_squadre(&((*nuovo_campionato)->sl));
	if(result == 1){
		free(*nuovo_campionato);
		*nuovo_campionato = NULL;
		return 1;
	}
	return 0;
}

int get_nome_campionato(campionato il_mio_campionato, char nome[]){
	if(il_mio_campionato == NULL) return 1;
	strcpy(nome, il_mio_campionato->nome); //nome_campionato
	return 0;
}

int set_nome_campionato(campionato il_mio_campionato, char nome[]){
	if(il_mio_campionato == NULL) return 1;
	strcpy(il_mio_campionato->nome, nome); //nome_campionato
	return 0;
}

int get_squadre(campionato il_mio_campionato, squadre** squadre){
	if(il_mio_campionato == NULL) return 1;
	*squadre = &(il_mio_campionato->sl);
	return 0;
}

int cancella_campionato(campionato* nuovo_campionato){
	if(*nuovo_campionato == NULL) return 1;
	int result = elimina_squadre(&((*nuovo_campionato)->sl));
	if (result == 1)
		return 1;
	free(*nuovo_campionato);
	*nuovo_campionato = NULL;
	return 0;
}

int stampa_campionato(campionato il_mio_campionato){
	if(il_mio_campionato == NULL) return 1;
	else printf("%s\n", il_mio_campionato->nome);
	return 0;
}

