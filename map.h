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
void DeplacePionMap(int joueur, int departx, int departy, int nombre_pions_depart, int nombre_pions_arrivee, int carte[10][10], SDL_Renderer* rendu, SDL_Rect *Hex);  //Déplace un pion d'une case a une autre, et recharge la tuile de départ si il n'y a plus de pions dessus
void DecallageHexagoneY(SDL_Rect *Hex, int d);                            //Decalle les coordonées x et y au début de la génération d'une nouvelle rangée d'hexagone
void GenerationHexagone(char terrain, SDL_Renderer* rendu, SDL_Rect *Hex);          //Crée une image a partir d'un fichier bmp
void DecallageHexagoneX(SDL_Rect *Hex);				//Decalle la coordonée x après la génération d'un hexagone
char IntEnChar(int Entier);                         //Transforme un entier en caractère (pour l'utiliser dans la recherche du fichier image)
void TextureRendu(SDL_Surface *image, SDL_Texture *texture, SDL_Renderer* rendu, SDL_Rect *Hex);      //Applique une texture sur le rendu            
void NouvelleCite(int joueur, int coordx, int coordy, int taille, SDL_Renderer* rendu, SDL_Rect *Hex);     //Genère une nouvelle cité; Change la couleur d'une cité conquise

#endif
