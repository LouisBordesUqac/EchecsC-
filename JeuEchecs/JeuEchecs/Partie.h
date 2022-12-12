
#if !defined Partie_h
#define Partie_h

#include "Piece.h"
#include "Plateau.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"
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

    bool joueurActuel;
    int x;
    int y;

public:

    void jouerPartie();
    void verifCoordonnees();
    
    int roiEnEchec();
    int convertPosX(char x);
    int convertPosY(char y);

};


#endif
