/*

-------------- TEMPUS --------------

Retrouvez le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au evenement-graphique dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "evenement.h".

Fait par dylan le 21/03/2022
Dernière modifications par dylanPerinetti le 24/03/2022

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

int SelectionCase(Tuile _map[10][10], SDL_Renderer* _rendu, int *_phase_jeu, int *_selectionx, int *_selectiony, int *_point_deplacement)
{
	int choix;
	for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(_map[i][j].curseur==1)
            {
                switch(*_phase_jeu)
                {
                	case 0: SelectionPion(_map, i, j, _phase_jeu, _selectionx, _selectiony); break;
                	case 1: Deplacement(_map, _rendu, _phase_jeu, i, j, _selectionx, _selectiony, _point_deplacement); MajCase(_map, i, j, _rendu); MajCase(_map, *_selectionx, *_selectiony, _rendu); break;
                	case 2:break;                                      //LA IMPORTANT YAURA TOUTES LES FONCTIONS IMPORTANTES GENRE DEPLACER PION
                	case 3:break;
                	case 4:break;
                	case 5:break;
                }
				
				return 0;
            }
        }
    }
}




void SelectionPion(Tuile _map[10][10], int i, int j, int *phase_jeu, int *_selectionx, int *_selectiony)
{
	if(_map[i][j].nombre_pion!='0'&&_map[i][j].couleur=='1')         //<------ faudra aussi mettre la variable du joueur en train de jouer (par défaut je mets 1 pour tester)
    {
		printf("\nVous avez selectionne le pion sur la case %d %d",i,j);       
        *phase_jeu=ChoixAction();
        printf("\nVous avez choisis %d",*phase_jeu);
        NouvelleSelectionCase(_selectionx, _selectiony, i, j);
	}
	else printf("\nVous n'avez pas selectionne un de vos pions");
}



void Deplacement(Tuile _map[10][10], SDL_Renderer* _rendu, int *phase_jeu, int i, int j, int *_selectionx, int *_selectiony, int *_point_deplacement)
{
	unsigned char couleur_temp='1';												//<------ faudra aussi mettre la variable du joueur en train de jouer (par défaut je mets 1 pour tester)
	int nbre_pion_deplace=0;
	if(*_point_deplacement>0)
	{
		if(_map[i][j].type_terrain=='5')
		{
			printf("\nVous ne pouvez pas vous deplacer sur un lac");
		}

		else if(_map[i][j].taille_ville!='0' && *_point_deplacement==1)
		{
			printf("\nVous ne pouvez pas finir votre deplacement sur une ville");
		}

		
		else if(_map[i][j].couleur==couleur_temp|| _map[i][j].couleur=='0')
		{
			
			printf("\nCombien de Pions voulez-vous deplacer ?");
			do
			{
				printf("\n");
				scanf("%d",&nbre_pion_deplace);
				if(nbre_pion_deplace>_map[i][j].nombre_pion-47) printf("\nIl n'y a pas %d pions sur cette case",nbre_pion_deplace);
			
			}while(nbre_pion_deplace>_map[i][j].nombre_pion-47);

			DeplacementPion(_map, _rendu, *_selectionx, *_selectiony, i, j, couleur_temp, nbre_pion_deplace);
		
			*_point_deplacement=*_point_deplacement-1;
			printf("\nIl vous reste %d point de deplacement", *_point_deplacement);
		
			NouvelleSelectionCase(_selectionx, _selectiony, i, j);
		}

		else
		{
			printf("\nVous ne pouvez pas vous deplacer sur une case controlee par d'autres joueurs");
		}
	}
	
	else {*phase_jeu=0; *_point_deplacement=4;} 
}




int ChoixAction()
{	
	int choix;
	printf("\nQue voulez vous faire ?");
	printf("\n1 : Deplacer des pions");
	printf("\n2 : Avoir des Enfants");
	printf("\n3 : Combattre");
	printf("\n4 : Avoir une idee");
	printf("\n5 : Construire une cite\n");
	
	do
	{
	printf("\nChoisissez un nombre entre 1 et 4\n");
	
	printf("\n");
	scanf("%d",&choix);
	}while(choix>5||choix<1);
	return choix;
}

void DeplacementPion(Tuile _map[10][10], SDL_Renderer* _rendu, int departx, int departy, int arriveex, int arriveey, unsigned char couleur, int nbre_pion_deplace)
{
	_map[departx][departy].nombre_pion = _map[departx][departy].nombre_pion-nbre_pion_deplace;
	_map[arriveex][arriveey].nombre_pion = _map[arriveex][arriveey].nombre_pion+nbre_pion_deplace;
	
	_map[arriveex][arriveey].couleur = couleur;
	
	if(_map[departx][departy].nombre_pion==48)
	{
		_map[departx][departy].couleur = '0';
	}
	
	MajCase(_map, departx, departy, _rendu); 
	MajCase(_map, arriveex, arriveey, _rendu);
	//printf("\n %d %d %c %d %d %c %c %c", departy, departy, _map[departx][departy].nombre_pion, arriveex, arriveey, _map[arriveex][arriveey].nombre_pion, _map[departx][departy].couleur,_map[arriveex][arriveey].couleur);
}


void NouvelleSelectionCase(int *_selectionx, int *_selectiony,  int _coordx, int _coordy)
{
	*_selectionx=_coordx;
    *_selectiony=_coordy;
}