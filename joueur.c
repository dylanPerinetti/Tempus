/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au Joueur dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier joueur.h

Fait par dylan le 14/03/2022
Dernière modifications par dylanPerinetti le 22/03/2022

Je suis acctuellement en train de develloper les fonction:
	-

*/
#include "objet.h"
#include "joueur.h"

#define NOMBRE_PION 16
#define NOMBRE_CITE 8


void CreeJoueur(Joueur* _joueur,unsigned char _couleur)//pour la crééation d'un nouveaux joueur
{
	//malloc(sizeof(char)*);
	//free();
	//strcpy(j->nom_utilisateur,nom);
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


void Cree4Joueurs(Joueur tab[])			//Pour Créé 4 Joueur
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


void AugmenterNiveauJoueur(Joueur* j)	//Pour Indenter le niveux d'un joueuer 
{
	j->niveaux_joueur++;
}


void AfficherNiveauJoueur(Joueur* j)	//Pour Afficher le niveaux d'un joueur
{
	printf("\nLe niveau du Joueur%u est %u \n", j->couleur, j->niveaux_joueur);
}


void AfficherInventaireJoueur(Joueur* j)//Pour Afficher L'inventaire d'un joueur
{
	int *tab=InventaireJoueur(j);
	printf("Le joueur %d Possede %d Pions et Possede %d Cite",j->couleur ,tab[0],tab[1]);
}


int* InventaireJoueur(Joueur* _joueur)	//Pour Ranger l'inventaire dans un tableau[<PIONS>,<CITE>]
{
	static int tab[2];
	tab[0] = InventairePions(_joueur);
	tab[1] = InventaireCite(_joueur);
	return tab;
}


int InventairePions(Joueur* _joueur)	//Pour Répertorier les Pions d'un joueur dans l'inventaire
{
	int nb_de_pion_dans_le_stuff = 0;

	for (unsigned char i = 0; i < 16; ++i)
	{
		if(_joueur->pion_possede[i].coordonnees.X == -1 && _joueur->pion_possede[i].coordonnees.Y == -1)
			nb_de_pion_dans_le_stuff++;
	}

	return nb_de_pion_dans_le_stuff;
}


int InventaireCite(Joueur* _joueur)		//Pour Répertorier les Cite d'un joueur dans l'inventaire
{
	int nb_de_cite_dans_le_stuff=0;

	for (unsigned char i = 0; i < 8; ++i)
	{
		if(_joueur->cite_possede[i].coordonnees.X == -1 && _joueur->cite_possede[i].coordonnees.Y == -1)
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
