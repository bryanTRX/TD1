/**
* Programme contenant le problème 1 du TD1.
* \file   TD1/Pb1.cpp
* \author Iliass Khider et Bryan Alexandre Tavares
* \date   14 mai 2024
* Créé le 9 mai 2024
*/

#include <iostream>
#include <cmath>

using namespace std;

// Numero 1 : Nombres premiers --------------------------------------------------------------------------------------

static bool estPremier(int n)
{
	if (n <= 1) { return false; }
	if (n % 2 == 0) { return false; }
	if (n <= 3) { return true; }

	for (int elem = 3; elem <= sqrt(n); elem += 2)
	{
		if (n % elem == 0) { return false; }
	}
	return true;
}

static int plusPetitDiviseur(int n)
{
	if (n <= 1) { return n; }
	if (n % 2 == 0) { return 2; }

	for (int elem = 3; elem <= sqrt(n); elem += 2)
	{
		if (n % elem == 0) { return elem; }
	}
	return n;
}

static void numero1()
{
	int nombre   = 0;
	bool premier = false;

	do
	{
		cout << "Entrer un nombre entier : ";
		cin >> nombre;

		if (estPremier(nombre))
		{
			premier = true;
			cout << "Ce nombre est premier. " << endl;
		}
		else
		{
			cout << "Ce nombre n'est pas premier car il est divisible par " << plusPetitDiviseur(nombre) << "." << " Essayez a nouveau !" << endl;
		}

	} while (!premier);
}

int main()
{
	numero1();
	
	return 0;
}