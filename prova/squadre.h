#ifndef SQUADRE_H
#define SQUADRE_H

struct squadre{
	squadra s;
	struct squadre* next;
};

typedef struct squadre* squadre;

int crea_squadre(squadre* squadre_lista);

int inserisci_squadra(squadre* squadra_lista, char nome[]);

squadra cerca_squadra(squadre squadra_lista, char nome_chiave[]);

int elimina_squadre(squadre* squadre_lista);

void stampa_squadre(squadre squadre_lista);



#endif 

