/*-------------------- Biblio ------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "joueur.h"

/*----------------------------------------------------*/

int main()
{
	int choix_utilisateur=0;
	Joueur joueur1 , joueur2 , joueur3 , joueur4;

	do{
		printf("\nBienvenue \n1. JOUER \n2. REGLES DU JEU \n3. QUITTER \n") ;
		scanf("%d",&choix_utilisateur);
		switch(choix_utilisateur)
    	{
	        case 1:
	            system("cls"); //Windows
	            CreeJoueurs(&joueur1,1);    
			    /*________________________TEST____________________________*/
			    printf("Le nom du joueur 1 est :%s,\net son lvl est : %d",joueur1.nom_utilisateur,joueur1.niveaux_joueur);//afficher les changements
			    /*________________________TEST____________________________*/
	        	CreeJoueurs(&joueur2,2);
			    /*________________________TEST____________________________*/
			    printf("Le nom du joueur 1 est :%s,\net son lvl est : %d",joueur1.nom_utilisateur,joueur1.niveaux_joueur);//afficher les changements
				/*________________________TEST____________________________*/
    
	            //CreeJoueurs(&joueur3,3);
	            //CreeJoueurs(&joueur4,4);
	            //DebutJeu();
	            //AfficherPlateau();
	            break;
	        case 2:
	            system("cls"); //Windows
	            //AfficherReglesDuJeu();
	            break;
	        case 3:
	            system("cls"); //Windows
	            printf("Merci et a Bientôt ;)");
	            return 0;
	        default :
	            system("cls"); //Windows
	            printf("Veuillez resaisir votre choix");
	            return 0 ;
	            break;
	    }
	    

    } while (choix_utilisateur!=4);
    
    return 0;
}
