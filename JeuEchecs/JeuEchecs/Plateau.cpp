
#include <iostream>
#include "Plateau.h"
#include "Piece.h"

using namespace std;

//****************************************
//
// Constructeur du plateau
//
//****************************************

Plateau::Plateau()
{
    for (int i = 0; i < 64; i++)
        echiquier[i] = NULL;
}

//****************************************
//
// Getter qui renvoie la piece de l'echiquier
//
//****************************************

Piece* Plateau::getPiece(int x, int y)
{
    if (caseValide(x, y))
        return echiquier[(x - 1) + 8 * (y - 1)];
    return NULL;
}

//****************************************
//
// Affiche le plateau de jeu
//
//****************************************

void Plateau::affiche()
{
    cout << endl << "  HGFEDCBA" << endl;
    for (int y = 1; y <= 8; ++y)
    {
        cout << y << " ";
        for (int x = 1; x <= 8; ++x)
        {
            char c;
            Piece* p = getPiece(x, y);
            if (p == 0)
                c = ((x + y) % 2) == 0 ? '~' : '.';
            else
                c = p->assignerPiece();   //Assigne les couleurs
            cout << c;
        }
        cout << " " << y << endl;
    }
    cout << "  HGFEDCBA" << endl;
}

//****************************************
//
// Place la piece en paramètre sur l'échiquier
//
//****************************************

bool Plateau::placer(Piece* piece)
{
    if (piece == NULL) return false;
    int position = (piece->getX() - 1) + 8 * (piece->getY() - 1);
    if ((piece->getX() >= 1) && (piece->getX() <= 8) && (piece->getY() >= 1) && (piece->getY() <= 8) && echiquier[position] == NULL)
    {
        echiquier[position] = piece;
        return true;
    }
    return false;
}

//****************************************
//
// Déplace un piece passée en paramètre aux coordonnées
//
//****************************************

void Plateau::deplacerPlateau(Piece* p, int x, int y)
{
    int xDepart = p->getX();
    int yDepart = p->getY();

    enleverPiece(xDepart, yDepart);
    p->deplacer(x, y);
    placer(p);
}

//****************************************
//
// Supprime une pièce à une position
//
//****************************************

Piece* Plateau::enleverPiece(int x, int y)
{
    if (caseValide(x, y) && getPiece(x, y) != NULL)
    {
        Piece* tmp = echiquier[(x - 1) + 8 * (y - 1)];
        echiquier[(x - 1) + 8 * (y - 1)] = NULL;
        return tmp;
    }
    return NULL;
}

//****************************************
//
// Vérifie que la case démandée existe bien
//
//****************************************

bool Plateau::caseValide(int x, int y) {

    if ((x >= 1) && (x <= 8) && (y >= 1) && (y <= 8))
        return true;
    return false;
}



