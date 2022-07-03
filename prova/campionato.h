#ifndef CAMPIONATO_H
#define CAMPIONATO_H

struct campionato{
	char nome[20];
	squadre sl;
};


typedef struct campionato* campionato;

int crea_campionato(campionato* nuovo_campionato, char nome[]);

int get_nome_campionato(campionato il_mio_campionato, char nome[]);

int set_nome_campionato(campionato il_mio_campionato, char cognome[]);

int get_squadre(campionato il_mio_campionato, squadre** squadre);

int cancella_campionato(campionato* nuovo_campionato);

int stampa_campionato(campionato nuovo_campionato);

#endif 

