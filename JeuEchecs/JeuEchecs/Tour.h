#if !defined Tour_h
#define Tour_h
#include "Piece.h"

class Tour : 
	virtual public Piece
{
public:
	Tour(bool white, bool left);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};

#endif