#ifndef __EVENEMENT_H__
#define __EVENEMENT_H__

int DeplacerPionGraphiqueDroite(Pions* _pion);          //Déplacer pion graphiquement a Droite
int DeplacerPionGraphiqueGauche(Pions* _pion);          //Déplacer pion graphiquement a Gauche
int DeplacerPionGraphiqueHautDroite(Pions* _pion);      //Déplacer pion en Haut graphiquement a Droite
int DeplacerPionGraphiqueHautGauche(Pions* _pion);      //Déplacer pion en Haut graphiquement a Gauche
int DeplacerPionGraphiqueBasDroite(Pions* _pion);       //Déplacer pion en Bas graphiquement a Droite
int DeplacerPionGraphiqueBasGauche(Pions* _pion);       //Déplacer pion en Bas graphiquement a Gauche
int PlacerPionGraphiqueSurMap(Pions* _pion,int _x,int _y);//placer Pion graphiquement du stuff du joueur sur la map au coordoner x,y
int PlacerCiteGraphiqueSurMap(Cite* _cite,int _x,int _y);//plcer Citer du graphiquement stuff du joueur sur la map au coordoner x,y 

#endif
