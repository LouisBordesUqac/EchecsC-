
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

	int x();
	int y();
	bool isWhite();
	bool isBlack();

	virtual bool mouvementValide(Plateau& e, int x, int y);
	virtual char assignerPiece();
};


class Roi : public Piece
{
public:
	Roi(bool white);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};

class Fou : virtual public Piece
{
public:
	Fou(bool white, bool left);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};

class Tour : virtual public Piece
{
public:
	Tour(bool white, bool left);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};

class Reine : public Fou, public Tour
{
public:
	Reine(bool white);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};

class Cavalier : virtual public Piece
{
public:
	Cavalier(bool white, bool left);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};

class Pion : virtual public Piece
{
public:
	Pion(int x, bool white);
	bool mouvementValide(Plateau& e, int x, int y);
	char assignerPiece();
};
#endif
