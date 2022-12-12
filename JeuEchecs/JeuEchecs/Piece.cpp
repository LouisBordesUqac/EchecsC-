
#include <iostream>
#include "Piece.h"
#include "Plateau.h"
#include <cmath>

#include "Roi.h"
#include "Reine.h"
#include "Fou.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Pion.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////
//
// Constructeurs pour les pièces
//
/////////////////////////////////////////////////////////////////////////

Piece::Piece()
{
    //Constructeur Piece defaut
}

Piece::Piece(int x, int y, bool white)
{
    pos_x = x;
    pos_y = y;
    couleur = white;
    //Constructeur Piece complet
}


/////////////////////////////////////////////////////////////////////////
//
// Fonctions utiles
//
/////////////////////////////////////////////////////////////////////////

//****************************************
//
// Initialise une pièce et ses valeurs
//
//****************************************

void Piece::init(int x, int y, bool white)
{
    pos_x = x;
    pos_y = y;
    couleur = white;
}

//****************************************
//
// Déplace une pièce
//
//****************************************

void Piece::deplacer(int x, int y)
{
    pos_x = x;
    pos_y = y;
}

//****************************************
//
// Getter de la valeur x
//
//****************************************
int Piece::getX()
{
    return pos_x;
}

//****************************************
//
// Getter de la valeur y
//
//****************************************
int Piece::getY()
{
    return pos_y;
}

//****************************************
//
// Getter couleur de la pièce
//
//****************************************
bool Piece::isWhite()
{
    return couleur;
}
bool Piece::isBlack()
{
    return !couleur;
}

//****************************************
//
// Fonction par défaut appelée lors d'un mouvement valide
//
//****************************************
bool Piece::mouvementValide(Plateau& e, int x, int y)
{
    cout << "mouvementValide Piece" << endl;
    return 0;
}


/////////////////////////////////////////////////////////////////////////
//
// On assigne une lettre a chaque pièce en fonction de la couleur
// Lettre majuscule pour les blancs
// Lettre minuscule pour les noirs
//
/////////////////////////////////////////////////////////////////////////

char Piece::assignerPiece()
{
    return (couleur) ? ' ' : ' ';
}

char Pion::assignerPiece()
{
    return (couleur) ? 'P' : 'p';
}

char Cavalier::assignerPiece()
{
    return (couleur) ? 'C' : 'c';
}

char Tour::assignerPiece()
{
    return (couleur) ? 'T' : 't';
}

char Fou::assignerPiece()
{
    return (couleur) ? 'F' : 'f';
}

char Reine::assignerPiece()
{
    return (couleur) ? 'Q' : 'q';
}

char Roi::assignerPiece()
{
    return (couleur) ? 'R' : 'r';
}

/////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////
//
// Constructeurs par défaut des pieces
//
/////////////////////////////////////////////////////////////////////////

Fou::Fou(bool white, bool left) : Piece(left ? 3 : 6, white ? 1 : 8, white)
{
    //Constructeur Fou
}

Tour::Tour(bool white, bool left) : Piece(left ? 1 : 8, white ? 1 : 8, white)
{

    //Constructeur Tour
}

Cavalier::Cavalier(bool white, bool left) : Piece(left ? 2 : 7, white ? 1 : 8, white)
{

    //Constructeur Cavalier
}

Pion::Pion(int x, bool white) : Piece(x, white ? 2 : 7, white)
{
    //Constructeur Pion
}

Reine::Reine(bool white) : Piece(4, white ? 1 : 8, white), Fou(white, true), Tour(white, true)
{

    //Constructeur Reine
}

Roi::Roi(bool white)
{
    pos_x = 5;
    pos_y = white ? 1 : 8;
    couleur = white;
    //Constructeur Roi
}

/////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////
//
// Fonctions de déplacement des pièces
//
/////////////////////////////////////////////////////////////////////////


