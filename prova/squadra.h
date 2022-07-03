#ifndef SQUADRA_H
#define SQUADRA_H

struct squadra{
	char nome_squadra[20];
	int punti;
	giocatori lon;
};


typedef struct squadra* squadra;

int crea_squadra(squadra* nuova_squadra, char nome_squadra[]);

int get_nome_squadra(squadra la_mia_squadra, char nome_squadra[]);

int get_punti (squadra la_mia_squadra, int punti);

int get_giocatori(squadra la_mia_squadra, giocatori** giocatori);

int aggiugi_punti(squadra la_mia_squadra, int punti);

int set_nome_squadra(squadra la_mia_squadra, char nome[]);

int cancella_squadra(squadra* la_mia_squadra);

int stampa_squadra(squadra la_mia_squadra);

int stampa_nome_squadra(squadra la_mia_squadra);



#endif 

