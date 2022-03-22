/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les prototype des fonction lier a la fenetre dans le jeu Tempus.
Vous retrouverer par aillieur leur mode d'utilisation.
Pour mieux comprendre leur fonctionnement rendez-vous sur le fichier "fenetre.c" .


Fait par MrTNTX et dylan le 15/03/2022
Dernière modifications par MrTNTX le 21/03/2022
*/
#ifndef __FENETRE_H__
#define __FENETRE_H__

#include "objet.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <time.h>
#include <string.h>


int GeneMap();					//Génération de la Map initiale
char CharactereAleatoire();		//Création du nombre aléatoire entre 0 et 5 qui définit la texture de la tuile lors de la génération
void Erreur(int error);			//Message d'erreur SDL (UNIQUEMENT)
void DeplacePionMap(Pions* _pion, int departx, int departy, int nombre_pions_depart, int nombre_pions_arrivee, int carte[10][10], SDL_Renderer* rendu, SDL_Rect *Hex);  //Déplace un pion d'une case a une autre, et recharge la tuile de départ si il n'y a plus de pions dessus


void GenerationHexagone(char terrain, SDL_Renderer* rendu, SDL_Rect *Hex);			//Crée une image a partir d'un fichier bmp

void InitialiseRect(SDL_Rect* _Rectangle, int _x, int _y, int _largeur,int _hauteur);//Initialise les Rect 
char InitialiseHexagone(SDL_Renderer* _rendu, SDL_Rect *_Hexagone);	//Crée une ligne Hexagone renvois le

void DecallageHexagoneY(SDL_Rect *Hex, int d);										//Decalle les coordonées x et y au début de la génération d'une nouvelle rangée d'hexagone
void DecallageHexagoneX(SDL_Rect *Hex);												//Decalle la coordonée x après la génération d'un hexagone

char IntEnChar(int Entier);																			//Transforme un entier en caractère (pour l'utiliser dans la recherche du fichier image)
void TextureRendu(SDL_Surface *image, SDL_Texture *texture, SDL_Renderer* rendu, SDL_Rect *Hex);	//Applique une texture sur le rendu            
void NouvelleCite(int joueur, int coordx, int coordy, int taille, SDL_Renderer* rendu, SDL_Rect *Hex);//Genère une nouvelle cité; Change la couleur d'une cité conquise


void AfficherVersionSDL();		//Affiche la version de sdl

#endif

