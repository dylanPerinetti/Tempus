/*

-------------- TEMPUS --------------

Retrouvez le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au evenement-graphique dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "evenement.h".

Fait par dylan le 21/03/2022
Dernière modifications par dylanPerinetti le 24/03/2022

*/
#include "action.h"


/*-----------------------------------------------------------------------------------------------------------------*/

int Deplacement(Tuile _map[10][10], SDL_Renderer *_rendu, int *_coordx, int *_coordy, Joueur _joueur, SDL_Window *_fenetre)
{
	
	SDL_bool programme_lance = SDL_TRUE;
	SDL_Event event;
	int fin_deplacement=0;
	int nbre_pion=-1;
	
	for(int i=0; i<_joueur.niveau_joueur.distance; i++) 
	{
		while(programme_lance&&fin_deplacement==0)
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
			                case SDLK_SPACE: fin_deplacement=TestDeplacement(_map, _rendu, _coordx, _coordy, _joueur.niveau_joueur.distance-i, &nbre_pion, _joueur); continue;
			                default : continue;
	            		}
	            	
	            	case SDL_QUIT: programme_lance = SDL_FALSE; SDL_DestroyRenderer(_rendu); SDL_DestroyWindow(_fenetre); SDL_Quit(); break;
	                default : break;
	            }
	        }
	    }
	    fin_deplacement=0;
	}
	printf("\nVous n'avez plus de points de deplacement...");
}



int TestDeplacement(Tuile _map[10][10], SDL_Renderer *_rendu, int *_coordx, int *_coordy, int point_dep, int *nbre_pion, Joueur _joueur)
{
	int ncoordx;
	int ncoordy;
	RechercheCurseur(_map, &ncoordx, &ncoordy);

	if(CaseAdjacente(*_coordx, *_coordy, ncoordx, ncoordy)==1)
	{
			if(_map[ncoordx][ncoordy].type_terrain=='5')
			{
				printf("\nVous ne pouvez pas vous deplacer sur un lac");
				return 0;
			}

			else if(_map[ncoordx][ncoordy].taille_ville!='0' && point_dep==1)
			{
				printf("\nVous ne pouvez vous deplacer sur une ville");
				return 0;
			}

			else if(_map[ncoordx][ncoordy].nombre_pion>=IntEnChar(_joueur.niveau_joueur.nbre_pion_max))
			{
				printf("\nVous n'avez pas atteint l'age pour avoir autant de pions sur une case");
				return 0;
			}

			
			else if(_map[ncoordx][ncoordy].couleur==IntEnChar(_joueur.couleur)|| _map[ncoordx][ncoordy].couleur=='0')
			{
				
				if(*nbre_pion==-1)
				{
					printf("\nCombien de Pions voulez-vous deplacer ?");
					do
					{
						printf("\n");
						scanf("%d",nbre_pion);
						printf("%d %d", IntEnChar(*nbre_pion), _map[*_coordx][*_coordy].nombre_pion);
					
						if(IntEnChar(*nbre_pion)>_map[*_coordx][*_coordy].nombre_pion) printf("\nIl n'y a pas assez pions sur cette case, saisissez une nouvelle valeur");
						else if(IntEnChar(*nbre_pion)>_joueur.niveau_joueur.deplacement) printf("\nVous n'avez pas atteint l'age pour deplacer autant de pions");
				
					}while(*nbre_pion>_map[ncoordx][ncoordy].nombre_pion||*nbre_pion>_joueur.niveau_joueur.deplacement);
				}

				DeplacementPion(_map, _rendu, *_coordx, *_coordy, ncoordx, ncoordy, IntEnChar(_joueur.couleur), *nbre_pion);

				printf("\nIl vous reste %d point de deplacement", point_dep-1);

				*_coordx=ncoordx;
				*_coordy=ncoordy;
			
				return 1;
			}
			
			else
			{
				printf("\nVous ne pouvez pas vous deplacer sur une case controlee par d'autres joueurs"); return 0;
			}
	}
	else printf("\nVous devez selectionner une case adjacente"); return 0;
}

