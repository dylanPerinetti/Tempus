#ifndef __OBJET_H__
#define __OBJET_H__
/*-------------------- OBJET ------------------------*/
typedef struct Pions
{       
        uint8_t id_pion;                        //uint8_t sigifie un nb entier non signer sur 1 Octer contre 4 Octer pour un simple int 
        uint8_t couleur;                        //Car la couleur est un Héritage du joueur 
        int coord_x;
        int coord_y;
}Pions;                                         //Cree la structure d'un pions
typedef struct Cite
{
        uint8_t id_cite;                        //identification de la piece
        uint8_t couleur;                        //Car la couleur est un Héritage du joueur 
        int coord_x;                            //tableux ?
        int coord_y;                            //tableux ?
        uint8_t niveaux_cite;
}Cite;                                          //Cree la structure d'une Cite

void AfficherCouleurCite(Cite c_);

#endif
