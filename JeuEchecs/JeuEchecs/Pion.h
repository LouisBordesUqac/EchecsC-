#if !defined Pion_h
#define Pion_h
#include "Piece.h"

class Pion : virtual public Piece
{
public:
	Pion(int x, bool white);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};

#endif