/*-----------------------------------------------------------------------------------------------------------------*/

int PlacementPion(Tuile _map[10][10], SDL_Renderer* _rendu, Joueur *_joueur, SDL_Window *_fenetre)
{
	SDL_bool programme_lance = SDL_TRUE;
	int fin_tour=0;
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
					case SDLK_SPACE: fin_tour = TestPlacementPion(_map, _rendu, _joueur); continue;

					default : continue;
				}

				case SDL_QUIT: programme_lance = SDL_FALSE; SDL_DestroyRenderer(_rendu); SDL_DestroyWindow(_fenetre); SDL_Quit(); break;
				default : break;
			}
		}
	}
}


int TestPlacementPion(Tuile _map[10][10], SDL_Renderer* _rendu, Joueur *_joueur)
{
	int coordx;
	int coordy;

	RechercheCurseur(_map, &coordx, &coordy);


	if(_map[coordx][coordy].type_terrain=='5')
	{
		printf("\nVous ne pouvez pas poser de pions sur un lac");
		return 0;
	}
	else if(_map[coordx][coordy].couleur!=IntEnChar(_joueur->couleur)&&_map[coordx][coordy].couleur!='0')
	{
		printf("\nCette case appartient deja a quelqu'un d'autre");
		return 0;
	}
	
	else if(_map[coordx][coordy].nombre_pion>=IntEnChar(_joueur->niveau_joueur.nbre_pion_max))
	{
		printf("\nVous n'avez pas atteint l'age pour avoir autant de pions sur une case");
		return 0;
	}
	
	else
	{
		_joueur->pions_possede--;
		printf("\n%d",_joueur->pions_possede);
		_map[coordx][coordy].nombre_pion++;
		_map[coordx][coordy].couleur=IntEnChar(_joueur->couleur);
		MajCase(_map, coordx, coordy, _rendu); 
		return 1;
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/


int FaireEnfant(Tuile _map[10][10], SDL_Renderer* _rendu, int *_coordx, int *_coordy, Joueur *_joueur)
{
	int compteur=_joueur->niveau_joueur.enfants;
	
	if(CaseNaissanceDispo(_map, _joueur)==0)
	{
		printf("\nVous ne controlez aucune prairie, vous ne pouvez donc pas faire d'enfants");
		return 0;
	}

	if(_joueur->pions_possede==0)
	{
		printf("\nVous n'avez plus assez de pions pour pouvoir enfanter");
		return 0;
	}

	if(TestFaireEnfant(_map, _rendu, _coordx, _coordy, _joueur)==1) compteur--;

	while(compteur!=0 && _joueur->pions_possede!=0 && CaseNaissanceDispo(_map, _joueur)==1)
	{
		printf("\nVous pouvez encore faire %d enfant, veuillez choisir une autre case de prairie", compteur);
			
		SDL_bool programme_lance = SDL_TRUE;
		int fin_tour=0;

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
						case SDLK_DOWN: CurseurBas(_map, _rendu); RechercheCurseur(_map, _coordx, _coordy); continue;
						case SDLK_UP: CurseurHaut(_map, _rendu); RechercheCurseur(_map, _coordx, _coordy); continue;
						case SDLK_RIGHT: CurseurDroite(_map, _rendu); RechercheCurseur(_map, _coordx, _coordy); continue;
						case SDLK_LEFT: CurseurGauche(_map, _rendu); RechercheCurseur(_map, _coordx, _coordy); continue;
						case SDLK_SPACE: fin_tour = TestFaireEnfant(_map, _rendu, _coordx, _coordy, _joueur); continue;

						default : continue;
					}
					default : break;
				}
			}
		}
		compteur--;
	}
	return 1;
}


