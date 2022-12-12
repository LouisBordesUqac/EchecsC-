#include <iostream>
#include "Joueur.h"

using namespace std;


/////////////////////////////////////////////////////////////////////////
//
// Constructeur pour le joueur
//
/////////////////////////////////////////////////////////////////////////

Joueur::Joueur(bool white) {
    
    // Constructeur par défaut du joueur
}


JoueurBlanc::JoueurBlanc() : Joueur(true)
{
    //Constructeur joueur blanc
    int nb = 0;
    int y = 1;
    for (int x = 1; x <= 8; ++x)
        piecesJoueur[nb++].init(x, y, true);
    y = 2;
    for (int x = 1; x <= 8; ++x)
        piecesJoueur[nb++].init(x, y, true);
}

JoueurNoir::JoueurNoir() : Joueur(false)
{
    //Constructeur joueur noir
    int nb = 0;
    int y = 8;
    for (int x = 1; x <= 8; ++x)
        piecesJoueur[nb++].init(x, y, false);
    y = 7;
    for (int x = 1; x <= 8; ++x)
        piecesJoueur[nb++].init(x, y, false);
}



//****************************************
//
// Fonctions utiles
//
//****************************************

void Joueur::placerPieces(Plateau& echiquier)
{
    for (int i = 0; i < 16; i++)
        echiquier.placer(&(piecesJoueur[i]));
}


/*
bool JoueurBlanc::isWhite()
{
    return true;
}

bool JoueurNoir::isWhite()
{
    return false;
}
*/

