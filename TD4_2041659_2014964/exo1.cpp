// TD4
// EXO1
// Bourai Sami : 2041659
// Chobah Oussama : 2014964

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

struct matrice {
	int ligne, colonne;
	int tab[32][32];

};

matrice tableau[2];    // tableau de type matrice pour stocker les elements lus du fichier // pour fonction 3

int entier_Aleatoire(int entier_Min, int entier_Max) {

	int nb_Aleatoire = rand() % (entier_Max - entier_Min + 1) + entier_Min;   // ceci est afin de genere un nombre aleatoire dans l'intervalle entree par l'utilisateur
	return nb_Aleatoire;
}

void generaterice_Matrice(int nombre_Ligne, int nombre_Colonne, int entier_Min, int entier_Max) {

	int** matrice;                 // declaration du tableau a deux dimensions

	matrice = new int*[nombre_Ligne];          // attribution de l'espace memoires pour les lignes


	for (int bl = 0; bl < nombre_Ligne; bl++)       // avec cette boucle on fait l'attribution de l'espace memoire pour les colonnes de toutes les lignes 
	{
		matrice[bl] = new int[nombre_Colonne];
	}


	for (int j = 0; j < nombre_Ligne; j++)                                 // remplissage et affichage de la matrice 
	{
		for (int k = 0; k < nombre_Colonne; k++)
		{
			matrice[j][k] = entier_Aleatoire(entier_Min, entier_Max);
			cout << setw(6) << matrice[j][k] << " ";
		}
		cout << endl;
	}


	for (int n = 0; n < nombre_Ligne; n++)       // liberer l'espace memoire de toutes les colonnes de chaque lignes 
	{
		delete[] matrice[n];
	}
	delete[] matrice;								// liberer l'espace meoire des lignes
}

void lecture_Fichier(const string nomFichier, matrice tableau_M[]) {
	ifstream lecture(nomFichier);

	if (lecture.fail())
	{
		cout << "- ***Erreur de lecture***" << endl;
	}
	else
	{

		cout << "- Fichier lu avec succes " << endl<<endl;
		int i = 0;
		while (!ws(lecture).eof()) {
			lecture >> tableau_M[i].ligne >> tableau_M[i].colonne;						// boule de lecture
			for (int j = 0; j < tableau_M[i].ligne; j++)
			{
				for (int n = 0; n < tableau_M[i].colonne; n++)						// puisqu'il faut lire et placer les donnees de la matrice on a besoin d'une boucle for
				{																	// de plus cette derniere contient comme tableau_M[i].colonne qui represente le nombre
					lecture >> tableau_M[i].tab[j][n];							// de colonne lues et tableau_M[i].ligne : lr nombre de ligne lues 
				}
			}
			i++;																// compteur ou on est rendu. De plus, il indique combien de matrice on a dans fichier
		}
		for (int k = 0; k < i; k++)												// boucle d'affichage 
		{

			cout << "- La matrice " << k + 1 << " est de dimension : " << tableau_M[k].ligne << " x " << tableau_M[k].colonne << endl;		// affichage de la dimension. ex matrice 1: 4x3

			for (int m = 0; m < tableau_M[k].ligne; m++)
			{
				for (int z = 0; z < tableau_M[k].colonne; z++)
				{
					cout << setw(6) << tableau_M[k].tab[m][z] << " ";		// je reserve 6 espace vers la droite pour l'affichage de chaque coefficient ij pour les allignes
				}
				cout << endl;
			}
		}
	}
}


void element_Min_Max(int nombre_Ligne, int nombre_Colonne, int entier_Min, int entier_Max) {

	int** matrice;                 // declaration du tableau a deux dimensions

	matrice = new int*[nombre_Ligne];          // attribution de l'espace memoires pour les lignes


	for (int bl = 0; bl < nombre_Ligne; bl++)       // avec cette boucle on fait l'attribution de l'espace memoire pour les colonnes de toutes les lignes 
	{
		matrice[bl] = new int[nombre_Colonne];
	}


	for (int j = 0; j < nombre_Ligne; j++)                                 // remplissage et affichage de la matrice 
	{
		for (int k = 0; k < nombre_Colonne; k++)
		{
			matrice[j][k] = entier_Aleatoire(entier_Min, entier_Max);
			cout << setw(6) << matrice[j][k] << " ";
		}
		cout << endl;
	}

	int min_Element = matrice[0][0], max_Element = matrice[0][0]; // initialiser min et max a la premiere valeur de la matrice, ensuite comprer avec les autres
	for (int r = 0; r < nombre_Ligne; r++)                                 // remplissage et affichage de la matrice 
	{
		for (int e = 0; e < nombre_Colonne; e++)
		{
			if (matrice[r][e] > max_Element)
			{
				max_Element = matrice[r][e];

			}
			
			if (matrice[r][e]< min_Element)
			{
				min_Element = matrice[r][e];
			}

		}
		
	}
	cout << endl;
	cout << "- L'element maximal  de cette matrice est : " << max_Element << endl;
	cout << "- L'element minimal  de cette matrice est : " << min_Element << endl;

	for (int n = 0; n < nombre_Ligne; n++)       // liberer l'espace memoire de toutes les colonnes de chaque lignes 
	{
		delete[] matrice[n];
	}
	delete[] matrice;								// liberer l'espace meoire des lignes
}
void ecriture_Fichier(const string nom_Fichier_Ecrit,int nombre_Ligne, int nombre_Colonne, int entier_Min, int entier_Max) {

	ofstream ecriture(nom_Fichier_Ecrit);

	int** matrice;                 // declaration du tableau a deux dimensions

	matrice = new int*[nombre_Ligne];          // attribution de l'espace memoires pour les lignes


	for (int bl = 0; bl < nombre_Ligne; bl++)       // avec cette boucle on fait l'attribution de l'espace memoire pour les colonnes de toutes les lignes 
	{
		matrice[bl] = new int[nombre_Colonne];
	}

	
	if (ecriture.fail()) {
		cout << "- *** Erreur, l'ecriture est impossible ***" << endl;
	}
	else {
		cout << "- ***** Ecriture reussie *****" << endl;
		cout << "- Voici le contenu qui sera ecrit dans le fichier text :" << endl;
		for (int j = 0; j < nombre_Ligne; j++)                                 // remplissage et affichage de la matrice 
		{
			for (int k = 0; k < nombre_Colonne; k++)
			{
				matrice[j][k] = entier_Aleatoire(entier_Min, entier_Max);
				cout << setw(6) << matrice[j][k] << " ";							// affichage a l'ecran de la matrice
				ecriture << setw(6) << matrice[j][k] << " ";					// au meme temps on en profite pour ecrire dans le fichier entre par l'utilisateur
			}
			cout << endl;
			ecriture << endl;
		}
	}

	for (int n = 0; n < nombre_Ligne; n++)       // liberer l'espace memoire de toutes les colonnes de chaque lignes 
	{
		delete[] matrice[n];
	}
	delete[] matrice;
}



