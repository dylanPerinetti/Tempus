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

typedef struct
{
  	Coordonnees coordonnees;
	unsigned char type_terrain;
	unsigned char nombre_de_pion;
	Pions pion_dessus[5];
	Cite cite_dessus;

}Tuile;

void CreeMapTuile();
void InitialiserCoordonneesTuile(Tuile* _tuile);								//	InitialiserCoordonneesTuile( <&Tuiles>) par defaut il sont a 99.
void InitialiserTypeTerrainTuile(Tuile* _tuile, unsigned char _Type_terrain);	//	InitialiserTypeTerrainTuile( <&Tuiles>, <Type de terrain>) par defaut il est a 99.
void InitialiserCiteTuile(Tuile* _tuile, Cite* _cite);							//	InitialiserCiteTuile( < &Tuiles >, < &Cite >)
void InitialiserPionsTuile(Tuile* _tuile, Pions _pion_dessus[]);				//	InitialiserPionsTuile( < &Tuiles >, < Tableaus de pion >)

int ChangerCoordonneesTuile(Tuile* _tuile, unsigned char _x, unsigned char _y);			//	ChangerCoordonneesTuiles( <&Tuiles>, <Coordonnee X>, <Coordonnee Y>)

int EcrireTuilesBinaire();				//	EcrireBinaire()
int LectureTuilesBinaire();				//	LectureBinaire()


void AfficherErreurEvenement(int _erreur);

#endif
