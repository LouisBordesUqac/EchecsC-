
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

	virtual void ajouterTempsJoueur(clock_t tempsTourActuel);
	virtual void afficherTempsJoueur(bool couleur);
	Joueur(bool white);
	void placerPieces(Plateau& plateau);

};
#endif
