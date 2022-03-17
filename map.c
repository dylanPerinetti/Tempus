#include <map.h>

//Fait par Rémi 
//LE 17/03/2022
//
//Modif par Dylan Perinetti
//Signer par YEP + map.h
//LE 17/03/2022

#define TAILLE_FENETRE 1200
#define TEMPS_FENETRE 1000          //YEP
#define X_MIN 0
#define X_MAX 10
#define Y_MIN 0
#define Y_MAX 10

int main(int argc, char* argv[])
{
    srand(time(NULL));
    SDL_Window* fenetre = NULL;  //initialisation de toutes le fenetres/rendus/textures
    SDL_Renderer* rendu = NULL;
    SDL_Surface* image = NULL;
    SDL_Texture* tex_case = NULL;
    SDL_Texture* tex_ocean = NULL;
    uint8_t i=0;                    //YEP
    uint8_t j=0;                    //YEP
    int d=0;
    int carte[10][10];                 //Carte pour le programme
    for(j = Y_MIN; j < Y_MAX; j++)  //YEP
    {
        for(i = X_MIN; i < X_MAX; i++)//YEP
        {
            carte[i][j]=7;             //Remplit la carte d'espaces vides (7)
        }
    }            

    
   
    SDL_Rect Fond_ocean;  //Definition du rectangle pour le fond océan
    Fond_ocean.x = 0;
    Fond_ocean.y = 0;
    Fond_ocean.w = TAILLE_FENETRE;
    Fond_ocean.h = TAILLE_FENETRE;
    
    SDL_Rect Hexagone;   //Definition du rectangle pour stocker texture de l'hexagone
    Hexagone.x = (TAILLE_FENETRE-624)/2;
    Hexagone.y = 100;
    Hexagone.w = 100;
    Hexagone.h = 100;
    
    //-----------------------------------Test et Initialisation de SDL--------------------------------//
   
    SDL_version nb;
    SDL_VERSION(&nb);
    printf("Votre version est %d.%d.%d\n", nb.major, nb.minor, nb.patch);   
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Erreur(1);
        exit(EXIT_FAILURE);
    }
    
    //-----------------------------------Création de la fenetre et du rendu--------------------------------//
    
    SDL_CreateWindowAndRenderer(TAILLE_FENETRE, TAILLE_FENETRE, 0, &fenetre, &rendu);
    
    //-----------------------------------Création et Application de la Texture du fond océan--------------------------------//
    
    image = SDL_LoadBMP("src/Sea.bmp");                         //Donne temporairement a image le chemin vers Sea.cmp
    tex_ocean = SDL_CreateTextureFromSurface(rendu, image);     //Crée une texture a partir de Sea.cmp
    if (tex_ocean == NULL)Erreur(8);                            //YEP

    SDL_FreeSurface(image);                                      //Libère la Variable image pour plus tard
    if (SDL_QueryTexture(tex_ocean, NULL, NULL, &Fond_ocean.w, &Fond_ocean.h) != 0) Erreur(6);//YEP     //Donne la texture a la forme
    if (SDL_RenderCopy(rendu, tex_ocean, NULL, &Fond_ocean) != 0)Erreur(7);//YEP                       //Met le fond océan dans le rendu
    SDL_RenderPresent(rendu);                                    //Applique les modifications au rendu

    



    //-----------------------------------Génération Random Partie Haute--------------------------------//
    

    for(j = 6; j < X_MAX; j++)  //YEP
    {
        for(i = 0; i < j; i++)
        {
            ImageAleatoir(&image);  //YEP   Pas SUR que sa marche 
            SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    

            //Rogne le blanc autour des hexagones stockés dans image
            
            if (d%2==0)carte[i+2-(d/2)][d]=terrain; //YEP                                  //Remplissage Carte (un peu mystique)
            else if (d==1)carte[i+1][d]=terrain;    //YEP
            else carte[i][d]=terrain;               //YEP
            
            tex_case = SDL_CreateTextureFromSurface(rendu, image);Erreur(6);//YEP
            SDL_FreeSurface(image);
            if (SDL_QueryTexture(tex_case, NULL, NULL, &Hexagone.w, &Hexagone.h) != 0)Erreur(7);     //Donne la texture a la forme Hexagone
            if (SDL_RenderCopy(rendu, tex_case, NULL, &Hexagone) != 0)Erreur(8);          //Met la forme Hexagone dans le rendu
            
            SDL_RenderPresent(rendu);                                             //Applique les modification au rendu
            Hexagone.x = Hexagone.x + 102;
        }
    d++;                                                                          
    Hexagone.y = Hexagone.y + 88;                                                 //Se décale en fonction de la ligne
    Hexagone.x = (TAILLE_FENETRE-624)/2-(50*d);
    }

    //-----------------------------------Génération Random Milieu--------------------------------//
    
    for(i=0;i<X_MAX;i++)        //YEP
    {
        ImageAleatoir(&image);  //YEP   Pas SUR que sa marche                                     
        SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    
        carte[i][4]=terrain;
    
        tex_case = SDL_CreateTextureFromSurface(rendu, image);                    
        if (tex_case == NULL)
            Erreur(6);//YEP
        SDL_FreeSurface(image);
        if (SDL_QueryTexture(tex_case, NULL, NULL, &Hexagone.w, &Hexagone.h) != 0)  
        {
            Erreur(7);
        }
        if (SDL_RenderCopy(rendu, tex_case, NULL, &Hexagone) != 0)           
        {
            Erreur(8);
        }
        SDL_RenderPresent(rendu);                                             
        Hexagone.x = Hexagone.x + 102;
    }
    d--;
    Hexagone.y = Hexagone.y + 88;
    Hexagone.x = (TAILLE_FENETRE-624)/2-(50*d);
    

    //-----------------------------------Génération Random Partie Basse--------------------------------//
    
    for(j = X_MAX-1; j > X_MAX/2; j--)  //YEP
    {
        for(i = 0; i < j; i++)          //YEP
        {
            ImageAleatoir(&image);      //YEP   Pas SUR que sa marche 
            SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    

            if (d==3)carte[i][8-d]=terrain;         //YEP
            else if (d==2)carte[i+1][8-d]=terrain;  //YEP
            else if (d==1)carte[i+1][8-d]=terrain;  //YEP
            else if (d==0)carte[i+2][8-d]=terrain;  //YEP

            tex_case = SDL_CreateTextureFromSurface(rendu, image);                     
            if (tex_case == NULL)Erreur(6);         //YEP
            SDL_FreeSurface(image);
            if (SDL_QueryTexture(tex_case, NULL, NULL, &Hexagone.w, &Hexagone.h) != 0)Erreur(7);//YEP
            if (SDL_RenderCopy(rendu, tex_case, NULL, &Hexagone) != 0)Erreur(8);//YEP
            SDL_RenderPresent(rendu);                                             
            Hexagone.x = Hexagone.x + 102;
        }
    d--;
    Hexagone.y = Hexagone.y + 88;                                                 
    Hexagone.x = (TAILLE_FENETRE-624)/2-(50*d);
    }


