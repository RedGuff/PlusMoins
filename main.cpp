#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>
using namespace std;
int main()
{
    srand (time(NULL));
    int minNombre=1;
    int maxNombre=10;
    int nombreATrouver = rand() % maxNombre + minNombre;
    int tentative = 0;
    string tentativeS = "0";
    bool inputOk = true;
    int nbTentative = 0;
    cout << "Plus ou moins, un classique de la programmation." << endl << endl;
    cout << "Pour commencer, on est entre "<< minNombre << " et " << maxNombre << "." << endl;
    do
    {
        do
        {
            inputOk = true; // Pour autre demande éventuelle.
            try
            {
                // cin >> tentative;
                getline(cin, tentativeS); // Pour éviter des bugs de non nombre.
                tentative = stoi(tentativeS);
            }
            catch (const std::invalid_argument& e)
            {
                cerr << "Un nombre, svp !" << endl;
                inputOk = false;
            }
        }
        while (inputOk == false);


        if (nombreATrouver > tentative)
        {
            cout << "C\'est plus !" << endl;
            minNombre = max(tentative, minNombre);
        }
        if (nombreATrouver < tentative)
        {
            cout << "C\'est moins !" << endl;
            maxNombre = min(tentative, maxNombre);
        }
        nbTentative++;
        if (tentative != nombreATrouver)
        {
            cout << "On est actuellement entre " << minNombre << " et " << maxNombre << "." << endl;
        }

    }
    while (tentative != nombreATrouver);
    cout << "Bravo ! C\'est une belle victoire, avec seulement " << nbTentative << " tentatives." << endl;
    return 0;
}

