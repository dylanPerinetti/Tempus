#include "map.h"
#include "objet.h"
#include "joueur.h"

int PlacerPionGraphiqueSurMap(Pions* _pion,int _x,int _y)
{
	int _coord_depart_x = _pion->coord_x;
	int _coord_depart_y = _pion->coord_y;
	PlacerPionSurMap(_pion, _x, _y);
	//DeplacePionMap(_pion,_coord_depart_x, _coord_depart_y);		//plus une fonction placer pion gsur map??
	return 0;
}
