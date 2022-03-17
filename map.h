#ifndef __MAP_H__
#define __MAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <time.h>
#include <string.h>

int Aleatoir();
void Erreur(int error);
void ImageAleatoir(SDL_Surface* image)
{
	int terrain = Aleatoir();                         //Donne une valeur random entre 0 et 4 a terrain
	switch(terrain)
		{
			case 0 : *image = SDL_LoadBMP("src/Case_Champ_Dim.bmp"); break;          
			case 1 : *image = SDL_LoadBMP("src/Case_Foret_Dim.bmp"); break;
			case 2 : *image = SDL_LoadBMP("src/Case_Prairie_Dim.bmp"); break;       //En fonction de la valeur de terrain,
			case 3 : *image = SDL_LoadBMP("src/Case_Montagne_Dim.bmp"); break;      //donne un dossier bmp différent a image
			case 4 : *image = SDL_LoadBMP("src/Case_Colline_Dim.bmp"); break; 
		}
}

#endif