//****************************************
//
// Déplacements des pions
//
//****************************************
bool Pion::mouvementValide(Plateau& e, int x, int y)
{
    bool estValide = false;

    if ((pos_y == 2 && couleur) || (pos_y == 7 && !couleur))
    {
        if ((x == pos_x && y == pos_y + 2 && couleur) || (x == pos_x && y == pos_y - 2 && !couleur)) //cas avancer de 2 cases
        {
            if (couleur && e.getPiece(pos_x, pos_y + 1) == NULL && e.getPiece(pos_x, pos_y + 2) == NULL)
            {
                estValide = true;
            }
            else
            {
                if (!couleur && e.getPiece(pos_x, pos_y - 1) == NULL && e.getPiece(pos_x, pos_y - 2) == NULL)
                {
                    estValide = true;
                }
            }
        }
        else
        {
            if ((x == pos_x && y == pos_y + 1 && couleur) || (x == pos_x && y == pos_y - 1 && !couleur))    //Cas avancer 1 case
            {
                if (e.getPiece(x, y) == NULL)
                {
                    estValide = true;
                }
            }
            else
            {
                if ((1 == abs(x - pos_x) && y == pos_y + 1 && couleur) || (1 == abs(x - pos_x) && y == pos_y - 1 && !couleur))
                {
                    if (e.getPiece(x, y) != NULL && e.getPiece(x, y)->isWhite() != couleur)
                    {
                        e.enleverPiece(x, y);
                        estValide = true;
                    }
                }
            }
        }
    }
    else
    {
        if ((x == pos_x && y == pos_y + 1 && couleur) || (x == pos_x && y == pos_y - 1 && !couleur))
        {
            if (e.getPiece(x, y) == NULL)
            {
                estValide = true;
            }
        }
        else
        {
            if ((1 == abs(x - pos_x) && y == pos_y + 1 && couleur) || (1 == abs(x - pos_x) && y == pos_y - 1 && !couleur))
            {
                if (e.getPiece(x, y) != NULL && e.getPiece(x, y)->isWhite() != couleur)
                {
                    e.enleverPiece(x, y);
                    estValide = true;
                }
            }
        }
    }

    return estValide;
}

//****************************************
//
// Déplacements des cavaliers
//
//****************************************

bool Cavalier::mouvementValide(Plateau& e, int x, int y)
{
    bool estValide = false;

    //Vérifie que la case est valide
    if ((abs(x - pos_x) == 2 && abs(y - pos_y) == 1) || (abs(x - pos_x) == 1 && abs(y - pos_y) == 2))
    {
        if (e.getPiece(x, y) != NULL)
        {
            if (e.getPiece(x, y)->isWhite() != couleur)
            {
                e.enleverPiece(x, y);
                estValide = true;
            }
        }
        else
        {
            estValide = true;
        }
    }

    return estValide;
}

//****************************************
//
// Déplacements des fous
//
//****************************************

