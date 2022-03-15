

void Test_coord(Joueur j,uint8_t c){

    for (int i = 0; i < 16; ++i)
	{
		printf("Pion %d se trouve en x=%d y=%d",i,j.pions_possede[i].Coordx,j.pions_possede[i].Coordy);
	}
	for (int i = 0; i < 8; ++i)
	{
		Ville ville_i={i,c,-1,-1};
		printf("Ville %d se trouve en x=%d y=%d",i,j.ville_possede[i].Coordx,j.ville_possede[i].Coordy);
	}
