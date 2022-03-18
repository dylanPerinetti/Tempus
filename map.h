#ifndef __MAP_H__
#define __MAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <time.h>
#include <string.h>


int GeneMap();
char Aleatoire();
void Erreur(int error);
void DeplacePionMap(int joueur, int departx, int departy, int arriveex, int arriveey, int nombre_pions_depart, int nombre_pions_arrivee, int case_depart, SDL_Renderer* rendu);

#endif
