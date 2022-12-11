
#if !defined Partie_h
#define Partie_h

#include "Piece.h"
#include "Plateau.h"
#include "Joueur.h"
#include <string>
#include <time.h>

using namespace std;

class Partie
{
private:

    Plateau echiquier;
    JoueurBlanc joueurBlanc;
    JoueurNoir joueurNoir;
    clock_t tempsPartie;

    bool joueurActuel;
    int x;
    int y;

public:

    void jouerPartie();
    void verifCoordonnees();
    void creerPieces();

    int roiEnEchec();
    int convertPosX(char x);
    int convertPosY(char y);

};


#endif
