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
#define VALEUR_INVENTAIRE 99 // Valeur par deafut de tous se qui a été initialiser /!\ cette dernier dois depasser la plus grande coordonnes de la map soit 10/10

void CreeMapTuile(Tuile _map[10][10])
{
	srand(time(NULL));
	for (int i = 0; i < Y_MAX; i++)
	{
		for (int j = 0; j < X_MAX; j++)
		{
			InitialiserCoordonneesTuile(&_map[i][j]);
			InitialiserTypeTerrainTuile(&_map[i][j]);
			InitialiserNombresPionsTuile(&_map[i][j]);
			ChangerCoordonneesTuile(&_map[i][j], i, j);
			ChangerTypeTerrainTuile(&_map[i][j], RandomizeTuile());
			ChangerNombresPionsTuile(&_map[i][j],'1');
			printf("\nInitialisation de la tuiles x = %u | y = %u | Type de terrain = %c ",_map[i][j].coordonnees.X,_map[i][j].coordonnees.Y, _map[i][j].type_terrain);
			if(i==0)
			{
				if(j<3||j>5)
				{
					ChangerTypeTerrainTuile(&_map[i][j], '7');
				}
			}
			if(i==1)
			{
				if(j==0||j==8)
				{
					ChangerTypeTerrainTuile(&_map[i][j], '7');
				}
			}
			if(i==8)
			{
				if(j<2||j>6)
				{
					ChangerTypeTerrainTuile(&_map[i][j], '7');
				}
			}
			if(i==9)
			{
				if(j!=4)
				{
					ChangerTypeTerrainTuile(&_map[i][j], '7');
				}
			}
			if(j==9)
			{
				ChangerTypeTerrainTuile(&_map[i][j], '7');
			}
		}
	}
}


void InitialiserCoordonneesTuile(Tuile* _tuile)
{
	_tuile->coordonnees.X = VALEUR_INVENTAIRE;
	_tuile->coordonnees.Y = VALEUR_INVENTAIRE;
}


void InitialiserTypeTerrainTuile(Tuile* _tuile)
{
	_tuile->type_terrain = VALEUR_INVENTAIRE;	
}


void InitialiserNombresPionsTuile(Tuile* _tuile)
{
	_tuile->nombre_pion = VALEUR_INVENTAIRE;
}



int ChangerNombresPionsTuile(Tuile* _tuile, unsigned char _nombre_pion)
{
	_tuile->nombre_pion = _nombre_pion;
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


