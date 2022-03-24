/*
 
-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les prototype des fonction lier au objet dans le jeu Tempus.
Vous retrouverer par aillieur leur mode d'utilisation .
Pour mieux comprendre leur fonctionnement rendez-vous sur le fichier "objet.c" .


Fait par dylan le 15/03/2022
Dernière modifications par dylanPerinetti le 22/03/2022
*/

#ifndef __OBJET_H__
#define __OBJET_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Coordonnees
{
        unsigned char X;
        unsigned char Y; 

}Coordonnees;


typedef struct Id_Objet
{
        unsigned char numero_serie_objet;           
        char lettre_serie;
        unsigned char numero_serie;
}Id_Objet;


typedef struct Pions
{       
        Id_Objet id_pion;                
        unsigned char couleur;                //Car la couleur est un Héritage du joueur 
        Coordonnees coordonnees;
}Pions;//Cree la structure d'un pions


typedef struct Cite
{
        Id_Objet id_cite;               //identification de la piece
        unsigned char couleur;                //Car la couleur est un Héritage du joueur 
        unsigned char niveaux_cite;
        Coordonnees coordonnees;
}Cite;                                  //Cree la structure d'une Cité


typedef struct Carte_Idee
{
        unsigned char Type_de_terrain;
}Carte_Idee;




void GenerateurID(Id_Objet *_id,unsigned char _couleur);

void InitialiserCouleurPion(Pions* _pion,unsigned char _couleur);//Initialiser la couleur d'un pion <_couleur>
void InitialiserCouleurCite(Cite* _cite,unsigned char _couleur);//Initialiser la couleur d'une cité <_couleur>
void InitialiserCoordonneesPion(Pions* _pion);                  //Initialiser les coordonnes d'un pion a x=-1 y=-1
void InitialiserCoordonneesCite(Cite* _cite);                   //Initialiser les coordonnes d'une cité a x=-1 y=-1
void InitialiserNiveauCite(Cite* _cite);                        //Initialiser le niveau d'une cité à 0
void InitialiserPions(Pions *_pion,unsigned char _couleur);     //Initialiser un pion entierement
void InitialiserCite(Cite *_cite,unsigned char _couleur);       //Initialiser une cité entierement
//int* CreePion();PAS ID plus tars fichier bin !!!!!

void AfficherCouleurCite(Cite _cite);           //Afficher Couleur dune cité
void AfficherCouleurPion(Pions _pion);          //Afficher Couleur d'un Pion
void AfficherIDCite(Cite _cite);                //Afficher id_cite d'une cité
void AfficherIDPion(Pions _pion);               //Afficher id_pion d'un Pion
void AfficherCoordonneesPion(Pions _pion);      //Afficher les coordonnees d'un Pion
void AfficherCoordonneesCite(Cite _cite);       //Afficher les coordonnees d'une Cite

int DeplacerPionDroite(Pions* _pion);           //Déplacer pion a Droite
int DeplacerPionGauche(Pions* _pion);           //Déplacer pion a Gauche
int DeplacerPionHautDroite(Pions* _pion);       //Déplacer pion en Haut a Droite
int DeplacerPionHautGauche(Pions* _pion);       //Déplacer pion en Haut a Gauche
int DeplacerPionBasDroite(Pions* _pion);        //Déplacer pion en Bas a Droite
int DeplacerPionBasGauche(Pions* _pion);        //Déplacer pion en Bas a Gauche
int PlacerPionSurMap(Pions* _pion,unsigned char _x,unsigned char _y);//placer Pion du stuff du joueur sur la map au coordoner x,y (22YERROR & 2 XERROR & 11Pion_not_in_stuff)
int PlacerCiteSurMap(Cite* _cite,unsigned char _x,unsigned char _y);//plcer Citer du stuff du joueur sur la map au coordoner x,y (22YERROR & 2 XERROR & 11Cite_not_in_stuff)

void ChangerCouleurCite(Cite* _cite, unsigned char _couleur);   //Changer la couleur d'une Cite par celle du joueur
void AugmenterNiveauCite(Cite* _Cite);                          //Pour Indenter le niveux d'une Cite

void AfficherErreurDeplacementObjet(int _erreur);    //Affiche les Erreur
#endif