#import <stdlib.h>
#include "joueur.h"

int main()
{
	int choix_utilisateur=0;

	do{
		printf("\nBienvenue \n1. JOUER \n2. REGLES DU JEU \n3. QUITTER \n") ;
		scanf("%d",&choix_utilisateur);
		switch(choix_utilisateur)
    	{
	        case 1:
	            system("cls"); //Windows
	            //debut_jeu();
	            //affichagePlateau();
	            break;
	        case 2:
	            system("cls"); //Windows
	            //regles_du_jeu();
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
	    

	    /*________________________TEST____________________________
	    Joueur j1;//créé un joueur
	    scanf("%s",j1.nom_utilisateur);//changer son nom
	    j1.niveaux_joueur=300;
	    printf("Le nom du joueur est :%s,\net son lvl est : %d",j1.nom_utilisateur,j1.niveaux_joueur);//afficher les changement
	    ________________________TEST____________________________*/
    

    } while (choix_utilisateur!=4);
    
    return 0;
}
