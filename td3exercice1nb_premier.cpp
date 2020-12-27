

#include <iostream>
using namespace std;

int main()
{ // entee et lecture d'un nombre premier:

	int n, j=0; 
	cout << "- Entrez un nombre entier : " << endl;
	cin >> n;

// si le nombre modulo 2 est de 0 le nombre est premier sinon il ne l'es pas --> faire autre chose .
	if (n%2==0)
	{
		cout << "- Le nombre n'est pas premier, car il est divisible par 2 ." << endl;
	}
	else 
	{
	
		//afin de verifier tout les nombres de 1 jusqu'a  (n) ....
		

		for (int i = 1; i <= n; i++)
			if (n%i == 0)
				j++;

		// si le nombre est divisible par plus de 2 nombres alors il est n'est automatiquement pas premier
		if (j>2)
		{
			cout << "- Le nombre n'est pas premier." << endl;
		}
		// sinon si j< ou = a 2, la le nombre est directement premier :
		else
		{
			cout << "- Le nombre est premier." << endl;
		}
			
	}
}

