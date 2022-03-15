#ifndef __JOUEUR_H__
#define __JOUEUR_H__
#include <stdio.h>
/*-------------------- Joueur ------------------------*/

typedef struct Joueur
{
	signed char nom_utilisateur[255];
	int couleur;
	int niveaux_joueur;
//	Pions pions_possede[16];
//	Cite cite_possede[8];
}Joueur;
typedef struct Pions Pions;
#endif
