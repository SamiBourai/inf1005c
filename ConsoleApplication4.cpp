

#include <iostream>
using namespace std;


int main()
{

	int premier_Tab[10];
	int deuxieme_Tab[10];



	int i = 0, n = 0, j = 0,m=0;

	int taille_Tab1 = sizeof(premier_Tab) / sizeof(int);

	for (int i = 0; i < taille_Tab1; i++)
	{
		cout << " - Entrez la donnee " << i + 1 << " : ";
		cin >> premier_Tab[i];
		cout << endl;
		
	}
	int compteur = 0;
	for (n = 0; n < taille_Tab1; n++)
	{
		if (premier_Tab[n] % 2 == 0) {

			deuxieme_Tab[compteur++] = premier_Tab[n];
		}
		
	}
	cout << "1-compteur est rendu a position : " << compteur << endl;

	for (int m = 0; m < taille_Tab1; m++)
	{
		
		if (premier_Tab[m] % 2 == 1) {

			deuxieme_Tab[compteur++] = premier_Tab[m];
		}
			
	}

	cout << "2-compteur est rendu a position : " << compteur << endl;



	cout << "- Voici le tableau initialement : ";
	for (j = 0; j < taille_Tab1; j++) {
		cout << premier_Tab[j] << " ";
	}
	cout << endl << endl;

	cout << "- Voici le tableau apres manipulation : ";
	for (int m = 0; m < taille_Tab1; m++) {
		cout << deuxieme_Tab[m] << " ";
	}

}

