/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient le code Pincipal du jeu (main).

Fait par dylan le 14/03/2022
Dernière modifications par dylanPerinetti le 06/04/2022
*/
#include "map.h"
#include "deplacement.h"
#include "fenetre.h"
#include "joueur.h"
#include "evenement.h"

#define NETTOYER_TERMINAL "clear" //Si vous etes sur windows remplacer "clear" par "cls"  

int main(int argc,char* argv[])
{
	int GRAPHIQUE = 1;
	if(argc == 2)
	{
		if(strcmp(argv[1],"-g")==0 ) 
		{
			system(NETTOYER_TERMINAL);
			printf("\n\nVous venez de choisir de lancer Tempus la version GRAPHIQUE\nPour l'activer QUITTER et relancez le jeu\n\n");
			GRAPHIQUE = 0;
		}
		else if(strcmp(argv[1],"-h")==0 ) 
		{
			fprintf(stderr,"\n[ Argment | %s ]Pour Afficher l'Aide \n[ Argment | -g ]Pour lancer sans la version Graphique\n\n",argv[1]);
			return 1;
		}
		else
		{
			fprintf(stderr,"\n[ Argment | %s ]Invalide\n[ Argment | -h ] Pour Afficher l'Aide\n\n",argv[1]);
			exit(EXIT_FAILURE);
		}
	}



	int choix_utilisateur=0;
	Joueur tableau_joueur[4];
	Tuile map[10][10];
	CreeMapTuile(map);

	printf("\n\n\n\nBonjour, Bienvenue a sur \n\n\n");
	

	do{
		printf("\nMENU:\n\n1. JOUER \n2. REGLES DU JEU \n3. QUITTER \n") ;
		scanf("%1d",&choix_utilisateur);			//Améliorer la Secu avec fgets ou JCP ...
	
		switch(choix_utilisateur)
    	{
	        case 1:
	            system(NETTOYER_TERMINAL);
	            Cree4Joueurs(tableau_joueur);
	            //DebutJeu();					//Initialisations du jeu
	            if(GRAPHIQUE != 0)AfficherFenetre(map);
	            break;
	        case 2:
	            system(NETTOYER_TERMINAL);
	            //AfficherReglesDuJeu();		//Affiche les regles du jeu 
	            break;
	        case 3:
	            system(NETTOYER_TERMINAL);
	            printf("\n\n\n\n\n\nMerci et a Bientot ;)\n\n\n\n\n\n");
	            return 0;
	        default :
	            system(NETTOYER_TERMINAL);
	            printf("Veuillez resaisir votre choix");
	            break;
	    }

	    //______________________   ZONE TESTE   ________________________//
		printf("\nPremier argument utile : %s\n",argv[1]); // teste
		//_____________________   FIN ZONE TESTE   _______________________//
    }while (choix_utilisateur!=4);
    return 0;
}