bool Fou::mouvementValide(Plateau& e, int x, int y)
{
    int xDepart = this->getX();
    int yDepart = this->getY();
    bool estBlanche = this->isWhite();
    bool estValide = false;
    int ecartX = x - xDepart;
    int ecartY = y - yDepart;

    if (ecartX == ecartY || ecartX == -ecartY)
    {
        if (ecartX > 0 && ecartY < 0)    //déplacement en haut à droite
        {
            while (xDepart != x && yDepart != y)
            {
                yDepart++;
                yDepart--;

                if (e.getPiece(yDepart, yDepart) != NULL)
                {
                    if (xDepart == x && yDepart == y && e.getPiece(x, y)->isWhite() != estBlanche)
                    {
                        e.enleverPiece(x, y);
                        estValide = true;
                    }
                }
                else
                {
                    if (xDepart == x && yDepart == y && estValide == false)
                    {
                        estValide = true;
                    }
                }
            }
        }
        else
        {
            if (ecartX < 0 && ecartY > 0)    //déplacement en bas à gauche
            {
                while (xDepart != x && yDepart != y)
                {
                    xDepart--;
                    yDepart++;

                    if (e.getPiece(yDepart, yDepart) != NULL)
                    {
                        if (xDepart == x && yDepart == y && e.getPiece(x, y)->isWhite() != estBlanche)
                        {
                            e.enleverPiece(x, y);
                            estValide = true;
                        }
                    }
                    else
                    {
                        if (xDepart == x && yDepart == y && estValide == false)
                        {
                            estValide = true;
                        }
                    }
                }
            }
            else
            {
                if (ecartX < 0 || ecartY < 0)    //déplacement haut gauche
                {
                    while (xDepart != x || yDepart != y)
                    {
                        xDepart--;
                        yDepart--;

                        if (e.getPiece(xDepart, yDepart) != NULL)
                        {
                            if (xDepart == x && yDepart == y && e.getPiece(x, y)->isWhite() != estBlanche)
                            {
                                e.enleverPiece(x, y);
                                estValide = true;
                            }
                        }
                        else
                        {
                            if (xDepart == x && yDepart == y && estValide == false)
                            {
                                estValide = true;
                            }
                        }
                    }
                }
                else            //déplacement bas droite
                {
                    while (ecartX != x && ecartY != y)
                    {
                        xDepart++;
                        yDepart++;

                        if (e.getPiece(xDepart, yDepart) != NULL)
                        {
                            if (xDepart == x && yDepart == y && e.getPiece(x, y)->isWhite() != estBlanche)
                            {
                                e.enleverPiece(x, y);
                                estValide = true;
                            }
                        }
                        else
                        {
                            if (xDepart == x && yDepart == y && estValide == false)
                            {
                                estValide = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return estValide;
}

//****************************************
//
// Déplacements des tours
//
//****************************************

bool Tour::mouvementValide(Plateau& e, int x, int y)
{
    bool estValide = false;
    int i = 0;  //pour indice de boucle

    //vérifier si pièce sur chemin et vérifier si pièce sur case d'arrivée et sa couleur
    if ((x == pos_x && y >= 1 && y <= 8) || (y == pos_y && x >= 1 && x <= 8))
    {
        if (pos_x < x)    //déplacement vers droite
        {
            for (i = pos_x; i <= x; i++)
            {
                if (e.getPiece(i, y) != NULL)
                {
                    if (i == x && e.getPiece(i, y)->isWhite() != couleur)
                    {
                        e.enleverPiece(x, y);
                        estValide = true;
                    }
                }
                else
                {
                    if (i == x && estValide == false)
                    {
                        estValide = true;
                    }
                }
            }
        }
        else
        {
            if (pos_x > x)    //déplacement vers gauche
            {
                for (i = pos_x; i <= x; i--)
                {
                    if (e.getPiece(i, y) != NULL)
                    {
                        if (i == x && e.getPiece(i, y)->isWhite() != couleur)
                        {
                            e.enleverPiece(x, y);
                            estValide = true;
                        }
                    }
                    else
                    {
                        if (i == x && estValide == false)
                        {
                            estValide = true;
                        }
                    }
                }
            }
            else
            {
                if (pos_y < y)    //déplacement vers bas
                {
                    for (i = pos_y; i <= y; i++)
                    {
                        if (e.getPiece(x, i) != NULL)
                        {
                            if (i == y && e.getPiece(x, i)->isWhite() != couleur)
                            {
                                e.enleverPiece(x, y);
                                estValide = true;
                            }
                        }
                        else
                        {
                            if (i == y && estValide == false)
                            {
                                estValide = true;
                            }
                        }
                    }
                }
                else            //déplacement vers haut
                {
                    for (i = pos_y; i <= y; i--)
                    {
                        if (e.getPiece(x, i) != NULL)
                        {
                            if (i == y && e.getPiece(x, i)->isWhite() != couleur)
                            {
                                e.enleverPiece(x, y);
                                estValide = true;
                            }
                        }
                        else
                        {
                            if (i == y && estValide == false)
                            {
                                estValide = true;
                            }
                        }
                    }
                }
            }
        }
    }

    return estValide;
}

//****************************************
//
// Déplacements de la reine
//
//****************************************

bool Reine::mouvementValide(Plateau& e, int x, int y)
{
    bool mouvementValide = false;

    if (Tour::mouvementValide(e, x, y) || Fou::mouvementValide(e, x, y))
    {
        mouvementValide = true;
    }

    return (mouvementValide);
}

//****************************************
//
// Déplacements du roi
//
//****************************************

bool Roi::mouvementValide(Plateau& e, int x, int y)
{
    bool estValide = false;

    if ((abs(x - pos_x) <= 1) && (abs(y - pos_y) <= 1))
    {
        //Vérifier si piece présente ou pas sur case d'arrivée
        if (e.getPiece(x, y) != NULL)
        {
            if (e.getPiece(x, y)->isWhite() != couleur)
            {
                e.enleverPiece(x, y);
                cout << "Le mouvement du Roi est valide" << endl;
                estValide = true;
            }
        }
        else
        {
            cout << "Le mouvement du Roi est valide" << endl;
            estValide = true;
        }
    }

    return estValide;
}

/////////////////////////////////////////////////////////////////////////