
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Plateau.h"
#include "Partie.h"
#include <ctime>
#include <time.h>

using namespace std;


//////////////////////////:
// Programme principal  //
//////////////////////////

int main(int argc, char** argv)
{
    clock_t temps;
    float tempsEnSecondes;
    Partie p;


    temps = clock();
    p.jouerPartie();

    temps = clock() - temps;
    tempsEnSecondes = temps / CLOCKS_PER_SEC;

    cout << "La partie a dure " << tempsEnSecondes << " seconds" << endl;
    cout << "La partie a dure " << ((float)temps / CLOCKS_PER_SEC) / 60 << " minutes" << endl;

}




