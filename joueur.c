#include <stdio.h>
#include "joueur.h"
#include <stdlib.h>
#define TAILLE 50
int main()
{
    struct Pawn
    {
        int Joueur;
        int Coordx;
        int Coordy;
    };

typedef struct Pawn S_Pawn;
int i;
int j;
int Player;
int Placex;
int Placey;
printf("Quel joueur etes vous (1,2,3,4) ?\n");
scanf("%d",&Player);
printf("Sur quelle case voulez vous poser votre pion (coordonee x puis y) ?\n");
scanf("%d %d",&Placex,&Placey);

S_Pawn Pions={Player,Placex,Placey};
printf("Vous etes le joueur %d, et votre pion se trouve au coordonees %d, %d", Pions.Joueur,Pions.Coordx,Pions.Coordy);

for (i=0;i<TAILLE-20;i++)
{
    for (j=0;j<TAILLE;j++)
    {
        printf(" ");
        if(j==Pions.Coordx*5&&i==Pions.Coordy*3){
            printf("O");
        }
    }
    printf("\n");
}
}
