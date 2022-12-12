#include <iostream>
#include "Joueur.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"

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


void Joueur::ajouterTempsJoueur(clock_t tempsTourActuel) 
{
    tempsJoueur = clock() + tempsTourActuel;
}

void Joueur::afficherTempsJoueur(bool couleur) 
{
    float tempsEnSecondes;
    
    tempsEnSecondes = tempsJoueur / CLOCKS_PER_SEC;
    if (couleur) {
        cout << "Le joueur blanc a joue pendant " << ((float)tempsJoueur / CLOCKS_PER_SEC) / 60 << " minutes" << endl;
    }
    else {
        cout << "Le joueur noir a joue pendant " << ((float)tempsJoueur / CLOCKS_PER_SEC) / 60 << " minutes" << endl;
    }

}