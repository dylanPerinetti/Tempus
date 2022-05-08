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
			if(_map[ncoordx][ncoordy].type_terrain==5)
			{
				printf("\nVous ne pouvez pas vous deplacer sur un lac");
				return 0;
			}

			else if(_map[ncoordx][ncoordy].taille_ville!=0 && point_dep==1)
			{
				printf("\nVous ne pouvez vous deplacer sur une ville");
				return 0;
			}

			else if(_map[ncoordx][ncoordy].nombre_pion>=(_joueur.niveau_joueur.nbre_pion_max))
			{
				printf("\nVous n'avez pas atteint l'age pour avoir autant de pions sur une case");
				return 0;
			}

			
			else if(_map[ncoordx][ncoordy].couleur==(_joueur.couleur)|| _map[ncoordx][ncoordy].couleur==0)
			{
				
				if(*nbre_pion==-1)
				{
					printf("\nCombien de Pions voulez-vous deplacer ?");
					do
					{
						printf("\n");
						scanf("%d",nbre_pion);
						printf("%d %d", (*nbre_pion), _map[*_coordx][*_coordy].nombre_pion);
					
						if(*nbre_pion>_map[*_coordx][*_coordy].nombre_pion) printf("\nIl n'y a pas assez pions sur cette case, saisissez une nouvelle valeur");
						else if(*nbre_pion>_joueur.niveau_joueur.deplacement) printf("\nVous n'avez pas atteint l'age pour deplacer autant de pions");
				
					}while(*nbre_pion>_map[*_coordx][*_coordy].nombre_pion||*nbre_pion>_joueur.niveau_joueur.deplacement);
				}

				DeplacementPion(_map, _rendu, *_coordx, *_coordy, ncoordx, ncoordy, _joueur.couleur, *nbre_pion);

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

int CombatPions(Tuile _map[10][10], SDL_Renderer *_rendu, int _coordx, int _coordy, Joueur _joueur[4], Joueur* attaquant, SDL_Window *_fenetre)
{
	SDL_bool programme_lance = SDL_TRUE;

	while(programme_lance)
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
			            case SDLK_SPACE: return TestCombat(_map, _rendu, _coordx, _coordy, attaquant, _joueur); continue;
			            default : continue;
	            	}
	            	
	            case SDL_QUIT: programme_lance = SDL_FALSE; SDL_DestroyRenderer(_rendu); SDL_DestroyWindow(_fenetre); SDL_Quit(); break;
	            default : break;
	        }
	    }
	 }
}

