/**
* Programme contenant le problème 3 du TD1.
* \file   TD1/Pb3.cpp
* \author Iliass Khider et Bryan Alexandre Tavares
* \date   14 mai 2024
* Créé le 9 mai 2024
*/

#include <iostream>
#include <cmath>

using namespace std;

// Numero 3 : Hauteur de Rebond ----------------------------------------------------------------------------------------

static bool saisieReelleDansIntervalle(double valeur, double min, double max = INFINITY)
{
	return (valeur >= min && valeur <= max);
}

static double calculHauteurRebond(double hauteurInitiale, int nombreRebonds, double coefficientRebond)
{
	double hauteur = hauteurInitiale;
	double const g = 9.81;
	for (int i = 0; i < nombreRebonds; ++i)
	{
		double vitesseAvant = sqrt(2 * g * hauteur);
		double vitesseApres = vitesseAvant * coefficientRebond;
		hauteur = pow(vitesseApres, 2) / (2 * g);
	}
	return hauteur;
}

static void numero3()
{
	double hauteurInitiale, coefficientRebond;
	int nombreRebonds;

	do
	{
		cout << "Veuillez saisir la hauteur initiale de la balle (en metres) : ";
		cin >> hauteurInitiale;
	} while (!saisieReelleDansIntervalle(hauteurInitiale, 0));

	do
	{
		cout << "Veuillez saisir le nombre de rebonds souhaite : ";
		cin >> nombreRebonds;
	} while (!saisieReelleDansIntervalle(nombreRebonds, 0));

	do
	{
		cout << "Veuillez saisir le coefficient de rebond (entre 0 et 1) : ";
		cin >> coefficientRebond;
	} while (!saisieReelleDansIntervalle(coefficientRebond, 0, 1));

	double hauteurFinale = calculHauteurRebond(hauteurInitiale, nombreRebonds, coefficientRebond);

	cout << "La hauteur de la balle apres " << nombreRebonds << " rebonds est de : " << hauteurFinale << " metres." << std::endl;
}

int main()
{
	numero3();

	return 0;
}