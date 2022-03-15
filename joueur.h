#ifndef __JOUEUR_H__
#define __JOUEUR_H__

/*---------------------- Joueur ----------------------*/

typedef struct Joueur
{
	//char nom_utilisateur[255];
	uint8_t couleur;
	uint8_t niveaux_joueur;
	Pions pion_possede[16];
	Cite cite_possede[8];
}Joueur;


void CreeJoueurs(Joueur* j,uint8_t c);
void Cree4Joueurs(Joueur tab[]);
void AugmenterNiveauxJoueur(Joueur* j);
void AfficherNiveauxJoueur(Joueur* j);

int InventairePions(Joueur* j);
int InventaireCite(Joueur* j);

#endif
