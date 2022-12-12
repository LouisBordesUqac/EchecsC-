
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Partie.h"
#include "Piece.h"
#include "Joueur.h"
#include "Plateau.h"
#include <cstring>

#include "Roi.h"
#include "Reine.h"
#include "Fou.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Pion.h"


using namespace std;



void Partie::verifCoordonnees()
{
    string xy = "";
    char cx;
    char cy;
    char tabPos[3];

    while (true)
    {
        tabPos[0] = 0;
        tabPos[1] = 0;
        cout << "\nXY = ";

        cin >> xy;
        //cout << "xy = " << xy << endl;
        //strcpy_s(tabPos, 2, xy);
        strcpy(tabPos, xy.c_str());

        cx = tabPos[0];
        cy = tabPos[1];

        x = convertPosX(cx);
        y = convertPosY(cy);


        if ((x >= 1) && (x <= 8) && (y >= 1) && (y <= 8))
        {
            break;
        }
        else
        {
            cout << "\nCase incorrecte, Veuillez resaisir les coordonnees :";
        }
    }
}

int Partie::convertPosX(char xval) {

    switch (xval) {
    case 'A':
        return 8;
        break;
    case 'B':
        return 7;
        break;
    case 'C':
        return 6;
        break;
    case 'D':
        return 5;
        break;
    case 'E':
        return 4;
        break;
    case 'F':
        return 3;
        break;
    case 'G':
        return 2;
        break;
    case 'H':
        return 1;
        break;
    default:
        return -1;
    }
}

int Partie::convertPosY(char yval) {

    switch (yval) {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    default:
        return -1;
    }
}


//VERIFIER SI PIECE ADVERSAIRE PEUT SE DEPLACER SUR ROI JOUEUR ACTUEL
//echec = 1; exit function;

