/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez à la map dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "map.h".

Fait par MrTNTX le 22/03/2022
Dernière modifications par dylanPerinetti le 22/03/2022

*/
#include "map.h"

int EcrireTuilesBinaire(Tuile* _tuile)
{
	FILE* fic;

	fic = fopen("_DATA/_SAVE.data","wba");
	if(fic == NULL)
	{
		fprintf(stderr, "Erreur ouverture fichier.\n");
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
		fprintf(stderr, "Erreur ouverture fichier.\n");
		return 3;
	}
	fread(_tuile,sizeof(*_tuile),1,fic);
	fclose(fic);
	return 0;
}
