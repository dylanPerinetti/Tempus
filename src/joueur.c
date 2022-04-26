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
	for(int i=0; i<7; i++)
	{
		_joueur->carte_joueur[i].couleur=0;
		_joueur->carte_joueur[i].effet=0;
	}
}

/*--------------------------------------------------------------------------*/

void Cree4Joueurs(Joueur* _tab)
{
	for(unsigned char i = 0; i < 4; ++i) CreeJoueur(&_tab[i], i+1);
}

/*--------------------------------------------------------------------------*/

void InitialiserCouleurJoueur(Joueur* _joueur,unsigned char _couleur)
{
	_joueur->couleur=_couleur;
}

/*--------------------------------------------------------------------------*/

void InitialiserNiveauJoueur(Joueur* _joueur)
{
	_joueur->niveau_joueur.niveau=0;
	_joueur->niveau_joueur.deplacement=1;
	_joueur->niveau_joueur.distance=1;
	_joueur->niveau_joueur.enfants=1;
	_joueur->niveau_joueur.nbre_pion_max=2;
	_joueur->niveau_joueur.voyage_naval=0;
	_joueur->niveau_joueur.carte_pioche=1;
	_joueur->niveau_joueur.carte_max=5;
	_joueur->niveau_joueur.actions=1;  //3
}

/*--------------------------------------------------------------------------*/

void AugmenterNiveauJoueur(Joueur* _joueur)
{
	_joueur->niveau_joueur.niveau++;
	switch(_joueur->niveau_joueur.niveau)
	{
		case 1: _joueur->niveau_joueur.carte_pioche=2; _joueur->niveau_joueur.actions=3; break;
		case 2: _joueur->niveau_joueur.enfants=2; _joueur->niveau_joueur.actions=3; break;
		case 3: _joueur->niveau_joueur.nbre_pion_max=3; _joueur->niveau_joueur.actions=4; break; //4
		case 4: _joueur->niveau_joueur.distance=2; _joueur->niveau_joueur.actions=4; break; //4
		case 5: _joueur->niveau_joueur.deplacement=2; _joueur->niveau_joueur.actions=4; break; //4
		case 6: _joueur->niveau_joueur.voyage_naval=1; _joueur->niveau_joueur.actions=5; break;  //5
		case 7: _joueur->niveau_joueur.carte_max=7; _joueur->niveau_joueur.actions=5; break; //5
		case 8: _joueur->niveau_joueur.nbre_pion_max=4; _joueur->niveau_joueur.actions=6; break; //6
		case 9: _joueur->niveau_joueur.deplacement=3; _joueur->niveau_joueur.distance=5; _joueur->niveau_joueur.actions=6; break; //6
	}
}

/*--------------------------------------------------------------------------*/

void AfficherNiveauJoueur(Joueur* _joueur)
{
	printf("\nLe niveau du Joueur%u est %u \n", _joueur->couleur, _joueur->niveau_joueur);
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

int EntrerNomJoueur(Joueur *_joueur)
{
	printf("\nJoueur %d : ", _joueur->couleur);
	char poubelle[30];
	char entree[30];

	if(_joueur->couleur==1) gets(poubelle); //Il y a un entrée dans la mémoire tampon, donc on a pas trouvé d'autres solutions pour le degager
	
	gets(entree);
	_joueur->pseudo = (char*) malloc(strlen(entree)+1);

	if(_joueur->pseudo!=NULL)
	{
		strcpy(_joueur->pseudo, entree);
		printf("\nBienvenue %s", _joueur->pseudo);
		return 0;
	}
	else return 1;
}

void PiocherCarte(Joueur* _joueur)
{
	int i=0; int fin=0; 
	while(i<7&&fin==0)
	{
		if(_joueur->carte_joueur[i].couleur==0)
		{
			_joueur->carte_joueur[i].couleur = rand()%5;  //5 mais jsuis pas sur
			_joueur->carte_joueur[i].effet = rand()%5;   //la meme
			fin=1;
		}
	i++;
	}
}

void RangerCartes(Joueur* _joueur)
{
	for(int i=0; i<7; i++)
	{
		if(_joueur.carte_joueur[i].couleur==0)
		{
			int j=6; int fin=0;
			while(j>=0&&fin==0)
			{
				int memoire1, memoire2;
				if(_joueur.carte_joueur[j].couleur!=0)
				{
					_joueur.carte_joueur[i].couleur=_joueur.carte_joueur[j].couleur;
					_joueur.carte_joueur[i].effet=_joueur.carte_joueur[j].effet;
					_joueur.carte_joueur[j].couleur=0;
					_joueur.carte_joueur[j].effet=0;
					fin=1;
				}

			}
		}
	}
}

int CaseNaissanceDispo(Tuile _map[10][10], Joueur* _joueur)
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(_map[i][j].type_terrain=='0' && _joueur->couleur+48 ==_map[i][j].couleur && _joueur->niveau_joueur.nbre_pion_max+48>_map[i][j].nombre_pion) return 1;
		}
	}
	return 0;
}

