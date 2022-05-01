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
#define HAUTEUR_FENETRE 1100
#define UNITE_X 104
#define UNITE_Y 120
#define DEPART_X 100
#define DEPART_Y 50


#define DIM_PION 40

//---------------------------------Rémi 03/04/2022-------------------------------//



int AfficherFenetre(Tuile _map[10][10], Joueur tableau_joueur[4], SDL_Renderer *_rendu, SDL_Window *_fenetre)
{
    srand(time(NULL));

    int i=0;
    int j=0;
    
    AfficherVersionSDL(); 
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)Erreur(1);
    SDL_CreateWindowAndRenderer(LARGEUR_FENETRE, HAUTEUR_FENETRE, 0, &_fenetre, &_rendu);
    GenerationOcean(_rendu);

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++) MajCase(_map, i, j, _rendu);
    }
    
    MajNiveaux(_rendu, tableau_joueur);

    LancementPartie(_map, tableau_joueur, _rendu, _fenetre);
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
    unsigned char couleur=_map[i][j].couleur;                               
    unsigned char taille=_map[i][j].taille_ville;
    int curseur=_map[i][j].curseur;                                      

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

void MajCartes(SDL_Renderer* _rendu, Carte _carte[7])
{
    GenerationPlateauCartes(_rendu);
    for(int i=0; i<7; i++) GenerationCartes(_rendu, _carte[i], i);
}

void MajNiveaux(SDL_Renderer* _rendu, Joueur _joueur[4])
{
    GenerationTableauNiveau(_rendu);
    for(int i=0; i<4; i++) GenerationNiveauJoueur( _rendu, _joueur[i]);
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

void GenerationPlateauCartes(SDL_Renderer* _rendu)
{
    SDL_Texture *tex_plateau = NULL;
    SDL_Surface *image = NULL;
    
    SDL_Rect Plateau;
    InitialiseRect(&Plateau, LARGEUR_FENETRE/2-600, HAUTEUR_FENETRE-200, 1000, 200);
    image = SDL_LoadBMP("src/Img/Carte/Plateau.bmp"); 
    tex_plateau = SDL_CreateTextureFromSurface(_rendu, image);
    if (tex_plateau == NULL)Erreur(2);

    SDL_FreeSurface(image);

    if (SDL_QueryTexture(tex_plateau, NULL, NULL, &Plateau.w, &Plateau.h) != 0)Erreur(3);
    if (SDL_RenderCopy(_rendu, tex_plateau, NULL, &Plateau) != 0)Erreur(4);

    SDL_RenderPresent(_rendu);
}

void GenerationCartes(SDL_Renderer* _rendu, Carte _carte, int i)
{
    SDL_Texture *tex_carte = NULL;
    SDL_Surface *image = NULL;

    SDL_Rect Carte;
    InitialiseRect(&Carte, LARGEUR_FENETRE/2-525+(125*i), HAUTEUR_FENETRE-175, 100 , 150);
    char fichier_carte[]="src/Img/Carte/Carte_9.bmp";                                        //On implementera les effets plus tard si on a le temps

    fichier_carte[20] = IntEnChar(_carte.couleur);

    image = SDL_LoadBMP(fichier_carte); 
    TextureRendu(image, tex_carte, _rendu, &Carte);
}

void GenerationTableauNiveau(SDL_Renderer* _rendu)
{
    SDL_Texture *tex_tableau = NULL;
    SDL_Surface *image = NULL;
    
    SDL_Rect Tableau;
    InitialiseRect(&Tableau, LARGEUR_FENETRE-200, 0, 200, 1100);
    image = SDL_LoadBMP("src/Img/Niveau/Tableau.bmp"); 
    tex_tableau = SDL_CreateTextureFromSurface(_rendu, image);
    if (tex_tableau == NULL)Erreur(2);

    SDL_FreeSurface(image);

    if (SDL_QueryTexture(tex_tableau, NULL, NULL, &Tableau.w, &Tableau.h) != 0)Erreur(3);
    if (SDL_RenderCopy(_rendu, tex_tableau, NULL, &Tableau) != 0)Erreur(4);

    SDL_RenderPresent(_rendu);
}

void GenerationNiveauJoueur(SDL_Renderer* _rendu, Joueur _joueur)
{
    SDL_Texture *tex_niveau = NULL;
    SDL_Surface *image = NULL;
    
    SDL_Rect Niveau;
    InitialiseRect(&Niveau, LARGEUR_FENETRE-189+46*(_joueur.couleur-1), 100+95*(_joueur.niveau_joueur.niveau), DIM_PION, DIM_PION);
    char fichier_niveau[]="src/Img/Niveau/Niveau_9.bmp";

    fichier_niveau[22] = IntEnChar(_joueur.couleur);
    printf("%s",fichier_niveau);

    image = SDL_LoadBMP(fichier_niveau); 
    
    TextureRendu(image, tex_niveau, _rendu, &Niveau);
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


