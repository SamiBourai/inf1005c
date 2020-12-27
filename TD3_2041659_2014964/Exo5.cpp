#include <iostream>
#include<string>
using namespace std;

int main()
{
	int tab1[10] = {};
	int tab2[10] = {};
	int v = 0;


											// lecture des 10 nombres
	for (int i = 0;i < 10;i++) {

		cout << "Entrez un entier: ";
		cin >> tab1[i];
	
	}
	int x = 0;											// ce compteur sert a placer les chiffre pairs au debut 
														// Au meme temps cette boucle nous permet de mettre les chiffres pairs en premier 
	
		for(int j=0;j<10;j++)
		{
			if((tab1[j])%2==0)
			{
				tab2[x] = tab1[j];
				x++;
				
				
			}

		}
		
													// le compteur est rendu a n nombre pairs, ainsi il va directement continuer a placer les chiffres impaire la ou il est rendu 
													// donc cette boucle nous sert a place les chiffres impaire 

    
	
	{ 
		for (int z = 0;z < 10;z++) {
			if (tab1[z] % 2 != 0) {
				tab2[x] = tab1[z];
				x++;
			}
		}								

	}

	cout<<" le tableau devient  : "							// affichage du tableau apres manipulation 
	for (int a = 0;a < 10; a++) {
		cout << tab2[a] << " ";
	}
}

