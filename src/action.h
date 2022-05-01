/*

-------------- TEMPUS --------------

Retrouvez le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les prototype des fonction lier au evenement-graphique dans le jeu Tempus.
Vous retrouverer par aillieur leur mode d'utilisation .
Pour mieux comprendre leur fonctionnement rendez-vous sur le fichier "evenement.c" .


Fait par dylan le 21/03/2022
Dernière modifications par dylanPerinetti le 22/03/2022
*/

#ifndef __ACTION_H__
#define __ACTION_H__
#include <SDL.h>
#include "fenetre.h"
#include "map.h"
#include "joueur.h"
#define NETTOYER_TERMINAL "cls"



int Deplacement(Tuile _map[10][10], SDL_Renderer *_rendu, int *_coordx, int *_coordy, Joueur _joueur, SDL_Window *_fenetre);
int TestDeplacement(Tuile _map[10][10], SDL_Renderer *_rendu, int *_coordx, int *_coordy, int point_dep, int *nbre_pion, Joueur _joueur);

int PlacementPion(Tuile _map[10][10], SDL_Renderer* _rendu, Joueur *_joueur, SDL_Window *_fenetre);
int TestPlacementPion(Tuile _map[10][10], SDL_Renderer* _rendu, Joueur *_joueur);

int FaireEnfant(Tuile _map[10][10], SDL_Renderer* _rendu, int *_coordx, int *_coordy, Joueur *_joueur);
int TestFaireEnfant(Tuile _map[10][10], SDL_Renderer* _rendu, int *_coordx, int *_coordy, Joueur *_joueur);

int PlacementVille(Tuile _map[10][10], SDL_Renderer* _rendu, int *_coordx, int *_coordy, Joueur *_joueur);
int PiocherCarte(SDL_Renderer* _rendu, Joueur* _joueur);

void DeplacementPion(Tuile _map[10][10], SDL_Renderer* _rendu, int departx, int departy, int arriveex, int arriveey, unsigned char couleur, int nbre_pion_deplace);
int ChoixAction();
void RechercheCurseur(Tuile _map[10][10], int *_coordx, int *_coordy);

#endif