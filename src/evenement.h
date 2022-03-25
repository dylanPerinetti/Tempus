/*

-------------- TEMPUS --------------

Retrouvez le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les prototype des fonction lier au evenement-graphique dans le jeu Tempus.
Vous retrouverer par aillieur leur mode d'utilisation .
Pour mieux comprendre leur fonctionnement rendez-vous sur le fichier "evenement.c" .


Fait par dylan le 21/03/2022
Dernière modifications par dylanPerinetti le 22/03/2022
*/
#ifndef __EVENEMENT_H__
#define __EVENEMENT_H__
//#include "fenetre.h"
#include "map.h"
//#include "objet.h"

int DeplacerPionGraphiqueDroite(Pions* _pion,unsigned char _x,unsigned char _y);          //Déplacer pion graphiquement a Droite
int DeplacerPionGraphiqueGauche(Pions* _pion,unsigned char _x,unsigned char _y);          //Déplacer pion graphiquement a Gauche
int DeplacerPionGraphiqueHautDroite(Pions* _pion,unsigned char _x,unsigned char _y);      //Déplacer pion en Haut graphiquement a Droite
int DeplacerPionGraphiqueHautGauche(Pions* _pion,unsigned char _x,unsigned char _y);      //Déplacer pion en Haut graphiquement a Gauche
int DeplacerPionGraphiqueBasDroite(Pions* _pion,unsigned char _x,unsigned char _y);       //Déplacer pion en Bas graphiquement a Droite
int DeplacerPionGraphiqueBasGauche(Pions* _pion,unsigned char _x,unsigned char _y);       //Déplacer pion en Bas graphiquement a Gauche

#endif
