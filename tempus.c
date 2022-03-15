#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "joueur.h"

#define NETTOYER_TERMINAL "clear"		//Si vous etes sur windows dans le CMD remplacer par "cls"  

int main()
{
	system(NETTOYER_TERMINAL);			//shell Netoyer le terminal 
	int choix_utilisateur=0;
	Joueur joueur1 , joueur2 , joueur3 , joueur4;
	printf("Bonjour, Bienvenue a sur TEMPUS 3.0");
	do{
		printf("\nMENU:\n\n1. JOUER \n2. REGLES DU JEU \n3. QUITTER \n") ;
		scanf("%d",&choix_utilisateur);
		switch(choix_utilisateur)
    	{
	        case 1:
	            system(NETTOYER_TERMINAL);
	            CreeJoueurs(&joueur1,1);
	            CreeJoueurs(&joueur2,2);
	            CreeJoueurs(&joueur3,3);
	            CreeJoueurs(&joueur4,4);
	            //DebutJeu();			//Initialisations du jeu
	            //AfficherPlateau();
	            break;
	        case 2:
	            system(NETTOYER_TERMINAL);
	            //AfficherReglesDuJeu();//Affiche les regles du jeu 
	            break;
	        case 3:
	            system(NETTOYER_TERMINAL);
	            printf("Merci et a Bientôt ;)");
	            return 0;
	        default :
	            system(NETTOYER_TERMINAL);
	            printf("Veuillez resaisir votre choix");
	            return 0 ;
	            break;
	    }
    } while (choix_utilisateur!=4);
    return 0;
