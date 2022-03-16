#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objet.h"
#include "joueur.h"

#define X_MIN 0
#define X_MAX 10
#define Y_MIN 0
#define Y_MAX 10

void AfficherCouleurCite(Cite c_)
{
	char nom_couleur[6]={0};				//Update a faire avec un switch
	switch((c_).couleur)
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
	}

	printf("\nLa couleur de cette cité est %s\n",nom_couleur);//
}
void AfficherCouleurPion(Pions p)
{
	char nom_couleur[6]={0};				//Update a faire avec un switch
	switch(p.couleur)
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
	}

	printf("\nLa couleur de ce pion est %s\n",nom_couleur);
}

void AfficherIDCite(Cite c_)
{
	printf("\nL'ID de cette cité est %u",(c_).id_cite);
}
void AfficherIDPion(Pions p)
{
	printf("\nL'ID de ce pion est %u",(p).id_pion);
}
void AfficherCoordonneesPion(Pions p)
{
	int x = p.coord_x;
	int y = p.coord_y;
	if(x != -1 && y != -1)
		printf("Le pion a pour coordonnées x = [%d]et y = [%d]\n",x,y);
	else if (x == -1 && y == -1)
		printf("Le pion n°%u est dans votre inventaire !",p.id_pion);
	else
		printf("ERROR");
}
void AfficherCoordonneesCite(Cite c_)
{
	int x = (c_).coord_x;
	int y = (c_).coord_y;
	if(x != -1 && y != -1)
		printf("La Cité a pour coordonnées [x][y]\n     [%d][%d]\n",x,y);
	else if (x == -1 && y == -1)
	printf("La Cité n°%u est dans votre inventaire !",(c_).id_cite);
	else
		printf("ERROR");
}
int DeplacerPionDroite(Pions* p)
{
	if((p->coord_x)<X_MAX)p->coord_x++;
	else return 1;
	return 0;
}
int DeplacerPionGauche(Pions* p)
{
	if((p->coord_x)>X_MIN)p->coord_x--;
	else return 1;
	return 0;
}
int DeplacerPionHautDroite(Pions* p)
{
	if((p->coord_x)<X_MAX)p->coord_x++;
	else return 1;
	if((p->coord_y)>Y_MIN)p->coord_y--;
	else return 1;
	return 0;
}
int DeplacerPionHautGauche(Pions* p)
{
	if((p->coord_x)>X_MIN)p->coord_x--;
	else return 1;
	if((p->coord_y)>Y_MIN)p->coord_y--;
	else return 1;
	return 0;
}
int DeplacerPionBasGauche(Pions* p)
{
	if((p->coord_x)>X_MIN)p->coord_x--;
	else return 1;
	if((p->coord_y)<Y_MAX)p->coord_y++;
	else return 1;
	return 0;
}
int DeplacerPionBasDroite(Pions* p)
{
	if((p->coord_x)<X_MAX)p->coord_x++;
	else return 1;
	if((p->coord_y)<Y_MAX)p->coord_y++;
	else return 1;
	return 0;
}
