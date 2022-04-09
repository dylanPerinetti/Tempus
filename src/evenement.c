/*

-------------- TEMPUS --------------

Retrouvez le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au evenement-graphique dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "evenement.h".

Fait par dylan le 21/03/2022
Dernière modifications par dylanPerinetti le 06/04/2022

*/
#include "evenement.h"


int CurseurBas(Tuile _map[10][10], SDL_Renderer* _rendu)
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
        	if(_map[i][j].curseur==1&&j!=9&&CaseInterdite(i,j+1)==0)
        	{
				_map[i][j].curseur=0;
                _map[i][j+1].curseur=1;

                MajCase(_map, i, j, _rendu);
                MajCase(_map, i, j+1, _rendu);
                return 0;
			}
        }
    }
}

/*--------------------------------------------------------------------------*/

int CurseurHaut(Tuile _map[10][10], SDL_Renderer* _rendu)
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(_map[i][j].curseur==1&&j!=0&&CaseInterdite(i,j-1)==0)
            {
                _map[i][j].curseur=0;
                _map[i][j-1].curseur=1;
                MajCase(_map, i, j, _rendu);
                MajCase(_map, i, j-1, _rendu);
                return 0;
            }
        }
    }
}

/*--------------------------------------------------------------------------*/

int CurseurDroite(Tuile _map[10][10], SDL_Renderer* _rendu)
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(_map[i][j].curseur==1&&i!=9&&CaseInterdite(i+1,j)==0)
            {
                _map[i][j].curseur=0;
                _map[i+1][j].curseur=1;
                MajCase(_map, i, j, _rendu);
                MajCase(_map, i+1, j, _rendu);
                return 0;
        	}
        }
    }
}

/*--------------------------------------------------------------------------*/

int CurseurGauche(Tuile _map[10][10], SDL_Renderer* _rendu)
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(_map[i][j].curseur==1&&i!=0&&CaseInterdite(i-1,j)==0)
            {
                _map[i][j].curseur=0;
                _map[i-1][j].curseur=1;
                MajCase(_map, i, j, _rendu);
                MajCase(_map, i-1, j, _rendu);
                return 0;
        	}
        }
    }
}

/*--------------------------------------------------------------------------*/

int SelectionCase(Tuile _map[10][10])
{
	for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(_map[i][j].curseur==1)
            {
                printf("\nVous avez selectionne le pion sur la case %d %d",i,j);
                printf("\n vous avez choisis %d",ChoixAction());
                return 0;
        	}
        }
    }
}

/*--------------------------------------------------------------------------*/

int ChoixAction()
{	
	int choix;
	printf("\nQue voulez vous faire ?");
	printf("\n1 : Deplacer des pions");
	printf("\n2 : Avoir des Enfants");
	printf("\n3 : Combattre");
	//printf("\n4 : Avoir une idee");
	printf("\n4 : Construire une cite\n");
	scanf("%d",&choix);
	return choix;
}

/*--------------------------------------------------------------------------*/