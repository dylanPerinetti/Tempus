/*

-------------- TEMPUS --------------

Retrouvez le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au evenement-graphique dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "evenement.h".

Fait par dylan le 21/03/2022
Dernière modifications par dylanPerinetti le 24/03/2022

*/
#include "evenement.h"


/*-----------------------------------------------------------------------------------------------------------------*/

void LancementPartie(Tuile _map[10][10], Joueur _joueur[4], SDL_Renderer* _rendu, SDL_Window* _fenetre)
{
	int i=0;
	int age=0;

	printf("\n---------------------Bienvenue dans Tempus-----------------------");
	printf("\n\n Veuillez entrer les pseudos des joueurs :");
	
	for(int i=0;i<4;i++)
	{
		EntrerNomJoueur(&_joueur[i]);
	}

	printf("\n\nVous allez chacun pouvoir, chacun votre tour, placer 3 pions sur l'ile de Tempus. Choisissez bien !");
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
		{
			printf("\n\n-------Joueur %s, a vous---------",_joueur[j].pseudo);
			PlacementPion(_map, _rendu, &_joueur[j], _fenetre);
			printf("\n%d",_joueur[j].pions_possede);
		}
	}

	printf("\n\n-------------Debut de la partie--------------");
	
	while(_joueur[0].niveau_joueur.niveau<10||_joueur[1].niveau_joueur.niveau<10||_joueur[2].niveau_joueur.niveau<10||_joueur[3].niveau_joueur.niveau<10)
	{
		while(_joueur[0].niveau_joueur.actions>0||_joueur[1].niveau_joueur.actions>0||_joueur[2].niveau_joueur.actions>0||_joueur[3].niveau_joueur.actions>0)
		{
			for(i=0;i<4;i++)
			{
				system(NETTOYER_TERMINAL);
				printf("\n\n---------Au tour du joueur %s-----------", _joueur[i].pseudo);
				
				if(_joueur[i].niveau_joueur.actions>0) 
				{
					printf("\nIl vous reste %d actions pour cet age", _joueur[i].niveau_joueur.actions); 
					SelectionCase(_map, _rendu, _joueur[i], _fenetre);
					_joueur[i].niveau_joueur.actions=_joueur[i].niveau_joueur.actions-1;
				}
				
				else printf("\nVous n'avez plus de points d'actions, vous passez donc votre tour");
			}
		}
		system(NETTOYER_TERMINAL);
		age++;
		
		char u;
		printf("\n\n--------TOUS LES JOUEURS N'ONT PLUS DE POINTS D'ACTIONS, FIN DE L'AGE------------");
		printf("\nTous les joueurs atteignent l'age %d \nDe plus, le joueur 1 ayant le plus de cartes idees monte a l'age %d", age, age+1); //Pour l'instant je fixe le joueur 1 on verra plus tard pour la suite.
		printf("\nEntrez o pour continuer");

		scanf("%c", &u);

		for(i=0;i<4;i++) 
		{
			if(_joueur[i].niveau_joueur.niveau<age) AugmenterNiveauJoueur(&_joueur[i]);
		}
		AugmenterNiveauJoueur(&_joueur[1]); //la meme
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/


int SelectionCase(Tuile _map[10][10], SDL_Renderer* _rendu, Joueur _joueur, SDL_Window *_fenetre)
{
	int fin_tour=0;
	SDL_bool programme_lance = SDL_TRUE;
	
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
					case SDLK_SPACE: fin_tour=SelectionPion(_map, _rendu, _joueur, _fenetre); continue;

					default : continue;
				}

				case SDL_QUIT: programme_lance = SDL_FALSE; SDL_DestroyRenderer(_rendu); SDL_DestroyWindow(_fenetre); SDL_Quit(); break;
				default : break;
			}
		}
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/


