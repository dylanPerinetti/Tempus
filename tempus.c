/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient le code Pincipal du jeu (main).

Fait par dylan le 14/03/2022
Dernière modifications par dylanPerinetti le 19/03/2022
*/


#include "objet.h"
#include "joueur.h"
//#include "map.h"

#define NETTOYER_TERMINAL "cls"				//Si vous etes sur windows dans le CMD remplacer par "cls"  

int main(int argc, char* argv[])
{
	int choix_utilisateur=0;
	Joueur tableau_joueur[4];


	system(NETTOYER_TERMINAL);					//shell Netoyer le terminal 
	printf("\nBonjour, Bienvenue a sur TEMPUS 3.0\n\n\n");
	

	do{
	
		printf("\nMENU:\n\n1. JOUER \n2. REGLES DU JEU \n3. QUITTER \n") ;
		scanf("%1d",&choix_utilisateur);			//Améliorer la Secu avec fgets ou JCP ...
	
		switch(choix_utilisateur)
    	{
	        case 1:
	            system(NETTOYER_TERMINAL);
	            Cree4Joueurs(tableau_joueur);
	            //DebutJeu();					//Initialisations du jeu
	            //GeneMap();
	            break;
	        case 2:
	            system(NETTOYER_TERMINAL);
	            //AfficherReglesDuJeu();		//Affiche les regles du jeu 
	            break;
	        case 3:
	            system(NETTOYER_TERMINAL);
	            printf("\n\n\n\n\n\nMerci et à Bientôt ;)\n\n\n\n\n\n");
	            return 0;
	        default :
	            system(NETTOYER_TERMINAL);
	            printf("Veuillez resaisir votre choix");
	            break;
	    }

	    //______________________   ZONE TESTE   ________________________//

		DeplacerPionDroite(&tableau_joueur[2].pion_possede[7]);       //Déplacer pion a Droite
		DeplacerPionGauche(&tableau_joueur[2].pion_possede[7]);      //Déplacer pion a Gauche
		DeplacerPionHautDroite(&tableau_joueur[2].pion_possede[7]);   //Déplacer pion en Haut a Droite
		DeplacerPionHautGauche(&tableau_joueur[2].pion_possede[7]);  //Déplacer pion en Haut a Gauche
		DeplacerPionBasDroite(&tableau_joueur[2].pion_possede[7]);    //Déplacer pion en Bas a Droite
		DeplacerPionBasGauche(&tableau_joueur[2].pion_possede[7]);   //Déplacer pion en Bas a Gauche
		AfficherIDCite(tableau_joueur[2].cite_possede[7]);
		printf("\n%d\n",InventaireCite(&tableau_joueur[1]));	//TESTE
		printf("\n%d\n",InventairePions(&tableau_joueur[1]));	//TEST
	   	AugmenterNiveauJoueur(&tableau_joueur[1]);				//TESTE 
		AfficherNiveauJoueur(&tableau_joueur[1]);				//TESTE
		AfficherInventaireJoueur(&tableau_joueur[1]);			//TESTE
		AfficherCouleurCite(tableau_joueur[2].cite_possede[2]);	//TESTE
		ChangerCouleurCite(&tableau_joueur[2].cite_possede[2],tableau_joueur[1].couleur);//TESTE
		AfficherCouleurCite(tableau_joueur[2].cite_possede[2]);	//TESTE
		ChangerCouleurCite(&tableau_joueur[2].cite_possede[2],tableau_joueur[1].couleur);//TESTE
	    	AfficherCoordonneesCite(tableau_joueur[2].cite_possede[7]);
	    	DeplacerPionDroite(&tableau_joueur[2].pion_possede[7]);     //Déplacer pion a Droite
		DeplacerPionGauche(&tableau_joueur[2].pion_possede[7]);     //Déplacer pion a Gauche
		DeplacerPionHautDroite(&tableau_joueur[2].pion_possede[7]); //Déplacer pion en Haut a Droite
		DeplacerPionHautGauche(&tableau_joueur[2].pion_possede[7]); //Déplacer pion en Haut a Gauche
		DeplacerPionBasDroite(&tableau_joueur[2].pion_possede[7]);	//Déplacer pion en Bas a Droite
		DeplacerPionBasGauche(&tableau_joueur[2].pion_possede[7]);  //Déplacer pion en Bas a Gauche
	    	AfficherIDCite(tableau_joueur[2].cite_possede[7]);
	    	AfficherIDPion(tableau_joueur[2].pion_possede[7]);
	    	printf("\n%d\n",InventaireCite(&tableau_joueur[1]));	//TESTE
	    	printf("\n%d\n",InventairePions(&tableau_joueur[1]));	//TEST
	    	AugmenterNiveauJoueur(&tableau_joueur[3]);				//TESTE 
		AfficherNiveauJoueur(&tableau_joueur[1]);				//TESTE
		AfficherInventaireJoueur(&tableau_joueur[1]);			//TESTE
		AfficherCouleurCite(tableau_joueur[2].cite_possede[2]);	//TESTE
		ChangerCouleurCite(&tableau_joueur[2].cite_possede[2],tableau_joueur[1].couleur);//TESTE
		AfficherCouleurCite(tableau_joueur[2].cite_possede[2]);	//TESTE
		ChangerCouleurCite(&tableau_joueur[2].cite_possede[2],tableau_joueur[1].couleur);//TESTE
		
		//_____________________   FIN ZONE TESTE   _______________________//
    }while (choix_utilisateur!=4);
    return 0;
}
