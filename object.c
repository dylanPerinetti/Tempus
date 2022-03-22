/*
 
-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au Objet dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "objet.h".

Fait par dylan le 15/03/2022
Dernière modifications par dylanPerinetti le 22/03/2022 
Pour correctif de beug

*/

#include "objet.h"
#include "joueur.h"

#define X_MIN 0
#define X_MAX 10
#define Y_MIN 0
#define Y_MAX 10
#define NOMBRE_PION 16
#define NOMBRE_CITE 8
#define COORDONNEES_INVENTAIRE 99



void GenerateurID(Id_Objet *_id,unsigned char _couleur)
{
	static unsigned char _numeros_serie = 0;
	_numeros_serie++;
	char _lettre_serie[5]="BROP";;
	_id->numero_serie = _numeros_serie;
	_id->lettre_serie = _lettre_serie[_couleur];
}


void InitialiserCouleurPion(Pions* _pion,unsigned char _couleur)
{
	_pion->couleur = _couleur;
}


void InitialiserCouleurCite(Cite* _cite,unsigned char _couleur)
{
	_cite->couleur = _couleur;
}


void InitialiserCoordonneesPion(Pions* _pion)
{
	_pion->coordonnees.X=COORDONNEES_INVENTAIRE;
	_pion->coordonnees.Y=COORDONNEES_INVENTAIRE;
}


void InitialiserCoordonneesCite(Cite* _cite)
{
	_cite->coordonnees.X=COORDONNEES_INVENTAIRE;
	_cite->coordonnees.Y=COORDONNEES_INVENTAIRE;
}


void InitialiserNiveauCite(Cite* _cite)
{
	_cite->niveaux_cite = 0;
}


void InitialiserPions(Pions* _pion,unsigned char _couleur)
{
	GenerateurID(&_pion->id_pion,_couleur);
	InitialiserCouleurPion(_pion,_couleur);
	InitialiserCoordonneesPion(_pion);
}


void InitialiserCite(Cite* _cite,unsigned char _couleur)
{
	GenerateurID(&(_cite->id_cite),_couleur);
	InitialiserCouleurCite(_cite,_couleur);
	InitialiserCoordonneesCite(_cite);
	InitialiserNiveauCite(_cite);
}



void AfficherCouleurCite(Cite _cite)
{
	char nom_couleur[6]={0};				
	switch(_cite.couleur)
	{
		case 0:
			strcpy(nom_couleur,"Bleu ");
			break;
		case 1:
			strcpy(nom_couleur,"Blanc");
			break;
		case 2:
			strcpy(nom_couleur,"Rouge");
			break;
		case 3:
			strcpy(nom_couleur,"Rose ");
			break;
		default :
			strcpy(nom_couleur,"ERROR");
			printf("\n\n ERREUR %u\n",_cite.couleur);
	}

	printf("\nLa couleur de cette cite est %s\n",nom_couleur);//
}


void AfficherCouleurPion(Pions _pion)
{
	char nom_couleur[6]={0};				//Update a faire avec un switch
	switch(_pion.couleur)
	{
		case 0:
			strcpy(nom_couleur,"Bleu ");
			break;
		case 1:
			strcpy(nom_couleur,"Blanc");
			break;
		case 2:
			strcpy(nom_couleur,"Rouge");
			break;
		case 3:
			strcpy(nom_couleur,"Rose ");
			break;
		default :
			strcpy(nom_couleur,"ERROR");
			printf("\n\n ERREUR %u\n",_pion.couleur);
	}

	printf("\nLa couleur de ce pion est %s\n",nom_couleur);
}


void AfficherIDCite(Cite _cite)
{
	printf("\nL'ID de cette cite est %u%c",_cite.id_cite.numero_serie, _cite.id_cite.lettre_serie);
}


void AfficherIDPion(Pions _pion)
{
	printf("\nL'ID de ce pion est %u%c",(_pion).id_pion.numero_serie,_pion.id_pion.lettre_serie);
}


void AfficherCoordonneesPion(Pions _pion)
{
	int x = _pion.coordonnees.X;
	int y = _pion.coordonnees.Y;
	if(x != COORDONNEES_INVENTAIRE && y != COORDONNEES_INVENTAIRE) printf("\nLe pion %u%c a pour coordonnes x = [%d] et y = [%d]\n",_pion.id_pion.numero_serie,_pion.id_pion.lettre_serie,x,y);
	else if (x == COORDONNEES_INVENTAIRE && y == COORDONNEES_INVENTAIRE) printf("\nLe pion %u%c est dans votre inventaire !",_pion.id_pion.numero_serie,_pion.id_pion.lettre_serie);
	else printf("\nERROR");
}


