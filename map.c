#include <map.h>

//Fait par Rémi 
//LE 17/03/2022
//
//Modif par Dylan Perinetti
//Signer par YEP + map.h
//LE 17/03/2022

#include "map.h"
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
    Fond_ocean.x = 0;
    Fond_ocean.y = 0;
    Fond_ocean.w = TAILLE_FENETRE;
    Fond_ocean.h = TAILLE_FENETRE;
    
    SDL_Rect Hexagone;                    
    Hexagone.x = (TAILLE_FENETRE-624)/2;
    Hexagone.y = 100;
    Hexagone.w = 104;
    Hexagone.h = 120;


    
    //-----------------------------------Test et Initialisation de SDL--------------------------------//
   
    SDL_version nb;
    SDL_VERSION(&nb);
    printf("Votre version est %d.%d.%d\n", nb.major, nb.minor, nb.patch);   
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Erreur(1);
    }
    
    //-----------------------------------Création de la fenetre et du rendu--------------------------------//
    
    SDL_CreateWindowAndRenderer(TAILLE_FENETRE, TAILLE_FENETRE, 0, &fenetre, &rendu);
    
    
    //--------------------Création et Application de la Texture du fond océan-----------------------------//
    
    image = SDL_LoadBMP("src/Img/Case/Sea.bmp");                         
    tex_ocean = SDL_CreateTextureFromSurface(rendu, image);             
    if (tex_ocean == NULL)
    {
        Erreur(2);
    }

    SDL_FreeSurface(image);                                      
    
    if (SDL_QueryTexture(tex_ocean, NULL, NULL, &Fond_ocean.w, &Fond_ocean.h) != 0)     
    {                                                                                   
        Erreur(3);
    }
    if (SDL_RenderCopy(rendu, tex_ocean, NULL, &Fond_ocean) != 0)                       
    {
        Erreur(4);
    }
    SDL_RenderPresent(rendu);                                   

    



    //-----------------------------------Génération Random Partie Haute--------------------------------//
    

    for(j=6;j<10;j++)
    {
        for(i=0;i<j;i++)
        {                       
            char terrain = Aleatoire();                        
            TextureSurRendu(terrain, rendu, &Hexagone);                                          
            DecallageHexagoneX(&Hexagone);

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
        char terrain = Aleatoire();                        
        TextureSurRendu(terrain, rendu, &Hexagone);                                  
        DecallageHexagoneX(&Hexagone);
        
        carte[i][4]=terrain-48;
    }
    d--;
    DecallageHexagoneY(&Hexagone, d);
    

    //-----------------------------------Génération Random Partie Basse--------------------------------//
    
    for(j=9;j>5;j--)
    {
        for(i=0;i<j;i++)
        {
            char terrain = Aleatoire();                        
            TextureSurRendu(terrain, rendu, &Hexagone);                                         
            DecallageHexagoneX(&Hexagone);
            
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
    
    DeplacePionMap(0,3,3,6,6,1,1,0,rendu,&Hexagone);
    DeplacePionMap(1,2,3,5,6,1,1,0,rendu,&Hexagone);
    DeplacePionMap(2,8,3,2,6,1,1,0,rendu,&Hexagone);
    DeplacePionMap(3,7,7,1,2,1,1,0,rendu,&Hexagone);
    SDL_Delay(2000);
    DeplacePionMap(2,4,3,7,2,0,1,0,rendu,&Hexagone);
    SDL_Delay(5000);
    SDL_DestroyTexture(tex_ocean);                                               
    SDL_DestroyTexture(tex_case);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}


//-----------------------------------Sous-Programmes--------------------------------------------------//
    

char Aleatoire()
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

void DeplacePionMap(int joueur, int departx, int departy, int arriveex, int arriveey, int nombre_pions_depart, int nombre_pions_arrivee, int case_depart, SDL_Renderer* rendu, SDL_Rect *Hex)
{
    SDL_Surface *image = NULL;
    SDL_Texture *tex_pion = NULL;
    SDL_Rect Pion;
    char pion_type[] = "src/Img/Pions/Pion9_9.bmp";
    printf("%s\n",pion_type);
    Pion.x = 88 + arriveex*UNITE_X + (104/2) - (DIM_PION/2);                                      
    Pion.y = 100 + arriveey*UNITE_Y + (120/2) - (DIM_PION/2);
    Pion.w = DIM_PION;
    Pion.h = DIM_PION;

    if (arriveey%2!=0)                                                                
    {
        Pion.x = Pion.x+50;                                              
    }


    pion_type[18] = joueur+48;
    pion_type[20] = nombre_pions_arrivee+48;
    printf("%s\n",pion_type);
    image = SDL_LoadBMP(pion_type);
    
    SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    

        tex_pion = SDL_CreateTextureFromSurface(rendu, image);                    
        if (tex_pion == NULL)
        {
            Erreur(2);
        }
        SDL_FreeSurface(image);
        if (SDL_QueryTexture(tex_pion, NULL, NULL, &Pion.w, &Pion.h) != 0)  
        {
            Erreur(3);
        }
        if (SDL_RenderCopy(rendu, tex_pion, NULL, &Pion) != 0)           
        {
            Erreur(4);
        }
        SDL_RenderPresent(rendu);


//------------------------------------------------/Reset de la texture d'origine/-------------------------------------------//

    
    Pion.x = 88 + departx*UNITE_X + (104/2) - (DIM_PION/2);                                      
    Pion.y = 100 + departy*UNITE_Y + (120/2) - (DIM_PION/2);
    
    if (departy%2!=0)                                                                
    {
        Pion.x = Pion.x+50;                                              
    }

    if(nombre_pions_depart==0)
    {
        Hex->x = 88 + departx*UNITE_X*2;
        
        if (departy%2!=0)                                                                
        {
            Hex->x = Hex->x+50;                                              
        }
        
        Hex->y = 100 + departy*UNITE_Y-3;
        
        printf("\n%d\n",IntEnChar(case_depart));
        TextureSurRendu(IntEnChar(case_depart), rendu, Hex);
    }
    else 

    {
        pion_type[20] = nombre_pions_depart+48;

        SDL_LoadBMP(pion_type);

         SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    

        tex_pion = SDL_CreateTextureFromSurface(rendu, image);                    
        if (tex_pion == NULL)
        {
            Erreur(2);
        }
        SDL_FreeSurface(image);
        if (SDL_QueryTexture(tex_pion, NULL, NULL, &Pion.w, &Pion.h) != 0)  
        {
            Erreur(3);
        }
        if (SDL_RenderCopy(rendu, tex_pion, NULL, &Pion) != 0)           
        {
            Erreur(4);
        }
        SDL_RenderPresent(rendu);
    }

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

//--------------------------------------------/Generation de la Texture et Application sur le Rendu/---------------------//

void TextureSurRendu(char terrain, SDL_Renderer* rendu, SDL_Rect *Hex)
{
    SDL_Texture *tex_case = NULL;
    SDL_Surface *image = NULL;

    char fichier_terrain[]="src/Img/Case/Case_9_Dim.bmp";
    fichier_terrain[18] = terrain;
    
    image = SDL_LoadBMP(fichier_terrain);
            
    SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));     

    tex_case = SDL_CreateTextureFromSurface(rendu, image);                    
    if (tex_case == NULL)
        {
            Erreur(2);
        }
    SDL_FreeSurface(image);
    if (SDL_QueryTexture(tex_case, NULL, NULL, &Hex->w, &Hex->h) != 0)     
        {
            Erreur(3);
        }
    if (SDL_RenderCopy(rendu, tex_case, NULL, Hex) != 0)          
        {
            Erreur(4);
        }
    SDL_RenderPresent(rendu);                                            
}

char IntEnChar(int Entier)
{
    return (char) Entier+48;
}

// gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2                 

