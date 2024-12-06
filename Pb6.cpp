/**
* Programme contenant le problème 6 du TD1.
* \file   TD1/Pb6.cpp
* \author Iliass Khider et Bryan Alexandre Tavares
* \date   14 mai 2024
* Créé le 9 mai 2024
*/

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Numero 6 : Dictionnaire --------------------------------------------------------------------------------------

struct Mot
{
	string mot;
	string nature;
	string definition;
};

static void afficherMotLePlusLong(const vector<Mot>& dictionnaire)
{
	int indexMotLePlusLong = 0;
	for (int elem = 0; elem < dictionnaire.size(); ++elem)
	{
		if (dictionnaire[elem].mot.length() > dictionnaire[indexMotLePlusLong].mot.length())
		{
			indexMotLePlusLong = elem;
		}
	}
	cout << dictionnaire[indexMotLePlusLong].mot << " (" << dictionnaire[indexMotLePlusLong].nature << ") : " << dictionnaire[indexMotLePlusLong].definition << endl;
}

static void numero6()
{
	vector<Mot> dictionnaire;

	ifstream ficLire("dictionnaire.txt");
	if (!ficLire)
	{
		cerr << "Erreur lors de l'ouverture du fichier." << endl;
		return;
	}

	string ligne;
	while (getline(ficLire, ligne))
	{
		istringstream iss(ligne);

		Mot mot;
		if (getline(iss, mot.mot, '\t') && getline(iss, mot.nature, '\t') && getline(iss, mot.definition))
		{
			dictionnaire.push_back(mot);
		}	
	}
	ficLire.close();

	if (dictionnaire.empty())
	{
		cerr << "Aucune donnee lue depuis le fichier." << endl;
		return;
	}
	afficherMotLePlusLong(dictionnaire);
}

int main()
{
	numero6();

	return 0;
}