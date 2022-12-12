#if !defined Fou_h
#define Fou_h
#include "Piece.h"

class Fou : 
	virtual public Piece
{
public:
	Fou(bool white, bool left);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};

#endif