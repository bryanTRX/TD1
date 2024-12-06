/**
* Programme contenant le problème 5 du TD1.
* \file   TD1/Pb5.cpp
* \author Iliass Khider et Bryan Alexandre Tavares
* \date   14 mai 2024
* Créé le 9 mai 2024
*/

#include <iostream>
#include <array>

using namespace std;

// Numero 5 : Tableau pair/impair --------------------------------------------------------------------------------------

const int TAILLE_TABLEAU = 10;

static void afficherTableau(const array<int, TAILLE_TABLEAU>& tableau)
{
	cout << " {";
	for (int elem = 0; elem < TAILLE_TABLEAU; ++elem)
	{
		cout << tableau[elem];
		if (elem < TAILLE_TABLEAU - 1)
		{
			cout << ", ";
		}
	}
	cout << "}" << endl;
}

static void trierTableauPairImpair(const array<int, TAILLE_TABLEAU>& tableau, array<int, TAILLE_TABLEAU>& tableauTrie)
{
	int indexPair   = 0;
	int indexImpair = TAILLE_TABLEAU - 1;

	for (int elem : tableau)
	{
		if (elem % 2 == 0)
		{
			tableauTrie[indexPair++] = elem;
		}
		else
		{
			tableauTrie[indexImpair--] = elem;
		}
	}
}

static void numero5()
{
	array<int, TAILLE_TABLEAU> tableau = {};
	int valeur = 0;
	for (int elem = 0; elem < TAILLE_TABLEAU; ++elem)
	{
		cout << "Veuillez saisir les elements de la liste : ";
		cin >> valeur;
		tableau[elem] = valeur;
	}

	cout << "Contenu du tableau avant : ";
	afficherTableau(tableau);

	array<int, TAILLE_TABLEAU> tableauTrie = {};
	trierTableauPairImpair(tableau, tableauTrie);

	cout << "Tableau trie pair/impair : ";
	afficherTableau(tableauTrie);
}

int main()
{
	numero5();

	return 0;
}