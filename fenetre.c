/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez à la fenetre dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "fenetre.h".

Fait par MrTNTX le 15/03/2022
Dernière modifications par dylanPerinetti le 22/03/2022

*/
#include "fenetre.h"

#define TAILLE_FENETRE 1200
#define UNITE_X 102
#define UNITE_Y 88
#define DIM_PION 40
#define PRCT_PRAIRIE 40
#define PRCT_MONTAGNE 20
#define PRCT_FORET 10
#define PRCT_COLLINE 10
#define PRCT_CHAMP 10
#define PRCT_LAC 10

//---------------------------------Rémi 16/03/2022-------------------------------//



int GeneMap()
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
    int carte[10][10];                 
    for(j=0;j<10;j++)
    {
        for(i=0;i<10;i++)
        {
            carte[i][j]=7;             
        }
    }

    SDL_Rect Fond_ocean; 
    SDL_Rect Hexagone; 

    InitialiseRect(&Fond_ocean, 0, 0, TAILLE_FENETRE, TAILLE_FENETRE);
    InitialiseRect(&Hexagone, (TAILLE_FENETRE-624)/2, 100, 104, 120);
    
    //-----------------------------------Test et Initialisation de SDL--------------------------------//
    AfficherVersionSDL();   /*Je l'ai cree car elle n'est pas tres utile /?\ je crois /?\.*/
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

    //-----------------------------------Génération Random Partie Haute--------------------------------//
    

    for(j=6;j<10;j++)
    {
        for(i=0;i<j;i++)
        {
            char terrain = InitialiseHexagone(rendu, &Hexagone);                       
            /*
                // AVANTS LA FONCTION : InitialiseHexagone()

            char terrain = Aleatoire();                        
            GenerationHexagone(terrain, rendu, &Hexagone);                                  
            DecallageHexagoneX(&Hexagone);
            */
            if (d==3){carte[i][d]=terrain-48;}
            else if (d==2){carte[i+1][d]=terrain-48;}
            else if (d==1){carte[i+1][d]=terrain-48;}                                  
            else if (d==0){carte[i+2][d]=terrain-48;}
        }
        d++;                                                                          
        DecallageHexagoneY(&Hexagone,d);
    }

    //-----------------------------------Génération Random Milieu--------------------------------//
    for(i=0;i<10;i++)
    {
        char terrain = InitialiseHexagone(rendu, &Hexagone); 
        carte[i][4]=terrain-48;
    }
    d--;
    DecallageHexagoneY(&Hexagone, d);
    

    //-----------------------------------Génération Random Partie Basse--------------------------------//
    for(j=9;j>5;j--)
    {
        for(i=0;i<j;i++)
        {
            char terrain = InitialiseHexagone(rendu, &Hexagone);
            if (d==3){carte[i][8-d]=terrain-48;}
            else if (d==2){carte[i+1][8-d]=terrain-48;}
            else if (d==1){carte[i+1][8-d]=terrain-48;}
            else if (d==0){carte[i+2][8-d]=terrain-48;}
        }
        d--;
        DecallageHexagoneY(&Hexagone, d);
    }

    //-----------------------------------Imprime la carte-------------------------------------------------//
    for(j=0;j<10;j++)
        {
            for(i=0;i<10;i++)
            {
                printf("%d ",carte[i][j]);            
            }
        printf("\n");
        }    


    //-----------------------------------Delai et Detruit les objets ensuite--------------------------------//
    
    NouvelleCite(0,5,5,2,rendu,&Hexagone);
    SDL_Delay(5000);
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

//-----------------------------------Sous-Programmes--------------------------------------------------//
    

char CharactereAleatoire()        // pourquoi tu retourn-tu des pointeur ?? 
{
    int random = rand()%101;
    if (random<PRCT_PRAIRIE){return *"0";}
    else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE){return *"1";}  
    else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET){return *"2";}  
    else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET+PRCT_COLLINE){return *"3";} 
    else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET+PRCT_COLLINE+PRCT_CHAMP){return *"4";} 
    else {return *"5";}
}


void Erreur(int error)
{
    printf("\nErreur %d, %s\n", error, SDL_GetError());
    exit(EXIT_FAILURE);
}

