#if !defined Reine_h
#define Reine_h
#include "Piece.h"
#include "Fou.h"
#include "Tour.h"

class Reine : public Fou, public Tour
{
public:
	Reine(bool white);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};

#endif