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
				
				MajCartes(_rendu, _joueur[i].carte_joueur);
				
				if(_joueur[i].niveau_joueur.actions>0) 
				{
					printf("\nIl vous reste %d actions pour cet age", _joueur[i].niveau_joueur.actions); 
					SelectionCase(_map, _rendu, &_joueur[i], _fenetre);
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
		MajNiveaux(_rendu, _joueur);
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/


int SelectionCase(Tuile _map[10][10], SDL_Renderer* _rendu, Joueur* _joueur, SDL_Window *_fenetre)
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


int SelectionPion(Tuile _map[10][10], SDL_Renderer* _rendu, Joueur* _joueur, SDL_Window *_fenetre)
{
	int coordx;
	int coordy;
	int action;
	RechercheCurseur(_map, &coordx, &coordy);

	if(_map[coordx][coordy].nombre_pion!='0'&&_map[coordx][coordy].couleur==IntEnChar(_joueur->couleur))      
    {
		printf("\nVous avez selectionne le pion sur la case %d %d",coordx,coordy);       
        action=ChoixAction();
        switch(action)
        {
            case 1: printf("\nVous avez choisis de deplacer vos pions"); Deplacement(_map, _rendu, &coordx, &coordy, *_joueur, _fenetre); return 1; break;
            case 2: printf("\nVous avez choisis de faire un enfant"); return FaireEnfant(_map, _rendu, &coordx, &coordy, _joueur); break;
            case 3: printf("\nVous avez choisis %d", action); break;
            case 4: printf("\nVous avez choisis d'avoir une idee"); return PiocherCarte(_rendu, _joueur); break;
            case 5: printf("\nVous avez choisis de construire une ville"); return PlacementVille(_map, _rendu, &coordx, &coordy, _joueur);break;
		}
	}
	else printf("\nVous n'avez pas selectionne un de vos pions %d %c %d %c", IntEnChar(_joueur->couleur), IntEnChar(_joueur->couleur), _map[coordx][coordy].couleur, _map[coordx][coordy].couleur); return 0;

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

