#ifndef __OBJET_H__
#define __OBJET_H__

typedef struct Pions
{       
        uint8_t id_pion;                //uint8_t sigifie un nb entier non signer sur 1 Octer contre 4 Octer pour un simple int 
        uint8_t couleur;                //Car la couleur est un Héritage du joueur 
        int coord_x;
        int coord_y;
}Pions;                                 //Cree la structure d'un pions
typedef struct Cite
{
        uint8_t id_cite;                //identification de la piece
        uint8_t couleur;                //Car la couleur est un Héritage du joueur 
        int coord_x;                    //tableux ?
        int coord_y;                    //tableux ?
        uint8_t niveaux_cite;
}Cite;                                  //Cree la structure d'une Cité

void AfficherCouleurCite(Cite c_);      //Afficher Couleur dune cité
void AfficherCouleurPion(Pions p);      //Afficher Couleur d'un Pion
void AfficherIDCite(Cite c_);           //Afficher id_cite d'une cité
void AfficherIDPion(Pions p);           //Afficher id_pion d'un Pion

int DeplacerPionDroite(Pions* p);       //Déplacer pion a Droite
int DeplacerPionGauche(Pions* p);      //Déplacer pion a Gauche
int DeplacerPionHautDroite(Pions* p);   //Déplacer pion en Haut a Droite
int DeplacerPionHautGauche(Pions* p);  //Déplacer pion en Haut a Gauche
int DeplacerPionBasDroite(Pions* p);    //Déplacer pion en Bas a Droite
int DeplacerPionBasGauche(Pions* p);   //Déplacer pion en Bas a Gauche
#endif
