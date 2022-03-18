#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objet.h"
#include "joueur.h"

#define X_MIN 0
#define X_MAX 10
#define Y_MIN 0
#define Y_MAX 10
#define NOMBRE_PION 16
#define NOMBRE_CITE 8


int* GenerateurID(Id_Objet *_id)
{
	static uint8_t _numeros_serie = 0;
	_numeros_serie++;
	char _lettre_serie[5]="AZER";
	uint8_t _letre = rand()%5;
	_id->numero_serie = _numeros_serie;
	_id->lettre_serie = _lettre_serie[_letre];
	return _id;
}


void InitialiserCouleurPion(Pions* _pion,uint8_t _couleur)
{
	_pion->couleur = _couleur;
}


void InitialiserCouleurCite(Cite* _cite,uint8_t _couleur)
{
	_cite->couleur = _couleur;
}


void InitialiserCoordonneesPion(Pions* _pion)
{
	_pion->coord_x=-1;
	_pion->coord_y=-1;
}


void InitialiserCoordonneesCite(Cite* _cite)
{
	_cite->coord_x=-1;
	_cite->coord_y=-1;
}


void InitialiserNiveauCite(Cite* _cite)
{
	_cite->niveaux_cite = 0;
}


void Initialiser16Pions(Pions* _pion,uint8_t _couleur)
{
	GenerateurID(&_pion->id_pion);
	InitialiserCouleurPion(_pion,_couleur);
	InitialiserCoordonneesPion(_pion);
}


void Initialiser8Cite(Cite* _cite,uint8_t _couleur)
{
	GenerateurID(&_cite->id_cite);
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

	printf("\nLa couleur de cette cité est %s\n",nom_couleur);//
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
	printf("\nL'ID de cette cité est %u%c",_cite.id_cite.numero_serie, _cite.id_cite.lettre_serie);
}


void AfficherIDPion(Pions _pion)
{
	printf("\nL'ID de ce pion est %u%c",(_pion).id_pion.numero_serie,_pion.id_pion.lettre_serie);
}


void AfficherCoordonneesPion(Pions _pion)
{
	int x = _pion.coord_x;
	int y = _pion.coord_y;
	if(x != -1 && y != -1)
		printf("Le pion a pour coordonnées x = [%d] et y = [%d]\n",x,y);
	else if (x == -1 && y == -1)
		printf("Le pion n°%u%c est dans votre inventaire !",_pion.id_pion.numero_serie,_pion.id_pion.lettre_serie);
	else
		printf("ERROR");
}


void AfficherCoordonneesCite(Cite _cite)
{
	int x = _cite.coord_x;
	int y = _cite.coord_y;
	if(x != -1 && y != -1)
		printf("La Cité a pour coordonnées x = [%d] et y = [%d]\n",x,y);
	else if (x == -1 && y == -1)
	printf("La Cité n°%u%c est dans votre inventaire !",_cite.id_cite.numero_serie, _cite.id_cite.lettre_serie);
	else
		printf("ERROR");
}


int DeplacerPionDroite(Pions* p)
{
	if((p->coord_x)<X_MAX)p->coord_x++;
	else return 2;
	return 0;
}


int DeplacerPionGauche(Pions* p)
{
	if((p->coord_x)>X_MIN)p->coord_x--;
	else return 2;
	return 0;
}


int DeplacerPionHautDroite(Pions* p)
{
	if((p->coord_x)<X_MAX)p->coord_x++;
	else return 2;
	if((p->coord_y)>Y_MIN)p->coord_y--;
	else return 22;
	return 0;
}


int DeplacerPionHautGauche(Pions* p)
{
	if((p->coord_x)>X_MIN)p->coord_x--;
	else return 2;
	if((p->coord_y)>Y_MIN)p->coord_y--;
	else return 22;
	return 0;
}


int DeplacerPionBasGauche(Pions* p)
{
	if((p->coord_x)>X_MIN)p->coord_x--;
	else return 2;
	if((p->coord_y)<Y_MAX)p->coord_y++;
	else return 22;
	return 0;
}


int DeplacerPionBasDroite(Pions* p)
{
	if((p->coord_x)<X_MAX)p->coord_x++;
	else return 2;
	if((p->coord_y)<Y_MAX)p->coord_y++;
	else return 22;
	return 0;
}

int PlacerPionSurMap(Pions* _pion, int _x, int _y)		//placer Pion du stuff du joueur sur la map au coordoner x,y
{
	if(_pion->coord_x == -1 && _pion->coord_y == -1)
	{
		if( _x >= X_MIN && _x <= X_MAX)_pion->coord_x = _x;
		else return 2;
		if( _y >= Y_MIN && _y <= Y_MAX)_pion->coord_y = _y;
		else return 22;
		return 0;
	}
	else return 11;
}


int PlacerCiteSurMap(Cite* _cite, int _x,  int _y)		//plcer Citer du stuff du joueur sur la map au coordoner x,y
{
	if(_cite->coord_x == -1 && _cite->coord_y == -1)
	{
		if( _x >= X_MIN && _x <= X_MAX)_cite->coord_x = _x;
		else return 2;
		if( _y >= Y_MIN && _y <= Y_MAX)_cite->coord_y = _y;
		else return 22;
		return 0;
	}
	else return 11;
}


void AugmenterNiveauCite(Cite* _cite)
{
	_cite->niveaux_cite++;
}


void ChangerCouleurCite(Cite* c_,uint8_t _couleur)		//Changer la couleur d'une Cite par celle de _couleur
{
	(*c_).couleur = _couleur;
}
