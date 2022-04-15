/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez à la map dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "map.h".

Fait par Dylan le 22/03/2022
Dernière modifications par dylanPerinetti le 24/03/2022

	Je suis acctuellement en train de develloper :
		- void CreeMapTuile();
		- void InitialiserCoordonneesTuile(Tuile* _tuile);								
		- void InitialiserTypeTerrainTuile(Tuile* _tuile, unsigned char _Type_terrain);	
		- void InitialiserCiteTuile(Tuile* _tuile, Cite* _cite);							
		- void InitialiserPionsTuile(Tuile* _tuile, Pions _pion_dessus[]);
		- int ChangerCoordonneesTuile(Tuile* _tuile, unsigned char _x, unsigned char _y);
		- void AfficherErreurEvenement(int _erreur);
		
*/
#include "map.h"

#define X_MIN 0
#define X_MAX 10
#define Y_MIN 0
#define Y_MAX 10

void CreeMapTuile(Tuile _map[10][10])
{
	srand(time(NULL));
	for (int i = 0; i < Y_MAX; i++)
	{
		for (int j = 0; j < X_MAX; j++)
		{
			InitialiserCurseur(&_map[i][j], 0);
			ChangerTypeTerrainTuile(&_map[i][j], RandomizeTuile());
			ChangerNombresPionsTuile(&_map[i][j],'0','0');
			ChangerCouleurTuile(&_map[i][j],'0');
			ChangerTailleVilleTuile(&_map[i][j],'0');
			printf("\nInitialisation de la tuiles x = %u | y = %u | Type de terrain = %c | Couleur de la Tuile = %c |", i, j, _map[i][j].type_terrain,_map[i][j].couleur);
			printf("\n|Nombre de pion = %c | Taille de la Ville = %c | Curseur = %d\n",_map[i][j].nombre_pion,_map[i][j].taille_ville,_map[i][j].curseur);
			if(CaseInterdite(i,j)==1)
			{
					ChangerTypeTerrainTuile(&_map[i][j], '7');
			}
		}
	}
	InitialiserCurseur(&_map[5][5], 1);
	ChangerNombresPionsTuile(&_map[4][4],'1','1');
	ChangerNombresPionsTuile(&_map[3][3],'1','2');
	ChangerNombresPionsTuile(&_map[5][5],'2','3');
	ChangerNombresPionsTuile(&_map[6][6],'1','4');
}


void InitialiserCurseur(Tuile* _tuile, int bool)
{
	_tuile->curseur = bool;
}

int ChangerNombresPionsTuile(Tuile* _tuile, unsigned char _nombre_pion, unsigned char _couleur)
{
	_tuile->nombre_pion = _nombre_pion;
	if(_nombre_pion==0)
	{
		ChangerCouleurTuile(_tuile,'0');
	}
	else ChangerCouleurTuile(_tuile, _couleur);  //<----- pour l'instant je mets 1 par defaut mais on changera pour que ce soit le nombre correspondant au joueur qui joue
	return 0;

}


int ChangerTypeTerrainTuile(Tuile* _tuile, unsigned char _type_terrain)
{
	_tuile->type_terrain = _type_terrain;
	return 0;	
}

int ChangerCouleurTuile(Tuile* _tuile, unsigned char _couleur)
{
	_tuile->couleur = _couleur;
	return 0;	
}

int ChangerTailleVilleTuile(Tuile* _tuile, unsigned char _taille_ville)
{
	_tuile->taille_ville = _taille_ville;
	return 0;	
}



int EcrireTuilesBinaire(Tuile* _tuile)
{
	FILE* fic;

	fic = fopen("_DATA/_SAVE.data","wba");
	if(fic == NULL)
	{
		return 3;
	}
	fwrite(_tuile,sizeof(*_tuile),1,fic);
	fclose(fic);
	return 0;
}


int LectureTuilesBinaire(Tuile* _tuile)
{
	FILE* fic;

	fic = fopen("_DATA/_SAVE.data", "rb");
	if(fic == NULL)
	{
		return 3;
	}
	fread(_tuile,sizeof(*_tuile),1,fic);
	fclose(fic);
	return 0;
}


void AfficherErreurEvenement(int _erreur)
{
	switch(_erreur)
	{
		case 0:
			break;
		case 3:
			fprintf(stderr, "\nErreur%d Erreur a l ouverture fichier.\n",_erreur);
			break;
		case 2:
			fprintf(stderr,"\nErreur%d Probleme coordonnees X",_erreur);
			break;
		case 4:
			fprintf(stderr, "\nErreur%d Probleme cette tuiles n'est pas initialiser ou cette deriner est deja sur la map.\n",_erreur);
			break;
		case 22:
			fprintf(stderr,"\nErreur%d Probleme coordonnees Y",_erreur);
			break;
		default:
			fprintf(stderr,"\nErreur Inconnue");
	}

}

char RandomizeTuile()
{
	
	int random = rand()%101;
    if (random<PRCT_PRAIRIE)return '0';
    else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE)return '1';
    else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET)return '2'; 
    else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET+PRCT_COLLINE)return '3'; 
    else if (random<PRCT_PRAIRIE+PRCT_MONTAGNE+PRCT_FORET+PRCT_COLLINE+PRCT_CHAMP)return '4'; 
    else return '5';
}

int CaseInterdite(int i, int j)
{
	if(i==0)
	{
		if(j<3||j>5) return 1;
	}
	
	if(i==1)
	{
		if(j==0||j==8) return 1;
	}
	
	if(i==8)
	{
		if(j<2||j>6) return 1;
	}
	
	if(i==9)
	{
		if(j!=4) return 1;
	}
	
	if(j==9) return 1;

	else return 0;
}

int CaseAdjacente(int departx, int departy, int arriveex, int arriveey)
{
	if(arriveey==departy&&(arriveex==departx-1||arriveex==departx+1)) return 1;
	
	if(departy%2==0)
	{
		if((arriveey==departy+1)&&((arriveex==departx)||(arriveex==departx-1))) return 1;
		if((arriveey==departy-1)&&((arriveex==departx)||(arriveex==departx-1))) return 1;
	}
	else if(departy%2!=0)
	{
		if((arriveey==departy+1)&&((arriveex==departx)||(arriveex==departx+1))) return 1;
		if((arriveey==departy-1)&&((arriveex==departx)||(arriveex==departx+1))) return 1;
	}

	else return 0;
}

