#ifndef __JOUEUR_H__
#define __JOUEUR_H__

/*---------------------- Joueur ----------------------*/

typedef struct Joueur
{
	//char nom_utilisateur[255];
	uint8_t couleur;
	uint8_t niveaux_joueur;
	Pions pion_possede[16];
	Ville ville_possede[8];
}Joueur;


void CreeJoueurs(Joueur* j,uint8_t c);
void Cree4Joueurs(Joueur tab[]);
void AugmenterNiveaux(Joueur* j);
void AfficherNiveaux(Joueur* j);

#endif
