#ifndef __JOUEUR_H__
#define __JOUEUR_H__

/*---------------------- Joueur ----------------------*/

typedef struct Joueur
{
	char* nom_utilisateur;
	uint8_t couleur;
	uint8_t niveaux_joueur;
	Pions pion_possede[16];
	Cite cite_possede[8];
}Joueur;


void CreeJoueur(Joueur* j,uint8_t c);
void Cree4Joueurs(Joueur tab[]);
void AugmenterNiveauxJoueur(Joueur* j);

void AfficherNiveauxJoueur(Joueur* j);
void AfficherInventaireJoueur(Joueur* j);

int* InventaireJoueur(Joueur* j);
int InventairePions(Joueur* j);
int InventaireCite(Joueur* j);


#endif
