#ifndef GIOCATORE_H
#define GIOCATORE_H

struct giocatore{
	char nome[20];
	char cognome[20];
	char numero_maglia[3];
	int gol_personali;
};


typedef struct giocatore* giocatore;

int crea_giocatore(giocatore* nuovo_giocatore, char nome[], char  cognome[], char numero_maglia[]);

int get_nome(giocatore il_mio_giocatore, char nome[]);

int get_cognome(giocatore il_mio_giocatore, char cognome[]);

int get_numero_maglia(giocatore il_mio_giocatore, char numero_maglia[]);

int get_gol_personali(giocatore il_mio_giocatore, int gol_personali);

int set_nome(giocatore il_mio_giocatore, char nome[]);

int set_cognome(giocatore il_mio_giocatore, char cognome[]);

int set_numero_maglia(giocatore il_mio_giocatore, char numero_maglia[]);

int set_gol_personali(giocatore il_mio_giocatore, int gol_personali);

//int aggiungi_gol_personali(giocatore il_mio_giocatore, int gol_personali);

int distruggi_giocatore(giocatore* il_mio_giocatore);

int stampa_giocatore(giocatore il_mio_giocatore);


#endif 