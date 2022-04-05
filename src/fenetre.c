/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez à la fenetre dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "fenetre.h".

Fait par MrTNTX le 15/03/2022
Dernière modifications par dylanPerinetti le 24/03/2022

*/
#include "fenetre.h"

#define LARGEUR_FENETRE 1400
#define HAUTEUR_FENETRE 900
#define UNITE_X 104
#define UNITE_Y 120
#define DEPART_X 100
#define DEPART_Y 50


#define DIM_PION 40

//---------------------------------Rémi 03/04/2022-------------------------------//



int AfficherFenetre(Tuile _map[10][10])
{
    srand(time(NULL));
    SDL_Window *fenetre = NULL;  
    SDL_Renderer *rendu = NULL;
    SDL_bool programme_lance = SDL_TRUE;

    int i=0;
    int j=0;
    
    AfficherVersionSDL(); 
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)Erreur(1);
    SDL_CreateWindowAndRenderer(LARGEUR_FENETRE, HAUTEUR_FENETRE, 0, &fenetre, &rendu);
    GenerationOcean(rendu);

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            MajCase(_map, i, j, rendu);
        }
    }

    while(programme_lance)
    {
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_KEYDOWN: 
            switch(event.key.keysym.sym)
            {
                case SDLK_DOWN: CurseurBas(_map, rendu); continue;
                case SDLK_UP: CurseurHaut(_map, rendu); continue;
                case SDLK_RIGHT: CurseurDroite(_map, rendu); continue;
                case SDLK_LEFT: CurseurGauche(_map, rendu); continue;

                default : continue;
            }

            case SDL_QUIT: programme_lance = SDL_FALSE; break;
            default : break;
        }
    }
} 
    
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

void MajCase(Tuile _map[10][10], int i, int j, SDL_Renderer* _rendu)
{
    SDL_Rect Hexagone;
    SDL_Rect Pion;
    
    unsigned char type=_map[i][j].type_terrain;
    unsigned char nombre=_map[i][j].nombre_pion;
    unsigned char couleur='1';                                          //Temporaire le temps de regler le probleme des pions
    unsigned char taille='1';
    int curseur=_map[i][j].curseur;                                      //Temporaire aussi le temps de régler ville

    int coordgraphx=DEPART_X+(UNITE_X*i);
    int coordgraphy=DEPART_Y+(88*j);                                    //88 pcq je l'avais calculé ya longtemps
    if(j%2!=0)
    {
        coordgraphx=coordgraphx+(UNITE_X/2);
    }
    InitialiseRect(&Hexagone, coordgraphx , coordgraphy, UNITE_X, UNITE_Y);
    GenerationHexagone(type, _rendu, &Hexagone);
    GenerationVille(taille, couleur, _rendu, &Hexagone);
    GenerationCurseur(curseur, _rendu, &Hexagone);
    
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


void GenerationOcean(SDL_Renderer* _rendu)
{
    SDL_Texture *tex_ocean = NULL;
    SDL_Surface *image = NULL;
    SDL_Rect Fond_ocean; 
    InitialiseRect(&Fond_ocean, 0, 0, LARGEUR_FENETRE, HAUTEUR_FENETRE);
    image = SDL_LoadBMP("src/Img/Case/Sea.bmp");                  
    tex_ocean = SDL_CreateTextureFromSurface(_rendu, image);
    if (tex_ocean == NULL)Erreur(2);

    SDL_FreeSurface(image);

    if (SDL_QueryTexture(tex_ocean, NULL, NULL, &Fond_ocean.w, &Fond_ocean.h) != 0)Erreur(3);
    if (SDL_RenderCopy(_rendu, tex_ocean, NULL, &Fond_ocean) != 0)Erreur(4);

    SDL_RenderPresent(_rendu);
}

void GenerationHexagone(unsigned char terrain, SDL_Renderer* _rendu, SDL_Rect *Hex)
{
    SDL_Texture *tex_case = NULL;
    SDL_Surface *image = NULL;

    char fichier_terrain[]="src/Img/Case/Case_9_Dim.bmp";
    fichier_terrain[18] = terrain;
    
    image = SDL_LoadBMP(fichier_terrain);
            
    TextureRendu(image, tex_case, _rendu, Hex);
    SDL_DestroyTexture(tex_case);                                            
}

void GenerationVille(unsigned char _taille, unsigned char _couleur, SDL_Renderer* _rendu, SDL_Rect *Hex)
{
    SDL_Texture *tex_ville = NULL;
    SDL_Surface *image = NULL;

    char fichier_ville[]="src/Img/Cite/Cite9_9.bmp";
    fichier_ville[17] = _couleur;
    fichier_ville[19] = _taille;    
    
    image = SDL_LoadBMP(fichier_ville);
    TextureRendu(image, tex_ville, _rendu, Hex); 
    SDL_DestroyTexture(tex_ville);
}

void GenerationPion(unsigned char _nombre, unsigned char _couleur, SDL_Renderer* _rendu, SDL_Rect *Hex)
{
    SDL_Texture *tex_case = NULL;
    SDL_Surface *image = NULL;

    char fichier_pion[]="src/Img/Pion/Pion9_9.bmp";
    fichier_pion[17] = _couleur;
    fichier_pion[19] = _nombre;    
    image = SDL_LoadBMP(fichier_pion);
    TextureRendu(image, tex_case, _rendu, Hex);  
    SDL_DestroyTexture(tex_case);                           
}

void GenerationCurseur(int _curseur, SDL_Renderer* _rendu, SDL_Rect *Hex)
{
    SDL_Texture *tex_curseur = NULL;
    SDL_Surface *image = NULL;

    if(_curseur==1)
    {
        char fichier_curseur[]="src/Img/Curseur/Curs.bmp";
        image = SDL_LoadBMP(fichier_curseur);
        TextureRendu(image, tex_curseur, _rendu, Hex); 
    }
    
    SDL_DestroyTexture(tex_curseur);
}

void TextureRendu(SDL_Surface* _image, SDL_Texture* _texture, SDL_Renderer* _rendu, SDL_Rect *Hex)
{
    SDL_SetColorKey(_image, SDL_TRUE, SDL_MapRGB(_image->format, 255, 255, 255));    

        _texture = SDL_CreateTextureFromSurface(_rendu, _image);                    
        if (_texture == NULL)Erreur(2);

        SDL_FreeSurface(_image);

        if (SDL_QueryTexture(_texture, NULL, NULL, &Hex->w, &Hex->h) != 0)Erreur(3);
        if (SDL_RenderCopy(_rendu, _texture, NULL, Hex) != 0)Erreur(4);

        SDL_RenderPresent(_rendu);
}


