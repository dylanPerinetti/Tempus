/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient le code Pincipal du jeu (main).

Créé par dylan le 14/03/2022
Dernière modifications par dylanPerinetti le 22/03/2022
*/

#include "objet.h"
#include "joueur.h"
#include "fenetre.h"
#include "map.h"

#define NETTOYER_TERMINAL "clear"				//Si vous etes sur windows dans le CMD remplacer par "cls"  

int main(int argc,const char* argv[])
{
	system(NETTOYER_TERMINAL);				//Netoyer le terminal 
	int GRAPHIQUE = 1;
	if(argc == 2)
	{
		if(strcmp(argv[1],"-g")==0 ) 
		{
			printf("\nVous venez de choisir de lancer Tempus SANS la version GRAPHIQUE\nPour l'activer QUITTER et relancez le jeu\n\n");
			GRAPHIQUE = 0;
		}
	}
	int choix_utilisateur=0;
	Joueur tableau_joueur[4];

	printf("\nBonjour, Bienvenue a sur TEMPUS 3.0\n\n\n");
	

	do{
		printf("\nMENU:\n\n1. JOUER \n2. REGLES DU JEU \n3. QUITTER \n") ;
		scanf("%1d",&choix_utilisateur);		//Améliorer la Secu avec fgets ou JCP ...
	
		switch(choix_utilisateur)
    	{
	        case 1:
	            system(NETTOYER_TERMINAL);
	            Cree4Joueurs(tableau_joueur);
	            //DebutJeu();				//Initialisations du jeu
	            if(GRAPHIQUE != 0)GeneMap();
	            break;
	        case 2:
	            system(NETTOYER_TERMINAL);
	            //AfficherReglesDuJeu();			//Affiche les regles du jeu 
	            break;
	        case 3:
	            system(NETTOYER_TERMINAL);
	            printf("\n\n\n\n\n     Merci et a Bientot ;)\n\n\n\n\n");
	            return 0;
	        default :
	            system(NETTOYER_TERMINAL);
	            printf("Veuillez resaisir votre choix");
	            break;
	    }

	    //______________________   ZONE TESTE   ________________________//
		printf("\nPremier argument utile : %s\n",argv[1]); // teste
		Tuile tuile;
		tuile.coordonnees.X=4;
		tuile.coordonnees.Y=4;
		EcrireTuilesBinaire(&tuile);
		for (int j = 0; j < 4; ++j)
		{
			for (int i = 0; i < 16; ++i)
	    	{
	    		tuile.coordonnees.X=i;
				tuile.coordonnees.Y=j;
	    		printf("\n%d",EcrireTuilesBinaire(&tuile));
	    		PlacerPionSurMap(&tableau_joueur[j].pion_possede[i],4,4);
				AfficherInventaireJoueur(&tableau_joueur[j]);
			}
		}
		Tuile _tuile;
		LectureTuilesBinaire(&_tuile);
		printf("_tuile %d %d",_tuile.coordonnees.X,_tuile.coordonnees.Y);
		//_____________________   FIN ZONE TESTE   _______________________//
    }while (choix_utilisateur!=4);
    return 0;
}