int TestFaireEnfant(Tuile _map[10][10], SDL_Renderer* _rendu, int *_coordx, int *_coordy, Joueur *_joueur)
{
	if(_map[*_coordx][*_coordy].type_terrain!=IntEnChar(0))
	{
		printf("\nVous ne pouvez pas faire d'enfants sur une case autre qu'une prairie");
		return 0;
	}
	else if(IntEnChar(_joueur->niveau_joueur.nbre_pion_max)<=_map[*_coordx][*_coordy].nombre_pion)
	{
		printf("\nIl y a trop de pions sur cette case");
		return 0;
	}

	else
	{
		_map[*_coordx][*_coordy].nombre_pion++;
		_joueur->pions_possede--;
		MajCase(_map, *_coordx, *_coordy, _rendu);
		return 1;
	}
}

//--------------------------------------------------------------------------------------//

int PlacementVille(Tuile _map[10][10], SDL_Renderer* _rendu, int *_coordx, int *_coordy, Joueur *_joueur)
{
	int choix;
	if(_map[*_coordx][*_coordy].nombre_pion<IntEnChar(2)) {printf("\nVous n'avez pas assez de pions pour former une ville"); return 0;}
	if(_map[*_coordx][*_coordy].type_terrain==IntEnChar(1)) {printf("\nVous ne pouvez pas faire de villes sur une montagne"); return 0;}


	printf("\nDe quelle taille voulez-vous que la ville soit ?");
	
	do
	{
		scanf("%d", &choix);
		if(choix<2||IntEnChar(choix)>_map[*_coordx][*_coordy].nombre_pion) printf("\nVotre ville doit etre de taille inferieure ou egale a votre nombre de pions sur la case");
	}while(choix<2||IntEnChar(choix)>_map[*_coordx][*_coordy].nombre_pion);
	

	_map[*_coordx][*_coordy].nombre_pion='0';
	_map[*_coordx][*_coordy].taille_ville=IntEnChar(choix);
	
	MajCase(_map, *_coordx, *_coordy, _rendu);
	return 1;
}

//-------------------------------------------------------------------------------------//

int PiocherCarte(SDL_Renderer* _rendu, Joueur* _joueur)
{
	int i=0; int fin=0; 
	while(fin==0&&i<_joueur->niveau_joueur.carte_max)
	{
		if(_joueur->carte_joueur[i].couleur==7)
		{
			_joueur->carte_joueur[i].couleur = rand()%5;  //5 mais jsuis pas sur
			_joueur->carte_joueur[i].effet = rand()%5;   //la meme
			MajCartes(_rendu, _joueur->carte_joueur); 
		}
	
	i++;
	}
	
	printf("\nVous ne pouvez pas piocher plus de cartes"); return 0;
}


//-----------------------------------------------------------------------------------//


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
	if(choix>5||choix<1) printf("\nVous devez choisir une valeur entre 1 et 5");
	}while(choix>5||choix<1);
	return choix;
}

/*-----------------------------------------------------------------------------------------------------------------*/

void DeplacementPion(Tuile _map[10][10], SDL_Renderer* _rendu, int departx, int departy, int arriveex, int arriveey, unsigned char couleur, int nbre_pion_deplace)
{
	_map[departx][departy].nombre_pion = _map[departx][departy].nombre_pion-nbre_pion_deplace;
	_map[arriveex][arriveey].nombre_pion = _map[arriveex][arriveey].nombre_pion+nbre_pion_deplace;
	
	_map[arriveex][arriveey].couleur = couleur;
	
	if(_map[departx][departy].nombre_pion==IntEnChar(0))
	{
		_map[departx][departy].couleur = '0';
	}
	
	MajCase(_map, departx, departy, _rendu); 
	MajCase(_map, arriveex, arriveey, _rendu);
}

/*-----------------------------------------------------------------------------------------------------------------*/

void RechercheCurseur(Tuile _map[10][10], int *_coordx, int *_coordy)
{
	for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(_map[i][j].curseur==1)
            {
            	*_coordx=i;
            	*_coordy=j;
            }
        }
    }
}
/*-----------------------------------------------------------------------------------------------------------------*/
