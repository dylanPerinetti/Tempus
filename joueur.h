#ifndef __JOUEUR_H__
#define __JOUEUR_H__
#include <stdio.h>
#include <stdint.h>

typedef struct Joueur
{
	char* nom_utilisateur;
	uint8_t couleur;
	uint8_t niveaux_joueur;
	Pions pion_possede[16];
	Cite cite_possede[32];
}Joueur;										//Pour Cree la Structure d'un joueur

void InitialiserCouleurJoueur(Joueur* _joueur,uint8_t _couleur);//Pour Initialiser la couleur de joueur a 0
void InitialiserNiveauJoueur(Joueur* _joueur);					//Pour Initialiser le niveux de joueur a 0
void CreeJoueur(Joueur* _joueur,uint8_t _couleur);				//Pour la crééation d'un nouveaux joueur
void Cree4Joueurs(Joueur tab[]);								//Pour Créé 4 Joueur

void AugmenterNiveauJoueur(Joueur* j);			//Pour Indenter le niveux d'un joueuer 

void AfficherNiveauJoueur(Joueur* j);			//Pour Afficher le niveaux d'un joueur
void AfficherInventaireJoueur(Joueur* j);		//Pour Afficher L'inventaire d'un joueur

int* InventaireJoueur(Joueur* j);				//Pour Ranger l'inventaire dans un tableau[<PIONS>,<CITE>]
int InventairePions(Joueur* j);					//Pour Répertorier les Pions d'un joueur dans l'inventaire
int InventaireCite(Joueur* j);					//Pour Répertorier les Cite d'un joueur dans l'inventaire

void RecupererPion(Joueur* j,Pions* p);			//Placer un pion dans le stuff du joueur


#endif
