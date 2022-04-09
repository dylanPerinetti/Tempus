/*

-------------- TEMPUS --------------

Retrouver le Projet complet sur Git "https://github.com/dylanPerinetti/tempus" 

Ce fichier contient les fonction liez au deplacement dans le Jeu Tempus.
En savoir plus sur leur utilisation dans le ficheier "deplacement.h".

Fait par dylan le 15/03/2022
Dernière modifications par dylanPerinetti le 06/04/2022 
Pour correctif de beug

*/

#include "deplacement.h"

#define X_MIN 0
#define X_MAX 10
#define Y_MIN 0
#define Y_MAX 10
#define NOMBRE_PION 16
#define NOMBRE_CITE 8
#define COORDONNEES_INVENTAIRE 99

/*--------------------------------------------------------------------------*/
// A UPDATE
/*--------------------------------------------------------------------------*/

void AfficherErreurDeplacementObjet(int _erreur)
{
	switch(_erreur)
	{
		case 0:
			break;
		case 1:
			fprintf(stderr,"\nErreur%d Probleme le pion n'est pas dans l'inventaire",_erreur);
			break;
		case 2:
			fprintf(stderr,"\nErreur%d Probleme coordonnees X",_erreur);
			break;
		case 11:
			fprintf(stderr,"\nErreur%d Probleme couleur objet differrente de celle du joueur",_erreur);
			break;
		case 22:
			fprintf(stderr,"\nErreur%d Probleme coordonnees Y",_erreur);
			break;
		default:
			fprintf(stderr,"\nErreur Inconnue");
	}
}
