#ifndef CAMPIONATI_H
#define CAMPIONATI_H

struct campionati{
	campionato c;
	struct campionati* next;
};


typedef struct campionati* campionati;

int crea_campionati(campionati* campionati_lista);

int inserisci_campionato(campionati* campionati_lista, char nome[]);

campionato cerca_campionato(campionati campionati_lista, char nome_chiave[]);

int cancella_campionati(campionati* campionati_lista, char nome_chiave[]);

void stampa_campionati(campionati squadra_lista);

#endif 