int SelectionPion(Tuile _map[10][10], SDL_Renderer* _rendu, Joueur _joueur, SDL_Window *_fenetre)
{
	int coordx;
	int coordy;
	int action;
	int retour;

	RechercheCurseur(_map, &coordx, &coordy);

	if(_map[coordx][coordy].nombre_pion!='0'&&_map[coordx][coordy].couleur==(_joueur.couleur+48))      
    {
		printf("\nVous avez selectionne le pion sur la case %d %d",coordx,coordy);       
        action=ChoixAction();
        switch(action)
        {
            case 1: printf("\nVous avez choisis de deplacer vos pions"); Deplacement(_map, _rendu, &coordx, &coordy, _joueur, _fenetre); return 1; break;
            case 2: printf("\nVous avez choisis de faire un enfant"); retour=FaireEnfant(_map, _rendu, &coordx, &coordy, &_joueur); return retour; break;
            case 3: printf("\nVous avez choisis %d", action); break;
            case 4: printf("\nVous avez choisis %d", action);break;
            case 5: printf("\nVous avez choisis %d", action);break;
		}
	}
	else printf("\nVous n'avez pas selectionne un de vos pions %d %c %d %c", _joueur.couleur+48, _joueur.couleur+48, _map[coordx][coordy].couleur, _map[coordx][coordy].couleur); return 0;

}

/*-----------------------------------------------------------------------------------------------------------------*/

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

/*-----------------------------------------------------------------------------------------------------------------*/

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

/*-----------------------------------------------------------------------------------------------------------------*/

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

/*-----------------------------------------------------------------------------------------------------------------*/

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

/*-----------------------------------------------------------------------------------------------------------------*/

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
				printf("\nVous ne pouvez pas finir votre deplacement sur une ville");
				return 0;
			}

			else if(_map[ncoordx][ncoordy].nombre_pion>=_joueur.niveau_joueur.nbre_pion_max+48)
			{
				printf("\nVous n'avez pas atteint l'age pour avoir autant de pions sur une case");
				return 0;
			}

			
			else if(_map[ncoordx][ncoordy].couleur==(_joueur.couleur+48)|| _map[ncoordx][ncoordy].couleur=='0')
			{
				
				if(*nbre_pion==-1)
				{
					printf("\nCombien de Pions voulez-vous deplacer ?");
					do
					{
						printf("\n");
						scanf("%d",nbre_pion);
					
						if(*nbre_pion>_map[ncoordx][ncoordy].nombre_pion-47) printf("\nIl n'y a pas assez pions sur cette case, saisissez une nouvelle valeur");
						else if(*nbre_pion>_joueur.niveau_joueur.deplacement) printf("\nVous n'avez pas atteint l'age pour deplacer autant de pions");
				
					}while(*nbre_pion>_map[ncoordx][ncoordy].nombre_pion-47||*nbre_pion>_joueur.niveau_joueur.deplacement);
				}

				DeplacementPion(_map, _rendu, *_coordx, *_coordy, ncoordx, ncoordy, _joueur.couleur+48, *nbre_pion);

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

/*-----------------------------------------------------------------------------------------------------------------*/

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
	else if(_map[coordx][coordy].couleur!=_joueur->couleur+48&&_map[coordx][coordy].couleur!='0')
	{
		printf("\nCette case appartient deja a quelqu'un d'autre");
		return 0;
	}
	
	else if(_map[coordx][coordy].nombre_pion>=_joueur->niveau_joueur.nbre_pion_max+48)
	{
		printf("\nVous n'avez pas atteint l'age pour avoir autant de pions sur une case");
		return 0;
	}
	
	else
	{
		_joueur->pions_possede--;
		printf("\n%d",_joueur->pions_possede);
		_map[coordx][coordy].nombre_pion++;
		_map[coordx][coordy].couleur=_joueur->couleur+48;
		MajCase(_map, coordx, coordy, _rendu); 
		return 1;
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/

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
	
	if(_map[departx][departy].nombre_pion==48)
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
	if(_map[*_coordx][*_coordy].type_terrain!=48)
	{
		printf("\nVous ne pouvez pas faire d'enfants sur une case autre qu'une prairie");
		return 0;
	}
	else if(_joueur->niveau_joueur.nbre_pion_max+48<=_map[*_coordx][*_coordy].nombre_pion)
	{
		printf("Joueur : %d, Case : %d", _joueur->niveau_joueur.nbre_pion_max+48, _map[*_coordx][*_coordy].nombre_pion);
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