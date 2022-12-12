
#if !defined Piece_h
#define Piece_h

class Plateau;

class Piece
{
protected:

	int pos_x;
	int pos_y;
	bool couleur;

public:

	Piece();
	Piece(int x, int y, bool white);

	void init(int x, int y, bool white);
	void deplacer(int x, int y);

	int getX();
	int getY();
	bool isWhite();
	bool isBlack();	

	virtual bool mouvementValide(Plateau& e, int x, int y);
	virtual char assignerPiece();
};

#endif
