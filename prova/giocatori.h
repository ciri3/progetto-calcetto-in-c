#ifndef GIOCATORI_H
#define GIOCATORI_H

struct giocatori{
	giocatore pn;
	struct giocatori* next; 
};


typedef struct giocatori* giocatori;

int crea_giocatori(giocatori* giocatori_lista);

int inserisci_giocatore(giocatori* giocatori_lista, char nome[], char  cognome[], char numero_maglia[]);

giocatore cerca_giocatore(giocatori giocatori_lista, char numero_maglia_chiave[]);

int modifica_giocatore(giocatori giocatori_lista, char numero_maglia_chiave[], char nuovo_nome[], char nuovo_cognome[]);

//int aggiungi_gol_giocatore(giocatori giocatori_lista, char numero_maglia_chiave[], int gol_aggiuntivi);

int cancella_giocatori(giocatori* giocatori_lista);

void stampa_giocatori(giocatori giocatori_lista);

#endif 

