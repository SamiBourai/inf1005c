#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int entier;
	cout << "Entrez un nombre entier: ";
	cin >> entier;
	int i = 2;



	if (entier == 2) {
		cout << "Ce nombre est premier";
	}
	else {



		while ((entier % i) != 0 && (i <= sqrt(entier)))
		{
			i++;				// 

		};

		if (entier % i != 0)
		{
			cout << "Ce nombre est premier";

		}
		else {
			cout << "Ce nombre n'est pas premier car il est divisble par " << i << "." << endl;
		}

	}

}