#ifndef __OBJET_H__
#define __OBJET_H__
/*-------------------- Pions ------------------------*/

typedef struct Pions
{       
        uint8_t id_pion;        // uint8_t sigifie un nb entier non signer sur 1 Octer contre 4 Octer pour un simple int 
        uint8_t couleur;        //Car la couleur est un Héritage du joueur 
        int Coordx;             //tableux ?
        int Coordy;             //tableux ?
}Pions;


/*-------------------- CITE -------------------------*/

typedef struct Cite
{
        uint8_t id_cite;       //identification de la piece
        uint8_t couleur;        //Car la couleur est un Héritage du joueur 
        int Coordx;             //tableux ?
        int Coordy;             //tableux ?
        uint8_t niveaux_cite;
}Cite;

#endif
