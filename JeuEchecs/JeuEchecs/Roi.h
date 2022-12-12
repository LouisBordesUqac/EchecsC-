#if !defined Roi_h
#define Roi_h
#include "Piece.h"

class Roi : 
	public Piece
{
public:
	Roi(bool white);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};

#endif