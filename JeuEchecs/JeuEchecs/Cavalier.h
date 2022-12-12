#if !defined Cavalier_h
#define Cavalier_h
#include "Piece.h"

class Cavalier : virtual public Piece
{
public:
	Cavalier(bool white, bool left);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};

#endif