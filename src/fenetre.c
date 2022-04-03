/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez à la fenetre dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "fenetre.h".

Fait par MrTNTX le 15/03/2022
Dernière modifications par dylanPerinetti le 24/03/2022

*/
#include "fenetre.h"

#define TAILLE_FENETRE 1200
#define UNITE_X 104
#define UNITE_Y 120
#define DEPART_X 100
#define DEPART_Y 100


#define DIM_PION 40

//---------------------------------Rémi 16/03/2022-------------------------------//



int AfficherFenetre(Tuile _map[10][10])
{
    srand(time(NULL));
    SDL_Window *fenetre = NULL;  
    SDL_Renderer *rendu = NULL;
    SDL_Texture *tex_ocean = NULL;
    SDL_Surface *image = NULL;
    SDL_Texture *tex_case = NULL;
    SDL_bool programme_lance = SDL_TRUE;

    int i=0;
    int j=0;
    int d=0;

    SDL_Rect Fond_ocean; 

    InitialiseRect(&Fond_ocean, 0, 0, TAILLE_FENETRE, TAILLE_FENETRE);
    
    //-----------------------------------Test et Initialisation de SDL--------------------------------//
    AfficherVersionSDL(); 
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)Erreur(1);
    
    //-----------------------------------Création de la fenetre et du rendu--------------------------------//
    SDL_CreateWindowAndRenderer(TAILLE_FENETRE, TAILLE_FENETRE, 0, &fenetre, &rendu);
    
    //--------------------Création et Application de la Texture du fond océan-----------------------------//
    
    image = SDL_LoadBMP("src/Img/Case/Sea.bmp");                  
    tex_ocean = SDL_CreateTextureFromSurface(rendu, image);
    if (tex_ocean == NULL)Erreur(2);

    SDL_FreeSurface(image);

    if (SDL_QueryTexture(tex_ocean, NULL, NULL, &Fond_ocean.w, &Fond_ocean.h) != 0)Erreur(3);
    if (SDL_RenderCopy(rendu, tex_ocean, NULL, &Fond_ocean) != 0)Erreur(4);

    SDL_RenderPresent(rendu);                                   

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            RefreshCase(_map, i, j, rendu);
        }
    }


    //-----------------------------------Delai et Detruit les objets ensuite--------------------------------//

    while(programme_lance)
    {
    SDL_Event event;
    while(SDL_PollEvent(&event))
        switch(event.type)
        {
            case SDL_QUIT: programme_lance = SDL_FALSE; break;
            default : break;
        }
    } 
    
    SDL_DestroyTexture(tex_ocean);                                               
    SDL_DestroyTexture(tex_case);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}
    


void AfficherVersionSDL()
{
    SDL_version nb;
    SDL_VERSION(&nb);
    printf("Votre version de SDL est %d.%d.%d\n", nb.major, nb.minor, nb.patch);
}

void Erreur(int error)
{
    printf("\nErreur %d, %s\n", error, SDL_GetError());
    exit(EXIT_FAILURE);
}

void RefreshCase(Tuile _map[10][10], int i, int j, SDL_Renderer* _rendu)
{
    SDL_Rect Hexagone;
    SDL_Rect Pion;
    
    unsigned char type=_map[i][j].type_terrain;
    unsigned char nombre=_map[i][j].nombre_pion;
    unsigned char couleur='1';                                          //Temporaire le temps de regler le probleme des pions

    int coordgraphx=DEPART_X+(UNITE_X*i);
    int coordgraphy=DEPART_Y+(88*j);
    if(j%2!=0)
    {
        coordgraphx=coordgraphx+(UNITE_X/2);
    }
    InitialiseRect(&Hexagone, coordgraphx , coordgraphy, UNITE_X, UNITE_Y);
    GenerationHexagone(type, _rendu, &Hexagone);

    coordgraphx=coordgraphx + (UNITE_X/2) - (DIM_PION/2);
    coordgraphy=coordgraphy + (UNITE_Y/2) - (DIM_PION/2);
    InitialiseRect(&Pion, coordgraphx , coordgraphy, DIM_PION, DIM_PION);
    GenerationPion(nombre, couleur, _rendu, &Pion);

}


void InitialiseRect(SDL_Rect* _Rectangle, int _x, int _y, int _largeur,int _hauteur)
{
    _Rectangle->x = _x;
    _Rectangle->y = _y;
    _Rectangle->w = _largeur;
    _Rectangle->h = _hauteur;
}

void GenerationHexagone(unsigned char terrain, SDL_Renderer* rendu, SDL_Rect *Hex)
{
    SDL_Texture *tex_case = NULL;
    SDL_Surface *image = NULL;

    char fichier_terrain[]="src/Img/Case/Case_9_Dim.bmp";
    fichier_terrain[18] = terrain;
    
    image = SDL_LoadBMP(fichier_terrain);
            
    TextureRendu(image, tex_case, rendu, Hex);                                            
}

void GenerationPion(unsigned char pion_nombre, unsigned char pion_couleur, SDL_Renderer* rendu, SDL_Rect *Hex)
{
    SDL_Texture *tex_case = NULL;
    SDL_Surface *image = NULL;

    char fichier_pion[]="src/Img/Pion/Pion9_9.bmp";
    fichier_pion[17] = pion_couleur;
    fichier_pion[19] = pion_nombre;    
    image = SDL_LoadBMP(fichier_pion);
    TextureRendu(image, tex_case, rendu, Hex);                             
}


void TextureRendu(SDL_Surface *image, SDL_Texture *texture, SDL_Renderer* rendu, SDL_Rect *Hex)
{
    SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    

        texture = SDL_CreateTextureFromSurface(rendu, image);                    
        if (texture == NULL)Erreur(2);

        SDL_FreeSurface(image);

        if (SDL_QueryTexture(texture, NULL, NULL, &Hex->w, &Hex->h) != 0)Erreur(3);
        if (SDL_RenderCopy(rendu, texture, NULL, Hex) != 0)Erreur(4);

        SDL_RenderPresent(rendu);
}