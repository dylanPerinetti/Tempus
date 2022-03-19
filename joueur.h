/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 


Ce fichier contient les prototype des fonction lier au joueur dans le jeu Tempus.
Vous retrouverer par aillieur leur mode d'utilisation .
Pour mieux comprendre leur fonctionnement rendez-vous sur le fichier "joueur.c" .


Fait par dylan le 14/03/2022
Dernière modifications par dylanPerinetti le 19/03/2022
*/


#ifndef __JOUEUR_H__
#define __JOUEUR_H__
#include <stdio.h>
#include <stdint.h>

typedef struct Joueur
{
	char* nom_utilisateur;
	unsigned char couleur;
	unsigned char niveaux_joueur;
	Pions pion_possede[16];
	Cite cite_possede[32];
}Joueur;										//Pour Cree la Structure d'un joueur

void InitialiserCouleurJoueur(Joueur* _joueur,unsigned char _couleur);	//Pour Initialiser la couleur de joueur a 0
void InitialiserNiveauJoueur(Joueur* _joueur);							//Pour Initialiser le niveux de joueur a 0
void CreeJoueur(Joueur* _joueur,unsigned char _couleur);				//Pour la crééation d'un nouveaux joueur
void Cree4Joueurs(Joueur tab[]);								//Pour Créé 4 Joueur

void AugmenterNiveauJoueur(Joueur* j);			//Pour Indenter le niveux d'un joueuer 

void AfficherNiveauJoueur(Joueur* j);			//Pour Afficher le niveaux d'un joueur
void AfficherInventaireJoueur(Joueur* j);		//Pour Afficher L'inventaire d'un joueur

int* InventaireJoueur(Joueur* _joueur);				//Pour Ranger l'inventaire dans un tableau[<PIONS>,<CITE>]
int InventairePions(Joueur* _joueur);				//Pour Répertorier les Pions d'un joueur dans l'inventaire
int InventaireCite(Joueur* _joueur);				//Pour Répertorier les Cite d'un joueur dans l'inventaire

int RecupererPion(Joueur* _joueur,Pions* _pion);	//Placer un pion dans le stuff du joueur


#endif
