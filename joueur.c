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
		j->pion_possede[i]=pion_i;
	}
	for (uint8_t i = 0; i < 8; ++i)
	{
		Cite cite_i={i,c,-1,-1,0};
		j->cite_possede[i]=cite_i;
	}
}
void Cree4Joueurs(Joueur tab[])
{
	for (uint8_t i = 0; i < 4; ++i)
		CreeJoueurs(&tab[i],i+1);
}
void AugmenterNiveauxJoueur(Joueur* j)
{
	++j->niveaux_joueur;
}
void AfficherNiveauxJoueur(Joueur* j)
{
	printf("\nLe NV du Joueur n°%u est de %u \n", j->couleur, j->niveaux_joueur);
}

int InventairePions(Joueur* j)
{
	int nb_de_pion_dans_le_stuff = 0;

	for (uint8_t i = 0; i < 16; ++i)
	{
		if(j->pion_possede[i].Coordx == -1 && j->pion_possede[i].Coordy == -1)
			++nb_de_pion_dans_le_stuff;
	}

	return nb_de_pion_dans_le_stuff;
}
int InventaireCite(Joueur* j)
{
	int nb_de_cite_dans_le_stuff=0;

	for (uint8_t i = 0; i < 8; ++i)
	{
		if(j->cite_possede[i].Coordx == -1 && j->cite_possede[i].Coordy == -1)
			++nb_de_cite_dans_le_stuff;
	}

	return nb_de_cite_dans_le_stuff;
}
