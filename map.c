#include <map.h>

//Fait par Rémi 
//LE 17/03/2022
//
//Modif par Dylan Perinetti
//Signer par YEP + map.h
//LE 17/03/2022
#define TAILLE_FENETRE 1200
#define UNITE_X 102
#define UNITE_Y 88
#define DIM_PION 20
#define PRCT_PRAIRIE 40
#define PRCT_MONTAGNE 20
#define PRCT_FORET 10
#define PRCT_COLLINE 10
#define PRCT_CHAMP 10
#define PRCT_LAC 10

//---------------------------------Rémi 16/03/2022-------------------------------//

int Aleatoire();
void Erreur(int error);

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
    int d=0;
    int carte[10][10];                 //Carte pour le programme
    for(j=0;j<10;j++)
    {
        for(i=0;i<10;i++)
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
    
    //-----------------------------------Création et Application de la Texture du fond océan--------------------------------//
    
    image = SDL_LoadBMP("src/Sea.bmp");                          //Donne temporairement a image le chemin vers Sea.cmp
    tex_ocean = SDL_CreateTextureFromSurface(rendu, image);      //Crée une texture a partir de Sea.cmp
    if (tex_ocean == NULL)
    {
        Erreur(8);
    }

    SDL_FreeSurface(image);                                      //Libère la Variable image pour plus tard
    
    if (SDL_QueryTexture(tex_ocean, NULL, NULL, &Fond_ocean.w, &Fond_ocean.h) != 0)     //Donne la texture a la forme
    {                                                                                   //Fond_ocean
        Erreur(6);
    }
    if (SDL_RenderCopy(rendu, tex_ocean, NULL, &Fond_ocean) != 0)                       //Met le fond océan dans le rendu
    {
        Erreur(7);
    }
    SDL_RenderPresent(rendu);                                    //Applique les modifications au rendu

    



    //-----------------------------------Génération Random Partie Haute--------------------------------//
    

    for(j=6;j<10;j++)
    {
        for(i=0;i<j;i++)
        {
            int terrain = Aleatoire();                         //Donne une valeur random entre 0 et 4 a terrain
            switch(terrain)
            {
                case 0 : image = SDL_LoadBMP("src/Case_Prairie_Dim.bmp"); break;          
                case 1 : image = SDL_LoadBMP("src/Case_Montagne_Dim.bmp"); break;
                case 2 : image = SDL_LoadBMP("src/Case_Foret_Dim.bmp"); break;       
                case 3 : image = SDL_LoadBMP("src/Case_Champ_Dim.bmp"); break;      
                case 4 : image = SDL_LoadBMP("src/Case_Colline_Dim.bmp"); break; 
                case 5 : image = SDL_LoadBMP("src/Case_Mer_Dim.bmp"); break; 
                
            }
            
            SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    

            //Rogne le blanc autour des hexagones stockés dans image
            
            if (d==3){carte[i][d]=terrain;}
            else if (d==2){carte[i+1][d]=terrain;}
            else if (d==1){carte[i+1][d]=terrain;}
            else if (d==0){carte[i+2][d]=terrain;}
            
            tex_case = SDL_CreateTextureFromSurface(rendu, image);                     //Crée une texture a partir de image
            if (tex_case == NULL)
            {
                Erreur(6);
            }
            SDL_FreeSurface(image);
            if (SDL_QueryTexture(tex_case, NULL, NULL, &Hexagone.w, &Hexagone.h) != 0)     //Donne la texture a la forme Hexagone
            {
                Erreur(7);
            }
            if (SDL_RenderCopy(rendu, tex_case, NULL, &Hexagone) != 0)          //Met la forme Hexagone dans le rendu
            {
                Erreur(8);
            }
            SDL_RenderPresent(rendu);                                             //Applique les modification au rendu
            Hexagone.x = Hexagone.x + UNITE_X;
        }
    d++;                                                                          
    Hexagone.y = Hexagone.y + UNITE_Y;                                                 //Se décale en fonction de la ligne
    Hexagone.x = (TAILLE_FENETRE-624)/2-(50*d);
    }

    //-----------------------------------Génération Random Milieu--------------------------------//
    
    for(i=0;i<10;i++)
    {
        int terrain = Aleatoire();                        
        switch(terrain)
        {
            case 0 : image = SDL_LoadBMP("src/Case_Prairie_Dim.bmp"); break;          
                case 1 : image = SDL_LoadBMP("src/Case_Montagne_Dim.bmp"); break;
                case 2 : image = SDL_LoadBMP("src/Case_Foret_Dim.bmp"); break;       
                case 3 : image = SDL_LoadBMP("src/Case_Champ_Dim.bmp"); break;      
                case 4 : image = SDL_LoadBMP("src/Case_Colline_Dim.bmp"); break; 
                case 5 : image = SDL_LoadBMP("src/Case_Mer_Dim.bmp"); break;
        }
                                              
        SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    
        carte[i][4]=terrain;
    
        tex_case = SDL_CreateTextureFromSurface(rendu, image);                    
        if (tex_case == NULL)
        {
            Erreur(6);
        }
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
        Hexagone.x = Hexagone.x + UNITE_X;
    }
    d--;
    Hexagone.y = Hexagone.y + UNITE_Y;
    Hexagone.x = (TAILLE_FENETRE-624)/2-(50*d);
    

    //-----------------------------------Génération Random Partie Basse--------------------------------//
    
    for(j=9;j>5;j--)
    {
        for(i=0;i<j;i++)
        {
            int terrain = Aleatoire();                         
            switch(terrain)
            {
                case 0 : image = SDL_LoadBMP("src/Case_Prairie_Dim.bmp"); break;          
                case 1 : image = SDL_LoadBMP("src/Case_Montagne_Dim.bmp"); break;
                case 2 : image = SDL_LoadBMP("src/Case_Foret_Dim.bmp"); break;       
                case 3 : image = SDL_LoadBMP("src/Case_Champ_Dim.bmp"); break;      
                case 4 : image = SDL_LoadBMP("src/Case_Colline_Dim.bmp"); break; 
                case 5 : image = SDL_LoadBMP("src/Case_Mer_Dim.bmp"); break;
            }
            SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    

            if (d==3){carte[i][8-d]=terrain;}
            else if (d==2){carte[i+1][8-d]=terrain;}
            else if (d==1){carte[i+1][8-d]=terrain;}
            else if (d==0){carte[i+2][8-d]=terrain;}

            tex_case = SDL_CreateTextureFromSurface(rendu, image);                     
            if (tex_case == NULL)
            {
                Erreur(6);
            }
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
            Hexagone.x = Hexagone.x + UNITE_X;
        }
    d--;
    Hexagone.y = Hexagone.y + UNITE_Y;                                                 
    Hexagone.x = (TAILLE_FENETRE-624)/2-(50*d);
    }

    //-----------------------------------Imprime la carte--------------------------------//


    for(j=0;j<10;j++)
        {
            for(i=0;i<10;i++)
            {
                printf("%d ",carte[i][j]);            
            }
        printf("\n");
        }    


//-----------------------------------Delai et Detruit les objets ensuite--------------------------------//
    
    SDL_Delay(10000);

    SDL_DestroyTexture(tex_ocean);                                               
    SDL_DestroyTexture(tex_case);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    
    return 0;
}


