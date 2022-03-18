#include "objet.h"
#include "joueur.h"


void CreeJoueur(Joueur* _joueur,uint8_t _couleur)//pour la crééation d'un nouveaux joueur
{
	//malloc(sizeof(char)*);
	//free();
	//strcpy(j->nom_utilisateur,nom);
	InitialiserCouleurJoueur(_joueur,_couleur);
	InitialiserNiveauJoueur(_joueur);
	for (uint8_t i = 0; i < 16; ++i)
	{
		Pions _pion_i;
		InitialiserPions(&_pion_i, _couleur);
		_joueur->pion_possede[i]=_pion_i;
	}
	for (uint8_t i = 0; i < 8; ++i)
	{
		Cite _cite_i;
		InitialiserCite(&_cite_i, _couleur);
		_joueur->cite_possede[i]=_cite_i;
	}
}


void Cree4Joueurs(Joueur tab[])			//Pour Créé 4 Joueur
{
	for (uint8_t i = 0; i < 4; ++i)
	{
		CreeJoueur(&tab[i],i+1);
	}
}
void InitialiserCouleurJoueur(Joueur* _joueur,uint8_t _couleur)
{
	_joueur->couleur=_couleur;
}


void InitialiserNiveauJoueur(Joueur* _joueur)
{
	_joueur->niveaux_joueur=0;
}

void AugmenterNiveauJoueur(Joueur* j)	//Pour Indenter le niveux d'un joueuer 
{
	j->niveaux_joueur++;
}
void AfficherNiveauJoueur(Joueur* j)	//Pour Afficher le niveaux d'un joueur
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
		if(j->pion_possede[i].coord_x == -1 && j->pion_possede[i].coord_y == -1)
			nb_de_pion_dans_le_stuff++;
	}

	return nb_de_pion_dans_le_stuff;
}
int InventaireCite(Joueur* j)			//Pour Répertorier les Cite d'un joueur dans l'inventaire
{
	int nb_de_cite_dans_le_stuff=0;

	for (uint8_t i = 0; i < 8; ++i)
	{
		if(j->cite_possede[i].coord_x == -1 && j->cite_possede[i].coord_y == -1)
			nb_de_cite_dans_le_stuff++;
	}

	return nb_de_cite_dans_le_stuff;
}
