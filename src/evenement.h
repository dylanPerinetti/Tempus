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
#include "action.h"
#define NETTOYER_TERMINAL "cls"

void LancementPartie(Tuile _map[10][10], Joueur _joueur[4], SDL_Renderer* _rendu, SDL_Window* _fenetre);



int SelectionCase(Tuile _map[10][10], SDL_Renderer* _rendu, Joueur* _joueur, Joueur tab_joueur[4], SDL_Window *_fenetre);
int SelectionPion(Tuile _map[10][10], SDL_Renderer* _rendu, Joueur* _joueur, Joueur tab_joueur[4], SDL_Window *_fenetre);

int CurseurBas(Tuile _map[10][10], SDL_Renderer* _rendu);
int CurseurHaut(Tuile _map[10][10], SDL_Renderer* _rendu);
int CurseurDroite(Tuile _map[10][10], SDL_Renderer* _rendu);
int CurseurGauche(Tuile _map[10][10], SDL_Renderer* _rendu);

int ChoixAction();
void RechercheCurseur(Tuile _map[10][10], int *_coordx, int *_coordy);
int FinPartie(Tuile _map[10][10], Joueur _joueur[4]);


#endif
