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
#include "joueur.h"
#include "evenement.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <time.h>
#include <string.h>


int AfficherFenetre(Tuile _map[10][10], Joueur tableau_joueur[4], SDL_Renderer *_rendu, SDL_Window *_fenetre);					//Génération de la Map initiale a partir du tableau de tuile

void AfficherVersionSDL();		//Affiche la version de sdl
void Erreur(int error);			//Message d'erreur SDL (UNIQUEMENT)

void MajCase(Tuile _map[10][10], int i, int j, SDL_Renderer* _rendu);            //Reset une case a une certaine coordonnée, avec le type de cases, le nombre de pions et de villes (ça fait tout enft)
void InitialiseRect(SDL_Rect* _Rectangle, int _x, int _y, int _largeur,int _hauteur);        //Initialise les Rectangles SDL 

void GenerationOcean(SDL_Renderer* _rendu);                                                           //Génère le fond océan
void GenerationHexagone(unsigned char _terrain, SDL_Renderer* _rendu, SDL_Rect *Hex);			           //Crée un Hexagone a partir d'un fichier bmp																		
void GenerationVille(unsigned char _taille, unsigned char _couleur, SDL_Renderer* _rendu, SDL_Rect *Hex);	//Crée une Ville a partir d'un fichier bmp
void GenerationPion(unsigned char _nombre, unsigned char _couleur, SDL_Renderer* _rendu, SDL_Rect *Hex);    //Crée une Pion a partir d'un fichier bmp
void GenerationCurseur(int _curseur, SDL_Renderer* _rendu, SDL_Rect *Hex);

void TextureRendu(SDL_Surface* _image, SDL_Texture* _texture, SDL_Renderer* _rendu, SDL_Rect *Hex);	//Applique une texture qu'on lui envoie sur le rendu         


#endif

