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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define PRCT_PRAIRIE 40
#define PRCT_MONTAGNE 20
#define PRCT_FORET 10
#define PRCT_COLLINE 10
#define PRCT_CHAMP 10
#define PRCT_LAC 10


typedef struct Tuile
{
	unsigned char type_terrain;
	unsigned char nombre_pion;
	unsigned char couleur;
	unsigned char taille_ville;
	int curseur;

}Tuile;

void CreeMapTuile(Tuile _map[10][10]);           //Génère les cases de la carte de tuiles
char RandomizeTuile();                           //Renvoie un nombre aléatoire pour chaques tuiles de la fonction ci dessus

void InitialiserCurseur(Tuile* _tuile, int bool);      //Initialise le curseur a certaines coordonées
int ChangerNombresPionsTuile(Tuile* _tuile, unsigned char _nombre_pion, unsigned char _couleur);     
int ChangerTypeTerrainTuile(Tuile* _tuile, unsigned char _type_terrain);
int ChangerCouleurTuile(Tuile* _tuile, unsigned char _couleur);
int ChangerTailleVilleTuile(Tuile* _tuile, unsigned char _taille_ville);
		
int EcrireTuilesBinaire();				//	EcrireBinaire()
int LectureTuilesBinaire();				//	LectureBinaire()


void AfficherErreurEvenement(int _erreur);
int CaseInterdite(int i, int j);                                            //Renvoie 1 si la case envoyée est une case d'océan (bord de la cartes inaccessibles)
int CaseAdjacente(int departx, int departy, int arriveex, int arriveey);      //Renvoie 1 si la seconde case envoyée est adjacente a la première

int IntEnChar(int Entier);                                                 //Transforme un entier en char utilisable pour les fichiers

#endif