void AfficherCoordonneesCite(Cite _cite)
{
	int x = _cite.coordonnees.X;
	int y = _cite.coordonnees.Y;
	if(x != COORDONNEES_INVENTAIRE && y != COORDONNEES_INVENTAIRE) printf("\nLa Cite %u%c a pour coordonnees x = [%d] et y = [%d]\n",_cite.id_cite.numero_serie, _cite.id_cite.lettre_serie,x,y);
	else if (x == COORDONNEES_INVENTAIRE && y == COORDONNEES_INVENTAIRE) printf("\nLa Cite %u%c est dans votre inventaire !",_cite.id_cite.numero_serie, _cite.id_cite.lettre_serie);
	else printf("\nERROR");
}


int DeplacerPionDroite(Pions* p)
{
	if((p->coordonnees.X)<X_MAX)p->coordonnees.X++;
	else return 2;
	return 0;
}


int DeplacerPionGauche(Pions* p)
{
	if((p->coordonnees.X)>X_MIN)p->coordonnees.X--;
	else return 2;
	return 0;
}


int DeplacerPionHautDroite(Pions* p)
{
	if((p->coordonnees.X)<X_MAX)p->coordonnees.X++;
	else return 2;
	if((p->coordonnees.Y)>Y_MIN)p->coordonnees.Y--;
	else return 22;
	return 0;
}


int DeplacerPionHautGauche(Pions* p)
{
	if((p->coordonnees.X)>X_MIN)p->coordonnees.X--;
	else return 2;
	if((p->coordonnees.Y)>Y_MIN)p->coordonnees.Y--;
	else return 22;
	return 0;
}


int DeplacerPionBasGauche(Pions* p)
{
	if((p->coordonnees.X)>X_MIN)p->coordonnees.X--;
	else return 2;
	if((p->coordonnees.Y)<Y_MAX)p->coordonnees.Y++;
	else return 22;
	return 0;
}


int DeplacerPionBasDroite(Pions* p)
{
	if((p->coordonnees.X)<X_MAX)p->coordonnees.X++;
	else return 2;
	if((p->coordonnees.Y)<Y_MAX)p->coordonnees.Y++;
	else return 22;
	return 0;
}

int PlacerPionSurMap(Pions* _pion, unsigned char _x, unsigned char _y)		//placer Pion du stuff du joueur sur la map au coordoner x,y
{
	if(_pion->coordonnees.X == COORDONNEES_INVENTAIRE && _pion->coordonnees.Y == COORDONNEES_INVENTAIRE)
	{
		if( _x >= X_MIN && _x <= X_MAX)_pion->coordonnees.X = _x;
		else return 2;
		if( _y >= Y_MIN && _y <= Y_MAX)_pion->coordonnees.Y = _y;
		else return 22;
		return 0;
	}
	else return 1;
}


int PlacerCiteSurMap(Cite* _cite, unsigned char _x,  unsigned char _y)		//plcer Citer du stuff du joueur sur la map au coordoner x,y
{
	if(_cite->coordonnees.X == COORDONNEES_INVENTAIRE && _cite->coordonnees.Y == COORDONNEES_INVENTAIRE)
	{
		if( _x >= X_MIN && _x <= X_MAX)_cite->coordonnees.X = _x;
		else return 2;
		if( _y >= Y_MIN && _y <= Y_MAX)_cite->coordonnees.Y = _y;
		else return 22;
		return 0;
	}
	else return 1;
}


void AugmenterNiveauCite(Cite* _cite)
{
	_cite->niveaux_cite++;
}


void ChangerCouleurCite(Cite* c_,unsigned char _couleur)		//Changer la couleur d'une Cite par celle de _couleur
{
	(*c_).couleur = _couleur;
}


void AfficherErreurDeplacementObjet(int _erreur)
{
	switch(_erreur)
	{
		case 0:
			break;
		case 1:
			fprintf(stderr,"\nErreur%d Probleme le pion n'est pas dans l'inventaire",_erreur);
			break;
		case 2:
			fprintf(stderr,"\nErreur%d Probleme coordonnees X",_erreur);
			break;
		case 11:
			fprintf(stderr,"\nErreur%d Probleme couleur objet differrente de celle du joueur",_erreur);
			break;
		case 22:
			fprintf(stderr,"\nErreur%d Probleme coordonnees Y",_erreur);
			break;
		default:
			fprintf(stderr,"\nErreur Inconnue");
	}
}
