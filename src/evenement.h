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
#include "objet.h"

int CurseurBas(Tuile _map[10][10], SDL_Renderer* _rendu);
int CurseurHaut(Tuile _map[10][10], SDL_Renderer* _rendu);
int CurseurDroite(Tuile _map[10][10], SDL_Renderer* _rendu);
int CurseurGauche(Tuile _map[10][10], SDL_Renderer* _rendu);
int SelectionCase(Tuile _map[10][10], SDL_Renderer* _rendu, int *_phase_jeu, int *_selectionx, int *_selectiony, int *_point_deplacement);


void SelectionPion(Tuile _map[10][10], int i, int j, int *_phase_jeu, int *_selectionx, int *_selectiony);
void Deplacement(Tuile _map[10][10], SDL_Renderer* _rendu, int *phase_jeu, int i, int j, int *_selectionx, int *_selectiony, int *_point_deplacement);


void DeplacementPion(Tuile _map[10][10], SDL_Renderer* _rendu, int departx, int departy, int arriveex, int arriveey, unsigned char couleur, int nbre_pion_deplace);
void NouvelleSelectionCase(int *_selectionx, int *_selectiony,  int _coordx, int _coordy);
int ChoixAction();
#endif

// Dans SelectionMap, Deplacement, DeplacementPion et Nouvelle Selection Case, toutes les variables phase_jeu, selectionx, selectiony, point deplacement et couleur et nbre pion deplace pour eviter de demander 30 fois seront comprises dans la structure joueur(truc urgent a faire un peu)
