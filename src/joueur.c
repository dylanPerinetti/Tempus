/*************************************************** 

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au Joueur dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier joueur.h

Fait par dylan le 14/03/2022
Dernière modifications par dylanPerinetti le 06/04/2022

****************************************************/

#include "joueur.h"
#include "map.h"

#define NOMBRE_PION 16
#define NOMBRE_CITE 8
#define COORDONNEES_INVENTAIRE 99

/*--------------------------------------------------------------------------*/

void CreeJoueur(Joueur* _joueur,unsigned char _couleur)//pour la crééation d'un nouveaux joueur
{
	InitialiserCouleurJoueur(_joueur,_couleur);
	InitialiserNiveauJoueur(_joueur);
	_joueur->pions_possede = NOMBRE_PION;
	_joueur->cite_possede = NOMBRE_CITE;
}

/*--------------------------------------------------------------------------*/

void Cree4Joueurs(Joueur* _tab)
{
	for(unsigned char _i = 0; _i < 4; ++_i) CreeJoueur(&_tab[_i], _i+1);
}

/*--------------------------------------------------------------------------*/

void InitialiserCouleurJoueur(Joueur* _joueur,unsigned char _couleur)
{
	_joueur->couleur=_couleur;
}

/*--------------------------------------------------------------------------*/

void InitialiserNiveauJoueur(Joueur* _joueur)
{
	_joueur->niveaux_joueur=0;
}

/*--------------------------------------------------------------------------*/

void AugmenterNiveauJoueur(Joueur* _joueur)
{
	_joueur->niveaux_joueur++;
}

/*--------------------------------------------------------------------------*/

void AfficherNiveauJoueur(Joueur* _joueur)
{
	printf("\nLe niveau du Joueur%u est %u \n", _joueur->couleur, _joueur->niveaux_joueur);
}

/*--------------------------------------------------------------------------*/

void AfficherInventaireJoueur(Joueur* _joueur)
{
	int *_tab=InventaireJoueur(_joueur);
	printf("\nLe joueur %d Possede %d Pions et Possede %d Cite",_joueur->couleur ,_tab[0],_tab[1]);
}

/*--------------------------------------------------------------------------*/

int* InventaireJoueur(Joueur* _joueur)	//Pour Ranger l'inventaire dans un tableau[<PIONS>,<CITE>]
{
	static int _tab_static[2];
	_tab_static[0] = _joueur->pions_possede;
	_tab_static[1] = _joueur->cite_possede;
	return _tab_static;
}

/*--------------------------------------------------------------------------*/

int RecupererPion(Joueur* _joueur,Tuile* _tuile)
{	
	if(_joueur->couleur == _tuile->couleur)
	{
		_joueur->pions_possede++;
		_tuile->nombre_pion--;
		return 0;
	}
	else return 11;
}

/*--------------------------------------------------------------------------*/