int Partie::roiEnEchec()
{
    int caseEchec = -1;
    int rbX, rbY, rnX, rnY;

    //RECUPERER COORDONNEES DES 2 ROIS
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (echiquier.getPiece(i, j) != NULL)
            {
                //On vérifier si la pièce est un roi, si oui on récupère ses coordonnées
                if (echiquier.getPiece(i, j)->assignerPiece() == 'R')
                {
                    rbX = i;
                    rbY = j;
                    cout << "\n" << rbX;
                    cout << "\n" << rbY;
                }
                else
                {
                    if (echiquier.getPiece(i, j)->assignerPiece() == 'r')
                    {
                        rnX = i;
                        rnY = j;
                    }
                }
            }
        }
    }

    //VERIFIER SI PIECE JOUEUR ACTUEL PEUT SE DEPLACER SUR ROI ADVERSAIRE
    for (int k = 1; k <= 8; k++) {
        for (int l = 1; l <= 8; l++) {
            if (echiquier.getPiece(k, l) != NULL)
            {
                cout << "\n TEST 1";
                if (joueurActuel) //joueur blanc
                {
                    cout << "\n TEST 2";
                    if (echiquier.getPiece(k, l)->isWhite())
                    {
                        if (echiquier.getPiece(k, l)->mouvementValide(echiquier, rnX, rnY))
                        {
                            caseEchec = 2;

                            //VERIFIER SI ROI ADVERSAIRE PEUT SE DEPLACER
                            for (int m = rnX - 1; rnX + 1; rnX++)
                            {
                                for (int n = rnY - 1; rnY + 1; rnY++)
                                {
                                    if (echiquier.getPiece(rnX, rnY)->mouvementValide(echiquier, m, n))
                                    {
                                        caseEchec = 3;
                                        goto fin;
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (echiquier.getPiece(k, l)->mouvementValide(echiquier, rbX, rbY))
                    {
                        caseEchec = 2;
                        //VERIFIER SI ROI ADVERSAIRE PEUT SE DEPLACER
                        for (int m = rnX - 1; rnX + 1; rnX++)
                        {
                            for (int n = rnY - 1; rnY + 1; rnY++)
                            {
                                if (echiquier.getPiece(rnX, rnY)->mouvementValide(echiquier, m, n))
                                {
                                    caseEchec = 3;
                                    goto fin;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

fin:
    return (caseEchec);
}


void Partie::jouerPartie()
{
    //////////////////////////////////
    // Initialisation des variables
    //////////////////////////////////


    joueurActuel = true;    //Joueur blanc = vrai / Joueur noir = faux

    int roiEnEchec = 0;
    int deplacementX;
    int deplacementY;
    char typePiece;
    bool partieFinie = false;
    bool mouvementValide = false;

    //////////////////////////////////
    // Initialisation des joueurs de la partie
    //////////////////////////////////
    joueurBlanc.placerPieces(echiquier);
    joueurNoir.placerPieces(echiquier);

    //////////////////////////////////
    // Initialisation des pieces des deux joueurs
    //////////////////////////////////

    Roi rb(true);                 //ROIS
    Roi rn(false);
    Reine qb(true);               //REINES
    Reine qn(false);
    Tour tb1(true, true);         //TOURS
    Tour tn1(false, true);
    Tour tb2(true, false);
    Tour tn2(false, false);
    Fou fb1(true, true);          //FOUS
    Fou fn1(false, true);
    Fou fb2(true, false);
    Fou fn2(false, false);
    Cavalier cb1(true, true);     //CAVALIERS
    Cavalier cn1(false, true);
    Cavalier cb2(true, false);
    Cavalier cn2(false, false);
    Pion pb1(1, true);            //PIONS
    Pion pn1(1, false);
    Pion pb2(2, true);
    Pion pn2(2, false);
    Pion pb3(3, true);
    Pion pn3(3, false);
    Pion pb4(4, true);
    Pion pn4(4, false);
    Pion pb5(5, true);
    Pion pn5(5, false);
    Pion pb6(6, true);
    Pion pn6(6, false);
    Pion pb7(7, true);
    Pion pn7(7, false);
    Pion pb8(8, true);
    Pion pn8(8, false);


    //////////////////////////////////
    // Initialisation des positions des pieces
    // Placement des pièces sur ces positions
    //////////////////////////////////

    echiquier.enleverPiece(5, 1);  //Roi blanc
    echiquier.placer(&rb);
    echiquier.enleverPiece(5, 8);  //Roi noir
    echiquier.placer(&rn);
    echiquier.enleverPiece(4, 1);  //Reine blanc
    echiquier.placer(&qb);
    echiquier.enleverPiece(4, 8);  // Reine noir
    echiquier.placer(&qn);
    echiquier.enleverPiece(1, 1);  //Tour 
    echiquier.placer(&tb1);
    echiquier.enleverPiece(1, 8);  //Tour 
    echiquier.placer(&tn1);
    echiquier.enleverPiece(8, 1);  //Tour 
    echiquier.placer(&tb2);
    echiquier.enleverPiece(8, 8);  //Tour 
    echiquier.placer(&tn2);
    echiquier.enleverPiece(3, 1);  //Fou
    echiquier.placer(&fb1);
    echiquier.enleverPiece(3, 8);  //Fou
    echiquier.placer(&fn1);
    echiquier.enleverPiece(6, 1);  //Fou
    echiquier.placer(&fb2);
    echiquier.enleverPiece(6, 8);  //Fou
    echiquier.placer(&fn2);
    echiquier.enleverPiece(2, 1);  //Cavalier
    echiquier.placer(&cb1);
    echiquier.enleverPiece(2, 8);  //Cavalier
    echiquier.placer(&cn1);
    echiquier.enleverPiece(7, 1);  //Cavalier
    echiquier.placer(&cb2);
    echiquier.enleverPiece(7, 8);  //Cavalier
    echiquier.placer(&cn2);
    echiquier.enleverPiece(1, 2);  //Pions
    echiquier.placer(&pb1);
    echiquier.enleverPiece(1, 7);
    echiquier.placer(&pn1);
    echiquier.enleverPiece(2, 2);
    echiquier.placer(&pb2);
    echiquier.enleverPiece(2, 7);
    echiquier.placer(&pn2);
    echiquier.enleverPiece(3, 2);
    echiquier.placer(&pb3);
    echiquier.enleverPiece(3, 7);
    echiquier.placer(&pn3);
    echiquier.enleverPiece(4, 2);
    echiquier.placer(&pb4);
    echiquier.enleverPiece(4, 7);
    echiquier.placer(&pn4);
    echiquier.enleverPiece(5, 2);
    echiquier.placer(&pb5);
    echiquier.enleverPiece(5, 7);
    echiquier.placer(&pn5);
    echiquier.enleverPiece(6, 2);
    echiquier.placer(&pb6);
    echiquier.enleverPiece(6, 7);
    echiquier.placer(&pn6);
    echiquier.enleverPiece(7, 2);
    echiquier.placer(&pb7);
    echiquier.enleverPiece(7, 7);
    echiquier.placer(&pn7);
    echiquier.enleverPiece(8, 2);
    echiquier.placer(&pb8);
    echiquier.enleverPiece(8, 7);
    echiquier.placer(&pn8);


    //////////////////////////////////
    // Déroulement de la partie
    //////////////////////////////////

    while (partieFinie == false)
    {
        bool mouvementValide = false; // Définition du booleen pour éviter que le mouvement soit effectué par erreur
        int roiEnEchec = -1;          // Définition de la variable qui indique la situation du roi
        echiquier.affiche();          // Affichage de l'échiquier à chaque nouveau coup


        // Indique le joueur actif
        if (joueurActuel)
        {
            cout << "\n Au tour du joueur blanc." << endl << "Saisir les coordonnees de la piece a deplacer :";
        }
        else
        {
            cout << "\n Au tour du joueur noir." << endl << "Saisir les coordonnees de la piece a deplacer :";
        }


        //////////////////////////////////
        // Déroulement de la partie
        //////////////////////////////////
        while (!mouvementValide)
        {
            this->verifCoordonnees();   //Vérifie si les coordonnées données sont valides
            deplacementX = this->x;
            deplacementY = this->y;

            //////////////////////////////////
            // Vérifie que la piece existe
            // Vérifie que la pièce appartient au joueur
            //////////////////////////////////
            if (echiquier.getPiece(deplacementX, deplacementY) != NULL)
            {
                if ((joueurActuel && echiquier.getPiece(deplacementX, deplacementY)->isWhite()) || (!joueurActuel && echiquier.getPiece(deplacementX, deplacementY)->isBlack()))
                {
                    while (!mouvementValide)
                    {
                        cout << "\nSaisir les coordonnees de la nouvelle position de la piece : ";
                        verifCoordonnees();
                        if (echiquier.getPiece(deplacementX, deplacementY)->mouvementValide(echiquier, x, y))
                        {
                            //////////////////////////////////
                            // Vérifie que le roi n'est pas en échec
                            //////////////////////////////////
                            switch (roiEnEchec)
                            {
                            case 1:
                                cout << "\nDeplacement invalide : Vous etes en Echec si vous déplacez cette pièce !";
                                break;
                            case 2:
                                if (joueurActuel == true)
                                {
                                    cout << "\nLe joueur noir est en echec !";
                                }
                                else
                                {
                                    cout << "\nLe joueur blanc est en echec !";
                                }
                                echiquier.deplacerPlateau(echiquier.getPiece(deplacementX, deplacementY), x, y);
                                mouvementValide = true;
                                break;
                            case 3:
                                if (joueurActuel == true)
                                {
                                    cout << "\nLe roi du joueur noir est echec et mat ";
                                }
                                else
                                {
                                    cout << "\nLe roi du joueur blanc est echec et mat ";
                                }
                                echiquier.deplacerPlateau(echiquier.getPiece(deplacementX, deplacementY), x, y);
                                mouvementValide = true;
                                partieFinie = true;
                                break;
                            default:
                                echiquier.deplacerPlateau(echiquier.getPiece(deplacementX, deplacementY), x, y);
                                mouvementValide = true;
                                break;
                            }
                        }
                        else
                        {
                            cout << "\nLes coordonnees sont invalides pour cette piece.";
                        }
                    }
                }
                else
                {
                    cout << "\nCette piece n'appartient pas a ce joueur. Veuillez choisir de nouvelles coordonnees :";
                }
            }
            else
            {
                cout << "\nIl n'y a pas de piece a la position (" << deplacementX << "," << deplacementY << ")." << endl << "Saisissez une position valide :";
            }

        }

        joueurActuel = !joueurActuel;   //Le joueur actif change

        //partieFinie = true; //provisoire : afin de ne pas boucler indéfininiment tant que ce n'est pas fini
    }
}
