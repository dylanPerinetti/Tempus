#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "joueur.h"

#define NETTOYER_TERMINAL "clear"				//Si vous etes sur windows dans le CMD remplacer par "cls"  

int main()
{
	int choix_utilisateur=0;
	Joueur tableau_joueur[4];


	system(NETTOYER_TERMINAL);					//shell Netoyer le terminal 
	printf("\nBonjour, Bienvenue a sur TEMPUS 3.0\n\n\n");
	

	do{
	
		printf("\nMENU:\n\n1. JOUER \n2. REGLES DU JEU \n3. QUITTER \n") ;
		scanf("%d",&choix_utilisateur);			//Améliorer la Secu avec fgets ou JCP ...
	
	
		switch(choix_utilisateur)
    	{
	        case 1:
	            system(NETTOYER_TERMINAL);
	            Cree4Joueurs(tableau_joueur);
	            //DebutJeu();					//Initialisations du jeu
	            //AfficherPlateau();
	            break;
	        case 2:
	            system(NETTOYER_TERMINAL);
	            //AfficherReglesDuJeu();		//Affiche les regles du jeu 
	            break;
	        case 3:
	            system(NETTOYER_TERMINAL);
	            printf("Merci et a Bientôt ;)\n");
	            return 0;
	        default :
	            system(NETTOYER_TERMINAL);
	            printf("Veuillez resaisir votre choix");
	            return 0 ;
	            break;
	    }
	    AugmenterNiveaux(&tableau_joueur[3]);	//TESTE 
		AfficherNiveaux(&tableau_joueur[1]);	//TESTE
		AugmenterNiveaux(&tableau_joueur[1]);	//TESTE 
		AfficherNiveaux(&tableau_joueur[3]);	//TESTE
	    AugmenterNiveaux(&tableau_joueur[3]);	//TESTE 
		AfficherNiveaux(&tableau_joueur[1]);	//TESTE
		AugmenterNiveaux(&tableau_joueur[1]);	//TESTE 
		AfficherNiveaux(&tableau_joueur[1]);	//TESTE

    } while (choix_utilisateur!=4);
    return 0;
}
