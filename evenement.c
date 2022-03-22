/*

-------------- TEMPUS --------------

Retrouvez le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au evenement-graphique dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "evenement.h".

Fait par dylan le 21/03/2022
Dernière modifications par dylanPerinetti le 21/03/2022

*/
#include <evenement.h>

int PlacerPionGraphiqueSurMap(Pions* _pion,int _x,int _y)
{
	int _coord_depart_x = _pion->coord_x;
	int _coord_depart_y = _pion->coord_y;
	PlacerPionSurMap(_pion, _x, _y);
	//DeplacePionMap(_pion,_coord_depart_x, _coord_depart_y);		//plus une fonction placer pion gsur map??
	return 0;
}
