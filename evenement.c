/*

-------------- TEMPUS --------------

Retrouvez le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au evenement-graphique dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "evenement.h".

Fait par dylan le 21/03/2022
Dernière modifications par dylanPerinetti le 22/03/2022

*/
#include <evenement.h>

int PlacerPionGraphiqueSurMap(Pions* _pion,unsigned char _x,unsigned char _y)
{
	int _coord_depart_x = _pion->coordonnees.X;
	int _coord_depart_y = _pion->coordonnees.Y;
	PlacerPionSurMap(_pion, _x, _y);
	// PAS COMPLETE
	return 0;
}
