#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objet.h"
#include "joueur.h"

void AfficherCouleurCite(Cite c_)
{
	char nom_couleur[6]={0};				//Update a faire avec un switch
	if(((c_).couleur) == 0)
		strcpy(nom_couleur,"Bleu ");
	if(((c_).couleur) == 1)
		strcpy(nom_couleur,"Blanc");
	if(((c_).couleur) == 2)
		strcpy(nom_couleur,"Rouge");
	if(((c_).couleur) == 3)
		strcpy(nom_couleur,"Rose ");

	printf("La couleur de cette cité est %s\n",nom_couleur);//
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
