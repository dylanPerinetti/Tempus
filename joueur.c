#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "objet.h"
#include "joueur.h"

/*----------------------- Joueur ----------------------*/

//////////////////////////
//		FONCTION		//
/////////////////////////

void CreeJoueurs(Joueur* j,uint8_t c)	//pour la crééation d'un nouveaux joueur
{
	//strcpy(j->nom_utilisateur,nom);
	j->couleur=c;
	j->niveaux_joueur=0;
	for (uint8_t i = 0; i < 16; ++i)
	{
		Pions pion_i={i,c,-1,-1};
		j->pions_possede[i]=pion_i;
	}
	for (uint8_t i = 0; i < 8; ++i)
	{
		Ville ville_i={i,c,-1,-1,0};
		j->ville_possede[i]=ville_i;
	}
}
void Cree4Joueurs(Joueur tab[])
{
	for (uint8_t i = 0; i < 4; ++i)
		CreeJoueurs(&tab[i],i+1);
}
void AugmenterNiveaux(Joueur* j)
{
	++j->niveaux_joueur;
}
void AfficherNiveaux(Joueur* j)
{
	printf("\nLe NV du Joueur n°%u est de %u \n", j->couleur, j->niveaux_joueur);
}
