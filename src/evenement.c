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

int SelectionCase(Tuile _map[10][10], SDL_Renderer* _rendu, int _memoire[5])
{
	for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(_map[i][j].curseur==1)
            {
                switch(_memoire[2])
                {
                	case 0: SelectionPion(_map, i, j, _memoire); break;
                	case 1: Deplacement(_map, _rendu, i, j, _memoire); MajCase(_map, i, j, _rendu); MajCase(_map, _memoire[0], _memoire[1], _rendu); break;
                	case 2:break;                                      
                	case 3:break;
                	case 4:break;
                	case 5:break;
                }
				
				return 0;
            }
        }
    }
}




void SelectionPion(Tuile _map[10][10], int i, int j, int _memoire[5])
{
	if(_map[i][j].nombre_pion!='0'&&_map[i][j].couleur=='1')         //<------ faudra aussi mettre la variable du joueur en train de jouer (par défaut je mets 1 pour tester)
    {
		printf("\nVous avez selectionne le pion sur la case %d %d",i,j);       
        _memoire[2]=ChoixAction();
        printf("\nVous avez choisis %d",_memoire[2]);
        NouvelleSelectionCase(_memoire, i, j);
	}
	else printf("\nVous n'avez pas selectionne un de vos pions");
}




int Deplacement(Tuile _map[10][10], SDL_Renderer* _rendu, int i, int j, int _memoire[5])
{
	unsigned char couleur_temp='1';												//<------ faudra aussi mettre la variable du joueur en train de jouer (par défaut je mets 1 pour tester)

	if(CaseAdjacente(_memoire[0], _memoire[1], i, j)==0)
	{
		printf("\nVous devez selectionner une case adjacente");
		return 0;
	}

	if(_memoire[3]>0&&CaseAdjacente(_memoire[0], _memoire[1], i, j)==1)
	{
		if(_map[i][j].type_terrain=='5')
		{
			printf("\nVous ne pouvez pas vous deplacer sur un lac");
		}

		else if(_map[i][j].taille_ville!='0' && _memoire[3]==1)
		{
			printf("\nVous ne pouvez pas finir votre deplacement sur une ville");
		}

		
		else if(_map[i][j].couleur==couleur_temp|| _map[i][j].couleur=='0')
		{
			
			if(_memoire[4]==-1)
			{
				printf("\nCombien de Pions voulez-vous deplacer ?");
				do
				{
					printf("\n");
					scanf("%d",&_memoire[4]);
				
					if(_memoire[4]>_map[i][j].nombre_pion-47) printf("\nIl n'y a pas %d pions sur cette case",_memoire[4]);
			
				}while(_memoire[4]>_map[i][j].nombre_pion-47);
			}

			DeplacementPion(_map, _rendu, _memoire[0], _memoire[1], i, j, couleur_temp, _memoire[4]);
		
			_memoire[3]=_memoire[3]-1;
			printf("\nIl vous reste %d point de deplacement", _memoire[3]);
		
			NouvelleSelectionCase(_memoire, i, j);
		}

		else
		{
			printf("\nVous ne pouvez pas vous deplacer sur une case controlee par d'autres joueurs");
		}
	}
	
	else {_memoire[2]=0; _memoire[3]=4; _memoire[4]=-1;} 
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


void NouvelleSelectionCase(int _memoire[5],  int _coordx, int _coordy)
{
	_memoire[0]=_coordx;
    _memoire[1]=_coordy;
}
