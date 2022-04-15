/*

-------------- TEMPUS --------------

Retrouvez le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les prototype des fonction lier au evenement-graphique dans le jeu Tempus.
Vous retrouverer par aillieur leur mode d'utilisation .
Pour mieux comprendre leur fonctionnement rendez-vous sur le fichier "evenement.c" .


Fait par dylan le 21/03/2022
Dernière modifications par dylanPerinetti le 22/03/2022
*/
#ifndef __EVENEMENT_H__
#define __EVENEMENT_H__
#include <SDL.h>
#include "fenetre.h"
#include "map.h"
#include "joueur.h"

void LancementPartie(Tuile _map[10][10], Joueur _joueur[4], SDL_Renderer* _rendu, SDL_Window* _fenetre);

int CurseurBas(Tuile _map[10][10], SDL_Renderer* _rendu);
int CurseurHaut(Tuile _map[10][10], SDL_Renderer* _rendu);
int CurseurDroite(Tuile _map[10][10], SDL_Renderer* _rendu);
int CurseurGauche(Tuile _map[10][10], SDL_Renderer* _rendu);
int SelectionCase(Tuile _map[10][10], SDL_Renderer* _rendu, int _memoire[5], Joueur _joueur);


void SelectionPion(Tuile _map[10][10], int i, int j, int _memoire[5], Joueur _joueur);
int Deplacement(Tuile _map[10][10], SDL_Renderer *_rendu, int i, int j, int _memoire[5], Joueur _joueur);


void DeplacementPion(Tuile _map[10][10], SDL_Renderer* _rendu, int departx, int departy, int arriveex, int arriveey, unsigned char couleur, int nbre_pion_deplace);
void NouvelleSelectionCase(int _memoire[5],  int _coordx, int _coordy);
int ChoixAction();
#endif

// Dans SelectionMap, Deplacement, DeplacementPion et Nouvelle Selection Case.

//Tableau int : int selectionx; int selectiony; int phase_jeu; int point_dep_restant; int nbre_pion_deplace;