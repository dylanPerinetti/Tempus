/*************************************************** 

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au Joueur dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier joueur.h

Fait par dylan le 14/03/2022
Dernière modifications par dylanPerinetti le 29/03/2022

****************************************************/
#include "objet.h"
#include "joueur.h"

#define NOMBRE_PION 16
#define NOMBRE_CITE 8
#define COORDONNEES_INVENTAIRE 99

void CreeJoueur(Joueur* _joueur,unsigned char _couleur)//pour la crééation d'un nouveaux joueur
{
	InitialiserCouleurJoueur(_joueur,_couleur);
	InitialiserNiveauJoueur(_joueur);
	for (unsigned char i = 0; i < NOMBRE_PION; ++i)
	{
		Pions _pion_i;
		InitialiserPions(&_pion_i, _couleur);
		_joueur->pion_possede[i]=_pion_i;
	}
	for (unsigned char i = 0; i < NOMBRE_CITE; ++i)
	{
		Cite _cite_i;
		InitialiserCite(&_cite_i, _couleur);
		_joueur->cite_possede[i]=_cite_i;
	}
}


void Cree4Joueurs(Joueur tab[])
{
	for (unsigned char i = 0; i < 4; ++i)
	{
		CreeJoueur(&tab[i],i+1);
	}
}


void InitialiserCouleurJoueur(Joueur* _joueur,unsigned char _couleur)
{
	_joueur->couleur=_couleur;
}


void InitialiserNiveauJoueur(Joueur* _joueur)
{
	_joueur->niveaux_joueur=0;
}


void AugmenterNiveauJoueur(Joueur* j)
{
	j->niveaux_joueur++;
}


void AfficherNiveauJoueur(Joueur* j)
{
	printf("\nLe niveau du Joueur%u est %u \n", j->couleur, j->niveaux_joueur);
}


void AfficherInventaireJoueur(Joueur* j)
{
	int *tab=InventaireJoueur(j);
	printf("\nLe joueur %d Possede %d Pions et Possede %d Cite",j->couleur ,tab[0],tab[1]);
}


int* InventaireJoueur(Joueur* _joueur)	//Pour Ranger l'inventaire dans un tableau[<PIONS>,<CITE>]
{
	static int _tab_static[2];
	_tab_static[0] = InventairePions(_joueur);
	_tab_static[1] = InventaireCite(_joueur);
	return _tab_static;
}


int InventairePions(Joueur* _joueur)
{
	int nb_de_pion_dans_le_stuff = 0;

	for (unsigned char i = 0; i < NOMBRE_PION; ++i)
	{
		if(_joueur->pion_possede[i].coordonnees.X == COORDONNEES_INVENTAIRE && _joueur->pion_possede[i].coordonnees.Y == COORDONNEES_INVENTAIRE)
			nb_de_pion_dans_le_stuff++;
	}

	return nb_de_pion_dans_le_stuff;
}


int InventaireCite(Joueur* _joueur)
{
	int nb_de_cite_dans_le_stuff=0;

	for (unsigned char i = 0; i < NOMBRE_CITE; ++i)
	{
		if(_joueur->cite_possede[i].coordonnees.X == COORDONNEES_INVENTAIRE && _joueur->cite_possede[i].coordonnees.Y == COORDONNEES_INVENTAIRE)
			nb_de_cite_dans_le_stuff++;
	}

	return nb_de_cite_dans_le_stuff;
}

int RecupererPion(Joueur _joueur,Pions* _pion)
{	
	if(_joueur.couleur == _pion->couleur)
	{
		InitialiserCoordonneesPion(_pion);
		return 0;
	}
	else return 11;
}
