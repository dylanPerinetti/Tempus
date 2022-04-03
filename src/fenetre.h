/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les prototype des fonction lier a la fenetre dans le jeu Tempus.
Vous retrouverer par aillieur leur mode d'utilisation.
Pour mieux comprendre leur fonctionnement rendez-vous sur le fichier "fenetre.c" .


Fait par MrTNTX et dylan le 15/03/2022
Dernière modifications par dylanPerinetti le 22/03/2022
*/
#ifndef __FENETRE_H__
#define __FENETRE_H__

#include "map.h"
#include "objet.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <time.h>
#include <string.h>


int AfficherFenetre(Tuile _map[10][10]);					//Génération de la Map initiale

void AfficherVersionSDL();		//Affiche la version de sdl
void Erreur(int error);			//Message d'erreur SDL (UNIQUEMENT)

void RefreshCase(Tuile _map[10][10], int i, int j, SDL_Renderer* _rendu);            //Reset une case a une certaine coordonnée (ça fait tout enft)
void InitialiseRect(SDL_Rect* _Rectangle, int _x, int _y, int _largeur,int _hauteur);        //Initialise les Rect 
void GenerationHexagone(unsigned char terrain, SDL_Renderer* rendu, SDL_Rect *Hex);			 //Crée une image a partir d'un fichier bmp																		
void GenerationPion(unsigned char pion_nombre, unsigned char pion_couleur, SDL_Renderer* rendu, SDL_Rect *Hex);
void TextureRendu(SDL_Surface *image, SDL_Texture *texture, SDL_Renderer* rendu, SDL_Rect *Hex);	//Applique une texture sur le rendu            

#endif