int main() {
	/////////////////////////////////fonction #3//////////////////////////////////////////////////////////////////////

	cout << "- Fonction 3 -------------------------------------------------------------------------------------" << endl;
	string nomFichier;																				// la string prend le nom du fichier entre par l<utilisateur
	cout << "- entrer le nom du fichier --> (matrice1.txt) : ";
	getline(cin, nomFichier);
	cout << endl;
	lecture_Fichier(nomFichier, tableau);										// on appelle la fonction en lui passant la stringue qui porte le nom du fichier 
	cout << endl;															// ainsi que le tableau qui est de type (matrice)

	////////////////////////////////fonction #1 /////////////////////////////////////////////////////////////////////

	srand(time(NULL));																					  // initialisation afin de remettre le generateur a 0

	int en1, en2;																						  // les arguments que va prendre la fonction entiet_aleatoire
	cout << "- Fonction 1 -------------------------------------------------------------------------------------" << endl;
	cout << "- Entrez le nombre minimal de l'intervalle : ";
	cin >> en1; cout << endl;
	cout << "- Entrez le nombre maximal de l'intervalle : ";
	cin >> en2; cout << endl;
	cout << "- Voici un nombre genere aleatoirement :" << entier_Aleatoire(en1, en2) << endl << endl << endl;  // ici nous affichons le nombre aleatoire de la fonction 1

   /////////////////////////////////fonction #2//////////////////////////////////////////////////////////////////////

	int ligne_Matrice, colonne_Matrice;
	cout << "- Fonction 2 -------------------------------------------------------------------------------------" << endl;
	cout << "- Entrez le nombre de lignes de votre matrice : "; cin >> ligne_Matrice; cout << endl;
	cout << "- Entrez le nombre de colonnes de votre matrice : "; cin >> colonne_Matrice; cout << endl;
	cout << "- Voici la matrice : " << endl;
	generaterice_Matrice(ligne_Matrice, colonne_Matrice, en1, en2);         // pour cette fonction qui genere des matrices , on lui passe le nombre de ligne et de colonne
	cout << endl << endl;					//ainsi que l'intervalle entree precedemment (fonction 1) pour que les nombres genere par la fonction1 soit accorde a la matrice 

	/////////////////////////////////fonction #4//////////////////////////////////////////////////////////////////////

	cout << "- Fonction 4 -------------------------------------------------------------------------------------" << endl<<endl;
	cout << "- Voici une autre matrice : ";
	cout << endl;
	element_Min_Max(ligne_Matrice, colonne_Matrice, en1, en2);			// elle a les meme parametre que la fonction 2 puisque nous nous somme servi de la fonction 2
	cout << endl;																	// qui genere des matrices


	/////////////////////////////////fonction #5//////////////////////////////////////////////////////////////////////

	cout << "- Fonction 5 -------------------------------------------------------------------------------------" << endl;
	cout << endl;
	ecriture_Fichier("ecrit.txt", ligne_Matrice, colonne_Matrice, en1, en2);   // cette derniere fonction prend le meme parametre que la fonction 2
	cout << endl;																// de plus elle fait appelle a la fonction qui gene les nombre random (fonction1)
}


// message important au correcteur : la fonction 4 = elemnt_Min_Max()  et    la fonction 5 = ecriture_Fichier() contiennent en elles une grosse partie
// de la fonction 2 = generatrice_Matrice().  puisque nous avons besoin de genere des matrice dans ces dernieres 
// comme il impossible a une fonction de retouner une matrice ou un tableau ...on a ete oblige de repeter ce code dans ces derniere.








