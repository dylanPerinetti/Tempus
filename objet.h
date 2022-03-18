#ifndef __OBJET_H__
#define __OBJET_H__
typedef struct Id_Objet
{
        uint8_t numero_serie;           //uint8_t sigifie un nb entier non signer sur 1 Octer contre 4 Octer pour un simple int 
        char lettre_serie;
}Id_Objet;
typedef struct Pions
{       
        Id_Objet id_pion;                
        uint8_t couleur;                //Car la couleur est un Héritage du joueur 
        int coord_x;
        int coord_y;
}Pions;                                 //Cree la structure d'un pions
typedef struct Cite
{
        Id_Objet id_cite;               //identification de la piece
        uint8_t couleur;                //Car la couleur est un Héritage du joueur 
        int coord_x;                    //tableux ?
        int coord_y;                    //tableux ?
        uint8_t niveaux_cite;
}Cite;                                  //Cree la structure d'une Cité
typedef struct Carte_Idee
{
        uint8_t Type_de_terrain;
}Carte_Idee;
int* GenerateurID(Id_Objet *_id);

void InitialiserCouleurPion(Pions* _pion,uint8_t _couleur);     //Initialiser la couleur d'un pion <_couleur>
void InitialiserCouleurCite(Cite* _cite,uint8_t _couleur);      //Initialiser la couleur d'une cité <_couleur>
void InitialiserCoordonneesPion(Pions* _pion);                  //Initialiser les coordonnes d'un pion a x=-1 y=-1
void InitialiserCoordonneesCite(Cite* _cite);                   //Initialiser les coordonnes d'une cité a x=-1 y=-1
void InitialiserNiveauCite(Cite* _cite);                        //Initialiser le niveau d'une cité à 0
void InitialiserPions(Pions *_pion,uint8_t _couleur);           //Initialiser un pion entierement
void InitialiserCite(Cite *_cite,uint8_t _couleur);             //Initialiser une cité entierement
//int* CreePion();PAS ID plus tars fichier bin !!!!!

void AfficherCouleurCite(Cite _cite);           //Afficher Couleur dune cité
void AfficherCouleurPion(Pions _pion);          //Afficher Couleur d'un Pion
void AfficherIDCite(Cite _cite);                //Afficher id_cite d'une cité
void AfficherIDPion(Pions _pion);               //Afficher id_pion d'un Pion
void AfficherCoordonneesPion(Pions _pion);      //Afficher les coordonnees d'un Pion
void AfficherCoordonneesCite(Cite _cite);       //Afficher les coordonnees d'une Cite

int DeplacerPionDroite(Pions* p);               //Déplacer pion a Droite
int DeplacerPionGauche(Pions* p);               //Déplacer pion a Gauche
int DeplacerPionHautDroite(Pions* p);           //Déplacer pion en Haut a Droite
int DeplacerPionHautGauche(Pions* p);           //Déplacer pion en Haut a Gauche
int DeplacerPionBasDroite(Pions* p);            //Déplacer pion en Bas a Droite
int DeplacerPionBasGauche(Pions* p);            //Déplacer pion en Bas a Gauche
int PlacerPionSurMap(Pions* _pion,int _x,int _y);//placer Pion du stuff du joueur sur la map au coordoner x,y (22YERROR & 2 XERROR & 11Pion_not_in_stuff)
int PlacerCiteSurMap(Cite* _cite,int _x,int _y);//plcer Citer du stuff du joueur sur la map au coordoner x,y (22YERROR & 2 XERROR & 11Cite_not_in_stuff)

void ChangerCouleurCite(Cite* _cite, uint8_t _couleur); //Changer la couleur d'une Cite par celle du joueur
void AugmenterNiveauCite(Cite* _Cite);                  //Pour Indenter le niveux d'une Cite

#endif
