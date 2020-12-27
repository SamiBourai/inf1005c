#include<iostream>
#include<cmath>
#include<string>

using namespace std;

double validerEntrees(string chaine, int min, float max) {
	cout << chaine;
	double var;
	cin >> var;
	while (var<min || var>max) {
		cout << "Entrez une nouvelle valeur, la derniere entree ne se trouve pas dans l'intervalle permise ." << endl;
		cin >> var;
	}

	while (var >= min && var <= max)
		return var;
}
int main() {
	double pret;
	pret = validerEntrees("Veuillez entrer le montant prete:: ", 0, INFINITY);

	double interet;
	interet = validerEntrees("Veuillez entrer le taux d'interet annuel: ", 0, 100);

	double remboursement;
	remboursement = validerEntrees("Veuillez entrer le montant de remboursement mensuel: ", 0, INFINITY);

	double interetMensuel = interet / 12;
	int mois = 0;

	double sommeInteret = 0;
	while (pret > 0) {
		sommeInteret = sommeInteret + pret * (interetMensuel / 100);
		pret = pret + pret * (interetMensuel / 100) - remboursement;
		mois++;

	}
	cout << "Il faudra " << mois << " mois pour rembourser le montant emprunter." << endl;
	cout << "La somme des interets percu par l'emprunteur est de " << sommeInteret << "." << endl;
}