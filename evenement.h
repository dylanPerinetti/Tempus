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
#include "fenetre.h"
#include "map.h"
//#include "objet.h"

int DeplacerPionGraphiqueDroite(Pions* _pion,int _x,int _y);          //Déplacer pion graphiquement a Droite
int DeplacerPionGraphiqueGauche(Pions* _pion,int _x,int _y);          //Déplacer pion graphiquement a Gauche
int DeplacerPionGraphiqueHautDroite(Pions* _pion,int _x,int _y);      //Déplacer pion en Haut graphiquement a Droite
int DeplacerPionGraphiqueHautGauche(Pions* _pion,int _x,int _y);      //Déplacer pion en Haut graphiquement a Gauche
int DeplacerPionGraphiqueBasDroite(Pions* _pion,int _x,int _y);       //Déplacer pion en Bas graphiquement a Droite
int DeplacerPionGraphiqueBasGauche(Pions* _pion,int _x,int _y);       //Déplacer pion en Bas graphiquement a Gauche
int PlacerPionGraphiqueSurMap(Pions* _pion,int _x,int _y);            //placer Pion graphiquement du stuff du joueur sur la map au coordoner x,y
int PlacerCiteGraphiqueSurMap(Cite* _cite,int _x,int _y);             //plcer Citer du graphiquement stuff du joueur sur la map au coordoner x,y 

#endif
