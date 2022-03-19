#ifndef __MAP_H__
#define __MAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <time.h>
#include <string.h>


int GeneMap();                //Génération de la Map initiale
char Aleatoire();             //Création du nombre aléatoire entre 0 et 5 qui définit la texture de la tuile lors de la génération
void Erreur(int error);       //Message d'erreur SDL (UNIQUEMENT)
void DeplacePionMap(int joueur, int departx, int departy, int arriveex, int arriveey, int nombre_pions_depart, int nombre_pions_arrivee, int case_depart, SDL_Renderer* rendu, SDL_Rect *Hex);  //Déplace un pion d'une case a une autre, et recharge la tuile de départ si il n'y a plus de pions dessus
void DecallageHexagoneY(SDL_Rect *Hex, int d);                            //Decalle les coordonées x et y au début de la génération d'une nouvelle rangée d'hexagone
void TextureSurRendu(char terrain, SDL_Renderer* rendu, SDL_Rect *Hex);          //Génère une texture de tuile a partir d'une image et l'applique sur le rendu aux coordonées du rectangle Hex.
void DecallageHexagoneX(SDL_Rect *Hex);				//Decalle la coordonée x après la génération d'un hexagone
char IntEnChar(int Entier);                         //Transforme un entier en caractère (pour l'utiliser dans la recherche du fichier image)

#endif
