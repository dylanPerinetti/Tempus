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
		
		for(i=0;i<4;i++) 
		{
			if(_joueur[i].niveau_joueur.niveau<age) AugmenterNiveauJoueur(&_joueur[i]);
		}
		
		printf("\nTous les joueurs atteignent l'age %d\n", age);
		MajNiveaux(_rendu, _joueur);
		system("PAUSE");

		MeilleurJoueurAge(_map, _joueur, age);
		MajNiveaux(_rendu, _joueur);

		if(age==10)
		{
			int gagnant;
			gagnant=FinPartie(_map, _joueur);
			
			printf("\n\nLE GAGNANT EST %s, BIEN JOUE !", _joueur[gagnant].pseudo);
			GenerationVictoire(_rendu, gagnant);
			system("PAUSE");
			exit(EXIT_FAILURE);
		} 
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

	if(_map[coordx][coordy].nombre_pion!=0&&_map[coordx][coordy].couleur==(_joueur->couleur))      
    {
		printf("\nVous avez selectionne le pion sur la case %d %d",coordx,coordy);       
        action=ChoixAction();
        switch(action)
        {
            case 1: printf("\nVous avez choisis de deplacer vos pions"); Deplacement(_map, _rendu, &coordx, &coordy, *_joueur, _fenetre); return 1; break;
            case 2: printf("\nVous avez choisis de faire un enfant"); return FaireEnfant(_map, _rendu, &coordx, &coordy, _joueur); break;
            case 3: printf("\nVous avez choisis %d", action); /*return CombatPions(_map, _rendu, _coordx, _coordy, _joueur, int attaquant, SDL_Window *_fenetre)*/break;
            case 4: printf("\nVous avez choisis d'avoir une idee"); return PiocherCarte(_rendu, _joueur); break;
            case 5: printf("\nVous avez choisis de construire une ville"); return PlacementVille(_map, _rendu, &coordx, &coordy, _joueur);break;
		}
	}
	else printf("\nVous n'avez pas selectionne un de vos pions %d %c %d %c", (_joueur->couleur), (_joueur->couleur), _map[coordx][coordy].couleur, _map[coordx][coordy].couleur); return 0;

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

int FinPartie(Tuile _map[10][10], Joueur _joueur[4])
{
	int pjoueur[4];
	int ppions=0; int pvilles=0; int page=0;
	int pmax;
	pjoueur[0]=0; pjoueur[1]=0; pjoueur[2]=0; pjoueur[3]=0;

	for(int i=0; i<4; i++)
	{
		ppions=0; pvilles=0; page=0;
		
		for(int j=0; j<10; j++)
		{
			for(int k=0; k<10; k++)
			{
				if(_map[j][k].nombre_pion>(0)&&(_joueur[i].couleur)==_map[j][k].couleur) ppions++;
				if(_map[j][k].taille_ville>(0)&&(_joueur[i].couleur)==_map[j][k].couleur) pvilles=pvilles+_map[j][k].taille_ville;
			}
		}
		
		if(_joueur[i].niveau_joueur.niveau==10) page=page+3;

		pjoueur[i]=ppions+pvilles+page;

		printf("\nLe joueur %s comptabilise %d points :  %d grace a ses pions,  %d grace a ses villes", _joueur[i].pseudo, pjoueur[i], ppions, pvilles);
		
		if(page!=0) printf(" et 3 car il a atteint le dernier age.");
		
		if(pjoueur[i]>=pjoueur[0]&&pjoueur[i]>=pjoueur[1]&&pjoueur[i]>=pjoueur[2]&&pjoueur[i]>=pjoueur[3]) pmax=pjoueur[i];
	}

	for(int i=0; i<4; i++)
	{
		if(pjoueur[i]==pmax) return i;                           //Faire le cas ou yait une égalité
	}
}

/*int Egalite(Joueur _joueur[4], int gagnants[4])
{
	int VeritableGagnant=7;

	for(int i=0;i<4;i++)
	{
		if(gagnants[i]==1)
		{
			if(VeritableGagnant!=7)
			{
				if(_joueur[i].)





			}
			
			else VeritableGagnant=i;
		}
	}
}*/