/**
* Programme contenant le probl�me 3 du TD1.
* \file   TD1/Pb2.cpp
* \author Iliass Khider et Bryan Alexandre Tavares
* \date   14 mai 2024
* Cr�� le 9 mai 2024
*/

#include <iostream>
#include <cmath>

using namespace std;

// Numero 2 : Emprunt --------------------------------------------------------------------------------------------------

static bool saisieReelleDansIntervalle(double valeur, double min, double max = INFINITY)
{
	return (valeur >= min && valeur <= max);
}

static void numero2()
{
	double pret = 0.0, rembourserMensuel = 0.0, tauxInteretAnnuel = 0.0;

	do
	{
		cout << "Veuillez saisir un montant d'argent pr�t�e : ";
		cin >> pret;
	} while (!saisieReelleDansIntervalle(pret, 0));

	do
	{
		cout << "Veuillez saisir le montant rembours� chaque mois : ";
		cin >> rembourserMensuel;
	} while (!saisieReelleDansIntervalle(rembourserMensuel, 0));

	do
	{
		cout << "Veuillez saisir le taux d'interet : ";
		cin >> tauxInteretAnnuel;
	} while (!saisieReelleDansIntervalle(tauxInteretAnnuel, 0, 100));

	double tauxInteretMensuel = tauxInteretAnnuel / 12.0 / 100.0;
	int mois = 0;

	double sommeRestante = pret;
	double totalInterets = 0.0;

	while (sommeRestante > 0)
	{
		sommeRestante *= (1 + tauxInteretMensuel);
		sommeRestante -= rembourserMensuel;
		totalInterets += rembourserMensuel * tauxInteretMensuel;
		mois++;
	}
	cout << "Nombre de mois pour rembourser la dette : " << mois << endl;
	cout << "Somme des interet : " << totalInterets << endl;
}

int main()
{
	numero2();

	return 0;
}