/*

-------------- TEMPUS --------------

Retrouvez le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au evenement-graphique dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "evenement.h".

Fait par dylan le 21/03/2022
Dernière modifications par dylanPerinetti le 24/03/2022

*/
#include "evenement.h"

void LancementPartie(Tuile _map[10][10], Joueur _joueur[4], SDL_Renderer* _rendu, SDL_Window* _fenetre)
{
	int fin_tour=0;
	int k=0;
	SDL_bool programme_lance = SDL_TRUE;
	int memoire[5]; //Tableau int : int selectionx; int selectiony; int phase_jeu; int point_dep_restant; int nbre_pion_deplace;
    memoire[2]=0;
    memoire[3]=4;
    memoire[4]=-1;
	
	printf("\n---------------------Bienvenue dans Tempus-----------------------");
	printf("\n\n Veuillez entrer les pseudos des joueurs :");
	
	for(int i=0;i<4;i++)
	{
		printf("\nJoueur %d :", i+1);
		scanf("%s",_joueur[0].pseudo);
		printf("\nBienvenue %s", _joueur[0].pseudo);
	}

	SDL_Event event;

	for(int i=0; i<3; i++)
	{
	    while(programme_lance&&fin_tour==0)
	    {
	        SDL_Event event;
	        while(SDL_PollEvent(&event))
	        {
	            switch(event.type)
	            {
	                case SDL_KEYDOWN: 
			            switch(event.key.keysym.sym)
			            {
			                case SDLK_DOWN: CurseurBas(_map, _rendu); continue;
			                case SDLK_UP: CurseurHaut(_map, _rendu); continue;
			                case SDLK_RIGHT: CurseurDroite(_map, _rendu); continue;
			                case SDLK_LEFT: CurseurGauche(_map, _rendu); continue;
			                case SDLK_SPACE: fin_tour=SelectionCase(_map, _rendu, memoire, _joueur[k]); continue;

			             	default : continue;
	            		}
	            	
	            	case SDL_QUIT: programme_lance = SDL_FALSE; break;
	                default : break;
	            }
	        }
	    }
	    memoire[2]=0; memoire[3]=4; memoire[4]=-1;
	    k++;
	    printf("\nAu tour du joueur %d", k+1);
	    fin_tour=0;
	}
    
    SDL_DestroyRenderer(_rendu);
    SDL_DestroyWindow(_fenetre);
    SDL_Quit();
}


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

int SelectionCase(Tuile _map[10][10], SDL_Renderer* _rendu, int _memoire[5], Joueur _joueur)
{
	int etat;
	for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(_map[i][j].curseur==1)
            {
                switch(_memoire[2])
                {
                	case -1: break;
                	case 0: SelectionPion(_map, i, j, _memoire, _joueur); return 0; break;
                	case 1: return Deplacement(_map, _rendu, i, j, _memoire, _joueur); break;
                	case 2:break;                                      
                	case 3:break;
                	case 4:break;
                	case 5:break;
                }
            }
        }
    }
}

int PlacementPion(Tuile _map[10][10], int i, int j, Joueur _joueur)
{
	if(_map[i][j].type_terrain=='5')
	{
		printf("\nVous ne pouvez pas poser de pions sur un lac");
		return 0;
	}
	else if(_map[i][j].couleur!=_joueur.couleur)
	{
		printf("\nCette case appartient deja a quelqu'un d'autre");
		return 0;
	}
	else
	{
		_map[i][j].nombre_pion++;
	}
}


void SelectionPion(Tuile _map[10][10], int i, int j, int _memoire[5], Joueur _joueur)
{
	if(_map[i][j].nombre_pion!='0'&&_map[i][j].couleur==(_joueur.couleur+48))      
    {
		printf("\nVous avez selectionne le pion sur la case %d %d",i,j);       
        _memoire[2]=ChoixAction();
        printf("\nVous avez choisis %d",_memoire[2]);
        NouvelleSelectionCase(_memoire, i, j);
	}
	else printf("\nVous n'avez pas selectionne un de vos pions %d %c %d %c", _joueur.couleur+48, _joueur.couleur+48, _map[i][j].couleur, _map[i][j].couleur);
}




int Deplacement(Tuile _map[10][10], SDL_Renderer *_rendu, int i, int j, int _memoire[5], Joueur _joueur)
{
	if(CaseAdjacente(_memoire[0], _memoire[1], i, j)==1)
	{
		if(_memoire[3]>0)
		{
			if(_map[i][j].type_terrain=='5')
			{
				printf("\nVous ne pouvez pas vous deplacer sur un lac");
				return 0;
			}

			else if(_map[i][j].taille_ville!='0' && _memoire[3]==1)
			{
				printf("\nVous ne pouvez pas finir votre deplacement sur une ville");
				return 0;
			}

			
			else if(_map[i][j].couleur==(_joueur.couleur+48)|| _map[i][j].couleur=='0')
			{
				
				if(_memoire[4]==-1)
				{
					printf("\nCombien de Pions voulez-vous deplacer ?");
					do
					{
						printf("\n");
						scanf("%d",&_memoire[4]);
					
						if(_memoire[4]>_map[i][j].nombre_pion-47) printf("\nIl n'y a pas assez pions sur cette case, saisissez une nouvelle valeur");
				
					}while(_memoire[4]>_map[i][j].nombre_pion-47);
				}

				DeplacementPion(_map, _rendu, _memoire[0], _memoire[1], i, j, _joueur.couleur+48, _memoire[4]);
			
				_memoire[3]=_memoire[3]-1;
				printf("\nIl vous reste %d point de deplacement", _memoire[3]);
			
				NouvelleSelectionCase(_memoire, i, j);
				return 0;
			}
			
			else
			{
				printf("\nVous ne pouvez pas vous deplacer sur une case controlee par d'autres joueurs"); return 0;
			}
		}
		else {printf("\nVous n'avez plus assez de points de deplacement, fin du tour..."); return 1;}
	}
	else printf("\nVous devez selectionner une case adjacente"); return 0;
}




int ChoixAction()
{	
	int choix;
	printf("\n\n--------- Que voulez vous faire ? -----------");
	printf("\n1 : Deplacer des pions");
	printf("\n2 : Avoir des Enfants");
	printf("\n3 : Combattre");
	printf("\n4 : Avoir une idee");
	printf("\n5 : Construire une cite\n");
	
	do
	{
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
