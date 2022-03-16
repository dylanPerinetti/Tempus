#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "objet.h"
#include "joueur.h"

/*----------------------- Joueur ----------------------*/

//////////////////////////
//		FONCTION		//
/////////////////////////

void CreeJoueur(Joueur* j,uint8_t c)	//pour la crééation d'un nouveaux joueur
{
	//malloc(sizeof(char)*);
	//free();
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
void Cree4Joueurs(Joueur tab[])			//Pour Créé 4 Joueur
{
	for (uint8_t i = 0; i < 4; ++i)
		CreeJoueur(&tab[i],i+1);
}
void AugmenterNiveauxJoueur(Joueur* j)	//Pour Indenter le niveux d'un joueuer 
{
	++j->niveaux_joueur;
}
void AfficherNiveauxJoueur(Joueur* j)	//Pour Afficher le niveaux d'un joueur
{
	printf("\nLe NV du Joueur n°%u est de %u \n", j->couleur, j->niveaux_joueur);
}
void AfficherInventaireJoueur(Joueur* j)//Pour Afficher L'inventaire d'un joueur
{
	int *tab=InventaireJoueur(j);
	printf("Le joueur n°%d Possède %d Pions et Possède %d Cite",j->couleur ,tab[0],tab[1]);
}

int* InventaireJoueur(Joueur* j)		//Pour Ranger l'inventaire dans un tableau[<PIONS>,<CITE>]
{
	static int tab[2];
	tab[0] = InventairePions(j);
	tab[1] = InventaireCite(j);
	return tab;
}
int InventairePions(Joueur* j)			//Pour Répertorier les Pions d'un joueur dans l'inventaire
{
	int nb_de_pion_dans_le_stuff = 0;

	for (uint8_t i = 0; i < 16; ++i)
	{
		if(j->pion_possede[i].Coordx == -1 && j->pion_possede[i].Coordy == -1)
			++nb_de_pion_dans_le_stuff;
	}

	return nb_de_pion_dans_le_stuff;
}
int InventaireCite(Joueur* j)			//Pour Répertorier les Cite d'un joueur dans l'inventaire
{
	int nb_de_cite_dans_le_stuff=0;

	for (uint8_t i = 0; i < 8; ++i)
	{
		if(j->cite_possede[i].Coordx == -1 && j->cite_possede[i].Coordy == -1)
			++nb_de_cite_dans_le_stuff;
	}

	return nb_de_cite_dans_le_stuff;
}
