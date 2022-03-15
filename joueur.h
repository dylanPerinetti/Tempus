#ifndef __JOUEUR_H__
#define __JOUEUR_H__

/*---------------------- Joueur ----------------------*/

typedef struct Joueur
{
	//char nom_utilisateur[255];
	int couleur;
	int niveaux_joueur;
	Pions pions_possede[15];
	Ville ville_possede[7];
}Joueur;


void CreeJoueurs(Joueur* j,uint8_t c);
void Cree4Joueurs(Joueur tab[]);
void AugmenterNiveaux(Joueur* j);
void AfficherNiveaux(Joueur* j);

#endif
