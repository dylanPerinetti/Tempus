#include <stdio.h>
#include "joueur.h"

typedef struct Joueur
{
	signed char nom_utilisateur[255];
	int couleur = 0;
	int niveaux_joueur = 0;
//	Pions pions_possede[16];
//	Cite cite_possede[8];


}Joueur;
typedef struct Pawn
    {
        int Joueur;
        int Coordx;
        int Coordy;
    }Pions;
