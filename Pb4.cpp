/**
* Programme contenant le problème 3 du TD1.
* \file   TD1/Pb4.cpp
* \author Iliass Khider et Bryan Alexandre Tavares
* \date   14 mai 2024
* Créé le 9 mai 2024
*/

#include <iostream>
#include <random>
#include <iomanip> 

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

using namespace std;

// Numero 4 : Approximation de pi --------------------------------------------------------------------------------------

static double genererNombreAleatoire()
{
	return ((double)rand() / RAND_MAX) * 2 - 1;
}

static void numero4()
{
	srand(time(nullptr));
	int nombreIterations;
	int nombrePointsDansCercle = 0;

	cout << "Veuillez choisir le nombre d'iterations souhaitees : ";
	cin >> nombreIterations;

	for (int i = 0; i < nombreIterations; ++i)
	{
		double x = genererNombreAleatoire();
		double y = genererNombreAleatoire();

		if (pow(x,2) + pow(y, 2) < 1)
		{
			nombrePointsDansCercle++;
		}
	}

	double approximationPi = 4.0 * nombrePointsDansCercle / nombreIterations;
	cout << "L'approximation de pi par la méthode de Monte-Carlo est : " << fixed << setprecision(6) << approximationPi << endl;

	double ecartRelatif = abs(approximationPi - M_PI) / M_PI;
	cout << "L'ecart relatif avec la valeur precise de pi est : " << ecartRelatif << endl;
}

int main()
{
	numero4();

	return 0;
}