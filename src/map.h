/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les prototype des fonction lier a la map dans le jeu Tempus.
Vous retrouverer par aillieur leur mode d'utilisation.
Pour mieux comprendre leur fonctionnement rendez-vous sur le fichier "map.c" .


Crée par dylanPerinetti le 22/03/2022
Dernière modifications par dylanPerinetti le 24/03/2022

Je suis acctuellement en train de develloper :
	- Structure MAP 
	- ECRITURE dans un fichier(_SAVE.DATA) les donner de terrain
	- LECTURE du fichier 
	- demander ce qui il y dans un Hexagone avec cest coordonnee simplement 
*/

#ifndef __MAP_H__
#define __MAP_H__
#include "objet.h"
#include <stdlib.h>
#include <time.h>
#define PRCT_PRAIRIE 40
#define PRCT_MONTAGNE 20
#define PRCT_FORET 10
#define PRCT_COLLINE 10
#define PRCT_CHAMP 10
#define PRCT_LAC 10


typedef struct
{
	unsigned char type_terrain;
	unsigned char nombre_pion;
	unsigned char couleur;
	unsigned char taille_ville;

}Tuile;

void CreeMapTuile(Tuile _map[10][10]);								//	InitialiserCoordonneesTuile( <&Tuiles>) par defaut il sont a 99.
char RandomizeTuile();
						
void InitialiserTypeTerrainTuile(Tuile* _tuile);					//	InitialiserTypeTerrainTuile( <&Tuiles>, <Type de terrain>) par defaut il est a 99.
void InitialiserNombresPionsTuile(Tuile* _tuile);

int ChangerNombresPionsTuile(Tuile* _tuile, unsigned char _nombre_pion);
int ChangerTypeTerrainTuile(Tuile* _tuile, unsigned char _type_terrain);
int ChangerCouleurTuile(Tuile* _tuile, unsigned char _couleur);
int ChangerTailleVilleTuile(Tuile* _tuile, unsigned char _taille_ville);
		
int EcrireTuilesBinaire();				//	EcrireBinaire()
int LectureTuilesBinaire();				//	LectureBinaire()


void AfficherErreurEvenement(int _erreur);

#endif
