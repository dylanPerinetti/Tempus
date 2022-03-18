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
#define DIM_PION 40
#define PRCT_PRAIRIE 40
#define PRCT_MONTAGNE 20
#define PRCT_FORET 10
#define PRCT_COLLINE 10
#define PRCT_CHAMP 10
#define PRCT_LAC 10

//---------------------------------Rémi 16/03/2022-------------------------------//

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
    char fichier_terrain[]="src/Case_9_Dim.bmp";        

    
   
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
    
    //--------------------Création et Application de la Texture du fond océan-----------------------------//
    
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
            char terrain = Aleatoire();                        
            fichier_terrain[9] = terrain;
            image = SDL_LoadBMP(fichier_terrain);
            
            SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));     //Rogne le blanc autour des hexagones stockés dans image

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

            if (d==3){carte[i][d]=terrain-48;}
            else if (d==2){carte[i+1][d]=terrain-48;}
            else if (d==1){carte[i+1][d]=terrain-48;}
            else if (d==0){carte[i+2][d]=terrain-48;}
        }
        d++;                                                                          
        Hexagone.y = Hexagone.y + UNITE_Y;                                                 //Se décale en fonction de la ligne
        Hexagone.x = (TAILLE_FENETRE-624)/2-(50*d);
    }

    //-----------------------------------Génération Random Milieu--------------------------------//
    
    for(i=0;i<10;i++)
    {
        char terrain = Aleatoire();                        
        fichier_terrain[9] = terrain;
        image = SDL_LoadBMP(fichier_terrain);
                                              
        SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    
        
    
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
        carte[i][4]=terrain-48;
    }
    d--;
    Hexagone.y = Hexagone.y + UNITE_Y;
    Hexagone.x = (TAILLE_FENETRE-624)/2-(50*d);
    

    //-----------------------------------Génération Random Partie Basse--------------------------------//
    
    for(j=9;j>5;j--)
    {
        for(i=0;i<j;i++)
        {
            char terrain = Aleatoire();                        
            fichier_terrain[9] = terrain;


            image = SDL_LoadBMP(fichier_terrain);
            SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 255, 255));    


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
            
            if (d==3){carte[i][8-d]=terrain-48;}
            else if (d==2){carte[i+1][8-d]=terrain-48;}
            else if (d==1){carte[i+1][8-d]=terrain-48;}
            else if (d==0){carte[i+2][8-d]=terrain-48;}
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
    
    DeplacePionMap(1,3,3,6,6,1,1,0,rendu);
    SDL_Delay(5000);

    SDL_DestroyTexture(tex_ocean);                                               
    SDL_DestroyTexture(tex_case);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    
    return 0;
}


//-----------------------------------Sous-Programmes--------------------------------//
    
char Texture_Rendu(char fichier_terrain[18], SDL_Surface *image, SDL_Texture *tex_case, SDL_Renderer *rendu, SDL_Rect Hexagone)
{}


char Aleatoire()
    {
        int random = rand()%101;
        if (random<PRCT_PRAIRIE){return *"0";}
        else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE){return *"1";}  //Generation Montagnes
        else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET){return *"2";}  //Generation Foret
        else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET+PRCT_COLLINE){return *"3";} //Generation Colline
        else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET+PRCT_COLLINE+PRCT_CHAMP){return *"4";} //Generation Champs
        else {return *"5";}
        
    }


void Erreur(int error)
{
    printf("Erreur %d, %s\n", error, SDL_GetError());
    exit(EXIT_FAILURE);
}



//------------------------------------------------------/Placement d'un pion/-----------------------------------------------------//

void DeplacePionMap(int joueur, int departx, int departy, int arriveex, int arriveey, int nombre_pions_depart, int nombre_pions_arrivee, int case_depart, SDL_Renderer* rendu)
{
    SDL_Surface *image2 = NULL;
    SDL_Texture *tex_pion = NULL;
    SDL_Rect Pion;
    char pion_type[] = "src/Pion9_9.bmp";
    printf("%s\n",pion_type);
    Pion.x = 88 + arriveex*UNITE_X + (104/2) - (DIM_PION/2);                                      //Coordonees X et Y du pion sur le rendu
    Pion.y = 100 + arriveey*UNITE_Y + (120/2) - (DIM_PION/2);
    Pion.w = DIM_PION;
    Pion.h = DIM_PION;

    if (arriveex%2!=0)                                                                
    {
        Pion.x = Pion.x+50;                                              //Decallage en fonction de la ligne
    }
    pion_type[8] = joueur+48;
    pion_type[10] = nombre_pions_arrivee+48;
    printf("%s\n",pion_type);
    image2 = SDL_LoadBMP(pion_type);
    
    SDL_SetColorKey(image2, SDL_TRUE, SDL_MapRGB(image2->format, 255, 255, 255));    

        tex_pion = SDL_CreateTextureFromSurface(rendu, image2);                    
        if (tex_pion == NULL)
        {
            Erreur(6);
        }
        SDL_FreeSurface(image2);
        if (SDL_QueryTexture(tex_pion, NULL, NULL, &Pion.w, &Pion.h) != 0)  
        {
            Erreur(7);
        }
        if (SDL_RenderCopy(rendu, tex_pion, NULL, &Pion) != 0)           
        {
            Erreur(8);
        }
        SDL_RenderPresent(rendu);

    //IMPLEMENTER GENERATION DE LA TEXTURE DANS LE RENDU//

//------------------------------------------------/Reset de la texture d'origine/-------------------------------------------//

    
    Pion.x = 88 + departx*UNITE_X + (104/2) - (DIM_PION/2);                                      
    Pion.y = 100 + departy*UNITE_Y + (120/2) - (DIM_PION/2);
    if (departx%2!=0)                                                                
    {
        Pion.x = Pion.x+50;                                              //Decallage en fonction de la ligne
    }

    if(nombre_pions_depart==0)
    {
        switch(case_depart)
            {
                case 0 : image2 = SDL_LoadBMP("src/Case_0_Dim.bmp"); break;          
                case 1 : image2 = SDL_LoadBMP("src/Case_1_Dim.bmp"); break;
                case 2 : image2 = SDL_LoadBMP("src/Case_2_Dim.bmp"); break;       
                case 3 : image2 = SDL_LoadBMP("src/Case_3_Dim.bmp"); break;      
                case 4 : image2 = SDL_LoadBMP("src/Case_4_Dim.bmp"); break; 
                case 5 : image2 = SDL_LoadBMP("src/Case_5_Dim.bmp"); break;
            }
    }
    else 

    {
        pion_type[10] = nombre_pions_depart+48;

        SDL_LoadBMP(pion_type);

         SDL_SetColorKey(image2, SDL_TRUE, SDL_MapRGB(image2->format, 255, 255, 255));    

        tex_pion = SDL_CreateTextureFromSurface(rendu, image2);                    
        if (tex_pion == NULL)
        {
            Erreur(6);
        }
        SDL_FreeSurface(image2);
        if (SDL_QueryTexture(tex_pion, NULL, NULL, &Pion.w, &Pion.h) != 0)  
        {
            Erreur(7);
        }
        if (SDL_RenderCopy(rendu, tex_pion, NULL, &Pion) != 0)           
        {
            Erreur(8);
        }
        SDL_RenderPresent(rendu);
    }

}
