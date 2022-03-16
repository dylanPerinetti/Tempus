#ifndef __MAP__
#define __MAP__
typedef struct CarteTerrain
{
  //uint8_t type_terrain;
  //Salut MrTNTX peut tu me mettre au courrant quand tu vois ce messsage pour 
  //que l'on se mette d'accord sur la structure de terrain et surtout d'une uniter de surface
  //FAIT LE MAR 15 MARS 21:34
#include <stdio.h>
#include <SDL.h>
#include <time.h>
#include <string.h>


//---------------------------------Rémi 16/03/2022-------------------------------//

int Randomizer();
void erreur(int error);

int main(int argc, char* argv[])
{
    srand(time(NULL));
    SDL_Window *fenetre = NULL;  //initialisation de toutes le fenetres/rendus/textures
    SDL_Renderer *rendu = NULL;
    SDL_Surface *image = NULL;
    SDL_Texture *tex_case = NULL;
    SDL_Texture *tex_ocean = NULL;
    int i=0;
    int j=0;
    int carte[9][9];            //Carte pour le programme

    
   
    SDL_Rect Fond_ocean;  //Definition du rectangle pour le fond océan
    Fond_ocean.x = 0;
    Fond_ocean.y = 0;
    Fond_ocean.w = 1024;
    Fond_ocean.h = 1024;
    
    SDL_Rect Hexagone;   //Definition du rectangle pour stocker texture de l'hexagone
    Hexagone.x = 62;
    Hexagone.y = 200;
    Hexagone.w = 100;
    Hexagone.h = 100;
    
    //-----------------------------------Test et Initialisation de SDL--------------------------------//
   
    SDL_version nb;
    SDL_VERSION(&nb);
    printf("Votre version est %d.%d.%d\n", nb.major, nb.minor, nb.patch);   
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        erreur(1);
        exit(EXIT_FAILURE);
    }
    
    //-----------------------------------Création de la fenetre et du rendu--------------------------------//
    
    SDL_CreateWindowAndRenderer(1200, 1200, 0, &fenetre, &rendu);
    
    //-----------------------------------Création et Application de la Texture du fond océan--------------------------------//
    
    image = SDL_LoadBMP("src/Sea.bmp");                          //Donne temporairement a image le chemin vers Sea.cmp
    tex_ocean = SDL_CreateTextureFromSurface(rendu, image);      //Crée une texture a partir de Sea.cmp
    if (tex_ocean == NULL)
    {
        erreur(8);
    }

    SDL_FreeSurface(image);                                      //Libère la Variable image pour plus tard
    
    if (SDL_QueryTexture(tex_ocean, NULL, NULL, &Fond_ocean.w, &Fond_ocean.h) != 0)     //Donne la texture a la forme
    {                                                                                   //Fond_ocean
        erreur(6);
    }
    if (SDL_RenderCopy(rendu, tex_ocean, NULL, &Fond_ocean) != 0)                       //Met le fond océan dans le rendu
    {
        erreur(7);
    }
    SDL_RenderPresent(rendu);                                    //Applique les modifications au rendu

    



    //-----------------------------------Génération Random de la map (à compléter)--------------------------------//
    

    for(j=0;j<7;j++)
    {
        for(i=0;i<9;i++)
        {
            int terrain = Randomizer();                         //Donne une valeur random entre 0 et 4 a terrain
            switch(terrain)
            {
                case 0 : image = SDL_LoadBMP("src/Case_Champ_Dim.bmp"); break;          
                case 1 : image = SDL_LoadBMP("src/Case_Foret_Dim.bmp"); break;
                case 2 : image = SDL_LoadBMP("src/Case_Prairie_Dim.bmp"); break;       //En fonction de la valeur de terrain,
                case 3 : image = SDL_LoadBMP("src/Case_Montagne_Dim.bmp"); break;      //donne un dossier bmp différent a image
                case 4 : image = SDL_LoadBMP("src/Case_Colline_Dim.bmp"); break; 
            }

            carte[i][j] = terrain;                                                     //Stocke la valeur terrain dans la carte 
            SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    

            //Rogne le blanc autour des hexagones stockés dans image
    
            tex_case = SDL_CreateTextureFromSurface(rendu, image);                     //Crée une texture a partir de image
            if (tex_case == NULL)
            {
                erreur(6);
            }
            SDL_FreeSurface(image);
            if (SDL_QueryTexture(tex_case, NULL, NULL, &Hexagone.w, &Hexagone.h) != 0)  //Donne la texture a la forme Hexagone
            {
                erreur(7);
            }
            if (SDL_RenderCopy(rendu, tex_case, NULL, &Hexagone) != 0)            //Met la forme Hexagone dans le rendu
            {
                erreur(8);
            }
            SDL_RenderPresent(rendu);                                             //Applique les modification au rendu
            Hexagone.x = Hexagone.x + 102;
        }

    Hexagone.y = Hexagone.y + 88;                                                 //Se décale en fonction de la ligne
    if(j%2==0) Hexagone.x = 10;
    else Hexagone.x = 62;
    }

    for(j=0;j<7;j++)                                                              //"imprime" la carte dans le terminal
    {
        for (i=0;i<9;i++)
        {
            printf("%d ",carte[i][j]);
        }
        printf("\n");
    }


//-----------------------------------Delai et Detruit les objets ensuite--------------------------------//
    
    SDL_Delay(20000);

    SDL_DestroyTexture(tex_ocean);                                               
    SDL_DestroyTexture(tex_case);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    
    return 0;
}


//-----------------------------------Sous-Programmes--------------------------------//
    
int Randomizer()
    {
        int random = rand()%5;
        return random;
    }

void erreur(int error)
{
    printf("Erreur %d, %s\n", error, SDL_GetError());
}


// gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2



}CarteTerrain;
#endif
