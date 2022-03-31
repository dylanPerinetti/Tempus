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
  	Coordonnees coordonnees;
	unsigned char type_terrain;
	unsigned char nombre_pion;
	Pions pion_dessus[5];
	Cite cite_dessus;

}Tuile;

void CreeMapTuile(Tuile _map[10][10]);								//	InitialiserCoordonneesTuile( <&Tuiles>) par defaut il sont a 99.
char RandomizeTuile();
void InitialiserCoordonneesTuile(Tuile* _tuile);						
void InitialiserTypeTerrainTuile(Tuile* _tuile);					//	InitialiserTypeTerrainTuile( <&Tuiles>, <Type de terrain>) par defaut il est a 99.
void InitialiserNombresPionsTuile(Tuile* _tuile);

int InitialiserPionsTuile(Tuile* _tuile, Pions _pion_dessus[]);	//	InitialiserPionsTuile( < &Tuiles >, < Tableaus de pion >)
int InitialiserCiteTuile(Tuile* _tuile, Cite* _cite);				//	InitialiserCiteTuile( < &Tuiles >, < &Cite >)

int ChangerNombresPionsTuile(Tuile* _tuile, unsigned char _nombre_pion);
int ChangerTypeTerrainTuile(Tuile* _tuile, unsigned char _type_terrain);
int ChangerCoordonneesTuile(Tuile* _tuile, unsigned char _x, unsigned char _y);				//	ChangerCoordonneesTuiles( <&Tuiles>, <Coordonnee X>, <Coordonnee Y>)
		

int EcrireTuilesBinaire();				//	EcrireBinaire()
int LectureTuilesBinaire();				//	LectureBinaire()


void AfficherErreurEvenement(int _erreur);

#endif