//-----------------------------------Imprime la carte--------------------------------//


for(j = Y_MIN; j < Y_MAX; j++)          //YEP
    {
        for(i = X_MIN; i < X_MAX; i++)  //YEP
        {
            printf("%d ",carte[i][j]);            
        }
    printf("\n");
    }    


//-----------------------------------Delai et Detruit les objets ensuite--------------------------------//
    
    SDL_Delay(TEMPS_FENETRE);       //YEP

    SDL_DestroyTexture(tex_ocean);                                               
    SDL_DestroyTexture(tex_case);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    
    return 0;
}


//-----------------------------------Sous-Programmes--------------------------------//


void ImageAleatoir(SDL_Surface* image)  //YEP
{
    int terrain = Aleatoir();           //YEP      //Donne une valeur random entre 0 et 4 a terrain
    switch(terrain)
        {
            case 0 : *image = SDL_LoadBMP("src/Case_Champ_Dim.bmp"); break;     //YEP     
            case 1 : *image = SDL_LoadBMP("src/Case_Foret_Dim.bmp"); break;     //YEP
            case 2 : *image = SDL_LoadBMP("src/Case_Prairie_Dim.bmp"); break;   //YEP    //En fonction de la valeur de terrain,
            case 3 : *image = SDL_LoadBMP("src/Case_Montagne_Dim.bmp"); break;  //YEP   //donne un dossier bmp différent a image
            case 4 : *image = SDL_LoadBMP("src/Case_Colline_Dim.bmp"); break;   //YEP
        }
}
    
int Aleatoir()          //YEP  (CAR TOUTES ES EN FRANÇAIS )
    {
        int random = rand()%5;
        return random;
    }

void Erreur(int error)  //YEP
{
    printf("Erreur %d, %s\n", error, SDL_GetError());
}
