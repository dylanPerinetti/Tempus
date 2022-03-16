#ifndef __JOUEUR_H__
#define __JOUEUR_H__
/*---------------------- Joueur ----------------------*/

typedef struct Joueur
{
	char* nom_utilisateur;
	uint8_t couleur;
	uint8_t niveaux_joueur;
	Pions pion_possede[16];
	Cite cite_possede[32];
}Joueur;						//Pour Cree la Structure d'un joueur

void CreeJoueur(Joueur* j,uint8_t c);			//Pour la crééation d'un nouveaux joueur
void Cree4Joueurs(Joueur tab[]);			//Pour Créé 4 Joueur
void AugmenterNiveauxJoueur(Joueur* j);			//Pour Indenter le niveux d'un joueuer 

void AfficherNiveauxJoueur(Joueur* j);			//Pour Afficher le niveaux d'un joueur
void AfficherInventaireJoueur(Joueur* j);		//Pour Afficher L'inventaire d'un joueur

int* InventaireJoueur(Joueur* j);			//Pour Ranger l'inventaire dans un tableau[<PIONS>,<CITE>]
int InventairePions(Joueur* j);				//Pour Répertorier les Pions d'un joueur dans l'inventaire
int InventaireCite(Joueur* j);				//Pour Répertorier les Cite d'un joueur dans l'inventaire

void PlacerPionSurMap(Joueur* j,Pions* p,int x_,int y_);//placer Pion du stuff du joueur sur la map au coordoner x,y
void PlacerCiteSurMap(Joueur* j,Cite* c_,int x_,int y_);//plcer Citer du stuff du joueur sur la map au coordoner x,y
void RecupererPion(Joueur* j,Pions* p);			//Placer un pion dans le stuff du joueur
void ChangerCouleurCite(Joueur voleur,Cite* c_);	//Changer la couleur d'une Cite par celle du joueur


#endif
