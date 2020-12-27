#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	double h;
	cout << "Entrez une hauteur initiale : ";
	cin >> h;
	int i;
	cout << "Entrez le nombre de rebond ou vous desiriez connaitre la hauteur de la balle : ";
	cin >> i;
	double c;
	cout << "Entrez le coefficient de rebond: ";
	cin >> c;
	while (c<0 || c>1)
	{
		cout << "Entrez un nouveau coefficient de rebond car le dernier ne se trouve pas dans l'intervalle permise. ";
		cin >> c;

	}
	for (int x = 0;x < i;x++ ) {
		double vitesse = sqrt(2 * 9.81 * h);
		vitesse = c * vitesse;
		h = pow(vitesse,2) / (2 * 9.81);

	}
	cout << "La hauteur atteinte a " << i << " rebonds est de " << h << " ." << endl;
}
