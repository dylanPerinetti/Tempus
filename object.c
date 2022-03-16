#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objet.h"
#include "joueur.h"

#define X_MIN 0
#define X_MAX 8
#define Y_MIN 0
#define Y_MAX 8

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



/*
void Test_coord(Joueur j,uint8_t c){

    for (int i = 0; i < 16; ++i)
	{
		printf("Pion %d se trouve en x=%d y=%d",i,j.pions_possede[i].Coordx,j.pions_possede[i].Coordy);
	}
	for (int i = 0; i < 8; ++i)
	{
		Ville ville_i={i,c,-1,-1};
		printf("Ville %d se trouve en x=%d y=%d",i,j.ville_possede[i].Coordx,j.ville_possede[i].Coordy);
	}
}
*/
