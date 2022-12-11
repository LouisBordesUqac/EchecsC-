
#if !defined Joueur_h
#define Joueur_h

#include <time.h>
#include "Piece.h"
#include "Plateau.h"

class Joueur
{
protected:

	Piece piecesJoueur[16];
	clock_t tempsJoueur;

public:

	Joueur(bool white);
	void placerPieces(Plateau& plateau);

};


class JoueurBlanc : public Joueur
{
public:
	JoueurBlanc();
};


class JoueurNoir : public Joueur
{
public:
	JoueurNoir();
};

#endif
