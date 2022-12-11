
#if !defined Plateau_h
#define Plateau_h

#include "Piece.h"

class Plateau
{
private:

	Piece* echiquier[64];

public:


	Plateau();

	Piece* getPiece(int x, int y);
	void affiche();
	bool caseValide(int x, int y);

	bool placer(Piece* p);
	Piece* enleverPiece(int x, int y);
	void deplacerPlateau(Piece* p, int x, int y);


};

#endif