int TestCombat(Tuile _map[10][10], SDL_Renderer *_rendu, int _coordx, int _coordy, Joueur* attaquant, Joueur _joueur[4])
{
	int ncoordx;
	int ncoordy;
	int defenseur;
	RechercheCurseur(_map, &ncoordx, &ncoordy);
	int point_attaquant=0;
	int point_defenseur=0;

	if(CaseAdjacente(_coordx, _coordy, ncoordx, ncoordy)==1)
	{
		if(_map[ncoordx][ncoordy].nombre_pion>0&&_map[ncoordx][ncoordy].couleur!=attaquant->couleur)
		{
			defenseur=_map[ncoordx][ncoordy].couleur-1;
			if(_joueur[defenseur].pions_possede<4) {printf("\nVous ne pouvez pas attaquer un joueur possédant trois pions ou moins"); return 0;}
			else 
			{
				printf("\nJoueur %s, vous etes l'attaquant, vous pouvez donc choisir combien de cartes vous allez jouer\n",attaquant->pseudo);
				point_attaquant=point_attaquant+JouerCarte(attaquant, _map[ncoordx][ncoordy].type_terrain);

				point_attaquant=point_attaquant+_map[_coordx][_coordy].nombre_pion;

				printf("%d", defenseur);

				printf("\nJoueur %s vous etes le defenseur, vous allez pouvoir choisir en second combien de cartes vous allez jouer", _joueur[defenseur].pseudo);
				point_defenseur=point_defenseur+JouerCarte(&_joueur[defenseur], _map[ncoordx][ncoordy].type_terrain);

				point_defenseur=point_defenseur+_map[ncoordx][ncoordy].nombre_pion;

				system("PAUSE");

				if(point_attaquant<=point_defenseur) 
				{
					
					printf("\nLES DEFENSEURS ONT GAGNES");
					if(point_defenseur==point_attaquant)
					{
						_map[_coordx][_coordy].nombre_pion--;
					}

					else if(_map[_coordx][_coordy].nombre_pion-point_defenseur+point_attaquant>=0) 
					{
						attaquant->pions_possede = attaquant->pions_possede+point_defenseur-point_attaquant;
						_map[_coordx][_coordy].nombre_pion = _map[_coordx][_coordy].nombre_pion-point_defenseur+point_attaquant;
					}
					
					else
					{
						attaquant->pions_possede = attaquant->pions_possede+_map[_coordx][_coordy].nombre_pion;
						_map[_coordx][_coordy].nombre_pion = 0;
					}

				}
				else
				{
					printf("\nLES ATTAQUANTS ONT GAGNES");
					int choix=0;
					printf("\nCombien de pions voulez vous deplacer sur la case conquise ?\n");
					do
					{
						scanf("%d", &choix);
						if((choix)>_map[_coordx][_coordy].nombre_pion||choix<1) printf("\nVeuillez choisir une valeur comprise entre 1 et %d", _map[_coordx][_coordy].nombre_pion);
					}while((choix)>_map[_coordx][_coordy].nombre_pion||choix<1);

					_map[ncoordx][ncoordy].nombre_pion=0;
					DeplacementPion(_map, _rendu, _coordx, _coordy, ncoordx, ncoordy, attaquant->couleur, choix);
				}
				
				MajCase(_map, _coordx, _coordy, _rendu);
				MajCase(_map, ncoordx, ncoordy, _rendu);
				system("PAUSE");

				return 1;
			}
		}

		else if(_map[ncoordx][ncoordy].taille_ville!=0 && _map[ncoordx][ncoordy].couleur!=attaquant->couleur)
		{
			int terrain;
			defenseur=_map[ncoordx][ncoordy].couleur-1;
			printf("\nJoueur %s, vous controlez la ville qui se defend, vous pouvez donc choisir le terrain de l'affrontement :", _joueur[defenseur].pseudo);
			printf("\n1: Prairie\n2: Montagne\n3: Foret\n4: Champs\n5: Colline");
			do
			{
				scanf("%d", &terrain);
				if(terrain<1||terrain>5) printf("\nVeuillez entrer une valeur entre 1 et 5");
			}while(terrain<1||terrain>5);

			printf("\nJoueur %s, vous etes l'attaquant, vous pouvez donc choisir combien de cartes vous allez jouer\n",attaquant->pseudo);
			point_attaquant=point_attaquant+JouerCarte(attaquant, terrain-1);

			point_attaquant=point_attaquant+_map[_coordx][_coordy].nombre_pion;

			printf("%d", defenseur);

			printf("\nJoueur %s vous etes le defenseur, vous allez pouvoir choisir en second combien de cartes vous allez jouer", _joueur[defenseur].pseudo);
			point_defenseur=point_defenseur+JouerCarte(&_joueur[defenseur], terrain-1);

			point_defenseur=point_defenseur+_map[ncoordx][ncoordy].taille_ville;
			if(point_attaquant<=point_defenseur) 
			{
					
				printf("\nLES DEFENSEURS ONT GAGNES");
				if(point_defenseur==point_attaquant)
				{
					_map[_coordx][_coordy].nombre_pion--;
				}

				else if(_map[_coordx][_coordy].nombre_pion-point_defenseur+point_attaquant>=0) 
				{
					attaquant->pions_possede = attaquant->pions_possede+point_defenseur-point_attaquant;
					_map[_coordx][_coordy].nombre_pion = _map[_coordx][_coordy].nombre_pion-point_defenseur+point_attaquant;
				}
					
				else
				{
					attaquant->pions_possede = attaquant->pions_possede+_map[_coordx][_coordy].nombre_pion;
					_map[_coordx][_coordy].nombre_pion = 0;
				}

			}
			else
			{
				printf("\nLES ATTAQUANTS ONT GAGNES, VOUS PRENEZ DONC LA VILLE");
				_map[ncoordx][ncoordy].couleur=attaquant->couleur;
			}
		}
		else printf("\nVous devez selectionner une case appartenant a un de vos adversaires avec au moins un pion dessus, ou une ville");
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


	if(_map[coordx][coordy].type_terrain==5)
	{
		printf("\nVous ne pouvez pas poser de pions sur un lac");
		return 0;
	}
	else if(_map[coordx][coordy].couleur!=(_joueur->couleur)&&_map[coordx][coordy].couleur!=0)
	{
		printf("\nCette case appartient deja a quelqu'un d'autre");
		return 0;
	}
	
	else if(_map[coordx][coordy].nombre_pion>=(_joueur->niveau_joueur.nbre_pion_max))
	{
		printf("\nVous n'avez pas atteint l'age pour avoir autant de pions sur une case");
		return 0;
	}
	
	else
	{
		_joueur->pions_possede--;
		printf("\n%d",_joueur->pions_possede);
		_map[coordx][coordy].nombre_pion++;
		_map[coordx][coordy].couleur=(_joueur->couleur);
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
		printf("\nVous ne controlez aucun champs, vous ne pouvez donc pas faire d'enfants");
		return 0;
	}

	if(_joueur->pions_possede==0)
	{
		printf("\nVous avez atteint le nombre de pions maximum sur la carte");
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
	if(_map[*_coordx][*_coordy].type_terrain!=(3))
	{
		printf("\nVous ne pouvez pas faire d'enfants sur une case autre qu'un champs");
		return 0;
	}
	else if((_joueur->niveau_joueur.nbre_pion_max)<=_map[*_coordx][*_coordy].nombre_pion)
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
	if(_map[*_coordx][*_coordy].nombre_pion<(2)) {printf("\nVous n'avez pas assez de pions pour former une ville"); return 0;}
	if(_map[*_coordx][*_coordy].type_terrain==(1)) {printf("\nVous ne pouvez pas faire de villes sur une montagne"); return 0;}
	if(_joueur->cite_possede==0) {printf("\nVous avez déja atteint le maximum de cités sur la carte"); return 0;}


	printf("\nDe quelle taille voulez-vous que la ville soit ?\n");
	
	do
	{
		scanf("%d", &choix);
		if(choix<2||(choix)>_map[*_coordx][*_coordy].nombre_pion) printf("\nVotre ville doit etre de taille inferieure ou egale a votre nombre de pions sur la case");
	}while(choix<2||(choix)>_map[*_coordx][*_coordy].nombre_pion);
	

	_map[*_coordx][*_coordy].nombre_pion=0;
	_map[*_coordx][*_coordy].taille_ville=(choix);
	_joueur->cite_possede--;
	
	MajCase(_map, *_coordx, *_coordy, _rendu);
	return 1;
}

//-------------------------------------------------------------------------------------//

int PiocherCarte(SDL_Renderer* _rendu, Joueur* _joueur)
{
	int i=0; int fin=_joueur->niveau_joueur.carte_pioche;
	
	if (TestPiocheCarte==0) return 0;
	
	while(fin>0&&i<_joueur->niveau_joueur.carte_max)
	{
		if(_joueur->carte_joueur[i].couleur==7)
		{
			_joueur->carte_joueur[i].couleur = rand()%5; 
			_joueur->carte_joueur[i].effet = rand()%5;   
			MajCartes(_rendu, _joueur->carte_joueur); 
			fin--;
		}
	i++;
	}
	printf("\nVous ne pouvez pas piocher plus de cartes\n"); system("PAUSE"); return 1;
}

int TestPiocheCarte(Joueur* _joueur)
{
	for(int i=0;i<_joueur->niveau_joueur.carte_max;i++)
	{
		if(_joueur->carte_joueur[i].couleur!=7) return 1;
	}
	return 0;
}


/*-----------------------------------------------------------------------------------------------------------------*/

void DeplacementPion(Tuile _map[10][10], SDL_Renderer* _rendu, int departx, int departy, int arriveex, int arriveey, unsigned char couleur, int nbre_pion_deplace)
{
	_map[departx][departy].nombre_pion = _map[departx][departy].nombre_pion-nbre_pion_deplace;
	_map[arriveex][arriveey].nombre_pion = _map[arriveex][arriveey].nombre_pion+nbre_pion_deplace;
	
	_map[arriveex][arriveey].couleur = couleur;
	
	if(_map[departx][departy].nombre_pion==0)
	{
		_map[departx][departy].couleur = 0;
	}
	
	MajCase(_map, departx, departy, _rendu); 
	MajCase(_map, arriveex, arriveey, _rendu);
}

/*-----------------------------------------------------------------------------------------------------------------*/


