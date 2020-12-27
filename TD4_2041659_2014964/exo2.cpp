
////////////////////////////////////////////////////////////////////////////////
/// \file    CodeFourni.hpp
/// \author  Charles Hosson
///
/// Question 2 du TD4 Hiver 2016.
////////////////////////////////////////////////////////////////////////////////
// TD4 EXO2
// Sami Bourai 
// Oussama Chobah 
///////////////////////////////////////////////////////////////////////////////


#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include "cppitertools/range.hpp"
#include "gsl/span"


using namespace std;
using namespace iter;
using namespace gsl;
#pragma region "Déclaration" //{

#pragma region "Constantes" //{
static const unsigned gestionnaire = rand();

static const unsigned NB_ELEMENTS_MAX = 60;

static const char HOMME = 'M';
static const char FEMME = 'F';

#pragma endregion //}


#pragma region "Structures" //{

struct Stagiaire
{
	int  id;
	int  age;
	char sexe;
	int  taille;
};


struct ListeStagiaires
{
	unsigned  nElements;
	Stagiaire elements[NB_ELEMENTS_MAX];
};


struct InfoGestionnaire
{
	int  age;
	char preferenceDuJour;
};

#pragma endregion //}


#pragma region "Variables globales" //{

InfoGestionnaire gestionnaire;             // variable globale 

#pragma endregion //}

#pragma endregion //}
int Gestionnaire = rand();         //generation d'un nombre aleatoire 

ListeStagiaires ajouterElement(Stagiaire& stagiaire, ListeStagiaires& listeStagiaire)
{
	ListeStagiaires s;
	listeStagiaire.elements[listeStagiaire.nElements].id = stagiaire.id;
	listeStagiaire.elements[listeStagiaire.nElements].age = stagiaire.age;
	listeStagiaire.elements[listeStagiaire.nElements].sexe = stagiaire.sexe;
	listeStagiaire.elements[listeStagiaire.nElements].taille = stagiaire.taille;
	listeStagiaire.nElements++;

	return s;
}

ListeStagiaires LireFichier(const string nomFichier)
{
	ListeStagiaires a;												
	ifstream fichier1(nomFichier);								// ouverture du fichier 
	while (!ws(fichier1).eof())											// boucle de lecture 
	{
		fichier1 >> a.elements[a.nElements].id >> a.elements[a.nElements].age >>
			a.elements[a.nElements].sexe >> a.elements[a.nElements].taille;
		a.nElements++;


	}
	return a;                                            // retourne a de type liste stagiaire 

}

void AfficherListe(ListeStagiaires& listeStagiaire)
{
	for (int i : range(listeStagiaire.nElements)) {
		cout << setw(2) << listeStagiaire.elements[i].id 
			<< "	" << setw(2) << listeStagiaire.elements[i].age 
			<< "	" << setw(1) << listeStagiaire.elements[i].sexe            // on  reserver deux espaces vers la droite pour l'affichage 
			<< "	" << setw(1) << listeStagiaire.elements[i].taille;
	}
}



ListeStagiaires chercherParAge(ListeStagiaires& listeStagiaire, int& ageStagiaire)
{
	ListeStagiaires c;
	for (int i : range(listeStagiaire.nElements))
		if (listeStagiaire.elements[i].age == ageStagiaire) {                     // ageStagiare = age entree dans le main, donc c'est a ce dernier qu'on compare nos donnees

			cout << setw(2) << listeStagiaire.elements[i].id						
				<< "	" << setw(2) << listeStagiaire.elements[i].age 
				<< "	" << setw(1) << listeStagiaire.elements[i].sexe 
				<< "	" << setw(1) << listeStagiaire.elements[i].taille;
		}
	return c;
}

double calculerCoefficient(Stagiaire& stagiaire)
{
	InfoGestionnaire e;                         
	int facteurAge;
	double PI = 3.14159265359;
	facteurAge = stagiaire.age - ((e.age / 2) + 7);
	double facteurTaille = sin(stagiaire.taille * PI / 180) * 10;
	double FacteurSexe;
	char sexeIdEntre = stagiaire.sexe;
	if (((gestionnaire % 2) == 0))
	{
		e.preferenceDuJour = 'F';
		if (stagiaire.sexe == e.preferenceDuJour)
		{
			FacteurSexe = 1.25;
		}
		else
		{
			FacteurSexe = 1;
		}
	}
	else if ((gestionnaire % 2) != 0)
	{
		e.preferenceDuJour = 'M';
		if (stagiaire.sexe == e.preferenceDuJour) {
			FacteurSexe = 1.25;
		}
		else
		{
			FacteurSexe = 1;
		}


	}
	double Coefficient = (facteurAge + facteurTaille) * FacteurSexe;
	return Coefficient;

}


Stagiaire chercherMeilleurStagiaire(ListeStagiaires& listeStagiaire)
{
	Stagiaire f;
	double meilleurCoefficient = 0.0;
	int indiceMeilleurStagiaire = 0;

	for (int i : range(listeStagiaire.nElements))
	{
		double x = calculerCoefficient(f);
		if (x > meilleurCoefficient) {
			indiceMeilleurStagiaire = i;
		}

	}
	f.id = listeStagiaire.elements[indiceMeilleurStagiaire].id;
	return f;
};





int main()
{
	cout << "Voici les fonctions suggeres " << endl;
	cout << "- (1) fonction 1" << endl;
	cout << "- (2) fonction 2" << endl;
	cout << "- (3) fonction 3" << endl;
	cout << "- (4) fonction 4" << endl;
	cout << "- (5) fonction 5" << endl;
	cout << "- (6) fonction 6" << endl;
	int choixFonction;
	cout << "Choissisez la fonction voulu: ";
	cin >> choixFonction;
	switch (choixFonction)                           // on choisi de tester nos fonction avec un switch case
	{
	case 1:											// donc on donne le choix a l'utilisateur de choisir la fonction qu'il veut tester  ex; 1--> test fonction 1
		ListeStagiaires g;
		Stagiaire h;
		ajouterElement(h, g);
		break;                                      // on break afin de terminer 
	case 2:
		LireFichier("stagiaires.txt");
		break;
	case 3:
		ListeStagiaires i;
		AfficherListe(i);
		break;
	case 5:
		ListeStagiaires j;
		int ageStagiaire;
		cout << "Entrez l'age des stagiaires que vous voudriez voir affiche";
		cin >> ageStagiaire;
		chercherParAge(g, ageStagiaire);
		break;
	case 4:
		InfoGestionnaire d;
		cout << "Entrez votre age: ";
		cin >> d.age;
		Stagiaire k;
		calculerCoefficient(k);
		break;
	case 6:
		ListeStagiaires l;
		InfoGestionnaire m;
		cout << "Entrez votre age: ";
		cin >> m.age;
		InfoGestionnaire n;
		chercherMeilleurStagiaire(l);
		break;

	}

}