//---------------------------------/Placement d'un pion/--------------------------------------------//
void DeplacePionMap(Pions* _pion, int departx, int departy, int nombre_pions_depart, int nombre_pions_arrivee, int carte[10][10], SDL_Renderer* rendu, SDL_Rect *Hex)
{
    SDL_Surface *image = NULL;
    SDL_Texture *tex_pion = NULL;
    SDL_Rect Pion;
    char pion_type[] = "src/Img/Pions/Pion9_9.bmp";
    Pion.x = 88 + (_pion->coordonnees.X)*UNITE_X + (104/2) - (DIM_PION/2);                                      
    Pion.y = 100 + (_pion->coordonnees.Y)*UNITE_Y + (120/2) - (DIM_PION/2);
    Pion.w = DIM_PION;
    Pion.h = DIM_PION;

    if (_pion->coordonnees.Y%2!=0)Pion.x = Pion.x+46;

    pion_type[18] = _pion->couleur;// erreur unsign char possiblement à coriger
    pion_type[20] = IntEnChar(nombre_pions_arrivee);
    image = SDL_LoadBMP(pion_type);
    
    TextureRendu(image, tex_pion, rendu, &Pion); 


//------------------------------------------------/Reset de la texture d'origine/-------------------------------------------//

    
    Pion.x = 88 + departx*UNITE_X + (104/2) - (DIM_PION/2);                                      
    Pion.y = 100 + departy*UNITE_Y + (120/2) - (DIM_PION/2);
    
    if (departy%2!=0)Pion.x = Pion.x+50;

    if(nombre_pions_depart==0)
    {
        Hex->x = 88 + departx*UNITE_X;
        
        if (departy%2!=0)Hex->x = Hex->x+50;

        Hex->y = 100 + departy*UNITE_Y-3;

        int case_depart = carte[departx][departy];
        
        GenerationHexagone(IntEnChar(case_depart), rendu, Hex);
    }
    else 

    {
        pion_type[20] = nombre_pions_depart+48;

        image = SDL_LoadBMP(pion_type);

        TextureRendu(image, tex_pion, rendu, &Pion);
    }

}
//--------------------------------/Generation de la Texture d'un Hexagone/---------------------------------//
void GenerationHexagone(char terrain, SDL_Renderer* rendu, SDL_Rect *Hex)
{
    SDL_Texture *tex_case = NULL;
    SDL_Surface *image = NULL;

    char fichier_terrain[]="src/Img/Case/Case_9_Dim.bmp";
    fichier_terrain[18] = terrain;
    
    image = SDL_LoadBMP(fichier_terrain);
            
    TextureRendu(image, tex_case, rendu, Hex);                                            
}

void InitialiseRect(SDL_Rect* _Rectangle, int _x, int _y, int _largeur,int _hauteur)
{
    _Rectangle->x = _x;
    _Rectangle->y = _y;
    _Rectangle->w = _largeur;
    _Rectangle->h = _hauteur;
}



char InitialiseHexagone(SDL_Renderer* _rendu, SDL_Rect *_Hexagone)
{
    int _terrain = CharactereAleatoire();
    GenerationHexagone(_terrain, _rendu, _Hexagone);                                          
    DecallageHexagoneX(_Hexagone);
    return _terrain;
}

//--------------------------------------------/Decallage Nouvel hexagon/--------------------------------------------------//

void DecallageHexagoneX(SDL_Rect *Hex)
{
    Hex->x = Hex->x + UNITE_X;
}


//--------------------------------------------/Decallage Nouvelle ligne/--------------------------------------------------//

void DecallageHexagoneY(SDL_Rect *Hex, int d)
{
    Hex->y = Hex->y + UNITE_Y;
    Hex->x = (TAILLE_FENETRE-624)/2-(50*d);
}

char IntEnChar(int Entier)
{
    return (char) Entier+48;
}

//--------------------------------------------/Generation ou Prise d'une Cité/---------------------------------------------//

void NouvelleCite(int joueur, int coordx, int coordy, int taille, SDL_Renderer* rendu, SDL_Rect *Hex)
{
    SDL_Texture *tex_case = NULL;
    SDL_Surface *image = NULL;

    Hex->x = 88 + coordx*UNITE_X;
        
        if (coordy%2!=0)                                                                
        {
            Hex->x = Hex->x+50;                                              
        }
        
    Hex->y = 100 + coordy*UNITE_Y-3;

    char cite_type[] = "src/Img/Cite/Cite_9_9.bmp";
    cite_type[18]=IntEnChar(joueur);
    cite_type[20]=IntEnChar(taille);

    image = SDL_LoadBMP(cite_type);
    
   TextureRendu(image, tex_case, rendu, Hex);     
}

//---------------------------------------/Traitement de l'image et application sur le rendu/------------------------------//


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


void AfficherVersionSDL()
{
    SDL_version nb;
    SDL_VERSION(&nb);
    printf("Votre version de SDL est %d.%d.%d\n", nb.major, nb.minor, nb.patch);
}