//-----------------------------------Sous-Programmes--------------------------------//
    
int Aleatoire()
    {
        int random = rand()%101;
        if (random<PRCT_PRAIRIE)                       //Generation Prairies
        {
            return 0;
        }
        else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE)   //Generation Montagnes
        {
            return 1;
        }
        else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET)  //Generation Foret
        {
            return 2;
        }
        else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET+PRCT_COLLINE) //Generation Colline
        {
            return 3;
        }
        else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET+PRCT_COLLINE+PRCT_CHAMP) //Generation Champs
        {
            return 4;
        }
        else
        {
            return 5;
        }
    }



void Erreur(int error)
{
    printf("Erreur %d, %s\n", error, SDL_GetError());
    exit(EXIT_FAILURE);
}



//------------------------------------------------------/Placement d'un pion/-----------------------------------------------------//

/*int DeplacePion(int joueur, int departx, int departy, int arriveex, int arriveey, int nombre_pions_depart, int nombre_pions_arrivee)
{
    SDL_Surface *image2 = NULL;
    SDL_Rect Pion;
    Pion.x = 88 + arriveex*UNITE_X + (104/2) - (DIM_PION/2);                                      //Coordonees X et Y du pion sur le rendu
    Pion.y = 100 + arriveey*UNITE_Y + (120/2) - (DIM_PION/2);
    Pion.w = DIM_PION;
    Pion.h = DIM_PION;

    if (arriveex%2==0)                                                                
    {
        Pion.x = Pion.x+50;                                              //Decallage en fonction de la ligne
    }

    switch(nombre_pions_arrivee)
    {
        case 1 : image2 = SDL_LoadBMP("src/Case_Pion%d_1_Dim.bmp",joueur); break;      
        case 2 : image2 = SDL_LoadBMP("src/Case_Pion%d_2_Dim.bmp",joueur); break;       //Definition de la texture en fonction
        case 3 : image2 = SDL_LoadBMP("src/Case_Pion%d_3_Dim.bmp",joueur); break;       //Du nombre de pions a l'arrivée
        case 4 : image2 = SDL_LoadBMP("src/Case_Pion%d_4_Dim.bmp",joueur); break;
    }

    //IMPLEMENTER GENERATION DE LA TEXTURE DANS LE RENDU//

//------------------------------------------------/Reset de la texture d'origine/-------------------------------------------//

    
    Pion.x = 88 + departx*UNITE_X + (104/2) - (DIM_PION/2);                                      
    Pion.y = 100 + departy*UNITE_Y + (120/2) - (DIM_PION/2);

    switch(nombre_pions_depart)
    {
        case 0 : image2 = break; //faut que je reflechisse ALERTE     
        case 1 : image2 = SDL_LoadBMP("src/Case_Pion%d_1_Dim.bmp",joueur); break;  
        case 2 : image2 = SDL_LoadBMP("src/Case_Pion%d_2_Dim.bmp",joueur); break;       
        case 3 : image2 = SDL_LoadBMP("src/Case_Pion%d_3_Dim.bmp",joueur); break;
    }


    //IMPLEMENTER GENERATION DE LA TEXTURE DANS LE RENDU//

}
