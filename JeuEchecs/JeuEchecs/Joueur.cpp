#include <iostream>
#include "Joueur.h"

using namespace std;


/////////////////////////////////////////////////////////////////////////
//
// Constructeur pour le joueur
//
/////////////////////////////////////////////////////////////////////////

Joueur::Joueur(bool white) {
    int n = 0;
    int y = white ? 1 : 8;
    for (int x = 1; x <= 8; ++x)
        piecesJoueur[n++].init(x, y, white);
    y = white ? 2 : 7;
    for (int x = 1; x <= 8; ++x)
        piecesJoueur[n++].init(x, y, white);
}


JoueurBlanc::JoueurBlanc() : Joueur(true)
{
    //Constructeur joueur blanc
}

JoueurNoir::JoueurNoir() : Joueur(false)
{
    //Constructeur joueur noir
}



//****************************************
//
// Fonctions utiles
//
//****************************************

void Joueur::placerPieces(Plateau& e)
{
    for (int i = 0; i < 16; i++)
        e.placer(&(piecesJoueur[i]));
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

