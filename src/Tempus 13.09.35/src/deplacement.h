/*
 
-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les prototype des fonction lier au déplacement dans le jeu Tempus.
Vous retrouverer par aillieur leur mode d'utilisation .
Pour mieux comprendre leur fonctionnement rendez-vous sur le fichier "deplacement.c" .


Fait par dylan le 15/03/2022
Dernière modifications par dylanPerinetti le 06/04/2022 
Pour correctif de beug
*/

#ifndef __DEPLACEMENT_H__
#define __DEPLACEMENT_H__


#include "map.h"

int DeplacerPionDroite(Tuile* _tuile, Tuile* _tuile_d_arriver);         //Déplacer pion a Droite
int DeplacerPionGauche(Tuile* _tuile, Tuile* _tuile_d_arriver);         //Déplacer pion a Gauche
int DeplacerPionHautDroite(Tuile* _tuile, Tuile* _tuile_d_arriver);     //Déplacer pion en Haut a Droite
int DeplacerPionHautGauche(Tuile* _tuile, Tuile* _tuile_d_arriver);     //Déplacer pion en Haut a Gauche
int DeplacerPionBasDroite(Tuile* _tuile, Tuile* _tuile_d_arriver);      //Déplacer pion en Bas a Droite
int DeplacerPionBasGauche(Tuile* _tuile, Tuile* _tuile_d_arriver);      //Déplacer pion en Bas a Gauche

int PlacerPionSurMap(Tuile* _tuile,unsigned char _x,unsigned char _y);	//placer Pion du stuff du joueur sur la map au coordoner x,y (22YERROR & 2 XERROR & 11Pion_not_in_stuff)
int PlacerCiteSurMap(Tuile* _tuile,unsigned char _x,unsigned char _y);	//plcer Citer du stuff du joueur sur la map au coordoner x,y (22YERROR & 2 XERROR & 11Cite_not_in_stuff)

void ChangerCouleurCite(Tuile* _tuile,unsigned char _couleur);   //Changer la couleur d'une Cite par celle du joueur
void AugmenterNiveauCite(Tuile* _tuile);                          //Pour Indenter le niveux d'une Cite

void AfficherErreurDeplacementObjet(int _erreur);    //Affiche les Erreur
#endif
