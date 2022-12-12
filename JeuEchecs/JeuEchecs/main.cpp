
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Plateau.h"
#include "Partie.h"
#include <ctime>
#include <time.h>

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;


bool compare(Piece& pa, Piece& pb)
{
    return ((pa.getX() == pb.getX()) && (pa.getY() == pb.getY()));
}

void attendre(float temps);
/**
 * Programme principal
 */
int main(int argc, char** argv)
{
    clock_t temps;
    Partie p;


    temps = clock();
    p.jouerPartie();

    //attendre(61);

    //temps = clock() - temps;
    //cout << "La partie a dure " << (float)temps / CLOCKS_PER_SEC << " seconds" << endl;
    //cout << "La partie a dure " << ((float)temps / CLOCKS_PER_SEC) / 60 << " minutes" << endl;

}


void attendre(float temps)
{
    clock_t arrivee = clock() + (temps * CLOCKS_PER_SEC); // On calcule le moment où l'attente devra s'arrêter

    while (clock() < arrivee);
}




